#ifndef __CONSTANTS_HH__

#define __CONSTANTS_HH__

#include <string>
#include <vector>

const int COMMAND_TYPE_ORDER = 0;
const int COMMAND_NAME_ORDER = 1;
const int INITIAL_AVAILABLE_ID = 1;
const int NOT_FOUND = -1;
const int PRICE_COEFFICIENT = 10000;
const int PRECISION = 2;
const double DIST_COEFFICIENT = 110.5;
const char SPACE = ' ';
const char COMMA = ',';
const std::string BAD_REQUEST_ERR_MSG = "Bad Request";
const std::string NOT_FOUND_ERR_MSG = "Not Found";
const std::string PERMISSION_DENIED_ERR_MSG = "Permission Denied";
const std::string COMMAND_DELIMITER = "?";
const std::string WAITING_STATUS = "waiting";
const std::string TRAVELING_STATUS = "traveling";
const std::string FINISHED_STATUS = "finished";
const std::string POST = "POST";
const std::string GET = "GET";
const std::string DELETE = "DELETE";
const std::string SIGNUP_COMMAND = "signup";
const std::string USERNAME = "username";
const std::string ROLE = "role";
const std::string DRIVER = "driver";
const std::string PASSENGER = "passenger";
const std::string ORIGIN = "origin";
const std::string DESTINATION = "destination";
const std::string OK_MSG = "OK";
const std::string TRIPS_COMMAND = "trips";
const std::string ID = "id";
const std::string ACCEPT_COMMAND = "accept";
const std::string FINISH_COMMAND = "finish";
const std::string EMPTY = "EMPTY";
const std::string COST_COMMAND = "cost";
const std::string IN_HURRY = "in_hurry";
const std::string YES = "yes";
const std::string SORT_BY_COST = "sort_by_cost";


#endif