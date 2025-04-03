# 함수에서의 사용

## 값 전달 (Call by Value)

- 함수 호출 시 인수의 값 자체를 복사하여 함수에 전달한다.
- 함수 내부에서 인수 값을 변경해도 원본 데이터에는 영향을 주지 않는다. (변수의 수명)
- 주로 간단한 값을 전달할 때 사용한다.

### `swap()` 예시 (틀린 예시)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int a, int b) 
{
    // 인수로 값을 받음
    int temp = a;
    a = b;
    b = temp;
    // 값을 서로 바꿈
    // 함수 내부에서 변수의 값들이 바뀜
    // 소멸되는 변수의 값이므로 반환하지 않으면 의미 없는 작동이다
    return;
}

int main(void) 
{
    int x = 5, y = 10;
    printf("x: %d, y: %d\n", x, y);
    // 변경 전 출력
    swap(x, y);
    // 변수의 값을 전달
    printf("x: %d, y: %d\n", x, y);
    // 변경되지 않음
    return 0;
}
```

```
x: 5, y: 10
x: 5, y: 10
```

## 주소 전달 (Call by Reference)

- 함수 호출 시 변수의 주소를 전달하여 함수 내부에서 원본 데이터를 직접 변경할 수 있다.
- 주로 데이터를 수정하거나 대량의 데이터를 효율적으로 다룰 때 사용한다.

### `swap()` 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) 
{
    // 인수로 주소를 받음
    int temp = *a;
    // 주소를 통해 역참조하여 값 대입
    *a = *b;
    *b = temp;
    // 값을 서로 바꿈
    // 주소를 통해 값에 접근했으므로 
    // 실제로 main 함수의 값을 변경
    return;
}

int main(void) 
{
    int x = 5, y = 10;
    printf("x: %d, y: %d\n", x, y);
    // 변경 전 출력
    swap(&x, &y);
    // 변수의 주소를 전달
    printf("x: %d, y: %d\n", x, y);
    // 변경된 값 출력
    return 0;
}
```

```
x: 5, y: 10
x: 10, y: 5
```

## `scanf()` 에서 주소 전달

`scanf()` 함수는 주소를 인수로 받는다. 커멘드 창에서 입력을 받아 변수에 저장하기 때문에 인수로 받은 변수의 주소를 통해 역참조 하여 변수의 값을 변경한다.

### `scanf()` 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	int x = 0;
	scanf("%d", &x);
	printf("%d", x);
	return 0;
}
```

```
3
3
```

- `scanf("%d", &x)`에서 `&` 연산자를 통해 `x` 의 주소를 참조하여 `scanf` 에 값을 전달한다.
- `scanf("%d", x)` 처럼 값을 전달한다면 컴파일 에러가 발생하거나 프로그램이 예상대로 동작하지 않을 것이다.

## `qsort()` 에서 주소 전달

`qsort` 함수는 C 표준 라이브러리의 `<stdlib.h>` 에 포함된 함수로, 퀵 정렬(Quick Sort) 알고리즘을 기반으로 다양한 데이터를 정렬할 수 있게 한다. `qsort` 는 일반화된 정렬 함수로, 배열과 비교 함수를 인수로 받는다.

인수로 변수(배열)의 주소 뿐만 아니라 함수 포인터를 받아 정렬을 진행한다.

### `qsort` 함수의 원형

```c
void qsort(
void *base, 
size_t nitems, 
size_t size, 
int (*compar)(const void *, const void *)
);
```

### 매개변수

1. **`void *base`**: 정렬하려는 배열의 시작 주소.
2. **`size_t nitems`**: 배열의 요소 개수.
3. **`size_t size`**: 배열의 각 요소 크기(바이트 단위).
4. **`int (*compar)(const void *, const void *)`**: 두 요소를 비교하는 함수의 포인터.
    - 이 함수는 두 요소를 비교한다.
    - 반환하는 값을 지정하여 원하는 정렬을 한다
    - 두 값을 바꾸고 싶으면 음수 반환
    - 두 값을 바꾸고 싶지 않으면 양수 반환
    - 두 값이 같으면 0 반환

### `qsort()` 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) // int 형 포인터로 형 변환 후 역참조 한다
        return 1; // a 가 더 크면 값을 바꾼다.
    else if (*(int*)a < *(int*)b) // int 형 포인터로 형 변환 후 역참조 한다
        return -1; // a 가 더 작으면 유지한다.
    else
        return 0;
}

int main(void)
{
    int arr[] = { 40, 10, 100, 90, 20, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // 배열의 크기 계산

    void* ptrarr = arr;
    // 배열의 주소

    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    // 배열의 값 출력

    // qsort 호출
    qsort(ptrarr, n, sizeof(int), comp);
    // 배열의 주소
    // 값의 개수
    // 자료형의 크기
    // 함수 포인터

    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    // 정렬된 배열의 값 출력

    return 0;
}
```

```
40 10 100 90 20 25
10 20 25 40 90 100
```

## 함수에서 여러 값 반환

C 언어에서 함수는 기본적으로 하나의 값을 반환한다. 

그러나 포인터를 사용하면 함수에서 여러 값을 반환 받을 수 있다. 이는 함수의 인수로 전달된 포인터를 통해 값을 수정하는 방식으로 구현된다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find_min_max(int* arr, int n, int* min, int* max) 
{
    *min = *arr;
    *max = *arr;

    for (int i = 1; i < n; i++) 
    {
        if (*(arr + i) < *min)
            *min = *(arr + i);
        if (*(arr + i) > *max)
            *max = *(arr + i);
    }
    // min, max 값을 수정해가면서 값을 찾는다.
    return;
}

int main(void) 
{
    int arr[5] = { 10, 20, 5, 40, 30 };
    int n = sizeof(arr) / sizeof(*(arr));
    int min, max;

    find_min_max(arr, n, &min, &max);
    printf("%d %d", min, max);

    return 0;
}
```

```
5 40
```