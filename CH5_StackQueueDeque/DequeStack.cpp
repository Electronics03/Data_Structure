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
class DequeStack
{
public:
    DequeStack();
    ~DequeStack();

    int size(void) const;
    bool empty(void) const;
    const Elem &top(void) const;
    void pop(void);
    void push(const Elem &e);

private:
    LinkedDeque S;
    int n;
};
DequeStack::DequeStack() : S(), n(0) {}
DequeStack::~DequeStack() {}

int DequeStack::size(void) const { return n; }

bool DequeStack::empty(void) const { return n == 0; }
const Elem &DequeStack::top(void) const
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    return S.front();
}
void DequeStack::pop(void)
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    S.removeFront();
    n--;
}
void DequeStack::push(const Elem &e)
{
    S.insertFront(e);
    n++;
}
int main(void)
{
    DequeStack A;
    A.push("Hello");
    A.push("World");
    A.push("C++");
    cout << A.top() << endl;
    while (!A.empty())
    {
        cout << A.top() << endl;
        A.pop();
    }
    return 0;
}
/*
 * g++                                      -> 컴파일러
 * -o CH5_StackQueueDeque/DequeStack.exe   -> exe 파일 이름, 위치
 * CH5_StackQueueDeque/DequeStack.cpp      -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/DoubleList.cpp       -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/DataError.cpp        -> 함께 하는 파일 이름, 위치
 *
 * g++ -o CH5_StackQueueDeque/DequeStack.exe CH5_StackQueueDeque/DequeStack.cpp CH5_StackQueueDeque/DoubleList.cpp CH5_StackQueueDeque/DataError.cpp
 */