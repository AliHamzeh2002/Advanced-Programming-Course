#ifndef __BOOK_HH__

#define __BOOK_HH_

#include "constants.hpp"
#include "Document.hpp"
#include <string>

class Book : public Document{
    public:
        Book(std::string _title);
        virtual void update_holder_penalty(int current_day);
};

#endif