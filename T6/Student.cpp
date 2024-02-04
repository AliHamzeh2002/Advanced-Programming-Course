#include "Student.hpp"
#include <iostream>

using namespace std;

Student::Student(string _name, string _id) : LibraryMember(_name){
    if (_id == EMPTY_STR)
        throw runtime_error(EMPTY_FIELD_ERROR_MSG);
    id = _id;
    allowed_borrows_left = STUDENT_ALLOWED_BORROW_NUMS;
}