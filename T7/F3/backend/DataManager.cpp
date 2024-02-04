#include "DataManager.hpp"

using namespace std;

DataManager::DataManager(string data_file_address){
    CSVReader csv_reader(data_file_address);
    places_data = csv_reader.read_data();
}


bool DataManager::username_exists(string username){
    return (find_driver_index(username) != NOT_FOUND || find_passenger_index(username) != NOT_FOUND);
}

int DataManager::find_driver_index(string username){
    int index = find(drivers.begin(), drivers.end(), username) - drivers.begin();
    if (index < drivers.size())
        return index;
    return NOT_FOUND;
}

int DataManager::find_passenger_index(string username){
    int index = find(passengers.begin(), passengers.end(), username) - passengers.begin();
    if (index < passengers.size())
        return index;
    return NOT_FOUND;
}

Trip* DataManager::find_trip_by_id(std::string id){
    int index = find(trips.begin(), trips.end(), id) - trips.begin();
    if (index >= trips.size())
        throw NotFoundError();
    return trips[index];
}

Location DataManager::find_location(string place_name){
    if (places_data.find(place_name) != places_data.end())
        return places_data[place_name];
    throw NotFoundError();
}

Driver* DataManager::find_driver_by_username(string username){
    int driver_index = find_driver_index(username);
    if (find_passenger_index(username) != NOT_FOUND)
        throw PermissionDeniedError();
    else if (driver_index == NOT_FOUND)
        throw NotFoundError();
    return drivers[driver_index];
}

vector<Trip*> DataManager::get_trips(){
    return trips;
}

void DataManager::remove_trip_from_data(Trip* trip){
    trips.erase(find(trips.begin(), trips.end(), trip));
}

Passenger* DataManager::find_passenger_by_username(string username){
    int passenger_index = find_passenger_index(username);
    if (find_driver_index(username) != NOT_FOUND)
        throw PermissionDeniedError();
    else if (passenger_index == NOT_FOUND)
        throw NotFoundError();
    Passenger* passenger = passengers[passenger_index];
    return passenger;
}

void DataManager::add_new_driver(Driver* driver){
    drivers.push_back(driver);
}

void DataManager::add_new_passenger(Passenger* passenger){
    passengers.push_back(passenger);
}

void DataManager::add_new_trip(Trip* trip){
    trips.push_back(trip);
}
