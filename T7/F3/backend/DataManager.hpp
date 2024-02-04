#ifndef __DATA_MANAGER_HH__

#define __DATA_MANAGER_HH__

#include "Trip.hpp"
#include "Passenger.hpp"
#include "Driver.hpp"
#include "Location.hpp"
#include "CSVReader.hpp"
#include "Errors.hpp"
#include <string>
#include <algorithm>
#include <vector>
#include <map>

class DataManager{    
    public:
        DataManager(std::string data_file_address);
        Trip* find_trip_by_id(std::string id);
        Driver* find_driver_by_username(std::string username);
        Passenger* find_passenger_by_username(std::string username);
        bool username_exists(std::string username);
        Location find_location(std::string place_name);
        std::vector<Trip*> get_trips();
        void remove_trip_from_data(Trip* trip);
        void add_new_driver(Driver* driver);
        void add_new_passenger(Passenger* Passenger);
        void add_new_trip(Trip* trip);
    private:
        int find_passenger_index(std::string username);
        int find_driver_index(std::string driver);
        Places places_data;
        int available_id;
        std::vector<Passenger*> passengers;
        std::vector<Driver*> drivers;
        std::vector<Trip*> trips;

};

#endif