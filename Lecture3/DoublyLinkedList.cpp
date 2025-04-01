#include <iostream>
#include <cstdlib>
#include <string>

typedef std::string Data;

class DNode
{
private:
    Data elem;
    DNode *prev;
    DNode *next;
    friend class DLinkedList;
};

class DLinkedList
{
private:
    DNode *header;
    DNode *trailer;

public:
    DLinkedList(void);
    ~DLinkedList(void);

    bool isEmpty(void) const;

    const Data &peekFront(void);
    const Data &peekBack(void);

    void addFront(const Data &elem);
    void addBack(const Data &elem);
    Data removeFront(void);
    Data removeBack(void);

protected:
    void add(DNode *nodep, const Data &elem);
    void del(DNode *nodep);
};

DLinkedList::DLinkedList(void)
{
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}
DLinkedList::~DLinkedList(void)
{
    while (!isEmpty())
        removeFront();
    delete header;
    delete trailer;
}
bool DLinkedList::isEmpty(void) const
{
    if (header->next == trailer)
        return true;
    else
        return false;
}
const Data &DLinkedList::peekFront(void)
{
    return header->next->elem;
}
const Data &DLinkedList::peekBack(void)
{
    return trailer->prev->elem;
}
void DLinkedList::addFront(const Data &elem)
{
    add(header->next, elem);
    return;
}
void DLinkedList::addBack(const Data &elem)
{
    add(trailer, elem);
    return;
}
Data DLinkedList::removeFront(void)
{
    DNode *node = header->next;
    Data elem = node->elem;
    del(node);
    return elem;
}
Data DLinkedList::removeBack(void)
{
    DNode *node = trailer->prev;
    Data elem = node->elem;
    del(node);
    return elem;
}
void DLinkedList::add(DNode *nodep, const Data &elem)
{
    DNode *newN = new DNode;
    newN->elem = elem;
    newN->next = nodep;
    newN->prev = nodep->prev;
    nodep->prev->next = newN;
    nodep->prev = newN;
}
void DLinkedList::del(DNode *nodep)
{
    DNode *preN = nodep->prev;
    DNode *nexN = nodep->next;
    preN->next = nexN;
    nexN->prev = preN;
    delete nodep;
    return;
}

int main(void)
{
    DLinkedList A;
    A.addFront("Hello");
    Data tmp = A.peekFront();
    std::cout << tmp << std::endl;

    A.addFront("World");
    tmp = A.peekFront();
    std::cout << tmp << std::endl;
    return 0;
}