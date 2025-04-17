#ifndef DOUBLELIST_IMPLEMENTATION
#define DOUBLELIST_IMPLEMENTATION

#include "DoubleList.h"

template <typename E>
DoubleList<E>::DoubleList()
{
    header = new DNode<E>;
    trailer = new DNode<E>;
    header->next = trailer;
    trailer->prev = header;
    header->prev = nullptr;
    trailer->next = nullptr;
}

template <typename E>
DoubleList<E>::~DoubleList()
{
    while (!empty())
        removeFront();
}

template <typename E>
bool DoubleList<E>::empty(void) const
{
    return (header->next == trailer);
}

template <typename E>
const E &DoubleList<E>::front(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    return (header->next->elem);
}

template <typename E>
const E &DoubleList<E>::back(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    return (trailer->prev->elem);
}

template <typename E>
void DoubleList<E>::addFront(const E &elem)
{
    add(header->next, elem);
}

template <typename E>
void DoubleList<E>::addBack(const E &elem)
{
    add(trailer, elem);
}

template <typename E>
void DoubleList<E>::removeFront(void)
{
    remove(header->next);
}

template <typename E>
void DoubleList<E>::removeBack(void)
{
    remove(trailer->prev);
}

template <typename E>
void DoubleList<E>::add(DNode<E> *v, const E &e)
{
    DNode<E> *u = new DNode<E>;
    u->elem = e;
    u->prev = v->prev;
    u->next = v;
    v->prev->next = u;
    v->prev = u;
}

template <typename E>
void DoubleList<E>::remove(DNode<E> *v)
{
    if (empty())
        throw ListError("Error: List is empty.");
    DNode<E> *u = v->prev;
    DNode<E> *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}
#endif