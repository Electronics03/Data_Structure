#include <iostream> // Standard Input/Output Stream을 사용하기 위한 헤더임
#include <cstdlib>  // C Standard Library를 포함함 (예: malloc, free 등 — 여기선 사용되지 않음)

// insertionSort 함수는 주어진 정수 배열 A를 오름차순으로 정렬함
void insertionSort(int *A, int n)
{
    for (int i = 0; i < n; i++) // 배열의 모든 요소를 순회함
    {
        int cur = A[i]; // 현재 삽입할 요소를 cur에 저장함
        int j = i - 1;  // 정렬된 영역의 마지막 인덱스를 j에 저장함

        // 정렬된 부분에서 cur보다 큰 요소를 오른쪽으로 한 칸 이동시킴
        while ((j >= 0) && (cur < A[j]))
        {
            A[j + 1] = A[j]; // 한 칸 오른쪽으로 이동함
            j--;             // 왼쪽으로 이동하며 비교함
        }

        j++;        // 삽입 위치가 정확히 j + 1이므로 j를 다시 증가시킴
        A[j] = cur; // 현재 요소 cur를 정렬된 위치에 삽입함
    }

    return; // 함수 종료
}

// main 함수는 프로그램의 진입점이며, 사용자 입력과 결과 출력을 담당함
int main(void)
{
    int n = 0;     // 입력받을 배열 크기를 저장할 변수 n을 선언 및 초기화함
    std::cin >> n; // 사용자로부터 배열 크기 n을 입력받음

    int *array = new int[n]; // 크기 n의 정수 배열을 동적으로 할당함

    // 사용자로부터 배열의 각 요소를 입력받음
    for (int i = 0; i < n; i++)
        std::cin >> array[i]; // array[i]에 정수를 입력받음

    insertionSort(array, n); // insertion sort 알고리즘을 호출하여 배열을 정렬함

    // 정렬된 배열의 각 요소를 출력함
    for (int i = 0; i < n; i++)
        std::cout << array[i] << std::endl; // 요소를 출력하고 줄바꿈함
    delete[] array;
    return 0; // 프로그램을 정상 종료함 (※ delete[] array 생략됨, 메모리 해제는 필요함)
}
