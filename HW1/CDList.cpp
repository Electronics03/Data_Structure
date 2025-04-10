#include "CDList.hpp"

CDList::CDList() : cursor(nullptr)
{
    ;
}
CDList::~CDList()
{
    while (!isEmpty())
    {
        remove();
    }
}
void CDList::add(Elem data)
{
    CDNode *newNp = new CDNode;
    newNp->element = data;
    if (isEmpty())
    {
        cursor = newNp;
        cursor->nextNp = cursor;
        cursor->prevNp = cursor;
    }
    else
    {
        newNp->nextNp = cursor->nextNp;
        newNp->prevNp = cursor;
        cursor->nextNp = cursor->nextNp->prevNp = newNp;
    }
}
void CDList::remove()
{
    if (isEmpty())
    {
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    CDNode *delNp = cursor->nextNp;
    if (delNp == cursor)
    {
        cursor = nullptr;
    }
    else
    {
        delNp->nextNp->prevNp = cursor;
        cursor->nextNp = delNp->nextNp;
    }
    delete delNp;
}

bool CDList::isEmpty()
{
    return (cursor == nullptr);
}

void CDList::forward()
{
    cursor = cursor->nextNp;
}
void CDList::backward()
{
    cursor = cursor->prevNp;
}

ostream &operator<<(ostream &os, const CDList &list)
{
    if (list.cursor == nullptr)
    {
        os << "ERROR: Cannot print. The list is empty." << std::endl;
        return os;
    }

    CDNode *start = list.cursor->nextNp;
    CDNode *finish = list.cursor;
    CDNode *current = start;

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