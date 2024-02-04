#include "CSVReader.hpp"

using namespace std;

CSVReader::CSVReader(string file_address){
    csv_file.open(file_address);
}

Places CSVReader::read_data(){
    Places data_of_places;
    string line;
    getline(csv_file, line);
    while(!csv_file.eof()){
        data_of_places.insert(read_line());
    }
    return data_of_places;
}

pair<string, Location> CSVReader::read_line(){
    string place_name;
    getline(csv_file, place_name, COMMA);
    double place_latitude;
    double place_longitude;
    string str_num;
    getline(csv_file, str_num, COMMA);
    place_latitude = stod(str_num);
    getline(csv_file, str_num);
    place_longitude = stod(str_num);
    Location place_location = {place_latitude, place_longitude};
    return make_pair(place_name, place_location);
}
