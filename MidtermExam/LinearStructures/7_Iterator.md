# Iterator

쉽게 데이터에 접근할 수 있도록 Itertor을 제공할 수 있다.
사용자는 `header`나 `trailer`의 위치를 몰라도 함수로 접근 가능.
연산자 오버로딩을 통하여 쉬운 데이터 접근과 위치를 변경 가능

## 기본 구조

### 노드
```cpp
class Node
{
private:
    Elem elem;
    Node *prev;
    Node *next;
    friend class Iterator;
    friend class Nodelist;
};
```
- `Node`는 데이터인 `elem`을 담고 있다.
- 다음 노드의 주소인 `next`를 담고 있다.
- 이전 노드의 주소인 `prev`를 담고 있다.
- `Iterator`와 `Nodelist`에서 멤버에 접근할 수 있도록 한다.

### `Iterator`
```cpp
class Iterator
{
private:
    Node *presNode;
    Iterator(Node *newNode);

public:
    Elem &operator*();
    bool operator==(const Iterator &point) const;
    bool operator!=(const Iterator &point) const;
    Iterator &operator++(void);
    Iterator &operator--(void);
    friend class Nodelist;
};
```

### `Nodelist`
```cpp
class Nodelist
{
private:
    class Node
    {
        ...
    };

public:
    class Iterator
    {
        ...
    };

public:
    Nodelist();
    ~Nodelist();

    int size(void);
    bool empty(void) const;

    Iterator begin() const;
    Iterator end() const;

    void insert(const Iterator &point, const Elem &elem);
    void insertFront(const Elem &elem);
    void insertBack(const Elem &elem);

    void erase(const Iterator &point);
    void eraseFront(void);
    void eraseBack(void);

private:
    Node *header;
    Node *trailer;
    int n;
};
```


## 코드
```cpp
#include <cstdlib>
#include <iostream>
#include <string>
#include "DataError.h"

using Elem = std::string;

class Nodelist
{
private:
    class Node
    {
    private:
        Elem elem;
        Node *prev;
        Node *next;
        friend class Iterator;
        friend class Nodelist;
    };

public:
    class Iterator
    {
    private:
        Node *presNode;
        Iterator(Node *newNode);

    public:
        Elem &operator*();
        bool operator==(const Iterator &point) const;
        bool operator!=(const Iterator &point) const;
        Iterator &operator++(void);
        Iterator &operator--(void);
        friend class Nodelist;
    };

public:
    Nodelist();
    ~Nodelist();

    int size(void);
    bool empty(void) const;

    Iterator begin() const;
    Iterator end() const;

    void insert(const Iterator &point, const Elem &elem);
    void insertFront(const Elem &elem);
    void insertBack(const Elem &elem);

    void erase(const Iterator &point);
    void eraseFront(void);
    void eraseBack(void);

private:
    Node *header;
    Node *trailer;
    int n;
};

Nodelist::Iterator::Iterator(Nodelist::Node *newNode) : presNode(newNode) {}
Elem &Nodelist::Iterator::operator*()
{
    return presNode->elem;
}
bool Nodelist::Iterator::operator==(const Iterator &point) const
{
    return point.presNode == presNode;
}
bool Nodelist::Iterator::operator!=(const Iterator &point) const
{
    return point.presNode != presNode;
}
Nodelist::Iterator &Nodelist::Iterator::operator++(void)
{
    presNode = presNode->next;
    return *this;
}
Nodelist::Iterator &Nodelist::Iterator::operator--(void)
{
    presNode = presNode->prev;
    return *this;
}

Nodelist::Nodelist() : n(0)
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}
Nodelist::~Nodelist()
{
    while (empty())
        eraseFront();
    delete header;
    delete trailer;
}
void Nodelist::insert(const Iterator &point, const Elem &elem)
{
    Node *presNode = point.presNode;
    Node *prevNode = point.presNode->prev;
    Node *newNode = new Node;

    newNode->elem = elem;
    newNode->next = presNode;
    newNode->prev = prevNode;

    prevNode->next = newNode;
    presNode->prev = newNode;
    n++;
}
void Nodelist::erase(const Iterator &point)
{
    Node *delNode = point.presNode;
    Node *prevNode = delNode->prev;
    Node *nextNode = delNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete delNode;
    n--;
}
int Nodelist::size(void)
{
    return n;
}
bool Nodelist::empty(void) const
{
    return header->next == trailer;
}
Nodelist::Iterator Nodelist::begin() const
{
    return Iterator(header->next);
}
Nodelist::Iterator Nodelist::end() const
{
    return Iterator(trailer);
}
void Nodelist::insertFront(const Elem &elem)
{
    insert(begin(), elem);
}
void Nodelist::insertBack(const Elem &elem)
{
    insert(end(), elem);
}
void Nodelist::eraseFront(void)
{
    erase(begin());
}
void Nodelist::eraseBack(void)
{
    erase(--end());
}
```