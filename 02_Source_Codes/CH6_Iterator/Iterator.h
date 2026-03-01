#ifndef ITERATOR_H
#define ITERATOR_H

#include "DataError.h"

template <typename Elem>
class Nodelist
{
private:
    struct Node
    {
        Elem elem;
        Node *prev;
        Node *next;
    };

public:
    class Iterator
    {
    private:
        Node *v;
        Iterator(Node *u);

    public:
        Elem &operator*();
        bool operator==(const Iterator &p) const;
        bool operator!=(const Iterator &p) const;
        Iterator &operator++(void);
        Iterator &operator--(void);
        friend class Nodelist<Elem>;
    };

public:
    Nodelist();
    ~Nodelist();

    int size(void);
    bool empty(void) const;

    Iterator begin() const;
    Iterator end() const;

    void insert(const Iterator &p, const Elem &e);
    void insertFront(const Elem &e);
    void insertBack(const Elem &e);

    void erase(const Iterator &p);
    void eraseFront(void);
    void eraseBack(void);

private:
    Node *header;
    Node *trailer;
    int n;
};
#include "Iterator.cpp"
#endif