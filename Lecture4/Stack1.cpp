#include <iostream>
#include <cstdlib>
#include <string>

#define CAPACITY 100

template <typename E>
class ArrStack
{
private:
    E *arrData;
    int top;
    int capacity;

public:
    ArrStack(int cap = CAPACITY);
    ~ArrStack();
    int size(void) const;
    bool isEmpty(void);
    bool isFull(void);
    const E &peek(void) const;
    const E &pop(void);
    void push(const E &elem);
};

template <typename E>
ArrStack<E>::ArrStack(int cap) : arrData(new E[cap]), capacity(cap), top(-1)
{
    return;
}

template <typename E>
ArrStack<E>::~ArrStack()
{
    delete[] arrData;
    return;
}

template <typename E>
int ArrStack<E>::size(void) const
{
    return (top + 1);
}

template <typename E>
bool ArrStack<E>::isEmpty(void)
{
    return (top == -1);
}

template <typename E>
bool ArrStack<E>::isFull(void)
{
    return (top == capacity - 1);
}

template <typename E>
const E &ArrStack<E>::peek(void) const
{
    if (isEmpty())
    {
        std::cout << "ERROR : Stack is Empty" << std::endl;
        return NULL;
    }
    else
    {
        return arrData[top];
    }
}

template <typename E>
const E &ArrStack<E>::pop(void)
{
    if (isEmpty())
    {
        std::cout << "ERROR : Stack is Empty" << std::endl;
        return NULL;
    }
    else
    {
        return arrData[top--];
    }
}

template <typename E>
void ArrStack<E>::push(const E &elem)
{
    if (isFull())
        std::cout << "ERROR : Stack is Full" << std::endl;
    else
        arrData[++top] = elem;
}

int main(void)
{
    ArrStack<std::string> A;
    A.push("Hello");
    A.push("Workd");
    A.push("C++");
    while (!A.isEmpty())
        std::cout << A.pop() << std::endl;
    return 0;
}