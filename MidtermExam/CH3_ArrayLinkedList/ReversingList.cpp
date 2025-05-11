#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
typedef string Elem;

class DNode
{
private:
    Elem elem;
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
    DLinkedList();
    ~DLinkedList();

    bool empty(void) const;
    const Elem &front(void);
    const Elem &back(void);
    void addFront(const Elem &elem);
    void addBack(const Elem &elem);
    void removeFront(void);
    void removeBack(void);

protected:
    void add(DNode *nodep, const Elem &elem);
    void remove(DNode *nodep);
};

DLinkedList::DLinkedList()
{
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
    header->prev = nullptr;
    trailer->next = nullptr;
}

DLinkedList::~DLinkedList()
{
    while (!empty())
        removeFront();
}

bool DLinkedList::empty(void) const { return (header->next == trailer); }
const Elem &DLinkedList::front(void) { return (header->next->elem); }
const Elem &DLinkedList::back(void) { return (trailer->prev->elem); }
void DLinkedList::addFront(const Elem &elem) { add(header->next, elem); }
void DLinkedList::addBack(const Elem &elem) { add(trailer, elem); }
void DLinkedList::removeFront(void) { remove(header->next); }
void DLinkedList::removeBack(void) { remove(trailer->prev); }

void DLinkedList::add(DNode *v, const Elem &e)
{
    DNode *u = new DNode;
    u->elem = e;
    u->prev = v->prev;
    u->next = v;
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::remove(DNode *v)
{
    if (empty())
    {
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    DNode *u = v->prev;
    DNode *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}
void listReverse(DLinkedList &L)
{
    DLinkedList T;
    while (!L.empty())
    {
        Elem s = L.front();
        L.removeFront();
        T.addFront(s);
    }
    while (!T.empty())
    {
        Elem s = T.front();
        T.removeFront();
        L.addBack(s);
    }
}
int main(void)
{
    DLinkedList A;
    A.addFront("A");
    A.addFront("B");
    A.addFront("C");
    A.addFront("D");
    A.addFront("E");
    A.addFront("F");
    A.addFront("G");
    A.addFront("H");
    while (!A.empty())
    {
        cout << A.front() << endl;
        A.removeFront();
    }
    A.addFront("A");
    A.addFront("B");
    A.addFront("C");
    A.addFront("D");
    A.addFront("E");
    A.addFront("F");
    A.addFront("G");
    A.addFront("H");
    listReverse(A);
    while (!A.empty())
    {
        cout << A.front() << endl;
        A.removeFront();
    }
    return 0;
}
