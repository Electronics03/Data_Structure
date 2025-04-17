#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
class StringNode
{
private:
    string elem;
    StringNode *next;
    friend class StringLinkedList;
};
class StringLinkedList
{
public:
    StringLinkedList();
    ~StringLinkedList();

    bool empty(void) const;
    const string &front(void) const;
    void addFront(const string &e);
    void removeFront(void);
    friend ostream &operator<<(ostream &os, const StringLinkedList &list);

private:
    StringNode *head;
};

StringLinkedList::StringLinkedList() : head(nullptr) {}
StringLinkedList::~StringLinkedList()
{
    while (!empty())
        removeFront();
    return;
}

bool StringLinkedList::empty(void) const
{
    return (head == nullptr);
}
const string &StringLinkedList::front(void) const
{
    return (head->elem);
}
void StringLinkedList::addFront(const string &e)
{
    StringNode *v = new StringNode;
    v->elem = e;
    v->next = head;
    head = v;
    return;
}
void StringLinkedList::removeFront(void)
{
    StringNode *v = head;
    head = v->next;
    delete v;
}
int main(void)
{
    StringLinkedList A;
    A.addFront("Chung-Ang Univ");
    A.addFront("CAU");
    A.addFront("EEE");
    A.addFront("Chung-Ang Univ");
    A.addFront("CAU");
    A.addFront("EEE");
    while (!A.empty())
    {
        cout << A.front() << endl;
        A.removeFront();
    }
    return 0;
}