#ifndef CDLIST_H
#define CDLIST_H

#include <iostream>
#include <string>

using std::ostream;
using std::string;

typedef string Elem;

typedef struct CDNode
{
    CDNode *prevNp;
    Elem element;
    CDNode *nextNp;
} CDNode;

class CDList
{
private:
    CDNode *cursor;

public:
    CDList();
    ~CDList();

    void add(Elem data);
    void remove();

    friend ostream &operator<<(ostream &os, const CDList &list);

    bool isEmpty();

    void forward();
    void backward();
};

#endif