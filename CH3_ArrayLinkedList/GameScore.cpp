/*
 * Array를 이용하여 Game Score과 Name을 관리하는 코드
 * GameEntry class:
 *      name-score 값을 지님
 * Scores class:
 *      add로 정렬하면서 name-score pair을 받는다
 *      remove(i) 하면 index에 해당하는 GameEntry 반환 후 삭제
 */

#include <cstdlib>   // Standard C Library (e.g. malloc, free)
#include <iostream>  // Standard Input/Output Stream
#include <string>    // string Class
#include <stdexcept> // Standard Exception Classes (e.g. out_of_range)

using namespace std; // std:: 생략 가능

// GameEntry Class: 하나의 게임 점수를 저장
class GameEntry
{
public:
    GameEntry(const string &n = "", const int &s = 0); // Constructor with Default Arguments
    string getName(void) const;                        // Return Player Name
    int getScore(void) const;                          // Return Player Score

private:
    string name; // Player Name
    int score;   // Player Score
};

// Constructor Definition (Member Initializer List 사용)
GameEntry::GameEntry(const string &n, const int &s) : name(n), score(s) {};
// Return Name
string GameEntry::getName(void) const { return name; }
// Return Score
int GameEntry::getScore(void) const { return score; }
// Scores Class: GameEntry를 정렬된 상태로 저장 및 관리

class Scores
{
public:
    Scores(int maxEnt = 10);      // Constructor (Default maxEntries = 10)
    ~Scores();                    // Destructor (Dynamic Allocation 해제)
    void add(const GameEntry &e); // Add GameEntry to Sorted List
    GameEntry remove(int i);      // Remove GameEntry at Index i

private:
    int maxEntries;     // Maximum Number of Entries
    int numEntries;     // Current Number of Entries
    GameEntry *entries; // GameEntry Object Array (Dynamic Allocation)
};

// Constructor: GameEntry Array를 동적 할당
Scores::Scores(int maxEnt) : maxEntries(maxEnt), numEntries(0)
{
    entries = new GameEntry[maxEntries];
    // GameEntry Object Array를 Dynamic Allocation으로 생성
}

// Destructor: 동적 할당된 배열 해제
Scores::~Scores()
{
    delete[] entries;
}

// Add Function: 점수를 정렬된 위치에 삽입
void Scores::add(const GameEntry &e)
{
    int newScore = e.getScore(); // 새 점수 가져오기

    // 리스트가 가득 찼을 경우
    if (numEntries == maxEntries)
    {
        // 가장 낮은 점수보다 작으면 무시
        if (newScore < entries[maxEntries - 1].getScore())
            return;
    }
    else
        numEntries++; // 여유 공간이 있으면 카운트 증가

    // 삽입 위치 찾기
    int i = maxEntries - 2;
    // (maxEntries - 2)부터 시작한다
    // numEntries++ 했다면 마지막 값부터 검사하는 것
    // 아니라면 numEntries == maxEntries 라는 것이고
    // 마지막 값은 Overide 되어서 사라진다
    while ((i >= 0) && (newScore > entries[i].getScore()))
    {
        entries[i + 1] = entries[i]; // 오른쪽으로 Shift
        i--;
    }
    entries[i + 1] = e; // 새 점수를 정확한 위치에 삽입
    // (i + 1) 인 이유는 루프에서 탈출하기 전에 i-- 해서 다시 더해준다
    // while {...} 이후에
    // i++; 하여 명확히 해주는 것도 방법 중에 하나이다
    return;
}

// Remove Function: 지정된 인덱스의 점수 제거 및 반환
GameEntry Scores::remove(int i)
{
    GameEntry e = entries[i]; // 제거할 항목 저장

    // 오른쪽 요소들을 왼쪽으로 Shift
    for (int j = i + 1; j < numEntries; j++)
        entries[j - 1] = entries[j];
    // i + 1 부터 numEntries 전까지 진행
    // i는 return되는 값이고 이를 다음값으로 대체

    numEntries--; // Count 감소
    return e;     // 제거된 항목 반환
}

/*
 * Main Function: 프로그램 테스트
 * GameEntry 생성 및 삽입
 * 가장 높은 점수부터 차례로 삭제하며 출력
 */
int main(void)
{
    Scores A(20); // Scores Object 생성 (최대 20개 Entry 저장 가능)

    // GameEntry 생성 및 삽입
    GameEntry G1("User1", 1);
    A.add(G1);
    GameEntry G2("User2", 10);
    A.add(G2);
    GameEntry G3("User3", 2);
    A.add(G3);
    GameEntry G4("User4", 5);
    A.add(G4);
    GameEntry G5("User5", 3);
    A.add(G5);

    // 가장 높은 점수부터 차례로 삭제하며 출력
    for (int i = 0; i < 5; i++)
    {
        GameEntry User = A.remove(0);   // Always Remove Highest Score (Index 0)
        cout << User.getName() << "|";  // Print Name
        cout << User.getScore() << " "; // Print Score
    }
    cout << endl;
    return 0;
}