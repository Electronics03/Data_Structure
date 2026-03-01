#ifndef LSTACK_H
#define LSTACK_H

#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "DataError.h"

class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();

    int size(void) const;
    bool empty(void) const;
    const Elem &top(void) const;
    void pop(void);
    void push(const Elem &e);

private:
    SLinkedList S;
    int n;
};
LinkedStack::LinkedStack() : S(), n(0) {}
LinkedStack::~LinkedStack() {}

int LinkedStack::size(void) const { return n; }

bool LinkedStack::empty(void) const { return n == 0; }
const Elem &LinkedStack::top(void) const
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    return S.front();
}
void LinkedStack::pop(void)
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    S.removeFront();
    n--;
}
void LinkedStack::push(const Elem &e)
{
    S.addFront(e);
    n++;
}

#endif