#include "Command.hpp"

using namespace std;

Command::Command(string command_str){
    SplittedStrCommand splitted_command = make_splitted_command(command_str);
    type = splitted_command[COMMAND_TYPE_ORDER];
    name = splitted_command[COMMAND_NAME_ORDER];
    parameters = assign_command_parameters(splitted_command);
}

string Command::get_type(){
    return type;
}

string Command::get_name(){
    return name;
}

string Command::get_parameter(string param_name){
    if (parameters.find(param_name) != parameters.end())
        return parameters[param_name];
    throw BadRequestError();
}

SplittedStrCommand Command::make_splitted_command(string command_str){
    SplittedStrCommand splitted_command;
    int start = 0;
    for (int i = 0; i < command_str.size(); i++){
        char c = command_str[i];
        if (c == SPACE){
            splitted_command.push_back(command_str.substr(start, i - start));
            start = i + 1;
        }
    }
    splitted_command.push_back(command_str.substr(start, command_str.size() - start));
    return splitted_command;
}

CommandParameters Command::assign_command_parameters(SplittedStrCommand splitted_command){
    CommandParameters command_parameters;
    int pars_start_index = find(splitted_command.begin(), splitted_command.end(), COMMAND_DELIMITER) - splitted_command.begin() + 1;
    for (int i = pars_start_index; i < splitted_command.size(); i+=2){
        string parameter_type = splitted_command[i];
        string parameter_value = splitted_command[i+1];
        command_parameters.insert(make_pair(parameter_type, parameter_value));
    }
    return command_parameters;
}