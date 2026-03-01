/*
 * File: CDList.hpp
 * Description: Implementation of a circular doubly linked list.
 * Provides functionality to add, remove, and navigate nodes.
 * Provides << to print all of members in list
 * Author: Electronics03
 */
#ifndef CDLIST_H
#define CDLIST_H

#include <iostream>
#include <string>

using std::ostream;
using std::string;
typedef string Elem;

// Node structure for circular doubly linked list
typedef struct CDNode
{
    CDNode *prevNp; // Pointer to previous node
    Elem element;   // Data element
    CDNode *nextNp; // Pointer to next node
} CDNode;

// Circular doubly linked list class
class CDList
{
private:
    CDNode *cursor; // Pointer to current cursor node

public:
    CDList();            // Constructor
    ~CDList();           // Destructor
    void add(Elem data); // Add node after cursor
    void remove();       // Remove node after cursor
    friend ostream &operator<<(
        ostream &os,
        const CDList &list); // Output operator
    bool isEmpty();          // Check if list is empty
    void forward();          // Move cursor forward
    void backward();         // Move cursor backward
};
#endif