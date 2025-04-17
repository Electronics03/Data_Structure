#ifndef CIRCLELIST_IMPLEMENTATION
#define CIRCLELIST_IMPLEMENTATION

#include "CircleList.h"

template <typename E>
CircleList<E>::CircleList() : cursor(nullptr) {}

template <typename E>
CircleList<E>::~CircleList()
{
    while (!empty())
        remove();
}

template <typename E>
bool CircleList<E>::empty(void) const
{
    return (cursor == nullptr);
}

template <typename E>
const E &CircleList<E>::front(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    return (cursor->next->elem);
}

template <typename E>
const E &CircleList<E>::back(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    return (cursor->elem);
}

template <typename E>
void CircleList<E>::advance(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    cursor = cursor->next;
}

template <typename E>
void CircleList<E>::add(const E &e)
{
    CNode<E> *v = new CNode<E>;
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

template <typename E>
void CircleList<E>::remove(void)
{
    if (empty())
        throw ListError("Error: List is empty.");

    CNode<E> *old = cursor->next;

    if (old == cursor)
        cursor = nullptr;
    else
        cursor->next = old->next;

    delete old;
}

#endif