#ifndef __USER_HH__

#define __USER_HH__

#include <string>

class User{
    public:
        User(std::string _username);
        std::string get_username() const;
        bool is_on_trip();
        void set_off_trip();
        void set_on_trip();
    private:
        std::string username;
        bool on_trip;
};

bool operator==(const User* user, const std::string str);

#endif