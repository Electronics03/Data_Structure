#include <iostream>
#include <cstdlib>
#include <string>
#include "DataError.h"

#define CAPACITY 100

template <typename E>
class ArrayStack
{
private:
    E *S;
    int t;
    int capacity;

public:
    ArrayStack(int cap = CAPACITY);
    ~ArrayStack();

    int size(void) const;
    bool empty(void) const;
    bool full(void) const;

    const E &top(void) const;

    void pop(void);
    void push(const E &elem);
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap) : S(new E[cap]), capacity(cap), t(-1)
{
    return;
}

template <typename E>
ArrayStack<E>::~ArrayStack()
{
    delete[] S;
    return;
}

template <typename E>
int ArrayStack<E>::size(void) const { return (t + 1); }

template <typename E>
bool ArrayStack<E>::empty(void) const { return (t == -1); }

template <typename E>
bool ArrayStack<E>::full(void) const { return (t == capacity - 1); }

template <typename E>
const E &ArrayStack<E>::top(void) const
{
    if (empty())
        throw StackError("ERROR : Stack is empty.");
    else
        return S[t];
}

template <typename E>
void ArrayStack<E>::pop(void)
{
    if (empty())
        throw StackError("ERROR : Stack is empty.");
    else
        t--;
}

template <typename E>
void ArrayStack<E>::push(const E &elem)
{
    if (full())
        throw StackError("ERROR : Stack is full.");
    else
        S[++t] = elem;
}

int main(void)
{
    ArrayStack<std::string> A;
    A.push("Hello");
    A.push("Workd");
    A.push("C++");
    while (!A.empty())
    {
        std::cout << A.top() << std::endl;
        A.pop();
    }
    return 0;
}
/*
 * g++                                     -> 컴파일러
 * -o CH5_StackQueueDeque/ArrayStack.exe   -> exe 파일 이름, 위치
 * CH5_StackQueueDeque/ArrayStack.cpp      -> 함께 하는 파일 이름, 위치
 * CH5_StackQueueDeque/DataError.cpp       -> 함께 하는 파일 이름, 위치
 *
 * g++ -o CH5_StackQueueDeque/ArrayStack.exe CH5_StackQueueDeque/ArrayStack.cpp CH5_StackQueueDeque/DataError.cpp
 */