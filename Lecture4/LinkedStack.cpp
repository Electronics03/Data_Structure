#include <iostream>
#include <cstdlib>
#include <string>

typedef std::string Data;

class Node
{
private:
    Data elem;
    Node *next;
    friend class LinkedStack;
};

class LinkedStack
{
private:
    Node *head;

public:
    LinkedStack();
    ~LinkedStack();

    bool isEmpty(void) const;
    const Data &peek(void);

    void push(const Data &elem);
    const Data pop(void);
};

LinkedStack::LinkedStack() : head(NULL)
{
    return;
}
LinkedStack::~LinkedStack()
{
    while (!isEmpty())
        pop();
}
bool LinkedStack::isEmpty(void) const
{
    if (head == NULL)
        return true;
    else
        return false;
}
const Data &LinkedStack::peek(void)
{
    return head->elem;
}
void LinkedStack::push(const Data &elem)
{
    Node *newNode = new Node;
    newNode->elem = elem;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
const Data LinkedStack::pop(void)
{
    Node *delNode = head;
    if (isEmpty())
    {
        std::cout << "ERROR : Stack is Empty" << std::endl;
    }
    else
    {
        Data elem = delNode->elem;
        head = delNode->next;
        delete delNode;
        return elem;
    }
}
int main(void)
{
    LinkedStack A;
    A.push("Hello");
    A.push("World");
    A.push("C++");
    std::cout << A.peek() << std::endl;
    while (!A.isEmpty())
        std::cout << A.pop() << std::endl;
    return 0;
}