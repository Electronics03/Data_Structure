#include <iostream>
#include <cstdlib>
#include <string>

typedef std::string Elem;

class Node
{
private:
    Node *next;
    Node *prev;
    Elem elem;
    friend class DList;
};

class DList
{
public:
    DList();
    ~DList();
    bool empty(void) const;
    const Elem &front(void) const;
    const Elem &back(void) const;
    void addFront(const Elem &elem);
    void addBack(const Elem &elem);
    void removeFront(void);
    void removeBack(void);

private:
    Node *header;
    Node *trailer;

protected:
    void add(Node *p, const Elem &elem);
    void remove(Node *p);
};
DList::DList()
{
    header->next = trailer;
    trailer->prev = header;
}
DList::~DList()
{
    while (!empty())
        removeFront();
}
bool DList::empty(void) const { return header->next == trailer; }
const Elem &DList::front(void) const { return header->next->elem; }
const Elem &DList::back(void) const { return trailer->prev->elem; }
void DList::addFront(const Elem &elem)
{
    add(header->next, elem);
}
void DList::addBack(const Elem &elem)
{
    add(trailer, elem);
}
void DList::removeFront(void)
{
    remove(header->next);
}
void DList::removeBack(void)
{
    remove(trailer->prev);
}
void DList::add(Node *p, const Elem &elem)
{
    Node *newN = new Node;
    Node *pr = p->prev;
    newN->elem = elem;
    newN->prev = pr;
    newN->next = p;
    pr->next = newN;
    p->prev = newN;
}
void DList::remove(Node *p)
{
    Node *delN = p;
    p->next->prev = p->prev;
    p->prev->next = p->next;
    delete delN;
}