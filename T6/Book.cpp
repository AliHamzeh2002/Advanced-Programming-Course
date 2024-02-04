#include "Book.hpp"

using namespace std;

Book::Book(string _title) : Document(_title){
    max_allowed_extentions = BOOK_MAX_ALLOWED_EXTENSIONS;
    max_borrow_time = BOOK_MAX_BORROW_TIME;
}

void Book::update_holder_penalty(int current_day){
    if (current_day <= return_date)
        return;
    int delay = current_day - return_date;
    if (delay <= 7){
        holder_penalty += BOOK_SMALL_DELAY_PENALTY;
        return;
    }
    if (delay <= 21){
        holder_penalty += BOOK_MEDIUM_DELAY_PENALTY;
        return;
    }
    holder_penalty += BOOK_BIG_DELAY_PENALTY;
}