#ifndef DATAERROR_H
#define DATAERROR_H

#include <exception>
#include <string>

class HashError : public std::exception
{
private:
    std::string message;

public:
    HashError(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};
#endif