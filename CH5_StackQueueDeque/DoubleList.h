#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "DataError.h"

template <typename E>
class DNode
{
private:
    E elem;
    DNode<E> *prev;
    DNode<E> *next;
    friend class DoubleList<E>;
};

template <typename E>
class DoubleList
{
private:
    DNode<E> *header;
    DNode<E> *trailer;

public:
    DoubleList();
    ~DoubleList();

    bool empty(void) const;
    const E &front(void);
    const E &back(void);

    void addFront(const E &elem);
    void addBack(const E &elem);

    void removeFront(void);
    void removeBack(void);

protected:
    void add(DNode<E> *v, const E &elem);
    void remove(DNode<E> *v);
};

#include "DoubleList.cpp"
#endif