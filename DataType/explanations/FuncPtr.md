# 함수 포인터

## 정의

### 문법

```c
자료형 (*함수포인터이름)(매개변수목록);
```

- `자료형`: 함수가 반환하는 값의 자료형.
- `(*함수포인터이름)`: 함수 포인터의 이름을 나타냄.
- `(매개변수목록)`: 함수가 받을 매개변수들의 자료형.

### 설명

- 함수 포인터는 특정 함수의 주소를 저장하는 데 사용된다.
- 이를 통해 함수 호출을 동적으로 처리하거나, 매개변수로 함수를 전달할 수 있다.
- 함수의 이름은 곧 해당 함수의 시작 주소와 동일하므로 함수 포인터를 통해 함수를 호출할 수 있다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printMessage()
{
    printf("Hello, Function Pointer!\n");
}

int main(void)
{
    void (*funcPtr)() = &printMessage;
    // 함수 포인터에 함수 주소 저장
    funcPtr();
    // 함수 호출
    return 0;
}
```

```
Hello, Function Pointer!
```

## 함수 포인터를 이용한 동적 함수 호출

### 설명

- 동일한 자료형의 입출력을 필요로 하는데 작동만 변화해야 하는 상황에서 사용.
- 함수 포인터를 통해 동적으로 함수를 호출할 수 있다.
- 프로그램의 유연성을 높이고, 코드 중복을 줄일 수 있다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void add(int a, int b)
{
    printf("%d\n", a + b);
}

void sub(int a, int b)
{
    printf("%d\n", a - b);
}

int main(void)
{
    void (*operation)(int, int);

    operation = &add;
    operation(10, 5);  
    // add 함수 호출

    operation = &sub;
    operation(10, 5);  
    // sub 함수 호출

    return 0;
}
```

```
15
5
```

## 함수 포인터 배열

### 설명

- 여러 함수를 저장하고 필요에 따라 동적으로 선택하여 호출할 수 있다.
- 동일한 자료형을 입출력 하는 다양한 함수들 관리 가능

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Morning(void) 
{
    printf("Good Morning!\n");
}

void Afternoon(void)
{
    printf("Good Afternoon!\n");
}

void Evening(void)
{
    printf("Good Evening!\n");
}

int main(void) 
{
    void (*greet[3])(void) = { Morning, Afternoon, Evening };

    for (int i = 0; i < 3; i++) 
    {
        greet[i]();
    }
    return 0;
}
```

```
Good Morning!
Good Afternoon!
Good Evening!
```

## 함수 포인터를 매개변수로 전달

### 설명

- 함수 포인터를 매개변수로 사용하면 동적으로 동작을 변경할 수 있다.
- 대표적으로 `qsort` 함수가 있다.

### `qsort` 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int arr[] = { 40, 10, 100, 90, 20, 25 };
    int n = sizeof(arr) / sizeof(int);

    void* ptrarr = arr;
    int (*func)(const void* a, const void* b) = comp;
    // 함수의 주소를 대입

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    qsort(ptrarr, n, sizeof(int), func);
    // 함수의 주소를 전달

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