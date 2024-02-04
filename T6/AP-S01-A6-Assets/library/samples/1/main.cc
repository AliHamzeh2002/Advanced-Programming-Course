#include <Library.hh>
#include <iostream>
#include <set>

using namespace std;

int main() {
	Library ut_lib;
	ut_lib.time_pass(10);
	ut_lib.add_student_member("0", "std1");

	ut_lib.add_book("book1", 3);
	ut_lib.add_book("book2", 3);

	ut_lib.borrow("std1","book1");
	ut_lib.time_pass(5);

	cout << ut_lib.get_total_penalty("std1") << '\n';
	ut_lib.extend("std1", "book1");
	ut_lib.borrow("std1", "book2");
	ut_lib.time_pass(20);

	cout << ut_lib.get_total_penalty("std1") << '\n';
	ut_lib.return_document("std1", "book1");
	ut_lib.return_document("std1", "book2");
  	return 0;
}