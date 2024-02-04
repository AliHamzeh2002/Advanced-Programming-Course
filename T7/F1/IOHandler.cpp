#include "IOHandler.hpp"

using namespace std;

void IOHandler::run(string data_file_address){
    TaxiManager taxi_manager(data_file_address);
    string command_str;
    while (getline(cin, command_str)){
        Command command(command_str);
        try{
            string response = taxi_manager.handle_command(command);
            cout << response << endl;
        }
        catch(exception& error){
            cout << error.what() << endl;
        }
    } 
}





