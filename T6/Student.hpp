#ifndef __STUDENT_HH__

#define __STUDENT_HH__

#include "constants.hpp"
#include "LibraryMember.hpp"
#include <string>

class Student : public LibraryMember{
    public:
        Student(std::string _name, std::string _id);
    private:
        std::string id;
};

#endif