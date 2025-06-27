/*
 * File: CDList.cpp
 * Description: Implementation of a circular doubly linked list.
 * Provides functionality to add, remove, and navigate nodes.
 * Provides << to print all of members in list
 * Author: Electronics03
 */
#include "CDList.h"

// Constructor: initializes an empty list
CDList::CDList() : cursor(nullptr) {}
// Destructor: deletes all nodes in the list
CDList::~CDList()
{
    while (!isEmpty())
        remove();
}
// Adds a new node after the cursor
void CDList::add(Elem data)
{
    CDNode *newNp = new CDNode; // new-Node
    newNp->element = data;
    if (isEmpty())
    {
        // if list is Empty all pointer point new-Node
        // cursor -> new-Node
        // new-Node.next -> new-Node
        // new-Node.prev -> new-Node
        cursor = newNp;
        cursor->nextNp = cursor;
        cursor->prevNp = cursor;
    }
    else
    {
        // Insert new-Node between cursor and cursor->nextNp
        // cuser <=> new-Node <=> cuser-next
        newNp->nextNp = cursor->nextNp;
        newNp->prevNp = cursor;
        cursor->nextNp = cursor->nextNp->prevNp = newNp;
    }
}
// Removes the node after the cursor
void CDList::remove()
{
    if (isEmpty())
    {
        // Error messege
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    // del-Node
    CDNode *delNp = cursor->nextNp;
    if (delNp == cursor)
    {
        // if list has one element
        // 1 -> 0 elememt
        cursor = nullptr;
    }
    else
    {
        // Remove del-Node from the list
        // cursor <-> del-Node <-> after
        // cursor <-> after
        delNp->nextNp->prevNp = cursor;
        cursor->nextNp = delNp->nextNp;
    }
    delete delNp;
}
// Returns true if the list is empty
bool CDList::isEmpty()
{
    return (cursor == nullptr);
}
// Moves the cursor forward
void CDList::forward()
{
    cursor = cursor->nextNp;
}
// Moves the cursor backward
void CDList::backward()
{
    cursor = cursor->prevNp;
}
// Overloads << operator to print the list in both directions
ostream &operator<<(ostream &os, const CDList &list)
{
    if (list.cursor == nullptr)
    {
        os << "ERROR: Cannot print. The list is empty." << std::endl;
        return os;
    }

    // Forward directiom travle from cursor->next to cursor
    CDNode *start = list.cursor->nextNp;
    CDNode *finish = list.cursor;
    CDNode *current = start;
    os << "Forward hopping: ";
    while (current != finish)
    {
        os << current->element << "->";
        current = current->nextNp;
    }
    os << current->element << "*\n"; // cursor is marked *

    // Backward directiom travle from cursor->prev to cursor
    start = list.cursor->prevNp;
    finish = list.cursor;
    current = start;
    os << "Backward hopping: ";
    while (current != finish)
    {
        os << current->element << "->";
        current = current->prevNp;
    }
    os << current->element << "*\n"; // cursor is marked *

    return os;
}