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
- `presNode`: Iterator가 저장하고 있는 현재 노드 위치 `Nodelist`에서 접근 가능하다.
- `Iterator(Node *newNode)`: Iterator 복사 생성자. 이 함수로만 생성 가능하다.
- `Elem &operator*()`: Iterator가 가리키는 노드의 데이터를 반환
- `bool operator==(const Iterator &point) const`: Iterator가 같은지 검사
- `bool operator!=(const Iterator &point) const`: Iterator가 다른지 검사
- `Iterator &operator++(void)`: Iterator의 노드를 다음 노드로 변경
- `Iterator &operator--(void)`: Iterator의 노드를 이전 노드로 변경

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
- `header`는 더미 노드로 맨 앞 노드의 앞에 위치한다.
- `trailer`는 더미 노드로 맨 뒤 노드의 뒤에 위치한다.
- `n`: 리스트에 저장된 데이터 갯수를 저장
- `Nodelist()`: 생성자
- `~Nodelist()`: 소멸자
- `int size(void)`: 리스트의 크기를 반환
- `bool empty(void) const`: 리스트가 비어있는지 확인
- `Iterator begin() const`: 첫 노드(헤더의 다음)를 가리키는 Iterator 반환
- `Iterator end() const`: 마지막 노드(트레일러의 이전)를 가리키는 Iterator 반환
- `void insert(const Iterator &point, const Elem &elem)`: Iterator의 이전 위치에 삽입
- `void insertFront(const Elem &elem)`: 맨 앞에 삽입
- `void insertBack(const Elem &elem)`: 맨 뒤에 삽입
- `void erase(const Iterator &point)`: Iterator위치의 노드 삭제
- `void eraseFront(void)`: 맨 앞의 노드 삭제
- `void eraseBack(void)`: 맨 뒤의 노드 삭제

## 메인 로직
### `Iterator`
```cpp
Nodelist::Iterator::Iterator(Nodelist::Node *newNode) : presNode(newNode) {}
```
- `Iterator` 복사 생성자
- 이 함수만으로 생성 가능한데, 이 함수는 `private`이므로 외부에서 접근이 불가
- `begin()`과 `end()`등 만 `Iterator`를 생성 가능하다.
- `presNode`를 `newNode`로 초기화

### `operator*`
```cpp
Elem &Nodelist::Iterator::operator*()
{
    return presNode->elem;
}
```
- `*`연산자 오버로딩을 통해 `Iterator`가 가리키는 값에 접근 `presNode->elem;`
- 레퍼런스를 통해 값에 접근 및 변경이 가능하도록 함

### `operator==`
```cpp
bool Nodelist::Iterator::operator==(const Iterator &point) const
{
    return point.presNode == presNode;
}
```
- 두 `Iterator`가 같은지 검사한다.
- 입력받은 `Iterator`와 비교 `point.presNode == presNode;`

### `operator!=`
```cpp
bool Nodelist::Iterator::operator!=(const Iterator &point) const
{
    return point.presNode != presNode;
}
```
- 두 `Iterator`가 다른지 검사한다.
- 입력받은 `Iterator`와 비교 `point.presNode == presNode;`

### `operator++`
```cpp
Nodelist::Iterator &Nodelist::Iterator::operator++(void)
{
    presNode = presNode->next;
    return *this;
}
```
- 다음 노드로 이동
- `*this`로 자기 자신을 반환한다.


### `operator--`
```cpp
Nodelist::Iterator &Nodelist::Iterator::operator--(void)
{
    presNode = presNode->prev;
    return *this;
}
```
- 이전 노드로 이동
- `*this`로 자기 자신을 반환한다.


### `Nodelist`
```cpp
Nodelist::Nodelist() : n(0)
{
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}
```
- `header`와 `trailer`는 더미 노드이므로 할당해주어야 한다.
- 서로를 가리키도록 초기화 함


### `~Nodelist`
```cpp
Nodelist::~Nodelist()
{
    while (empty())
        eraseFront();
    delete header;
    delete trailer;
}
```
- `header`와 `trailer`는 더미 노드이므로 할당해제 해야한다.


### `insert`
```cpp
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
```
- `point`가 가리키는 노드 앞에 삽입해야 한다.
- `point`가 가리키는 노드를 `presNode`로 선언
- 이전 노드를 `prevNode`로 선언
- 새 노드 할당 `newNode`
- 먼저 데이터 초기화 `newNode->elem = elem;`
- 이전 노드를 `prevNode`로 설정 `newNode->prev = prevNode;`
- 다음 노드를 `presNode`로 설정 `newNode->next = presNode;`
- `prevNode`의 다음을 새 노드로 설정
- `presNode`의 이전노드를 새 노드로 설정

### `erase`
```cpp
void Nodelist::erase(const Iterator &point)
{
    if (empty())
        throw ListError("Error: List is empty.");
    Node *delNode = point.presNode;
    Node *prevNode = delNode->prev;
    Node *nextNode = delNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete delNode;
    n--;
}
```
- `point`가 가리키는 노드를 삭제해야 한다.
- 일단 리스트가 비어있다면 예외처리 `throw ListError("Error: List is empty.");`
- 삭제할 노드를 `delNode`로 선언
- 이전 노드를 `prevNode`, 다음노드를 `nextNode`로 설정
- 이전 노드의 다음을 `nextNode`로 설정 `prevNode->next = nextNode;`
- 다음 노드의 이전을 `prevNode`로 설정 `nextNode->prev = prevNode;`
- `delNode`할당 해제

### `begin`
```cpp
Nodelist::Iterator Nodelist::begin() const
{
    return Iterator(header->next);
}
```
- 첫 노드(헤더 다음)을 가리키는 `Iterator` 생성후 반환

### `end`
```cpp
Nodelist::Iterator Nodelist::end() const
{
    return Iterator(trailer);
}
```
- 마지막 노드 다음(트레일러)을 가리키는 `Iterator` 생성후 반환

### `insertFront`
```cpp
void Nodelist::insertFront(const Elem &elem)
{
    insert(begin(), elem);
}
```
- 맨 앞에 노드를 추가해야 한다.
- 헤더 다음 위치를 반환하는 `begin()`을 사용
- `begin()`앞에 새 노드가 추가된다.

### `insertBack`
```cpp
void Nodelist::insertBack(const Elem &elem)
{
    insert(end(), elem);
}
```
- 맨 뒤에 노드를 추가해야 한다.
- 트레일러 위치를 반환하는 `end()`을 사용
- `end()`앞에 새 노드가 추가된다.

### `eraseFront`
```cpp
void Nodelist::eraseFront(void)
{
    erase(begin());
}
```
- 맨 앞의 노드를 삭제한다.
- 헤더 다음 위치를 반환하는 `begin()`을 사용
- `begin()`이 가리키는 노드가 삭제된다

### `eraseBack`
```cpp
void Nodelist::eraseBack(void)
{
    erase(--end());
}
```
- 맨 뒤의 노드를 삭제한다.
- 트레일러의 위치를 반환하는 `end()`을 사용
- `--`연산을 사용하여 `end()`의 전 노드가 삭제된다.

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