#ifndef __SIGNUP_HANDLER_HH__

#define __SIGNUP_HANDLER_HH__

#include "../backend/TaxiManager.hpp"
#include "Handler.hpp"
#include <string>
#include <exception>
#include <fstream>

class SignupHandler : public Handler {
    public:
        SignupHandler(TaxiManager* _taxi_manager);
        Response* callback(Request* req);
};



#endif