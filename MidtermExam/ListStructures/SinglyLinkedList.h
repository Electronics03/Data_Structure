#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "DataError.h"

using Elem = std::string;

class Node
{
    Elem elem;
    Node *next;
    friend class SLinkedList;
};

class SLinkedList
{
public:
    SLinkedList();
    ~SLinkedList();

    bool empty(void) const;
    const Elem &front(void) const;

    void addFront(const Elem &elem);
    void removeFront(void);

private:
    Node *head;
};

SLinkedList::SLinkedList() : head(nullptr) {}
SLinkedList::~SLinkedList()
{
    while (!empty())
        removeFront();
    return;
}
bool SLinkedList::empty(void) const
{
    return (head == nullptr);
}
const Elem &SLinkedList::front(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return head->elem;
}
void SLinkedList::addFront(const Elem &elem)
{
    Node *newNode = new Node;
    newNode->elem = elem;
    newNode->next = head;
    head = newNode;
    return;
}
void SLinkedList::removeFront(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *delNode = head;
    head = delNode->next;
    delete delNode;
}

#endif