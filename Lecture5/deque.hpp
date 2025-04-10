#include <iostream>
#include <string>

using std::ostream;
using std::string;

typedef string Elem;

typedef struct node
{
    node *prevNp;
    Elem element;
    node *nextNp;
} node;

class deque
{
private:
    node *cursor;
    int len;

public:
    deque();
    ~deque();

    int size(void);
    bool isEmpty(void);

    const Elem &front(void);
    const Elem &back(void);

    void insertFront(const Elem &data);
    void insertBack(const Elem &data);

    void removeFront();
    void removeBack();

    friend ostream &operator<<(ostream &os, const deque &list);
};