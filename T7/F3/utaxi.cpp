#include "webapp/UtaxiWeb.hpp"
#include "webapp/WebConstants.hpp"
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    string data_file_address = argv[1]; 
    UtaxiWeb utaxi_web(PORT, data_file_address);
    utaxi_web.run();
}