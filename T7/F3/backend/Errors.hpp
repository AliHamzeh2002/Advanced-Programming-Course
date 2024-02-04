#ifndef __ERROR_HH__

#define __ERROR_HH__

#include "constants.hpp"
#include <exception>
#include <string>

class BadRequestError : public std::exception
{
    public:
        virtual const char * what() const noexcept;
};

class NotFoundError : public std::exception
{
    public:

        virtual char const * what() const noexcept;
};

class PermissionDeniedError : public std::exception
{
    public:
    virtual char const * what() const noexcept;
};

#endif