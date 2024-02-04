#ifndef __DOCUMENT_HH__

#define __DOCUMENT_HH__

#include "constants.hpp"
#include <string>
#include <stdexcept>

class Document{
    public:
        Document(std::string _title);
        virtual void update_holder_penalty(int current_day) = 0;
        bool is_free();
        int get_holder_penalty();
        std::string get_title();
        void set_borrowed(int day);
        virtual void extend(int current_day);
        void return_to_library();
    protected:
        bool is_borrow_day(int current_day);
        std::string title;
        bool is_borrowed;
        int return_date;
        int num_of_extensions;
        int max_allowed_extentions;
        int max_borrow_time;
        int holder_penalty;
};

#endif