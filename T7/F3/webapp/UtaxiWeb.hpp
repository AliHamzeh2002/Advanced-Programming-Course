#ifndef __UTAXI_WEB_HH__

#define __UTAXI_WEB_HH__

#include "../server/server.hpp"
#include "SignupHandler.hpp"
#include "NewTripHandler.hpp"
#include "DeleteTripHandler.hpp"
#include "TripsTableHandler.hpp"
#include "UpdateTripHandler.hpp"
#include "TripCostHandler.hpp"
#include "../backend/TaxiManager.hpp"
#include <string>

class UtaxiWeb{
  public:
    UtaxiWeb(int server_port, std::string data_file_address);
    void run();
  private:
    Server server;
    TaxiManager* taxi_manager;
};

#endif
