#include <iostream>
#include <cstdlib>
#include <string>

typedef std::string Data;

class Node
{
private:
    Data elem;
    Node *next;
    friend class CircleList;
};

class CircleList
{
private:
    Node *cursor;

public:
    CircleList();
    ~CircleList();
    bool isEmpty(void) const;

    const Data &peekFront(void);
    const Data &peekBack(void);

    void advance(void);
    void add(const Data &elem);
    void del(void);
};

CircleList::CircleList() : cursor(NULL)
{
    return;
}
CircleList::~CircleList()
{
    while (!isEmpty())
        del();
}
bool CircleList::isEmpty(void) const
{
    if (cursor == NULL)
        return true;
    else
        return false;
}
const Data &CircleList::peekFront(void)
{
    return cursor->next->elem;
}
const Data &CircleList::peekBack(void)
{
    return cursor->elem;
}
void CircleList::advance(void)
{
    cursor = cursor->next;
}
void CircleList::add(const Data &elem)
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
void CircleList::del(void)
{
    Node *delNode = cursor->next;
    if (delNode == cursor)
        cursor = NULL;
    else
        cursor->next = delNode->next;
    delete delNode;
}

int main(void)
{
    CircleList A;
    A.add("Hello");
    A.add("World");
    A.add("C++");
    A.advance();
    std::cout << A.peekBack() << std::endl;
    std::cout << A.peekFront() << std::endl;
    A.advance();
    A.del();
    std::cout << A.peekBack() << std::endl;
    std::cout << A.peekFront() << std::endl;
    return 0;
}