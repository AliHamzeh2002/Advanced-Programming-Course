#ifndef MAP_READER_H

#define MAP_READER_H

#include "constants.hpp"
#include "ObjectOnMapData.hpp"
#include <fstream>
#include "src/rsdl.hpp"
#include <vector>


class MapReader{
    public:
        MapReader(std::string map_file_name);
        std::vector<ObjectOnMapData> read_next_level();
        int get_num_levels();
        int get_num_cols();
        int get_num_rows();
    private:
        std::vector<ObjectOnMapData> read_row(int row_index, std::string row, std::vector<ObjectOnMapData> objects);
        std::ifstream map_file;
        int num_of_levels;
        int num_of_cols;
        int num_of_rows;
};

#endif