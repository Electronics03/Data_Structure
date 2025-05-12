# CircularlyLinkedList

마지막 노드의 다음을 첫 노드로 하여 원형 구조를 만들도록 하는 리스트 자료구조이다.

## 기본 구조
### 노드
```cpp
class Node
{
private:
    Elem elem;
    Node *next;
    friend class CLinkedList;
};
```
- `Node`는 데이터인 `elem`을 담고 있다.
- 다음 노드의 주소인 `next`를 담고 있다.
- `CLinkedList`에서 멤버에 접근할 수 있도록 한다.

### `CLinkedList`

```cpp
class CLinkedList
{
public:
    CLinkedList();
    ~CLinkedList();

    bool empty(void) const;

    const Elem &front(void) const;
    const Elem &back(void) const;

    void advance(void);
    void add(const Elem &e);
    void remove(void);

private:
    Node *cursor;
};
```
- `cursor`는 마지막 노드를 가리킨다.
- `CLinkedList()`: 생성자
- `~CLinkedList()`: 소멸자
- `bool empty(void) const`: 비어있는지 확인
- `const Elem &front(void) const`: 맨 앞의 노드의 데이터 확인
- `const Elem &back(void) const`: 맨 뒤의 노드의 데이터 확인
- `void advance(void);`: 커서가 가리키는 노드를 다음으로 변경
- `void add(const Elem &e)`: 커서 다음에 새 노드를 삽입
- `void remove(void)`: 커서 다음의 노드 삭제

## 메인 로직
### 삽입
```cpp
void CLinkedList::add(const Elem &e)
{
    Node *v = new Node;
    v->elem = e;

    if (empty())
    {
        v->next = v;
        cursor = v;
    }
    else
    {
        v->next = cursor->next;
        cursor->next = v;
    }
}
```
- 커서 앞에 삽입해야 한다.
- 새 노드 할당 `v`
- 먼저 데이터 초기화 `v->elem = elem;`
- 만약 비어있다면...
    - `next`가 자기 자신을 가리키도록 함 `v->next = v;`
    - 커서가 새 노드를 가리키도록 `cursor = v;`
- 비어있지 않다면...
    - 다음 노드를 커서의 다음으로 설정 `v->next = cursor->next;`
    - 커서의 다음을 새 노드로 설정 `cursor->next = v;`

### 삭제
```cpp
void CLinkedList::remove(void)
{
    if (empty())
        throw ListError("Error: List is empty.");

    Node *delNode = cursor->next;

    if (delNode == cursor)
        cursor = nullptr;
    else
        cursor->next = delNode->next;

    delete delNode;
}
```
- 커서 다음의 노드를 삭제해야 한다.
- 일단 리스트가 비어있다면 예외처리 `throw ListError("Error: List is empty.");`
- 삭제할 노드를 `delNode`에 대입한다
- 만약 노드가 하나 남았다면...
    - 커서를 비운다 `cursor = nullptr;`
- 아니라면...
    - 커서의 다음을 다음 다음으로 변경 `cursor->next = delNode->next;`
- 삭제노드 할당 해제 `delete delNode;`

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
    friend class CLinkedList;
};

class CLinkedList
{
public:
    CLinkedList();
    ~CLinkedList();

    bool empty(void) const;

    const Elem &front(void) const;
    const Elem &back(void) const;

    void advance(void);
    void add(const Elem &e);
    void remove(void);

private:
    Node *cursor;
};

CLinkedList::CLinkedList() : cursor(nullptr) {}
CLinkedList::~CLinkedList()
{
    while (!empty())
        remove();
    return;
}
bool CLinkedList::empty(void) const
{
    return (cursor == nullptr);
}
const Elem &CLinkedList::front(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return (cursor->next->elem);
}
const Elem &CLinkedList::back(void) const
{
    if (empty())
        throw ListError("Error: List is empty.");
    return (cursor->elem);
}
void CLinkedList::advance(void)
{
    if (empty())
        throw ListError("Error: List is empty.");
    cursor = cursor->next;
}
void CLinkedList::add(const Elem &e)
{
    Node *v = new Node;
    v->elem = e;

    if (empty())
    {
        v->next = v;
        cursor = v;
    }
    else
    {
        v->next = cursor->next;
        cursor->next = v;
    }
}
void CLinkedList::remove(void)
{
    if (empty())
        throw ListError("Error: List is empty.");

    Node *delNode = cursor->next;

    if (delNode == cursor)
        cursor = nullptr;
    else
        cursor->next = delNode->next;

    delete delNode;
}
```