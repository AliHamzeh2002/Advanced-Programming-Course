#include "LibraryMember.hpp"

using namespace std;

LibraryMember::LibraryMember(string _name){
    if (_name == EMPTY_STR)
        throw runtime_error(EMPTY_FIELD_ERROR_MSG);
    name = _name;
}

string LibraryMember::get_name(){
    return name;
}

int LibraryMember::get_total_penalty(){
    int total_penalty = submitted_penalty;
    for (auto doc : borrowed_docs)
        total_penalty += doc->get_holder_penalty();
    return total_penalty; 
}

int LibraryMember::find_borrowed_doc_index(string doc_title){
    for (int i = 0; i < borrowed_docs.size(); i++){
        Document* doc = borrowed_docs[i];
        if (doc->get_title() == doc_title)
            return i;
    }
    return NOT_FOUND_INDEX;
}

void LibraryMember::borrow(Document* doc){
    if (allowed_borrows_left < 1)
        throw runtime_error(NO_ALLOWED_BORROWS_LEFT_ERROR_MSG);
    if (find_borrowed_doc_index(doc->get_title()) != NOT_FOUND_INDEX)
        throw runtime_error(ALREADY_BORROWED_ERROR_MSG);
    borrowed_docs.push_back(doc);
    allowed_borrows_left--;
}


void LibraryMember::extend(string doc_title, int current_day){
    int doc_index = find_borrowed_doc_index(doc_title);
    if (doc_index == NOT_FOUND_INDEX)
        throw runtime_error(DOC_NOT_BORROWED_ERROR_MSG);
    borrowed_docs[doc_index]->extend(current_day);
}

void LibraryMember::return_doc(string doc_title){
    int doc_index = find_borrowed_doc_index(doc_title);
    if (doc_index == NOT_FOUND_INDEX)
        throw runtime_error(DOC_NOT_BORROWED_ERROR_MSG);
    submitted_penalty += borrowed_docs[doc_index]->get_holder_penalty();
    borrowed_docs[doc_index]->return_to_library();
    borrowed_docs.erase(borrowed_docs.begin() + doc_index);
    allowed_borrows_left++;
}

void LibraryMember::update(int current_day){
    for (auto doc : borrowed_docs)
        doc->update_holder_penalty(current_day);
}