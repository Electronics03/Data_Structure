#include <iostream>
#include <string>
#include "CircleList.h"
#include "DataError.h"

using namespace std;

typedef string Elem;

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
    CircleList<Elem> C;
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
int main(void)
{
    LinkedQueue A;
    A.enqueue("Hello");
    A.enqueue("World");
    A.enqueue("C++");
    while (!A.empty())
    {
        cout << A.front() << endl;
        A.dequeue();
    }
    return 0;
}

/*
 * g++                                      -> 컴파일러
 * -o CH5_StackQueueDeque/LinkedQueue.exe   -> exe 파일 이름, 위치
 * CH5_StackQueueDeque/LinkedQueue.cpp      -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/CircleList.cpp       -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/DataError.cpp        -> 함께 하는 파일 이름, 위치
 *
 * g++ -o CH5_StackQueueDeque/LinkedQueue.exe CH5_StackQueueDeque/LinkedQueue.cpp CH5_StackQueueDeque/CircleList.cpp CH5_StackQueueDeque/DataError.cpp
 */