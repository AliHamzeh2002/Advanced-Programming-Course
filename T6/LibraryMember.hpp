#ifndef __LIBRARY_MEMBER_HH__

#define __LIBRARY_MEMBER_HH__

#include "constants.hpp"
#include "Document.hpp"
#include <string>
#include <vector>
#include <stdexcept>

class LibraryMember{
    public:
        LibraryMember(std::string _name);
        int get_total_penalty();
        std::string get_name();
        void borrow(Document* doc);
        void return_doc(std::string doc_title);
        void extend(std::string doc_title, int current_day);
        void update(int current_day);
    protected:
        int find_borrowed_doc_index(std::string doc_title);
        std::string name;
        std::vector<Document*> borrowed_docs;
        int submitted_penalty;
        int allowed_borrows_left;
};

#endif