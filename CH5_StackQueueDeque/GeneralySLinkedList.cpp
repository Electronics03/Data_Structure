#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
template <typename E>
class SLinkedList;
template <typename E>
class SNode
{
private:
    E elem;
    SNode<E> *next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList
{
public:
    SLinkedList();
    ~SLinkedList();

    bool empty(void) const;
    const E &front(void) const;
    void addFront(const E &e);
    void removeFront(void);

private:
    SNode<E> *head;
};

template <typename E>
SLinkedList<E>::SLinkedList() : head(nullptr) {}

template <typename E>
SLinkedList<E>::~SLinkedList()
{
    while (!empty())
        removeFront();
    return;
}

template <typename E>
bool SLinkedList<E>::empty(void) const
{
    return (head == nullptr);
}

template <typename E>
const E &SLinkedList<E>::front(void) const
{
    return (head->elem);
}

template <typename E>
void SLinkedList<E>::addFront(const E &e)
{
    SNode<E> *v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
    return;
}

template <typename E>
void SLinkedList<E>::removeFront(void)
{
    if (empty())
    {
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    SNode<E> *v = head;
    head = v->next;
    delete v;
}