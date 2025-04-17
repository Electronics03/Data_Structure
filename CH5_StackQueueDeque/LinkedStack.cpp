#include <iostream>
#include <string>
#include "SingleList.h"
#include "DataError.h"

using namespace std;

typedef string Elem;

class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();

    int size(void) const;
    bool empty(void) const;
    const Elem &top(void) const;
    void pop(void);
    void push(const Elem &e);

private:
    SLinkedList<Elem> S;
    int n;
};
LinkedStack::LinkedStack() : S(), n(0) {}
LinkedStack::~LinkedStack() {}

int LinkedStack::size(void) const { return n; }

bool LinkedStack::empty(void) const { return n == 0; }
const Elem &LinkedStack::top(void) const
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    return S.front();
}
void LinkedStack::pop(void)
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    S.removeFront();
    n--;
}
void LinkedStack::push(const Elem &e)
{
    S.addFront(e);
    n++;
}
int main(void)
{
    LinkedStack A;
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
 * -o CH5_StackQueueDeque/LinkedStack.exe   -> exe 파일 이름, 위치
 * CH5_StackQueueDeque/LinkedStack.cpp      -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/SingleList.cpp       -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/DataError.cpp        -> 함께 하는 파일 이름, 위치
 *
 * g++ -o CH5_StackQueueDeque/LinkedStack.exe CH5_StackQueueDeque/LinkedStack.cpp CH5_StackQueueDeque/SingleList.cpp CH5_StackQueueDeque/DataError.cpp
 */