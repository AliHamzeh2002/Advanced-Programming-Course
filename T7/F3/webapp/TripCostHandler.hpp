#ifndef __TRIP_COST_HANDLER_HH__

#define __TRIP_COST_HANDLER_HH__

#include "../backend/TaxiManager.hpp"
#include "WebConstants.hpp"
#include "Handler.hpp"
#include <string>
#include <exception>

class TripCostHandler : public Handler {
    public:
        TripCostHandler(TaxiManager* _taxi_manager);
        Response* callback(Request* req);
};


#endif