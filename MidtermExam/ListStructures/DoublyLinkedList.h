#ifndef DOUBLELIST_H
#define DOUBLELIST_H

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
    Node *prev;
    friend class DLinkedList;
};

class DLinkedList
{
public:
    DLinkedList();
    ~DLinkedList();

    bool empty(void) const;
    const Elem &front(void) const;
    const Elem &back(void) const;

    void addFront(const Elem &elem);
    void removeFront(void);

    void addBack(const Elem &elem);
    void removeBack(void);

private:
    Node *header;
    Node *trailer;

protected:
    void add(Node *v, const Elem &elem);
    void remove(Node *v);
};

DLinkedList::DLinkedList()
{
    header = new Node;
    trailer = new Node;

    header->next = trailer;
    trailer->prev = header;
}
DLinkedList::~DLinkedList()
{
    while (!empty())
        removeFront();
    delete header;
    delete trailer;
    return;
}

bool DLinkedList::empty(void) const
{
    return (header->next == trailer);
}
const Elem &DLinkedList::front(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return header->next->elem;
}
const Elem &DLinkedList::back(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return trailer->prev->elem;
}

void DLinkedList::addFront(const Elem &elem)
{
    add(header->next, elem);
}
void DLinkedList::removeFront(void)
{
    remove(header->next);
}

void DLinkedList::addBack(const Elem &elem)
{
    add(trailer, elem);
}
void DLinkedList::removeBack(void)
{
    remove(trailer->prev);
}

void DLinkedList::add(Node *v, const Elem &elem)
{
    Node *u = new Node;
    u->elem = elem;
    u->prev = v->prev;
    u->next = v;
    v->prev->next = u;
    v->prev = u;
}
void DLinkedList::remove(Node *v)
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *u = v->prev;
    Node *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

#endif