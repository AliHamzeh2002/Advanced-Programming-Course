#include "IOHandler.hpp"
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    string data_file_address = argv[1]; 
    IOHandler io_hander;
    io_hander.run(data_file_address);
}