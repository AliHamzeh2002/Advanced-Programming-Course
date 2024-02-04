#include "User.hpp"

using namespace std;

User::User(string _username){
    username = _username;
    on_trip = false;
}

string User::get_username() const{
    return username;
}

bool User::is_on_trip(){
    return on_trip;
}

void User::set_on_trip(){
    on_trip = true;
}

void User::set_off_trip(){
    on_trip = false;
}

bool operator==(const User* user, const std::string str){
    return user->get_username() == str;
}
