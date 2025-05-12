# SinglyLinkedList

가장 기본적인 리스트 자료구조이다.

## 기본 구조
### 노드
```cpp
class Node
{
private:
    Elem elem;
    Node *next;
    friend class SLinkedList;
};
```
- `Node`는 데이터인 `elem`을 담고 있다.
- 다음 노드의 주소인 `next`를 담고 있다.
- `SLinkedList`에서 멤버에 접근할 수 있도록 한다.

### `SLinkedList`

```cpp
class SLinkedList
{
public:
    SLinkedList();
    ~SLinkedList();

    bool empty(void) const;
    const Elem &front(void) const;

    void addFront(const Elem &elem);
    void removeFront(void);

private:
    Node *head;
};
```
- `head`는 첫번째 노드를 가리킨다.
- `SLinkedList()`: 생성자
- `~SLinkedList()`: 소멸자
- `bool empty(void) const`: 비어있는지 확인
- `const Elem &front(void) const`: 맨 앞의 노드의 데이터 확인
- `void addFront(const Elem &elem)`: 맨 앞에 노드 추가
- `void removeFront(void)`: 맨 앞의 노드 제거

## 메인 로직
### 삽입
```cpp
void SLinkedList::addFront(const Elem &elem)
{
    Node *newNode = new Node;
    newNode->elem = elem;
    newNode->next = head;
    head = newNode;
    return;
}
```
- `head`가 가리키는 노드 앞에 삽입해야 한다.
- 새 노드 할당
- 먼저 데이터 초기화 `newNode->elem = elem;`
- 다음 노드를 `head`가 가리키는 노드로 설정 `newNode->next = head;`
- `head`가 새노드를 가리키도록 설정

### 삭제
```cpp
void SLinkedList::removeFront(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *delNode = head;
    head = delNode->next;
    delete delNode;
}
```
- `head`가 가리키는 노드를 삭제해야 한다.
- 일단 리스트가 비어있다면 예외처리 `throw ListError("Error: List is empty.");`
- 삭제할 노드를 `delNode`에 대입
- `head`가 `delNode->next`를 가리키도록 설정
- `delNode`할당 해제

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
    friend class SLinkedList;
};

class SLinkedList
{
public:
    SLinkedList();
    ~SLinkedList();

    bool empty(void) const;
    const Elem &front(void) const;

    void addFront(const Elem &elem);
    void removeFront(void);

private:
    Node *head;
};

SLinkedList::SLinkedList() : head(nullptr) {}
SLinkedList::~SLinkedList()
{
    while (!empty())
        removeFront();
    return;
}
bool SLinkedList::empty(void) const
{
    return (head == nullptr);
}
const Elem &SLinkedList::front(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return head->elem;
}
void SLinkedList::addFront(const Elem &elem)
{
    Node *newNode = new Node;
    newNode->elem = elem;
    newNode->next = head;
    head = newNode;
    return;
}
void SLinkedList::removeFront(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *delNode = head;
    head = delNode->next;
    delete delNode;
}
```