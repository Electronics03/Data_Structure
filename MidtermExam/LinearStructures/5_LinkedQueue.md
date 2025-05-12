# LinkedQueue

FIFO 먼저 들어간것이 먼저 나온다.

## 기본 구조
### `LinkedQueue`

```cpp
class LinkedQueue
{
public:
    LinkedQueue();
    ~LinkedQueue();

    int size(void) const;
    bool empty(void) const;

    const Elem &front(void) const;

    void enqueue(const Elem &e);
    void dequeue(void);

private:
    CLinkedList C;
    int n;
};
```
- `C`: CircularlyLinkedList를 바탕으로 큐를 구현
- `n`: 큐에 저장된 데이터 갯수를 저장
- `LinkedQueue()`: 생성자
- `~LinkedQueue()`: 소멸자
- `int size(void) const`: 큐에 들어있는 데이터 갯수를 반환 
- `bool empty(void) const`: 비어있는지 확인
- `const Elem &front(void) const`: 맨 앞의 노드의 데이터 확인
- `void enqueue(const Elem &e)`: 맨 뒤에 새 노드를 추가
- `void dequeue(void)`: 맨 앞의 노드를 삭제

## 메인 로직
### front
```cpp
const Elem &LinkedQueue::front(void) const
{
    if (empty())
        throw QueueError("Error: Queue is empty.");
    return C.front();
}
```
- 비어있다면 예외처리한다.
- CircularlyLinkedList의 `front`를 이용한다.

### enqueue
```cpp
void LinkedQueue::enqueue(const Elem &e)
{
    C.add(e);
    C.advance();
    n++;
}
```
- CircularlyLinkedList의 `add`를 이용한다.
- 커서가 마지막에 추가한 노드를 가리키도록 `advance`한다.
- n을 하나 증가시킨다.

### dequeue
```cpp
void LinkedQueue::dequeue(void)
{
    if (empty())
        throw QueueError("Error: Queue is empty.");
    C.remove();
    n--;
}
```
- 비어있다면 예외처리한다.
- CircularlyLinkedList의 `remove`를 이용한다.
- n을 하나 감소시킨다.

## 코드
```cpp
#include <iostream>
#include <string>
#include "CircularlyLinkedList.h"
#include "DataError.h"

class LinkedQueue
{
public:
    LinkedQueue();
    ~LinkedQueue();

    int size(void) const;
    bool empty(void) const;

    const Elem &front(void) const;

    void enqueue(const Elem &e);
    void dequeue(void);

private:
    CLinkedList C;
    int n;
};
LinkedQueue::LinkedQueue() : C(), n(0) {}
LinkedQueue::~LinkedQueue() {}

int LinkedQueue::size(void) const { return n; }
bool LinkedQueue::empty(void) const { return n == 0; }

const Elem &LinkedQueue::front(void) const
{
    if (empty())
        throw QueueError("Error: Queue is empty.");
    return C.front();
}

void LinkedQueue::enqueue(const Elem &e)
{
    C.add(e);
    C.advance();
    n++;
}
void LinkedQueue::dequeue(void)
{
    if (empty())
        throw QueueError("Error: Queue is empty.");
    C.remove();
    n--;
}
```