#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "DataError.h"

using Elem = std::string;

class Nodelist
{
private:
    class Node
    {
    private:
        Elem elem;
        Node *prev;
        Node *next;
        friend class Iterator;
        friend class Nodelist;
    };

public:
    class Iterator
    {
    private:
        Node *presNode;
        Iterator(Node *newNode);

    public:
        Elem &operator*();
        bool operator==(const Iterator &point) const;
        bool operator!=(const Iterator &point) const;
        Iterator &operator++(void);
        Iterator &operator--(void);
        friend class Nodelist;
    };

public:
    Nodelist();
    ~Nodelist();

    int size(void);
    bool empty(void) const;

    Iterator begin() const;
    Iterator end() const;

    void insert(const Iterator &point, const Elem &elem);
    void insertFront(const Elem &elem);
    void insertBack(const Elem &elem);

    void erase(const Iterator &point);
    void eraseFront(void);
    void eraseBack(void);

private:
    Node *header;
    Node *trailer;
    int n;
};

Nodelist::Iterator::Iterator(Nodelist::Node *newNode) : presNode(newNode) {}
Elem &Nodelist::Iterator::operator*()
{
    return presNode->elem;
}
bool Nodelist::Iterator::operator==(const Iterator &point) const
{
    return point.presNode == presNode;
}
bool Nodelist::Iterator::operator!=(const Iterator &point) const
{
    return point.presNode != presNode;
}
Nodelist::Iterator &Nodelist::Iterator::operator++(void)
{
    presNode = presNode->next;
    return *this;
}
Nodelist::Iterator &Nodelist::Iterator::operator--(void)
{
    presNode = presNode->prev;
    return *this;
}

Nodelist::Nodelist() : n(0)
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}
Nodelist::~Nodelist()
{
    while (empty())
        eraseFront();
    delete header;
    delete trailer;
}
void Nodelist::insert(const Iterator &point, const Elem &elem)
{
    Node *presNode = point.presNode;
    Node *prevNode = point.presNode->prev;
    Node *newNode = new Node;

    newNode->elem = elem;
    newNode->next = presNode;
    newNode->prev = prevNode;

    prevNode->next = newNode;
    presNode->prev = newNode;
    n++;
}
void Nodelist::erase(const Iterator &point)
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *delNode = point.presNode;
    Node *prevNode = delNode->prev;
    Node *nextNode = delNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete delNode;
    n--;
}
int Nodelist::size(void)
{
    return n;
}
bool Nodelist::empty(void) const
{
    return header->next == trailer;
}
Nodelist::Iterator Nodelist::begin() const
{
    return Iterator(header->next);
}
Nodelist::Iterator Nodelist::end() const
{
    return Iterator(trailer);
}
void Nodelist::insertFront(const Elem &elem)
{
    insert(begin(), elem);
}
void Nodelist::insertBack(const Elem &elem)
{
    insert(end(), elem);
}
void Nodelist::eraseFront(void)
{
    erase(begin());
}
void Nodelist::eraseBack(void)
{
    erase(--end());
}
#endif