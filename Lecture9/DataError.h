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

class StackError : public std::exception
{
private:
    std::string message;

public:
    StackError(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};

class QueueError : public std::exception
{
private:
    std::string message;

public:
    QueueError(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};

class DequeError : public std::exception
{
private:
    std::string message;

public:
    DequeError(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};
class TreeError : public std::exception
{
private:
    std::string message;

public:
    TreeError(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};
class MapError : public std::exception
{
private:
    std::string message;

public:
    MapError(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};
class HashError : public std::exception
{
private:
    std::string message;

public:
    HashError(const std::string &errorMessage) : message(errorMessage) {}
    const char *what() const noexcept override { return message.c_str(); }
};
#endif