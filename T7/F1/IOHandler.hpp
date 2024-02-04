#ifndef __IO_HANDLER_HH__

#define __IO_HANDLER_HH__

#include <iostream>
#include <string>
#include <exception>
#include "Command.hpp"
#include "constants.hpp"
#include "TaxiManager.hpp"



class IOHandler{
    public:
        void run(std::string data_file_address);
    private:

};

#endif