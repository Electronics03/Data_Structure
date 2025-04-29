#include <iostream>
#include <cstdlib>
#include <string>

typedef std::string Elem;

class Node
{
private:
    Node *next;
    Elem elem;
    friend class SList;
};
class SList
{
public:
    SList();
    ~SList();
    bool empty(void) const;
    const Elem &front(void) const;
    void removeFront(void);
    void addFront(const Elem &elem);

private:
    Node *head;
};
SList::SList() : head(nullptr) {}
SList::~SList()
{
    while (!empty())
        removeFront();
}
bool SList::empty(void) const { return head == nullptr; }
const Elem &SList::front(void) const { return (head->elem); }
void SList::removeFront(void)
{
    Node *delN = head;
    head = head->next;
    delete delN;
}
void SList::addFront(const Elem &elem)
{
    Node *newN = new Node;
    newN->elem = elem;
    newN->next = head->next;
    head->next = newN;
}

int main(void)
{
    return 0;
}