# Iterator

## Code
### Class
```cpp
typedef struct Node
{
    Node *prevNp;
    Data element;
    Node *nextNp;
} Node;

class DLinkedList
{
private:
    int n;
    Node *header;
    Node *trailer;

public:
    class Iterator
    {
    private:
        Node *v;
        Iterator(Node *u);

    public:
        Data &operator*();
        bool operator==(const Iterator &p) const;
        bool operator!=(const Iterator &p) const;
        Iterator &operator++(void);
        Iterator &operator--(void);
        friend class DLinkedList;
    };

public:
    DLinkedList();
    ~DLinkedList();

    int size(void);
    bool isEmpty(void) const;

    Iterator begin() const;
    Iterator end() const;

    const Data &peekFront(void);
    const Data &peekBack(void);

    void insert(const Iterator &p, const Data &elem);
    void insertFront(const Data &elem);
    void insertBack(const Data &elem);

    void erase(const Iterator &p);
    void eraseFront(void);
    void eraseBack(void);

    friend ostream &operator<<(ostream &os, const DLinkedList &list);
};
```

### 구현
```cpp
DLinkedList::DLinkedList()
{
    n = 0;
    header = new Node;
    trailer = new Node;
    header->nextNp = trailer;
    header->prevNp = nullptr;
    trailer->nextNp = nullptr;
    trailer->prevNp = header;
}
DLinkedList::~DLinkedList()
{
    while (!isEmpty())
        eraseFront();
    delete header;
    delete trailer;
}
int DLinkedList::size(void)
{
    return n;
}
bool DLinkedList::isEmpty(void) const
{
    return (header->nextNp == trailer);
}
DLinkedList::Iterator DLinkedList::begin() const
{
    return Iterator(header->nextNp);
}
DLinkedList::Iterator DLinkedList::end() const
{
    return Iterator(trailer);
}
const Data &DLinkedList::peekFront(void)
{
    return header->nextNp->element;
}
const Data &DLinkedList::peekBack(void)
{
    return trailer->prevNp->element;
}
void DLinkedList::insert(const Iterator &p, const Data &elem)
{
    Node *w = p.v;
    Node *u = w->prevNp;

    Node *newNp = new Node;

    newNp->element = elem;
    newNp->nextNp = w;
    newNp->prevNp = u;

    u->nextNp = newNp;
    w->prevNp = newNp;

    n++;
}
void DLinkedList::insertFront(const Data &elem)
{
    insert(begin(), elem);
    return;
}
void DLinkedList::insertBack(const Data &elem)
{
    insert(end(), elem);
    return;
}

void DLinkedList::erase(const Iterator &p)
{
    if (isEmpty())
    {
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    Node *v = p.v;
    Node *w = v->nextNp;
    Node *u = v->prevNp;
    u->nextNp = w;
    w->prevNp = u;
    delete v;
    n--;
    return;
}
void DLinkedList::eraseFront(void)
{
    erase(begin());
    return;
}
void DLinkedList::eraseBack(void)
{
    erase(--end());
    return;
}
ostream &operator<<(ostream &os, const DLinkedList &list)
{
    if (list.isEmpty())
    {
        os << "ERROR: Cannot print. The list is empty." << std::endl;
        return os;
    }
    for (DLinkedList::Iterator i = list.begin(); i != --list.end(); ++i)
    {
        os << *i << "->";
    }
    os << *--list.end() << "*" << std::endl;
    return os;
}
DLinkedList::Iterator::Iterator(Node *u)
{
    v = u;
}
Data &DLinkedList::Iterator::operator*()
{
    return v->element;
}
bool DLinkedList::Iterator::operator==(const Iterator &p) const
{
    return v == p.v;
}
bool DLinkedList::Iterator::operator!=(const Iterator &p) const
{
    return v != p.v;
}
DLinkedList::Iterator &DLinkedList::Iterator::operator++(void)
{
    v = v->nextNp;
    return *this;
}
DLinkedList::Iterator &DLinkedList::Iterator::operator--(void)
{
    v = v->prevNp;
    return *this;
}
```

### main
```cpp
int main()
{
    DLinkedList playList;

    std::cout << "insertFront(SA)" << std::endl;
    playList.insertFront("SA");
    std::cout << playList << std::endl;

    std::cout << "insertFront(LF)" << std::endl;
    playList.insertFront("LF");
    std::cout << playList << std::endl;

    std::cout << "insertBack(JT)" << std::endl;
    playList.insertBack("JT");
    std::cout << playList << std::endl;

    std::cout << "eraseFront()" << std::endl;
    playList.eraseFront();
    std::cout << playList << std::endl;

    std::cout << "insertBack(DI)" << std::endl;
    playList.insertBack("DI");
    std::cout << playList << std::endl;

    std::cout << "eraseFront()" << std::endl;
    playList.eraseFront();
    std::cout << playList << std::endl;

    std::cout << "eraseBack()" << std::endl;
    playList.eraseBack();
    std::cout << playList << std::endl;

    std::cout << "eraseBack()" << std::endl;
    playList.eraseBack();
    std::cout << playList << std::endl;

    std::cout << "eraseBack()" << std::endl;
    playList.eraseBack();
    std::cout << playList << std::endl;

    getchar();

    return EXIT_SUCCESS;
}
```

### 출력
```
insertFront(SA)
SA*

insertFront(LF)
LF->SA*

insertBack(JT)
LF->SA->JT*

eraseFront()
SA->JT*

insertBack(DI)
SA->JT->DI*

eraseFront()
JT->DI*

eraseBack()
JT*

eraseBack()
ERROR: Cannot print. The list is empty.

eraseBack()
ERROR: Cannot remove from an empty list.
ERROR: Cannot print. The list is empty.
```