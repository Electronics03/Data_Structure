#ifndef DATAERROR_H
#define DATAERROR_H

#include <exception>
#include <string>

class ListError : public std::exception
{
private:
    std::string message;

public:
    ListError(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};
/*
class StackError : public std::exception
{
private:
    std::string message;

public:
    StackError(const std::string &errorMessage);
    const char *what() const noexcept override;
};

class QueueError : public std::exception
{
private:
    std::string message;

public:
    QueueError(const std::string &errorMessage);
    const char *what() const noexcept override;
};

class DequeError : public std::exception
{
private:
    std::string message;

public:
    DequeError(const std::string &errorMessage);
    const char *what() const noexcept override;
};

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

QueueError::QueueError(const std::string &errorMessage) : message(errorMessage) {}

const char *QueueError::what() const noexcept
{
    return message.c_str();
}

DequeError::DequeError(const std::string &errorMessage) : message(errorMessage) {}

const char *DequeError::what() const noexcept
{
    return message.c_str();
}
*/
#endif