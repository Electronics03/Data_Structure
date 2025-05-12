# 구조체 배열

구조체도 기본 자료형과 동일하게 배열을 선언할 수 있다.

이를 통해 동일한 구조체 데이터를 여러 개 효율적으로 관리할 수 있다.

## 구조체 배열 선언

### 문법

```c
struct 구조체이름 배열이름[배열크기];
```

- 구조체 배열은 구조체 타입의 데이터를 연속적으로 저장한다.
- 배열의 각 요소는 해당 구조체 타입을 가진 개별적인 구조체 변수로 취급된다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student 
{
    int id;
    double grade;
};

int main(void) 
{
    struct Student s[3] = { 0 };
    for (int i = 0; i < 3; i++)
        scanf("%d %lf", &(s[i].id), &(s[i].grade));
    printf("\n");
    for (int i = 0; i < 3; i++)
        printf("%d %.1lf\n", s[i].id, s[i].grade);
    return 0;
}
```

```
1 4.5
2 3.4
3 2.4

1 4.5
2 3.4
3 2.4
```

## 포인터와 구조체 배열

### 설명

- 구조체 배열은 포인터와 함께 사용할 수 있다. 구조체 배열의 이름은 배열의 첫 번째 요소를 가리키는 포인터로 동작한다.
- 구조체 배열의 이름을 포인터 변수에 할당하면, 배열 요소를 포인터로 역참조할 수 있다.
- `포인터 + 인덱스`를 통해 배열 요소의 주소에 접근할 수 있다. 이 주소에서 `->` 연산자를 사용해 멤버에 접근할 수 있다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student 
{
    int id;
    double grade;
};

int main(void) 
{
    struct Student s[3] = { 0 };
    for (int i = 0; i < 3; i++)
        scanf("%d %lf", &((s + i)->id), &((s + i)->grade));
    printf("\n");
    for (int i = 0; i < 3; i++)
        printf("%d %.1lf\n", (s + i)->id, (s + i)->grade);
    return 0;
}
```

```
1 4.5
2 3.4
3 2.4

1 4.5
2 3.4
3 2.4
```