#include "TripsTableHandler.hpp"
#include <iostream>

using namespace std;

TripsTableHandler::TripsTableHandler(TaxiManager* _taxi_manager) : Handler(_taxi_manager) {}

Response* TripsTableHandler::callback(Request* request){
    string username = request->getBodyParam(USERNAME);
    string sort_by_cost = request->getBodyParam(SORT_BY_COST);
    Command command(GET_STR, TRIPS_COMMAND);
    command.add_parameter(USERNAME, username);
    command.add_parameter(SORT_BY_COST, sort_by_cost);
    try{
        string trips_str = taxi_manager->handle_command(command);
        vector<string> trips_data = split(trips_str, ENTER_STR, false);
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        string body = add_table_body(trips_data, username);
        res->setBody(body);
        return res;
    }
    catch(exception& error){
        string error_msg = error.what();
        return Response::redirect("/driver-authentication-form?msg=" + error_msg);
    }    
}

string TripsTableHandler::add_table_body(vector<string> trips_data, string username){
    ostringstream table;
    for (auto trip : trips_data)
        table << add_row(trip, username);
    ifstream html_template("templates/trip-tables.html");
    ostringstream body;
    string buffer;
    for(int line_num = 1; getline(html_template, buffer); line_num++){
        if (line_num == TABLE_LINE)
            body << table.str() << endl;
        else
            body << buffer << endl;
    }
    return body.str();
}

string TripsTableHandler::add_row(string trip_str, string username){
    ostringstream row;
    row << "<tr>" << endl;
    vector<string> trip_elements = split(trip_str, SPACE_STR, false); 
    for (auto trip_element : trip_elements){
        row << "    <td>" << trip_element << "</td>" << endl;
    }
    row << add_accept_finish_form(trip_elements, username);
    row << endl << "    </td>" << endl << "</tr>";
    return row.str();
}

string TripsTableHandler::add_accept_finish_form(vector<string> trip_elements, string username){
    string trip_status = trip_elements[trip_elements.size() - 1];
    if (trip_status != TRAVELING_STATUS && trip_status != WAITING_STATUS)
        return "    <td></td>";
    ostringstream os;
    string trip_id = trip_elements[ID_INDEX];
    string action = "accept-trip";
    string submit_value = "Accept";
    if (trip_status == TRAVELING_STATUS){
        action = "finish-trip";
        submit_value = "Finish";
    }
    os  << "    <td>" << endl << "      <form method='POST' action='" << action << "'>" << endl
        << "            <input type='hidden' name='username' value='" << username << "'>" << endl
        << "            <input type='hidden' name='id' value='" << trip_id << "'>" << endl
        << "            <input type='submit' class='acceptBtn' value='" << submit_value << "'>"  << endl << "      </form>";
    return os.str();
}
