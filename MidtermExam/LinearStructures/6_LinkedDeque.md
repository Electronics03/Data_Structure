# LinkedDeque

양단에서 접근 가능한 Double Ended Queue (DeQue)

## 기본 구조
### `LinkedDeque`

```cpp
class LinkedDeque
{
public:
    LinkedDeque();
    ~LinkedDeque();

    int size(void) const;
    bool empty(void) const;

    const Elem &front(void) const;
    const Elem &back(void) const;

    void insertFront(const Elem &e);
    void insertBack(const Elem &e);

    void removeFront(void);
    void removeBack(void);

private:
    DLinkedList D;
    int n;
};
```
- `D`: DoublyLinkedList를 바탕으로 큐를 구현
- `n`: 덱에 저장된 데이터의 갯수를 저장
- `LinkedDeque()`: 생성자
- `~LinkedDeque()`: 소멸자
- `int size(void) const`: 덱에 들어있는 데이터 갯수를 반환 
- `bool empty(void) const`: 비어있는지 확인
- `const Elem &front(void) const`: 맨 앞에 데이터 확인
- `const Elem &back(void) const`: 맨 뒤에 데이터 확인
- `oid insertFront(const Elem &e)`: 맨 앞에 노드 삽입
- `void insertBack(const Elem &e)`: 맨 뒤에 노드 삽입
- `void removeFront(void)`: 맨 앞의 노드 삭제
- `void removeBack(void)`: 맨 뒤의 노드 삭제

## 메인 로직

DoublyLinkedList와 동일한 기능을 제공한다. `LinkedDeque`가 `DLinkedList`를 감싼 형태를 하고 있다.
구현도 함수명만 변경되었고, n을 관리하는 코드가 추가되었다.

## 코드
```cpp
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "DataError.h"

class LinkedDeque
{
public:
    LinkedDeque();
    ~LinkedDeque();

    int size(void) const;
    bool empty(void) const;

    const Elem &front(void) const;
    const Elem &back(void) const;

    void insertFront(const Elem &e);
    void insertBack(const Elem &e);

    void removeFront(void);
    void removeBack(void);

private:
    DLinkedList D;
    int n;
};
LinkedDeque::LinkedDeque() : D(), n(0) {}
LinkedDeque::~LinkedDeque() {}

int LinkedDeque::size(void) const { return n; }
bool LinkedDeque::empty(void) const { return n == 0; }

const Elem &LinkedDeque::front(void) const
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    return D.front();
}
const Elem &LinkedDeque::back(void) const
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    return D.back();
}
void LinkedDeque::insertFront(const Elem &e)
{
    D.addFront(e);
    n++;
}
void LinkedDeque::insertBack(const Elem &e)
{
    D.addBack(e);
    n++;
}
void LinkedDeque::removeFront(void)
{
    if (empty())
        throw DequeError("Error: Deque is empty.");
    D.removeFront();
    n--;
}
void LinkedDeque::removeBack(void)
{
    if (empty())
        throw DequeError("Error: DequeError is empty.");
    D.removeBack();
    n--;
}
```