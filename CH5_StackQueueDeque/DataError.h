#ifndef DATAERROR_H
#define DATAERROR_H

#include <exception>
#include <string>

class ListError : public std::exception
{
private:
    std::string message;

public:
    ListError(const std::string &errorMessage);
    const char *what() const noexcept override;
};
class StackError : public std::exception
{
private:
    std::string message;

public:
    StackError(const std::string &errorMessage);
    const char *what() const noexcept override;
};

#endif