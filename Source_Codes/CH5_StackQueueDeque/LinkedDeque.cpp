#include <iostream>
#include <string>
#include "DoubleList.h"
#include "DataError.h"

using namespace std;

typedef string Elem;

class LinkedDeque
{
public:
    LinkedDeque();
    ~LinkedDeque();

    int size(void) const;
    bool empty(void) const;

    const Elem &front(void) const;
    const Elem &back(void) const;

    void insertFront(const Elem &e);
    void insertBack(const Elem &e);

    void removeFront(void);
    void removeBack(void);

private:
    DoubleList<Elem> D;
    int n;
};
LinkedDeque::LinkedDeque() : D(), n(0) {}
LinkedDeque::~LinkedDeque() {}

int LinkedDeque::size(void) const { return n; }
bool LinkedDeque::empty(void) const { return n == 0; }

const Elem &LinkedDeque::front(void) const
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    return D.front();
}
const Elem &LinkedDeque::back(void) const
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    return D.back();
}
void LinkedDeque::insertFront(const Elem &e)
{
    D.addFront(e);
    n++;
}
void LinkedDeque::insertBack(const Elem &e)
{
    D.addBack(e);
    n++;
}
void LinkedDeque::removeFront(void)
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    D.removeFront();
    n--;
}
void LinkedDeque::removeBack(void)
{
    if (empty())
        throw DequeError("Error: DequeError is empty.");
    D.removeBack();
    n--;
}
int main(void)
{
    LinkedDeque A;
    A.insertFront("Hello");
    A.insertFront("World");
    A.insertFront("C++");
    A.insertBack("Hello");
    A.insertBack("World");
    A.insertBack("C++");
    while (!A.empty())
    {
        cout << A.front() << " " << A.back() << endl;
        A.removeFront();
    }
    return 0;
}

/*
 * g++                                      -> 컴파일러
 * -o CH5_StackQueueDeque/LinkedDeque.exe   -> exe 파일 이름, 위치
 * CH5_StackQueueDeque/LinkedDeque.cpp      -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/DoubleList.cpp       -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/DataError.cpp        -> 함께 하는 파일 이름, 위치
 *
 * g++ -o CH5_StackQueueDeque/LinkedDeque.exe CH5_StackQueueDeque/LinkedDeque.cpp CH5_StackQueueDeque/DoubleList.cpp CH5_StackQueueDeque/DataError.cpp
 */