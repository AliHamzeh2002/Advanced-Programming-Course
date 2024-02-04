#ifndef __PASSENGER_HH__

#define __PASSENGER_HH__

#include "User.hpp"
#include <string>

class Passenger : public User{
    public:
        Passenger(std::string username);
};

#endif