#ifndef __MAGAZINE_HH__

#define __MAGAZINE_HH__

#include "constants.hpp"
#include "Document.hpp"
#include <string>

class Magazine : public Document{
    public:
        Magazine(std::string _title, int year, int number);
        virtual void update_holder_penalty(int current_day);
        virtual void extend(int current_day);
    private:
        int year;
        int number;
};

#endif