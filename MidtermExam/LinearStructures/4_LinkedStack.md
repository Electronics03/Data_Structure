# LinkedStack

LIFO 나중에 들어간것이 먼저 나온다.

## 기본 구조
### `LinkedStack`

```cpp
class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();

    int size(void) const;
    bool empty(void) const;
    const Elem &top(void) const;
    void pop(void);
    void push(const Elem &e);

private:
    SLinkedList S;
    int n;
};
```
- `S`: SinglyLinkedList를 바탕으로 스택을 구현
- `n`: 스택에 저장된 데이터의 갯수를 저장
- `LinkedStack()`: 생성자
- `~LinkedStack()`: 소멸자
- `int size(void) const`: 스택에 들어있는 데이터 갯수를 반환 
- `bool empty(void) const`: 비어있는지 확인
- `const Elem &top(void) const`: 맨 앞의 노드의 데이터 확인
- `void push(const Elem &e)`: 맨 앞에 새 노드를 추가
- `void pop(void)`: 맨 앞의 노드를 삭제

## 메인 로직
### top
```cpp
const Elem &LinkedStack::top(void) const
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    return S.front();
}
```
- 비어있다면 예외처리한다.
- SinglyLinkedList의 `front`를 이용한다.

### push
```cpp
void LinkedStack::push(const Elem &e)
{
    S.addFront(e);
    n++;
}
```
- SinglyLinkedList의 `addFront`를 이용한다.
- n을 하나 증가시킨다.

### pop
```cpp
void LinkedStack::pop(void)
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    S.removeFront();
    n--;
}
```
- 비어있다면 예외처리한다.
- SinglyLinkedList의 `removeFront`를 이용한다.
- n을 하나 감소시킨다.

## 코드
```cpp
#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "DataError.h"

class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();

    int size(void) const;
    bool empty(void) const;
    const Elem &top(void) const;
    void pop(void);
    void push(const Elem &e);

private:
    SLinkedList S;
    int n;
};
LinkedStack::LinkedStack() : S(), n(0) {}
LinkedStack::~LinkedStack() {}

int LinkedStack::size(void) const { return n; }

bool LinkedStack::empty(void) const { return n == 0; }
const Elem &LinkedStack::top(void) const
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    return S.front();
}
void LinkedStack::pop(void)
{
    if (empty())
        throw StackError("Error: Stack is empty.");
    S.removeFront();
    n--;
}
void LinkedStack::push(const Elem &e)
{
    S.addFront(e);
    n++;
}
```