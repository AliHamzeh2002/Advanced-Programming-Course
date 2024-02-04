#ifndef __LIBRARY_HH__
#define __LIBRARY_HH__

#include "LibraryMember.hpp"
#include "Student.hpp"
#include "Professor.hpp"
#include "Document.hpp"
#include "Magazine.hpp"
#include "Reference.hpp"
#include "Book.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Library {
public:
	void add_student_member(std::string student_id, std::string student_name);
	void add_prof_member(std::string prof_name);
	void add_book(std::string book_title, int copies);
	void add_magazine(std::string magazine_title, int year, int number, int copies);
	void add_reference(std::string reference_title, int copies);
	void borrow(std::string member_name, std::string document_title);
	void extend(std::string member_name, std::string document_title);
	void return_document(std::string member_name, std::string document_title);
	int get_total_penalty(std::string member_name);
	std::vector<std::string> available_titles();
	void time_pass(int days);
private:
	void check_name_exists(std::string name);
	void check_title_exists(std::string title);
	void update_members();
	int current_day;
	LibraryMember* find_member_by_name(std::string name);
	Document* find_free_doc(std::string title);
	std::vector<LibraryMember*> members;
	std::vector<Document*> library_docs;
	std::vector<std::string> unique_titles;
};

#endif