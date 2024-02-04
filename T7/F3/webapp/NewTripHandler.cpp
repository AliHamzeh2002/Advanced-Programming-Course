#include "NewTripHandler.hpp"
#include <iostream>

using namespace std;

NewTripHandler::NewTripHandler(TaxiManager* _taxi_manager):Handler(_taxi_manager){}

Response* NewTripHandler::callback(Request* request){
    string username = request->getBodyParam(USERNAME);
    string origin = request->getBodyParam(ORIGIN);
    string destination = request->getBodyParam(DESTINATION);
    string in_hurry = request->getBodyParam(IN_HURRY);
    Command command(POST_STR, TRIPS_COMMAND);
    command.add_parameter(USERNAME, username);
    command.add_parameter(ORIGIN, origin);
    command.add_parameter(DESTINATION, destination);
    command.add_parameter(IN_HURRY, in_hurry);
    string response_msg;
    try{
        response_msg = NEW_TRIP_ID_MSG + taxi_manager->handle_command(command);
    }
    catch(exception& error){
        response_msg = error.what();
    }
    return Response::redirect("/new-trip-form?msg=" + response_msg);
}