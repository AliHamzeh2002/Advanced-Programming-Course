#include "Library.hpp"

using namespace std;

void Library::add_student_member(string student_id, string student_name){
    try{
        check_name_exists(student_name);
        members.push_back(new Student(student_name, student_id));
    }
    catch (runtime_error& error){
        cout << error.what();
        exit(EXIT_SUCCESS);
    }
}

void Library::add_prof_member(string prof_name){
    try{
        check_name_exists(prof_name);
        members.push_back(new Professor(prof_name));
    }
    catch (runtime_error& error){
        cout << error.what();
        exit(EXIT_SUCCESS);
    }
}

void Library::check_name_exists(string name){
    if (find_member_by_name(name) != NULL)
        throw runtime_error(NAME_EXISTS_ERROR_MSG);
}

void Library::add_book(string book_title, int copies){
    try{
        check_title_exists(book_title);
        for (int i = 0; i < copies; i++)
            library_docs.push_back(new Book(book_title));
        unique_titles.push_back(book_title);
    }
    catch (runtime_error& error){
        cout << error.what();
        exit(EXIT_SUCCESS);
    }
}

void Library::add_reference(string reference_title, int copies){
    try{
        check_title_exists(reference_title);
        for (int i = 0; i < copies; i++)
            library_docs.push_back(new Reference(reference_title));
        unique_titles.push_back(reference_title);
    }
    catch (runtime_error& error){
        cout << error.what();
        exit(EXIT_SUCCESS);
    }
}

void Library::add_magazine(std::string magazine_title, int year, int number, int copies){
    try{
        check_title_exists(magazine_title);
        for (int i = 0; i < copies; i++){
            library_docs.push_back(new Magazine(magazine_title, year, number));
        }
        unique_titles.push_back(magazine_title);
    }
    catch (runtime_error& error){
        cout << error.what();
        exit(EXIT_SUCCESS);
    }
}

bool is_in_vector(vector<string> vec, string element){
    return (count(vec.begin(), vec.end(), element) > 0); 
}

void Library::check_title_exists(string title){
    if (is_in_vector(unique_titles, title) > 0)
        throw runtime_error(TITLE_EXISTS_ERROR_MSG);
}

void Library::borrow(string member_name, string document_title){
    try{
        LibraryMember* member = find_member_by_name(member_name);
        Document* asked_doc = find_free_doc(document_title);
        member->borrow(asked_doc);
        asked_doc->set_borrowed(current_day);
    }
    catch(runtime_error& error){
        cout << error.what();
        exit(EXIT_SUCCESS);
    }
}

void Library::extend(string member_name, string document_title){
    try{
        LibraryMember* member = find_member_by_name(member_name);
        member->extend(document_title, current_day);
    }
    catch(runtime_error& error){
        cout << error.what();
        exit(EXIT_SUCCESS);
    }
}

void Library::return_document(string member_name, string document_title){
    try{
        LibraryMember* member = find_member_by_name(member_name);
        member->return_doc(document_title);
    }
    catch(runtime_error& error){
        cout << error.what();
        exit(EXIT_SUCCESS);
    }
}

int Library::get_total_penalty(string member_name){
    LibraryMember* member = find_member_by_name(member_name);
    return member->get_total_penalty();
}

vector<string> Library::available_titles(){
    vector<string> output;
    for (auto doc : library_docs){
        if (doc->is_free() && !is_in_vector(output, doc->get_title()))
            output.push_back(doc->get_title());
    }
    return output;
}

void Library::time_pass(int days){
    if (days < 0){
        cout << INVALID_DAYS_ERROR_MSG;
        exit(EXIT_SUCCESS);
    }
    for (int i = 0; i < days; i++){
        current_day++;
        update_members();
    }
}

void Library::update_members(){
    for (auto member : members)
        member->update(current_day);
}

Document* Library::find_free_doc(string title){
    for (auto doc : library_docs){
        if (doc->is_free() && doc->get_title() == title)
            return doc;
    }
    throw runtime_error(DOCUMENT_NOT_AVAILABLE_ERROR_MSG);
}

LibraryMember* Library::find_member_by_name(string name){
    for (auto member : members)
        if (member->get_name() == name)
            return member;
    return NULL;
}