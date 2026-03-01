#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>

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
    if (empty())
        throw out_of_range("Error: empty list.");
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

int main(void)
{
    SLinkedList<string> A;
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
    A.removeFront();
    SLinkedList<int> B;
    B.addFront(1);
    B.addFront(3);
    B.addFront(2);
    B.addFront(1);
    B.addFront(2);
    B.addFront(6);
    while (!B.empty())
    {
        cout << B.front() << endl;
        B.removeFront();
    }
    B.removeFront();
    return 0;
}
