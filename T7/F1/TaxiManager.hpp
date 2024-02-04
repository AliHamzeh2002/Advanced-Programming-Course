#ifndef __TAXI_MANAGER_HH__

#define __TAXI_MANAGER_HH__

#include "Passenger.hpp"
#include "Driver.hpp"
#include "Trip.hpp"
#include "Location.hpp"
#include "CSVReader.hpp"
#include "Command.hpp"
#include "Errors.hpp"
#include "DataManager.hpp"
#include <vector>
#include <map>
#include <string>
#include <sstream>

class TaxiManager{
    public:
        TaxiManager(std::string data_file_address);
        std::string handle_command(Command command);
    private:
        std::string handle_post_command(Command command);
        std::string handle_get_command(Command command);
        std::string handle_delete_command(Command command);
        std::string handle_signup(Command command);
        std::string handle_post_trip(Command command);
        std::string handle_accept(Command command);
        std::string handle_finish(Command command);
        std::string handle_delete_trips(Command command);
        std::string handle_get_trips(Command command);
        std::string get_trip(std::string id);
        std::string get_all_trips();
        DataManager data_manager;
        int available_id;
          
};

#endif