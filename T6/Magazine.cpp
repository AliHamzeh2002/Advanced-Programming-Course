#include "Magazine.hpp"

using namespace std;

Magazine::Magazine(string _title, int _year, int _number) : Document(_title) {
    if (_year <= 0)
        throw runtime_error(INVALID_YEAR_ERROR_MSG);
    if (_number <= 0)
        throw runtime_error(INVALID_NUMBER_ERROR_MSG);
    year = _year;
    number = _number;
    max_allowed_extentions = MAGAZINE_MAX_ALLOWED_EXTENSIONS;
    max_borrow_time = MAGAZINE_MAX_BORROW_TIME;
}

void Magazine::update_holder_penalty(int current_day){
    if (current_day <= return_date)
        return;
    if (year < OLD_MAGAZINE_YEAR){
        holder_penalty += OLD_MAGAZINE_PENALTY;
        return;
    }
    holder_penalty += NORMAL_MAGAZINE_PENALTY;
}

void Magazine::extend(int current_day){
    throw runtime_error(MAGAINE_CANT_EXTEND_ERROR_MSG);
}