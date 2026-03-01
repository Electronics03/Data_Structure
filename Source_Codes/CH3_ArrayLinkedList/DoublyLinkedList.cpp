#include <cstdlib>  // 표준 유틸리티 함수들(ex. malloc/free 등)을 위한 헤더
#include <iostream> // 표준 입출력 스트림 사용을 위한 헤더
#include <string>   // string 클래스 사용을 위한 헤더
#include <stdexcept>

using namespace std; // std 네임스페이스 안의 모든 것을 전역에서 사용

typedef string Elem; // 문자열 타입(string)을 Elem이라는 별칭으로 정의

// Doubly Linked List의 노드 클래스 정의
class DNode
{
private:
    Elem elem;                // 노드가 저장할 데이터 (문자열)
    DNode *prev;              // 이전 노드를 가리키는 포인터
    DNode *next;              // 다음 노드를 가리키는 포인터
    friend class DLinkedList; // DLinkedList 클래스가 DNode의 private 멤버에 접근할 수 있도록 허용
};

// Doubly Linked List 클래스 정의
class DLinkedList
{
private:
    DNode *header;  // 리스트의 가장 앞(더미 헤더 노드)을 가리키는 포인터
    DNode *trailer; // 리스트의 가장 뒤(더미 트레일러 노드)를 가리키는 포인터

public:
    DLinkedList();  // 생성자: 빈 리스트 초기화
    ~DLinkedList(); // 소멸자: 모든 노드 메모리 해제

    bool empty(void) const; // 리스트가 비었는지 확인하는 함수

    const Elem &front(void); // 첫 번째 요소를 참조로 반환하는 함수
    const Elem &back(void);  // 마지막 요소를 참조로 반환하는 함수

    void addFront(const Elem &elem); // 리스트 앞에 요소를 추가하는 함수
    void addBack(const Elem &elem);  // 리스트 뒤에 요소를 추가하는 함수

    void removeFront(void); // 리스트 앞의 요소를 제거하는 함수
    void removeBack(void);  // 리스트 뒤의 요소를 제거하는 함수

protected:
    void add(DNode *nodep, const Elem &elem); // 주어진 위치 앞에 새 노드를 삽입하는 내부 함수
    void remove(DNode *nodep);                // 주어진 노드를 삭제하는 내부 함수
};

// 생성자 정의
DLinkedList::DLinkedList()
{
    header = new DNode;      // 더미 헤더 노드 생성
    trailer = new DNode;     // 더미 트레일러 노드 생성
    header->next = trailer;  // 헤더의 다음 노드를 트레일러로 설정
    trailer->prev = header;  // 트레일러의 이전 노드를 헤더로 설정
    header->prev = nullptr;  // 헤더는 리스트의 시작이므로 prev는 nullptr
    trailer->next = nullptr; // 트레일러는 리스트의 끝이므로 next는 nullptr
}

// 소멸자 정의
DLinkedList::~DLinkedList()
{
    while (!empty())   // 리스트가 비어있지 않다면
        removeFront(); // 앞에서부터 노드를 하나씩 삭제
}

// 리스트가 비었는지 확인하는 함수
bool DLinkedList::empty(void) const
{
    return (header->next == trailer); // 헤더 다음이 트레일러이면 리스트가 비어 있는 상태
}

// 첫 번째 요소를 참조로 반환하는 함수
const Elem &DLinkedList::front(void)
{
    if (empty())
        throw out_of_range("Error: empty list.");
    return (header->next->elem); // 헤더 다음 노드의 데이터를 반환
}

// 마지막 요소를 참조로 반환하는 함수
const Elem &DLinkedList::back(void)
{
    if (empty())
        throw out_of_range("Error: empty list.");
    return (trailer->prev->elem); // 트레일러 이전 노드의 데이터를 반환
}

// 앞에 요소를 추가하는 함수
void DLinkedList::addFront(const Elem &elem)
{
    add(header->next, elem); // 헤더 다음 위치 앞에 새 노드를 삽입
}

// 뒤에 요소를 추가하는 함수
void DLinkedList::addBack(const Elem &elem)
{
    add(trailer, elem); // 트레일러 앞 위치에 새 노드를 삽입
}

// 앞의 요소를 제거하는 함수
void DLinkedList::removeFront(void)
{
    remove(header->next); // 헤더 다음 노드를 삭제
}

// 뒤의 요소를 제거하는 함수
void DLinkedList::removeBack(void)
{
    remove(trailer->prev); // 트레일러 이전 노드를 삭제
}

// 주어진 노드 앞에 새 노드를 추가하는 내부 함수
void DLinkedList::add(DNode *v, const Elem &e)
{
    DNode *u = new DNode; // 새 노드를 동적으로 생성
    u->elem = e;          // 새 노드에 데이터 저장
    u->prev = v->prev;    // 새 노드의 prev를 기존 노드의 prev로 설정
    u->next = v;          // 새 노드의 next를 현재 노드로 설정
    v->prev->next = u;    // 이전 노드의 next를 새 노드로 연결
    v->prev = u;          // 현재 노드의 prev를 새 노드로 갱신
}

// 주어진 노드를 리스트에서 제거하는 내부 함수
void DLinkedList::remove(DNode *v)
{
    if (empty())
    {
        // Error messege
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    DNode *u = v->prev; // v의 이전 노드 저장
    DNode *w = v->next; // v의 다음 노드 저장
    u->next = w;        // 이전 노드의 next를 v의 다음 노드로 연결
    w->prev = u;        // 다음 노드의 prev를 v의 이전 노드로 연결
    delete v;           // 노드 v를 삭제하여 메모리 해제
}

int main(void)
{
    DLinkedList A;
    A.addFront("Hello");
    Elem tmp = A.front();
    std::cout << tmp << std::endl;

    A.addFront("World");
    tmp = A.front();
    std::cout << tmp << std::endl;
    A.removeFront();
    A.removeFront();
    A.removeFront();
    A.removeFront();
    return 0;
}