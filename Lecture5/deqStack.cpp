#include <iostream>
#include <string>
#include "deque.hpp"

using std::ostream;
using std::string;

class deqStack
{
private:
    deque closedData;

public:
    deqStack();
    ~deqStack();
    int size(void);
    bool isEmpty(void);
    const Elem &top(void);
    void push(const Elem &data);
    void pop(void);
    friend ostream &operator<<(ostream &os, const deqStack &stack);
};

deqStack::deqStack() {}
deqStack::~deqStack() {}

int deqStack::size(void)
{
    return closedData.size();
}
bool deqStack::isEmpty(void)
{
    return closedData.isEmpty();
}
const Elem &deqStack::top(void)
{
    return closedData.front();
}
void deqStack::push(const Elem &data)
{
    closedData.insertFront(data);
}
void deqStack::pop(void)
{
    closedData.removeFront();
}
ostream &operator<<(ostream &os, const deqStack &stack)
{
    os << stack.closedData;
    return os;
}

int main()
{
    deqStack playList;

    std::cout << "push(SA)" << std::endl;
    playList.push("SA");
    std::cout << playList << std::endl;

    std::cout << "push(LF)" << std::endl;
    playList.push("LF");
    std::cout << playList << std::endl;

    std::cout << "push(JT)" << std::endl;
    playList.push("JT");
    std::cout << playList << std::endl;

    std::cout << "pop()" << std::endl;
    playList.pop();
    std::cout << playList << std::endl;

    std::cout << "push(DI)" << std::endl;
    playList.push("DI");
    std::cout << playList << std::endl;

    std::cout << "pop()" << std::endl;
    playList.pop();
    std::cout << playList << std::endl;

    std::cout << "pop()" << std::endl;
    playList.pop();
    std::cout << playList << std::endl;

    std::cout << "pop()" << std::endl;
    playList.pop();
    std::cout << playList << std::endl;

    std::cout << "pop()" << std::endl;
    playList.pop();
    std::cout << playList << std::endl;

    return EXIT_SUCCESS;
} // g++ Lecture5/deqStack.cpp Lecture5/deque.cpp -o Lecture5/deqStack