#include "Trip.hpp"

using namespace std;

Trip::Trip(int _id, Passenger* _passenger, Place _origin, Place _destination){
    id = _id;
    origin = _origin;
    destination = _destination;
    passenger = _passenger;
    if (passenger->is_on_trip())
        throw BadRequestError();
    status = WAITING_STATUS;
    passenger->set_on_trip();
}

void Trip::start_trip(Driver* _driver){
    if (_driver->is_on_trip() || status != WAITING_STATUS)
        throw BadRequestError();
    driver = _driver;
    driver->set_on_trip();
    status = TRAVELING_STATUS;
}

void Trip::end_trip(Driver* driver_asker){
    if (status != TRAVELING_STATUS)
        throw BadRequestError();
    if (driver->get_username() != driver_asker->get_username() )
        throw PermissionDeniedError();
    driver->set_off_trip();
    passenger->set_off_trip();
    status = FINISHED_STATUS;
}

void Trip::cancel_trip(Passenger* passenger_asker){
    if (status != WAITING_STATUS)
        throw BadRequestError();
    if (passenger_asker->get_username() != passenger->get_username())
        throw PermissionDeniedError();
    passenger->set_off_trip();
    delete this;
}

bool Trip::matches_id(int _id)const{
    return id == _id;
}

string Trip::to_string(){
    ostringstream os;
    os << id << SPACE << passenger->get_username() << SPACE << origin.name << SPACE << destination.name << SPACE << status;
    return os.str();
}

bool operator==(const Trip* trip, const std::string id){
    return trip->matches_id(stoi(id));
}