#ifndef __TRIPS_TABLE_HANDLER_HH__

#define __TRIPS_TABLE_HANDLER_HH__

#include "../server/server.hpp"
#include "../backend/TaxiManager.hpp"
#include "../utils/utilities.hpp"
#include "WebConstants.hpp"
#include "Handler.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class TripsTableHandler : public Handler {
    public:
        TripsTableHandler(TaxiManager* _taxi_manager);
        Response* callback(Request* req);
    private:
        std::string add_row(std::string trip_str, std::string username);
        std::string add_table_body(std::vector<std::string> trips_data, std::string username);
        std::string add_accept_finish_form(std::vector<std::string> trip_elements, std::string username);
};

#endif