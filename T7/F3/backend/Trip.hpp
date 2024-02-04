#ifndef _TRIP_HH__

#define _TRIP_HH__

#include "constants.hpp"
#include "Errors.hpp"
#include "Location.hpp"
#include "Passenger.hpp"
#include "Driver.hpp"
#include <string>
#include <sstream>
#include <cmath>

class Trip{
    public:
        Trip(int _id, Passenger* _passenger, Place _origin, Place _destination, double _cost);
        void start_trip(Driver* _driver);
        void end_trip(Driver* driver_asker);
        void cancel_trip(Passenger* passenger_asker);
        void sudo_cancel_trip();
        double get_cost();
        bool matches_id(int _id) const;
        std::string to_string();
    private:
        int id;
        double cost;
        std::string status;
        Place origin;
        Place destination;
        Passenger* passenger;
        Driver* driver;
        
};

bool operator==(const Trip* trip, const std::string id);


#endif