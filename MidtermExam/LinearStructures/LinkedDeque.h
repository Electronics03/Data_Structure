#ifndef LDEQUE_H
#define LDEQUE_H

#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "DataError.h"

class LinkedDeque
{
public:
    LinkedDeque();
    ~LinkedDeque();

    int size(void) const;
    bool empty(void) const;

    const Elem &front(void) const;
    const Elem &back(void) const;

    void insertFront(const Elem &e);
    void insertBack(const Elem &e);

    void removeFront(void);
    void removeBack(void);

private:
    DLinkedList D;
    int n;
};
LinkedDeque::LinkedDeque() : D(), n(0) {}
LinkedDeque::~LinkedDeque() {}

int LinkedDeque::size(void) const { return n; }
bool LinkedDeque::empty(void) const { return n == 0; }

const Elem &LinkedDeque::front(void) const
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    return D.front();
}
const Elem &LinkedDeque::back(void) const
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    return D.back();
}
void LinkedDeque::insertFront(const Elem &e)
{
    D.addFront(e);
    n++;
}
void LinkedDeque::insertBack(const Elem &e)
{
    D.addBack(e);
    n++;
}
void LinkedDeque::removeFront(void)
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    D.removeFront();
    n--;
}
void LinkedDeque::removeBack(void)
{
    if (empty())
        throw DequeError("Error: DequeError is empty.");
    D.removeBack();
    n--;
}

#endif