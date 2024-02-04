#ifndef __NEW_TRIP_HANDLER_HH__

#define __NEW_TRIP_HANDLER_HH__

#include "../backend/TaxiManager.hpp"
#include "WebConstants.hpp"
#include "Handler.hpp"
#include <string>
#include <exception>

class NewTripHandler : public Handler {
    public:
        NewTripHandler(TaxiManager* _taxi_manager);
        Response* callback(Request* req);
};



#endif