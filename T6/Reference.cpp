#include "Reference.hpp"

using namespace std;

Reference::Reference(string _title) : Document(_title){
    max_allowed_extentions = REFERENCE_MAX_ALLOWED_EXTENSIONS;
    max_borrow_time = REFERENCE_MAX_BORROW_TIME;
}

void Reference::update_holder_penalty(int current_day){
    if (current_day <= return_date)
        return;
    if ((current_day - return_date) <= 3){
        holder_penalty += REFERENCE_SMALL_DELAY_PENALTY;
        return;
    }
    holder_penalty += REFERENCE_BIG_DELAY_PENALTY;
}