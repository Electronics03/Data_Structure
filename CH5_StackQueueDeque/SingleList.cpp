#ifndef SINGLELIST_IMPLEMENTATION
#define SINGLELIST_IMPLEMENTATION

#include "SingleList.h"

template <typename E>
SLinkedList<E>::SLinkedList() : head(nullptr) {}

template <typename E>
SLinkedList<E>::~SLinkedList()
{
    while (!empty())
        removeFront();
    return;
}

template <typename E>
bool SLinkedList<E>::empty(void) const
{
    return (head == nullptr);
}

template <typename E>
const E &SLinkedList<E>::front(void) const
{
    if (empty())
        throw ListError("Error: List is empty.front()");
    return (head->elem);
}

template <typename E>
void SLinkedList<E>::addFront(const E &e)
{
    SNode<E> *v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
    return;
}

template <typename E>
void SLinkedList<E>::removeFront(void)
{
    if (empty())
        throw ListError("Error: List is empty.removeFront()");
    SNode<E> *v = head;
    head = v->next;
    delete v;
}
#endif