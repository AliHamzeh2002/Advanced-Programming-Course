#ifndef __HANDLER_HH__

#define __HANDLER_HH__

#include "../server/server.hpp"
#include "../backend/TaxiManager.hpp"
#include <string>
#include <exception>

class Handler : public RequestHandler {
    public:
        Handler(TaxiManager* _taxi_manager);
        virtual Response* callback(Request* req) = 0;
    protected:
        TaxiManager* taxi_manager;
};

#endif