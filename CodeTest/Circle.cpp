#include <iostream>
#include <cstdlib>
#include <string>

typedef std::string Elem;

class Node
{
private:
    Node *next;
    Elem elem;
    friend class Clist;
};
class Clist
{
public:
    Clist();
    ~Clist();
    bool empty(void) const;
    const Elem &back(void) const;
    const Elem &front(void) const;
    void advance(void);
    void remove(void);
    void add(const Elem &elem);

private:
    Node *cursor;
};
Clist::Clist() : cursor(nullptr) {}
Clist::~Clist()
{
    while (!empty())
        remove();
}
bool Clist::empty(void) const { return cursor == nullptr; }
const Elem &Clist::back(void) const { return (cursor->elem); }
const Elem &Clist::front(void) const { return (cursor->next->elem); }
void Clist::advance(void) { cursor = cursor->next; }
void Clist::remove(void)
{
    Node *delN = cursor->next;
    if (delN == cursor)
        cursor = nullptr;
    else
        cursor->next = delN->next;
    delete delN;
}
void Clist::add(const Elem &elem)
{
    Node *newN = new Node;
    newN->elem = elem;
    if (empty())
    {
        newN->next = newN;
        cursor = newN;
    }
    else
    {
        newN->next = cursor->next;
        cursor->next = newN;
    }
}

int main(void)
{
    return 0;
}