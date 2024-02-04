#include "SignupHandler.hpp"

using namespace std;

SignupHandler::SignupHandler(TaxiManager* _taxi_manager):Handler(_taxi_manager){
}

Response* SignupHandler::callback(Request* request){
    string username = request->getBodyParam(USERNAME);
    string role = request->getBodyParam(ROLE);
    Command command(POST_STR, SIGNUP_COMMAND);
    command.add_parameter(USERNAME, username);
    command.add_parameter(ROLE, role);
    string response_msg;
    try{
        response_msg = taxi_manager->handle_command(command);
    }
    catch(exception& error){
        response_msg = error.what();
    }
    return Response::redirect("/signup?msg=" + response_msg);
}

