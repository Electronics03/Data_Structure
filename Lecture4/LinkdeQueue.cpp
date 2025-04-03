#include <iostream>
#include <cstdlib>
#include <string>

typedef std::string Data;

class Node
{
private:
    Data elem;
    Node *next;
    friend class LinkedQueue;
};

class LinkedQueue
{
private:
    Node *cursor;

public:
    LinkedQueue();
    ~LinkedQueue();
    bool isEmpty(void) const;

    const Data &peekFront(void);
    const Data &peekBack(void);

    void enqueue(const Data &elem);
    const Data dequeue(void);
};

LinkedQueue::LinkedQueue() : cursor(NULL)
{
    return;
}
LinkedQueue::~LinkedQueue()
{
    while (!isEmpty())
        dequeue();
}
bool LinkedQueue::isEmpty(void) const
{
    if (cursor == NULL)
        return true;
    else
        return false;
}
const Data &LinkedQueue::peekFront(void)
{
    return cursor->next->elem;
}
const Data &LinkedQueue::peekBack(void)
{
    return cursor->elem;
}

void LinkedQueue::enqueue(const Data &elem)
{
    Node *newNode = new Node;
    newNode->elem = elem;
    if (cursor == NULL)
    {
        newNode->next = newNode;
        cursor = newNode;
    }
    else
    {
        newNode->next = cursor->next;
        cursor->next = newNode;
        cursor = newNode;
    }
}
const Data LinkedQueue::dequeue(void)
{
    Node *delNode = cursor->next;
    Data elem = delNode->elem;
    if (delNode == cursor)
        cursor = NULL;
    else
        cursor->next = delNode->next;
    delete delNode;
    return elem;
}

int main(void)
{
    LinkedQueue A;
    A.enqueue("Hello");
    A.enqueue("World");
    A.enqueue("C++");
    while (!A.isEmpty())
        std::cout << A.dequeue() << std::endl;
    return 0;
}