#include <iostream>
#include <string>
#include "deque.hpp"

using std::ostream;
using std::string;

deque::deque() : cursor(nullptr), len(0) {}
deque::~deque()
{
    while (!isEmpty())
        removeFront();
}
void deque::insertFront(const Elem &data)
{
    node *newNp = new node;
    newNp->element = data;
    if (isEmpty())
    {
        len++;
        cursor = newNp;
        cursor->nextNp = cursor;
        cursor->prevNp = cursor;
    }
    else
    {
        len++;
        newNp->nextNp = cursor->nextNp;
        newNp->prevNp = cursor;
        cursor->nextNp = cursor->nextNp->prevNp = newNp;
    }
}
void deque::insertBack(const Elem &data)
{
    node *newNp = new node;
    newNp->element = data;
    if (isEmpty())
    {
        len++;
        cursor = newNp;
        cursor->nextNp = cursor;
        cursor->prevNp = cursor;
    }
    else
    {
        len++;
        newNp->nextNp = cursor->nextNp;
        newNp->prevNp = cursor;
        cursor->nextNp = cursor->nextNp->prevNp = newNp;
        cursor = newNp;
    }
}
void deque::removeFront()
{
    if (isEmpty())
    {
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    node *delNp = cursor->nextNp;
    if (delNp == cursor)
    {
        len = 0;
        cursor = nullptr;
    }
    else
    {
        len--;
        delNp->nextNp->prevNp = cursor;
        cursor->nextNp = delNp->nextNp;
    }
    delete delNp;
}
void deque::removeBack()
{
    if (isEmpty())
    {
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    node *delNp = cursor;
    if (delNp == delNp->nextNp)
    {
        len = 0;
        cursor = nullptr;
    }
    else
    {
        len--;
        cursor = delNp->prevNp;
        cursor->nextNp = delNp->nextNp;
        delNp->nextNp->prevNp = cursor;
    }
    delete delNp;
}
bool deque::isEmpty()
{
    return (cursor == nullptr);
}
const Elem &deque::front(void)
{
    return cursor->nextNp->element;
}
const Elem &deque::back(void)
{
    return cursor->element;
}
int deque::size(void)
{
    return len;
};

ostream &operator<<(ostream &os, const deque &list)
{
    if (list.cursor == nullptr)
    {
        os << "ERROR: Cannot print. The list is empty." << std::endl;
        return os;
    }

    node *start = list.cursor->nextNp;
    node *finish = list.cursor;
    node *current = start;

    os << "Forward hopping: ";
    while (current != finish)
    {
        os << current->element << "->";
        current = current->nextNp;
    }
    os << current->element << "*\n";

    start = list.cursor->prevNp;
    finish = list.cursor;
    current = start;

    os << "Backward hopping: ";
    while (current != finish)
    {
        os << current->element << "->";
        current = current->prevNp;
    }
    os << current->element << "*\n";

    return os;
}
int main()
{
    deque playList;

    std::cout << "insertFront(SA)" << std::endl;
    playList.insertFront("SA");
    std::cout << playList << std::endl;

    std::cout << "insertBack(LF)" << std::endl;
    playList.insertBack("LF");
    std::cout << playList << std::endl;

    std::cout << "insertBack(JT)" << std::endl;
    playList.insertBack("JT");
    std::cout << playList << std::endl;

    std::cout << "removeBack()" << std::endl;
    playList.removeBack();
    std::cout << playList << std::endl;

    std::cout << "insertFront(DI)" << std::endl;
    playList.insertFront("DI");
    std::cout << playList << std::endl;

    std::cout << "removeFront()" << std::endl;
    playList.removeFront();
    std::cout << playList << std::endl;

    std::cout << "removeFront()" << std::endl;
    playList.removeFront();
    std::cout << playList << std::endl;

    std::cout << "removeFront()" << std::endl;
    playList.removeFront();
    std::cout << playList << std::endl;

    std::cout << "removeBack()" << std::endl;
    playList.removeBack();
    std::cout << playList << std::endl;

    return EXIT_SUCCESS;
}