#include "Professor.hpp"

using namespace std;

Professor::Professor(string _name) : LibraryMember(_name){
    allowed_borrows_left = PROF_ALLOWED_BORROW_NUMS;
}