#ifndef HASHERROR_H
#define HASHERROR_H

#include <exception>
#include <string>

class NonexistentElement : public std::exception
{
private:
    std::string message;

public:
    NonexistentElement(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};
#endif