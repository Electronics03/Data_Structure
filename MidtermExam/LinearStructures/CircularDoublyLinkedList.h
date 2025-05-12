#ifndef CDLIST_H
#define CDLIST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "DataError.h"

using Elem = std::string;

typedef struct Node
{
    Elem element;
    Node *next;
    Node *prev;
} Node;

class CDList
{
private:
    Node *cursor;

public:
    CDList();
    ~CDList();
    void add(Elem data);
    void remove();
    bool empty();
    void forward();
    void backward();
};
CDList::CDList() : cursor(nullptr) {}
CDList::~CDList()
{
    while (!empty())
        remove();
}
void CDList::add(Elem data)
{
    Node *newNode = new Node;
    newNode->element = data;
    if (empty())
    {
        cursor = newNode;
        cursor->next = cursor;
        cursor->prev = cursor;
    }
    else
    {
        newNode->next = cursor->next;
        newNode->prev = cursor;
        cursor->next = cursor->next->prev = newNode;
    }
}

void CDList::remove()
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *delNode = cursor->next;
    if (delNode == cursor)
    {
        cursor = nullptr;
    }
    else
    {
        delNode->next->prev = cursor;
        cursor->next = delNode->next;
    }
    delete delNode;
}
bool CDList::empty()
{
    return (cursor == nullptr);
}
void CDList::forward()
{
    cursor = cursor->next;
}
void CDList::backward()
{
    cursor = cursor->prev;
}
#endif