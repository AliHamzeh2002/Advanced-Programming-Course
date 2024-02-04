#ifndef __PROFESSOR_HH__

#define __PROFESSOR_HH__

#include "LibraryMember.hpp"
#include <string>

class Professor : public LibraryMember{
    public:
        Professor(std::string _name);
};

#endif