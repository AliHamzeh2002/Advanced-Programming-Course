#include "Library.hh"
#include <iostream>

using namespace std;

int main() {
	Library ut_lib;
	ut_lib.add_student_member("0", "std1");

	ut_lib.add_book("book1",3);
	ut_lib.add_book("book1",3);
	cout << ut_lib.get_total_penalty("std1") << '\n';
}