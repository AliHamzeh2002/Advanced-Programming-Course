#include "Handler.hpp"

using namespace std;

Handler::Handler(TaxiManager* _taxi_manager):RequestHandler(){
    taxi_manager = _taxi_manager;
}
