#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "DataError.h"

template <typename E>
class SLinkedList;

template <typename E>
class SNode
{
private:
    E elem;
    SNode<E> *next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList
{
public:
    SLinkedList();
    ~SLinkedList();

    bool empty(void) const;
    const E &front(void) const;
    void addFront(const E &e);
    void removeFront(void);

private:
    SNode<E> *head;
};

#include "SingleList.cpp"
#endif