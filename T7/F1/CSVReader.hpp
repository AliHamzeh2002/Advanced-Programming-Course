#ifndef __CSV_READER_HH__

#define __CSV_READER_HH__

#include <string>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include "Location.hpp"
#include "constants.hpp"

class CSVReader{
    public:
        CSVReader(std::string file_address);
        Places read_data();
    private:
        std::pair<std::string, Location> read_line();
        std::ifstream csv_file;



};

#endif