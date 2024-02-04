#ifndef __DRIVER_HH__

#define __DRIVER_HH__

#include "User.hpp"
#include <string>

class Driver : public User{
    public:
        Driver(std::string username);
    private:
};

#endif