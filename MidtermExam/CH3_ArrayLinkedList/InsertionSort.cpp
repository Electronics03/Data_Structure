#include <iostream> // Standard Input/Output Stream을 사용하기 위한 헤더임
#include <cstdlib>  // C Standard Library를 포함함 (예: malloc, free 등 — 여기선 사용되지 않음)

// insertionSort 함수는 주어진 정수 배열 A를 오름차순으로 정렬함
void insertionSort(int *A, int n)
{
    for (int i = 0; i < n; i++) // 배열의 모든 Element를 순회함
    {
        int cur = A[i]; // 현재 Element를 cur에 저장함
        int j = i - 1;  // i보다 1 작은 값부터 검사 시작 (i는 삽입할 Element)
        // 정렬된 부분에서 cur보다 큰 Element를 오른쪽으로 한 칸 이동시킴
        while ((j >= 0) && (cur < A[j]))
        {
            A[j + 1] = A[j]; // 한 칸 오른쪽으로 이동함
            j--;             // 왼쪽으로 이동하며 비교함
        }
        j++; // while 코드 특성상 증가후 검사 -> 삽입 위치보다 1 작게 끝남
        // 그래서 j++ 로 위치를 재조정해줌
        // GameScore의 경우와 다르게 해보았음
        A[j] = cur; // cur을 삽입
    }
    return; // 함수 종료
}

// main 함수: 테스트 코드
int main(void)
{
    int n = 0;     // 입력받을 배열 크기를 저장할 변수 n을 선언 및 초기화함
    std::cin >> n; // 사용자로부터 배열 크기 n을 입력받음

    int *array = new int[n]; // 크기 n의 정수 배열을 동적으로 할당함

    // 사용자로부터 배열의 각 Element를 입력받음
    for (int i = 0; i < n; i++)
        std::cin >> array[i]; // array[i]에 정수를 입력받음

    insertionSort(array, n); // insertion sort 알고리즘을 호출하여 배열을 정렬함

    // 정렬된 배열의 각 Element를 출력함
    for (int i = 0; i < n; i++)
        std::cout << array[i] << std::endl; // Element 출력
    delete[] array;
    return 0;
}
