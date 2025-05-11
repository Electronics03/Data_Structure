#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
typedef string Elem;

// 원형 리스트 노드를 나타내는 클래스 정의
class CNode
{
private:
    Elem elem;               // 노드에 저장되는 데이터 (문자열)
    CNode *next;             // 다음 노드를 가리키는 포인터
    friend class CircleList; // CircleList 클래스가 이 클래스의 private 멤버에 접근할 수 있도록 함
};

// 원형 연결 리스트 클래스 정의
class CircleList
{
public:
    CircleList();  // 생성자: 리스트 초기화
    ~CircleList(); // 소멸자: 리스트 메모리 해제

    bool empty(void) const; // 리스트가 비어 있는지 확인하는 함수

    const Elem &front(void); // 현재 커서의 다음 노드 데이터를 반환 (가장 앞 원소)
    const Elem &back(void);  // 현재 커서의 데이터를 반환 (가장 뒤 원소)

    void advance(void);      // 커서를 한 칸 앞으로 이동하는 함수
    void add(const Elem &e); // 커서 다음 위치에 노드를 추가하는 함수
    void remove(void);       // 커서 다음 위치의 노드를 삭제하는 함수

private:
    CNode *cursor; // 커서를 가리키는 포인터 (현재 위치 추적용)
};

// 생성자: 커서를 nullptr로 초기화하여 빈 리스트 상태로 만듦
CircleList::CircleList() : cursor(nullptr) {}

// 소멸자: 리스트가 빌 때까지 remove()를 반복하여 노드 메모리를 해제
CircleList::~CircleList()
{
    while (!empty())
        remove();
}

// 리스트가 비었는지 여부 반환
bool CircleList::empty(void) const
{
    return (cursor == nullptr); // 커서가 nullptr이면 비어 있는 상태
}

// 커서의 다음 노드에 있는 데이터를 반환
const Elem &CircleList::front(void)
{
    if (empty())
        throw out_of_range("Error: empty list.");
    return (cursor->next->elem); // 커서 다음 노드의 element를 반환
}

// 커서가 가리키는 노드의 데이터를 반환
const Elem &CircleList::back(void)
{
    if (empty())
        throw out_of_range("Error: empty list.");
    return (cursor->elem); // 커서가 가리키는 현재 노드의 element 반환
}

// 커서를 한 칸 앞으로 이동시키는 함수
void CircleList::advance(void)
{
    if (empty())
        throw out_of_range("Error: empty list.");
    cursor = cursor->next; // 커서를 다음 노드로 이동
}

// 커서 다음 위치에 새 노드를 추가하는 함수
void CircleList::add(const Elem &e)
{
    CNode *v = new CNode; // 새 노드 생성
    v->elem = e;          // 노드에 데이터 저장

    if (empty()) // 리스트가 비어 있을 경우
    {
        v->next = v; // 자기 자신을 next로 연결 (1개짜리 원형 리스트)
        cursor = v;  // 커서를 새 노드로 설정
    }
    else // 리스트가 비어 있지 않을 경우
    {
        v->next = cursor->next; // 새 노드의 다음은 커서 다음 노드
        cursor->next = v;       // 커서 다음에 새 노드를 삽입
    }
}

// 커서 다음 노드를 삭제하는 함수
void CircleList::remove(void)
{
    if (empty()) // 리스트가 비어 있으면
    {
        std::cout << "ERROR: Cannot remove from an empty list." << std::endl;
        return; // 에러 메시지 출력 후 종료
    }

    CNode *old = cursor->next; // 삭제할 노드를 old에 저장

    if (old == cursor)    // 노드가 하나뿐인 경우
        cursor = nullptr; // 커서를 nullptr로 설정 (빈 리스트)
    else
        cursor->next = old->next; // 커서가 old의 다음 노드를 가리키게 함

    delete old; // old 노드 메모리 해제
}

int main(void)
{
    CircleList A;
    A.add("Hello");                      // Hello*
    A.add("World");                      // World->Hello*
    A.add("C++");                        // C++->World->Hello*
    A.advance();                         // World->Hello->C++*
    std::cout << A.back() << std::endl;  // C++
    std::cout << A.front() << std::endl; // World
    A.advance();                         // Hello->C++->World*
    A.remove();                          // C++->World*
    std::cout << A.back() << std::endl;  // World
    std::cout << A.front() << std::endl; // C++
    A.remove();
    A.remove();
    A.remove();
    A.remove();
    A.remove();
    return 0;
}