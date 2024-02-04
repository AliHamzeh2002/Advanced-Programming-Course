#include "TaxiManager.hpp"
#include <iostream>

using namespace std;

TaxiManager::TaxiManager(string data_file_address) : data_manager(data_file_address){
    available_id = INITIAL_AVAILABLE_ID;
}

string TaxiManager::handle_command(Command command){
    string type = command.get_type();
    if (type == POST)
        return handle_post_command(command);
    else if(type == DELETE)
        return handle_delete_command(command);
    else if(type == GET)
        return handle_get_command(command);
    throw BadRequestError();
}

string TaxiManager::handle_post_command(Command command){
    string command_name = command.get_name();
    if (command_name == SIGNUP_COMMAND)
        return handle_signup(command);
    else if (command_name == TRIPS_COMMAND)
        return handle_post_trip(command);
    else if(command_name == ACCEPT_COMMAND)
        return handle_accept(command);
    else if(command_name == FINISH_COMMAND)
        return handle_finish(command);
    throw NotFoundError();
}

string TaxiManager::handle_delete_command(Command command){
    string command_name = command.get_name();
    if (command_name == TRIPS_COMMAND)
        return handle_delete_trips(command);
    throw NotFoundError();
}

string TaxiManager::handle_get_trips(Command command){
    string username = command.get_parameter(USERNAME);
    Driver* driver = data_manager.find_driver_by_username(username);
    try{
        string id = command.get_parameter(ID);
        return get_trip(id);
    }
    catch(BadRequestError& e){
        return get_all_trips();
    }
    catch(...){
        throw;
    }
}

string TaxiManager::get_trip(string id){
    Trip* trip = data_manager.find_trip_by_id(id);
    return trip->to_string();
}

string TaxiManager::get_all_trips(){
    ostringstream os;
    vector<Trip*> trips = data_manager.get_trips();
    for (int i = 0; i < trips.size(); i++){
        Trip* trip = trips[i];
        os << trip->to_string();
        if (i != trips.size() - 1)
            os << endl;
    }
    if (trips.size() == 0)
        os << EMPTY;
    return os.str();
}

string TaxiManager::handle_get_command(Command command){
    string command_name = command.get_name();
    if (command_name == TRIPS_COMMAND)
        return handle_get_trips(command);
    throw NotFoundError();}

string TaxiManager::handle_delete_trips(Command command){
    string username = command.get_parameter(USERNAME);
    Passenger* passenger = data_manager.find_passenger_by_username(username);
    string trip_id = command.get_parameter(ID);
    Trip* trip = data_manager.find_trip_by_id(trip_id);
    trip->cancel_trip(passenger);
    data_manager.remove_trip_from_data(trip);
    return OK_MSG;
}

string TaxiManager::handle_signup(Command command){
    string username = command.get_parameter(USERNAME);
    if (data_manager.username_exists(username))
        throw BadRequestError();
    string role = command.get_parameter(ROLE);
    if (role == DRIVER)
        data_manager.add_new_driver(new Driver(username));
    else if(role == PASSENGER)
        data_manager.add_new_passenger(new Passenger(username));
    else
        throw BadRequestError();
    return OK_MSG;
}

string TaxiManager::handle_post_trip(Command command){
    string username = command.get_parameter(USERNAME);
    Passenger* passenger = data_manager.find_passenger_by_username(username);
    string dest_str = command.get_parameter(DESTINATION);
    string origin_str = command.get_parameter(ORIGIN);
    Location dest = data_manager.find_location(dest_str);
    Location origin = data_manager.find_location(origin_str);
    data_manager.add_new_trip(new Trip(available_id, passenger, {origin_str,origin} , {dest_str, dest} ));
    return to_string(available_id++);
}


string TaxiManager::handle_accept(Command command){
    string username = command.get_parameter(USERNAME);
    Driver* driver = data_manager.find_driver_by_username(username);
    string trip_id = command.get_parameter(ID);
    data_manager.find_trip_by_id(trip_id)->start_trip(driver);
    return OK_MSG;
}

string TaxiManager::handle_finish(Command command){
    string username = command.get_parameter(USERNAME);
    Driver* driver = data_manager.find_driver_by_username(username);
    string trip_id = command.get_parameter(ID);
    data_manager.find_trip_by_id(trip_id)->end_trip(driver);
    return OK_MSG;    
}

