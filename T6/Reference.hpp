#ifndef __REFERENCE_HH__

#define __REFERENCE_HH__

#include "constants.hpp"
#include "Document.hpp"
#include <string>

class Reference : public Document{
    public:
        Reference(std::string _title);
        virtual void update_holder_penalty(int current_day);
};

#endif