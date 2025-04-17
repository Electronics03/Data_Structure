#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// 문자열 노드를 표현하는 클래스 정의
class StringNode
{
private:
    string elem;                   // 노드에 저장될 문자열(string element)
    StringNode *next;              // 다음 노드를 가리키는 포인터(next pointer)
    friend class StringLinkedList; // Linked List 클래스가 이 클래스의 private 멤버에 접근할 수 있도록 설정
};

// 단일 연결 리스트(Singly Linked List)를 표현하는 클래스 정의
class StringLinkedList
{
public:
    StringLinkedList();  // 생성자: 리스트 초기화
    ~StringLinkedList(); // 소멸자: 리스트 메모리 정리

    bool empty(void) const;          // 리스트가 비어 있는지 확인하는 함수
    const string &front(void) const; // 리스트의 첫 번째 요소를 반환하는 함수 (참조 반환)
    void addFront(const string &e);  // 리스트의 맨 앞에 요소를 추가하는 함수
    void removeFront(void);          // 리스트의 맨 앞 요소를 제거하는 함수

    friend ostream &operator<<(ostream &os, const StringLinkedList &list);
    // 리스트 전체를 출력할 수 있게 도와주는 연산자 오버로딩

private:
    StringNode *head; // 리스트의 첫 번째 노드를 가리키는 포인터(head pointer)
};

// 생성자 정의: head 포인터를 nullptr로 초기화하여 빈 리스트 상태로 설정
StringLinkedList::StringLinkedList() : head(nullptr) {}

// 소멸자 정의: 리스트가 빌 때까지 모든 노드를 제거함
StringLinkedList::~StringLinkedList()
{
    while (!empty())   // 리스트가 비어 있지 않으면
        removeFront(); // 맨 앞 노드를 계속 제거
    return;
}

// 리스트가 비어 있는지 확인하는 함수
bool StringLinkedList::empty(void) const
{
    return (head == nullptr); // head가 nullptr이면 리스트가 비어 있음
}

// 리스트의 첫 번째 요소를 반환하는 함수
const string &StringLinkedList::front(void) const
{
    return (head->elem); // head 노드의 문자열 데이터를 반환
}

// 새로운 요소를 리스트 맨 앞에 추가하는 함수
void StringLinkedList::addFront(const string &e)
{
    StringNode *v = new StringNode; // 새 노드를 동적으로 생성
    v->elem = e;                    // 새 노드에 전달받은 문자열 저장
    v->next = head;                 // 새 노드의 next 포인터가 기존 head를 가리키도록 설정
    head = v;                       // head를 새 노드로 갱신 (새 노드가 리스트의 첫 번째가 됨)
    return;
}

// 리스트의 맨 앞 요소를 제거하는 함수
void StringLinkedList::removeFront(void)
{
    if (empty())
    {
        // Error messege
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return;
    }
    StringNode *v = head; // 현재 head 노드를 v에 저장
    head = v->next;       // head를 다음 노드로 갱신
    delete v;             // 기존 head였던 노드 메모리를 해제
}
int main(void)
{
    StringLinkedList A;
    A.addFront("Chung-Ang Univ");
    A.addFront("CAU");
    A.addFront("EEE");
    A.addFront("Chung-Ang Univ");
    A.addFront("CAU");
    A.addFront("EEE");
    while (!A.empty())
    {
        cout << A.front() << endl;
        A.removeFront();
    }
    return 0;
}