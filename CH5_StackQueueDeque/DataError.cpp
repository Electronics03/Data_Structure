#ifndef DATAERROR_IMPLEMENTATION
#define DATAERROR_IMPLEMENTATION

#include "DataError.h"

ListError::ListError(const std::string &errorMessage) : message(errorMessage) {}

const char *ListError::what() const noexcept
{
    return message.c_str();
}
StackError::StackError(const std::string &errorMessage) : message(errorMessage) {}

const char *StackError::what() const noexcept
{
    return message.c_str();
}
#endif