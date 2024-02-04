#include "UpdateTripHandler.hpp"

using namespace std;

UpdateTripHandler::UpdateTripHandler(TaxiManager* _taxi_manager, string _update_type):Handler(_taxi_manager){
    update_type = _update_type;
}

Response* UpdateTripHandler::callback(Request* request){
    string username = request->getBodyParam(USERNAME);
    string id = request->getBodyParam(ID);
    Command command(POST_STR, update_type);
    command.add_parameter(USERNAME, username);
    command.add_parameter(ID, id);
    string response_msg;
    try{
        response_msg = taxi_manager->handle_command(command);
    }
    catch(exception& error){
        response_msg = error.what();
    }
    return Response::redirect("/driver-authentication-form?msg=" + response_msg);
}

