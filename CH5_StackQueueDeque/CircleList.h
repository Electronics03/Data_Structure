#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "DataError.h"

template <typename E>
class CNode
{
private:
    E elem;
    CNode<E> *next;
    friend class CircleList<E>;
};

template <typename E>
class CircleList
{
public:
    CircleList();
    ~CircleList();

    bool empty(void) const;
    const E &front(void);
    const E &back(void);
    void advance(void);
    void add(const E &e);
    void remove(void);

private:
    CNode<E> *cursor;
};

#include "CircleList.cpp"

#endif