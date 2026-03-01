#ifndef LQUEUE_H
#define LQUEUE_H

#include <iostream>
#include <string>
#include "CircularlyLinkedList.h"
#include "DataError.h"

class LinkedQueue
{
public:
    LinkedQueue();
    ~LinkedQueue();

    int size(void) const;
    bool empty(void) const;

    const Elem &front(void) const;

    void enqueue(const Elem &e);
    void dequeue(void);

private:
    CLinkedList C;
    int n;
};
LinkedQueue::LinkedQueue() : C(), n(0) {}
LinkedQueue::~LinkedQueue() {}

int LinkedQueue::size(void) const { return n; }
bool LinkedQueue::empty(void) const { return n == 0; }

const Elem &LinkedQueue::front(void) const
{
    if (empty())
        throw QueueError("Error: Queue is empty.");
    return C.front();
}

void LinkedQueue::enqueue(const Elem &e)
{
    C.add(e);
    C.advance();
    n++;
}
void LinkedQueue::dequeue(void)
{
    if (empty())
        throw QueueError("Error: Queue is empty.");
    C.remove();
    n--;
}

#endif