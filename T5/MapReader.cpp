#include "MapReader.hpp"

using namespace std;

MapReader::MapReader(string map_file_name){
    map_file.open(map_file_name);
    map_file >> num_of_rows;
    map_file >> num_of_cols;
    map_file >> num_of_levels;
}

vector<ObjectOnMapData> MapReader::read_next_level(){
    vector<ObjectOnMapData> objects;
    string junk_line;
    map_file >> junk_line;
    for (int row_index = 0; row_index < num_of_rows; row_index++){
        string row;
        map_file >> row;
        objects = read_row(row_index, row, objects);
    }
    return objects;
}

vector<ObjectOnMapData> MapReader::read_row(int row_index, string row, vector<ObjectOnMapData> objects){
    int col = 0;
    for (auto element : row){
        if (element != DOT){
            ObjectOnMapData new_object = {element, row_index, col};
            objects.push_back(new_object);
        }
        col++;
    }
    return objects;
}

int MapReader::get_num_levels(){
    return num_of_levels;
}

int MapReader::get_num_cols(){
    return num_of_cols;
}

int MapReader::get_num_rows(){
    return num_of_rows;
}