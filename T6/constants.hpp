#ifndef __CONSTANTS_HH__

#define __CONSTANTS_HH__

#include <string>

const int MAGAZINE_MAX_ALLOWED_EXTENSIONS = 0;
const int MAGAZINE_MAX_BORROW_TIME = 2;
const int OLD_MAGAZINE_YEAR = 1390;
const int OLD_MAGAZINE_PENALTY = 2000;
const int NORMAL_MAGAZINE_PENALTY = 3000;
const int REFERENCE_MAX_ALLOWED_EXTENSIONS = 5;
const int REFERENCE_SMALL_DELAY_PENALTY = 5000;
const int REFERENCE_BIG_DELAY_PENALTY = 7000;
const int REFERENCE_MAX_BORROW_TIME = 5;
const int BOOK_MAX_ALLOWED_EXTENSIONS = 10;
const int BOOK_SMALL_DELAY_PENALTY = 2000;
const int BOOK_MEDIUM_DELAY_PENALTY = 3000;
const int BOOK_BIG_DELAY_PENALTY = 5000;
const int BOOK_MAX_BORROW_TIME = 10;
const int STUDENT_ALLOWED_BORROW_NUMS = 2;
const int PROF_ALLOWED_BORROW_NUMS = 5;
const int NOT_FOUND_INDEX = -1;
const std::string EMPTY_STR = "";
const std::string EMPTY_FIELD_ERROR_MSG = "Empty field";
const std::string NAME_EXISTS_ERROR_MSG = "Name already exists";
const std::string TITLE_EXISTS_ERROR_MSG = "A document with the specified name already exists";
const std::string INVALID_YEAR_ERROR_MSG = "Invalid year";
const std::string INVALID_NUMBER_ERROR_MSG = "Invalid number";
const std::string DOCUMENT_NOT_AVAILABLE_ERROR_MSG = "This document does not exist";
const std::string NO_ALLOWED_BORROWS_LEFT_ERROR_MSG = "Maximum number of allowed borrows exceeded";
const std::string ALREADY_BORROWED_ERROR_MSG = "You borrowed this document already";
const std::string NO_ALLOWED_EXTENSIONS_LEFT_ERROR_MSG = "You can’t renew a document more than two times";
const std::string DOC_NOT_BORROWED_ERROR_MSG = "You have not borrowed this document";
const std::string BORROW_AND_EXTEND_AT_SAME_DAY_ERROR_MSG = "You can’t extend and borrow a document on the same day";
const std::string MAGAINE_CANT_EXTEND_ERROR_MSG = "You can’t renew magazines";
const std::string CANT_EXTEND_AFTER_RETURN_DATE = "You can’t renew a document after receiving a penalty";
const std::string INVALID_DAYS_ERROR_MSG = "Invalid day";

#endif