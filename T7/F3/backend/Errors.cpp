#include "Errors.hpp"
using namespace std;

const char * BadRequestError::what() const noexcept { 
    return BAD_REQUEST_ERR_MSG.c_str(); 
}

const char * NotFoundError::what() const noexcept { 
    return NOT_FOUND_ERR_MSG.c_str(); 
}

const char * PermissionDeniedError::what() const noexcept { 
    return PERMISSION_DENIED_ERR_MSG.c_str(); 
}