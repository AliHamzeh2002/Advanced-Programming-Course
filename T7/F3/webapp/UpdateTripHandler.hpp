#ifndef __UPDATE_TRIP_HANDLER_HH__

#define __UPDATE_TRIP_HANDLER_HH__

#include "../backend/TaxiManager.hpp"
#include "Handler.hpp"
#include <string>
#include <exception>
#include <fstream>

class UpdateTripHandler : public Handler {
    public:
        UpdateTripHandler(TaxiManager* _taxi_manager, std::string _update_type);
        Response* callback(Request* req);
    private:
        std::string update_type;
};



#endif