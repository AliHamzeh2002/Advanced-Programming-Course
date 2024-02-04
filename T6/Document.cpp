#include "Document.hpp"

using namespace std;

Document::Document(string _title){
    if (_title == EMPTY_STR)
        throw runtime_error(EMPTY_FIELD_ERROR_MSG);
    title = _title;
    is_borrowed = false;
}

int Document::get_holder_penalty(){
    return holder_penalty;
}

bool Document::is_free(){
    return !is_borrowed;
}

string Document::get_title(){
    return title;
}

void Document::set_borrowed(int current_day){
    is_borrowed = true;
    return_date = current_day + max_borrow_time;
    num_of_extensions = 0;
    holder_penalty = 0;
}

bool Document::is_borrow_day(int current_day){
    return (return_date - current_day == max_borrow_time);
}

void Document::extend(int current_day){
    if (num_of_extensions > max_allowed_extentions)
        throw runtime_error(NO_ALLOWED_EXTENSIONS_LEFT_ERROR_MSG);
    if (is_borrow_day(current_day))
        throw runtime_error(BORROW_AND_EXTEND_AT_SAME_DAY_ERROR_MSG);
    if (current_day > return_date)
        throw runtime_error(CANT_EXTEND_AFTER_RETURN_DATE);
    return_date += max_borrow_time;
    num_of_extensions++;
}

void Document::return_to_library(){
    is_borrowed = false;
}
