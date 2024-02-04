#ifndef _TRIP_HH__

#define _TRIP_HH__

#include "constants.hpp"
#include "Errors.hpp"
#include "Location.hpp"
#include "Passenger.hpp"
#include "Driver.hpp"
#include <string>
#include <sstream>

class Trip{
    public:
        Trip(int _id, Passenger* _passenger, Place _origin, Place _destination);
        void start_trip(Driver* _driver);
        void end_trip(Driver* driver_asker);
        void cancel_trip(Passenger* passenger_asker);
        bool matches_id(int _id) const;
        std::string to_string();
    private:
        int id;
        std::string status;
        Place origin;
        Place destination;
        Passenger* passenger;
        Driver* driver;
        
};

bool operator==(const Trip* trip, const std::string id);


#endif