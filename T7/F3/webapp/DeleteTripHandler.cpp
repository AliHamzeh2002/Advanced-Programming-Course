#include "DeleteTripHandler.hpp"

using namespace std;

DeleteTripHandler::DeleteTripHandler(TaxiManager* _taxi_manager):Handler(_taxi_manager){}

Response* DeleteTripHandler::callback(Request* request){
    string username = request->getBodyParam(USERNAME);
    string id = request->getBodyParam(ID);
    Command command(DELETE, TRIPS_COMMAND);
    command.add_parameter(USERNAME, username);
    command.add_parameter(ID, id);
    string response_msg;
    try{
        response_msg = taxi_manager->handle_command(command);
    }
    catch(exception& error){
        response_msg = error.what();
    }
    return Response::redirect("/delete-trip-form?msg=" + response_msg);
}