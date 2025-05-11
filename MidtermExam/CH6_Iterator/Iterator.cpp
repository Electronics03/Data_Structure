#ifndef ITERATOR_IMPLEMENTATION
#define ITERATOR_IMPLEMENTATION

#include "Iterator.h"

template <typename Elem>
Nodelist<Elem>::Iterator::Iterator(Nodelist::Node *u) : v(u) {}

template <typename Elem>
Elem &Nodelist<Elem>::Iterator::operator*() { return v->elem; }

template <typename Elem>
bool Nodelist<Elem>::Iterator::operator==(const Iterator &p) const { return p.v == v; }

template <typename Elem>
bool Nodelist<Elem>::Iterator::operator!=(const Iterator &p) const { return p.v != v; }

template <typename Elem>
typename Nodelist<Elem>::Iterator &Nodelist<Elem>::Iterator::operator++(void)
{
    v = v->next;
    return *this;
}

template <typename Elem>
typename Nodelist<Elem>::Iterator &Nodelist<Elem>::Iterator::operator--(void)
{
    v = v->prev;
    return *this;
}

template <typename Elem>
Nodelist<Elem>::Nodelist() : n(0)
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

template <typename Elem>
Nodelist<Elem>::~Nodelist()
{
    while (empty())
        eraseFront();
    delete header;
    delete trailer;
}
template <typename Elem>
void Nodelist<Elem>::insert(const Iterator &p, const Elem &e)
{
    Node *w = p.v;
    Node *v = new Node;
    Node *u = w->prev;
    v->elem = e;
    v->next = w;
    v->prev = u;
    u->next = v;
    w->prev = v;
    n++;
}

template <typename Elem>
void Nodelist<Elem>::erase(const Iterator &p)
{
    Node *v = p.v;
    Node *u = v->prev;
    Node *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
    n--;
}

template <typename Elem>
int Nodelist<Elem>::size(void) { return n; }

template <typename Elem>
bool Nodelist<Elem>::empty(void) const { return header->next == trailer; }

template <typename Elem>
typename Nodelist<Elem>::Iterator Nodelist<Elem>::begin() const { return Iterator(header->next); }

template <typename Elem>
typename Nodelist<Elem>::Iterator Nodelist<Elem>::end() const { return Iterator(trailer); }

template <typename Elem>
void Nodelist<Elem>::insertFront(const Elem &e) { insert(begin(), e); }

template <typename Elem>
void Nodelist<Elem>::insertBack(const Elem &e) { insert(end(), e); }

template <typename Elem>
void Nodelist<Elem>::eraseFront(void) { erase(begin()); }

template <typename Elem>
void Nodelist<Elem>::eraseBack(void) { erase(--end()); }

#endif