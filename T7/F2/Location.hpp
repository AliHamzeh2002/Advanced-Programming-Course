#ifndef __LOCATION_HH__

#define __LOCATION_HH__

#include <map>
#include <utility>


#define Places std::map<std::string, Location>

struct Location{
    double latitude;
    double longitude; 
    int traffic_coefficient;
};

struct Place{
    std::string name;
    Location location;
};

#endif