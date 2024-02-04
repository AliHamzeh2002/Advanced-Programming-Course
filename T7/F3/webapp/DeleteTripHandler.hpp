#ifndef __DELETE_TRIP_HANDLER_HH__

#define __DELETE_TRIP_HANDLER_HH__

#include "../backend/TaxiManager.hpp"
#include "WebConstants.hpp"
#include "Handler.hpp"
#include <string>
#include <exception>

class DeleteTripHandler : public Handler {
    public:
        DeleteTripHandler(TaxiManager* _taxi_manager);
        Response* callback(Request* req);
};



#endif