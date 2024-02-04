#ifndef __COMMAND_HH__

#define __COMMAND_HH__

#include "constants.hpp"
#include "Errors.hpp"
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#define CommandParameters std::map<std::string, std::string> 
#define SplittedStrCommand std::vector<std::string> 


class Command{
    public:
        Command(std::string command_str);
        Command(std::string command_type, std::string command_name);
        std::string get_type();
        std::string get_name();
        std::string get_parameter(std::string param_name);
        void add_parameter(std::string param_name, std::string value);
    private:
        SplittedStrCommand make_splitted_command(std::string command_str);
        CommandParameters assign_command_parameters(SplittedStrCommand command);
        std::string type;
        std::string name;
        CommandParameters parameters;


};

#endif