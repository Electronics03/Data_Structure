#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "DataError.h"

using Elem = std::string;

class Node
{
private:
    Elem elem;
    Node *next;
    friend class CLinkedList;
};

class CLinkedList
{
public:
    CLinkedList();
    ~CLinkedList();

    bool empty(void) const;

    const Elem &front(void) const;
    const Elem &back(void) const;

    void advance(void);
    void add(const Elem &e);
    void remove(void);

private:
    Node *cursor;
};

CLinkedList::CLinkedList() : cursor(nullptr) {}
CLinkedList::~CLinkedList()
{
    while (!empty())
        remove();
    return;
}
bool CLinkedList::empty(void) const
{
    return (cursor == nullptr);
}
const Elem &CLinkedList::front(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return (cursor->next->elem);
}
const Elem &CLinkedList::back(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return (cursor->elem);
}
void CLinkedList::advance(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    cursor = cursor->next;
}
void CLinkedList::add(const Elem &e)
{
    Node *v = new Node;
    v->elem = e;

    if (empty())
    {
        v->next = v;
        cursor = v;
    }
    else
    {
        v->next = cursor->next;
        cursor->next = v;
    }
}
void CLinkedList::remove(void)
{
    if (empty())
        throw ListError("Error: List is empty.");

    Node *delNode = cursor->next;

    if (delNode == cursor)
        cursor = nullptr;
    else
        cursor->next = delNode->next;

    delete delNode;
}
#endif