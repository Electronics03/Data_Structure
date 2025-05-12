# DoublyLinkedList

다음 노드의 주소뿐만 아니라 이전 노드의 주소를 통해 앞뒤 모두 접근할 수 있는 리스트 자료구조이다.

## 기본 구조
### 노드
```cpp
class Node
{
private:
    Elem elem;
    Node *next;
    Node *prev;
    friend class DLinkedList;
};
```
- `Node`는 데이터인 `elem`을 담고 있다.
- 다음 노드의 주소인 `next`를 담고 있다.
- 이전 노드의 주소인 `prev`를 담고 있다.
- `DLinkedList`에서 멤버에 접근할 수 있도록 한다.

### `DLinkedList`

```cpp
class DLinkedList
{
public:
    DLinkedList();
    ~DLinkedList();

    bool empty(void) const;
    const Elem &front(void) const;
    const Elem &back(void) const;

    void addFront(const Elem &elem);
    void removeFront(void);

    void addBack(const Elem &elem);
    void removeBack(void);

private:
    Node *header;
    Node *trailer;

protected:
    void add(Node *v, const Elem &elem);
    void remove(Node *v);
};
```
- `header`는 더미 노드로 맨 앞 노드의 앞에 위치한다.
- `trailer`는 더미 노드로 맨 뒤 노드의 뒤에 위치한다.
- `DLinkedList()`: 생성자
- `~DLinkedList()`: 소멸자
- `bool empty(void) const`: 비어있는지 확인
- `const Elem &front(void) const`: 맨 앞의 노드의 데이터 확인
- `const Elem &back(void) const`: 맨 뒤의 노드의 데이터 확인
- `void addFront(const Elem &elem)`: 맨 앞에 노드 추가
- `void removeFront(void)`: 맨 앞의 노드 제거
- `void addBack(const Elem &elem)`: 맨 뒤에 노드 추가
- `void removeBack(void)`: 맨 뒤의 노드 제거
- `void add(Node *v, const Elem &elem)`: `v`가 가리키는 노드의 앞에 새 노드를 삽입
- `void remove(Node *v)`: `v`가 가리키는 노드 삭제

## 메인 로직
### 생성
```cpp
DLinkedList::DLinkedList()
{
    header = new Node;
    trailer = new Node;

    header->next = trailer;
    trailer->prev = header;
}
```
- `header`와 `trailer`는 더미 노드이므로 할당해주어야 한다.
- 서로를 가리키도록 초기화 함

### 소멸
```cpp
DLinkedList::~DLinkedList()
{
    while (!empty())
        removeFront();
    delete header;
    delete trailer;
    return;
}
```
- `header`와 `trailer`는 더미 노드이므로 할당해제 해야한다.

### 삽입
```cpp
void DLinkedList::add(Node *v, const Elem &elem)
{
    Node *u = new Node;
    u->elem = elem;
    u->prev = v->prev;
    u->next = v;
    v->prev->next = u;
    v->prev = u;
}
```
- `v`가 가리키는 노드 앞에 삽입해야 한다.
- 새 노드 할당 `u`
- 먼저 데이터 초기화 `u->elem = elem;`
- 이전 노드를 `v`의 이전 노드로 설정 `u->prev = v->prev;`
- 다음 노드를 `v`가 가리키는 노드로 설정 `u->next = v;`
- `v`이전노드의 다음을 새 노드로 설정
- `v`의 이전노드를 새 노드로 설정

### 삭제
```cpp
void DLinkedList::remove(Node *v)
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *u = v->prev;
    Node *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}
```
- `v`가 가리키는 노드를 삭제해야 한다.
- 일단 리스트가 비어있다면 예외처리 `throw ListError("Error: List is empty.");`
- 이전 노드를 `u`, 다음노드를 `v`로 설정 `Node *u = v->prev; Node *w = v->next;`
- 이전 노드의 다음을 `v`로 설정 `u->next = w;`
- 다음노드의 이전을 `u`로 설정 `w->prev = u;`
- `v`할당 해제

## 코드
```cpp
#include <cstdlib>
#include <iostream>
#include <string>
#include "DataError.h"

using Elem = std::string;

class Node
{
private:
    Elem elem;
    Node *next;
    Node *prev;
    friend class DLinkedList;
};

class DLinkedList
{
public:
    DLinkedList();
    ~DLinkedList();

    bool empty(void) const;
    const Elem &front(void) const;
    const Elem &back(void) const;

    void addFront(const Elem &elem);
    void removeFront(void);

    void addBack(const Elem &elem);
    void removeBack(void);

private:
    Node *header;
    Node *trailer;

protected:
    void add(Node *v, const Elem &elem);
    void remove(Node *v);
};

DLinkedList::DLinkedList()
{
    header = new Node;
    trailer = new Node;

    header->next = trailer;
    trailer->prev = header;
}
DLinkedList::~DLinkedList()
{
    while (!empty())
        removeFront();
    delete header;
    delete trailer;
    return;
}

bool DLinkedList::empty(void) const
{
    return (header->next == trailer);
}
const Elem &DLinkedList::front(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return header->next->elem;
}
const Elem &DLinkedList::back(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return trailer->prev->elem;
}

void DLinkedList::addFront(const Elem &elem)
{
    add(header->next, elem);
}
void DLinkedList::removeFront(void)
{
    remove(header->next);
}

void DLinkedList::addBack(const Elem &elem)
{
    add(trailer, elem);
}
void DLinkedList::removeBack(void)
{
    remove(trailer->prev);
}

void DLinkedList::add(Node *v, const Elem &elem)
{
    Node *u = new Node;
    u->elem = elem;
    u->prev = v->prev;
    u->next = v;
    v->prev->next = u;
    v->prev = u;
}
void DLinkedList::remove(Node *v)
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *u = v->prev;
    Node *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}
```