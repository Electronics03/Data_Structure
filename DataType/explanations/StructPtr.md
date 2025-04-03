# 구조체 포인터

## 구조체의 메모리 저장 방식

### 구조체의 멤버 배치

- 구조체의 멤버들은 선언된 순서대로 메모리에 배치된다.
- 각 멤버 변수는 CPU가 빠르게 메모리에 접근할 수 있도록 정렬 규칙을 따른다.
- 메모리에 대한 접근 속도를 높이기 위해, 구조체의 멤버들은 메모리 블록 안에 하나의 멤버가 온전히 들어올 수 있도록 배치된다.
- 멤버 변수들이 CPU의 정렬 기준을 만족하도록 배치되면서, 일부 빈 공간이 발생할 수 있다. 이러한 빈 공간을 정렬 패딩(alignment padding)이라 한다.

### 64비트 운영체제에서의 메모리 할당

- 64비트 운영체제에서는 CPU가 메모리에 접근할 때 8 Byte로 데이터를 처리한다.
- 따라서 구조체의 멤버 변수들이 올바른 정렬 기준에 따라 8의 배수 주소에 배치되도록 패딩이 추가된다.

## 정렬 패딩(alignment padding)

### **패딩은 구조체의 일부**

- 구조체의 패딩은 컴파일러가 구조체 멤버 사이에 삽입한 빈 공간이다.
- 이 공간은 **구조체의 메모리 정렬 요구사항을 충족**하기 위해 존재하며, 다른 데이터나 변수를 저장할 수 없다.

### **구조체 내부의 고유 공간**

- 패딩은 구조체 자체의 메모리 공간에 포함되며, 구조체가 차지하는 크기(`sizeof(struct 구조체)`)의 일부로 계산된다.
- 따라서 구조체 외부에서 다른 변수가 패딩을 차지하거나 침범할 수 없다.

### **컴파일러의 규칙 준수**

- 컴파일러는 C 언어 표준을 준수하며, 구조체 멤버와 패딩 사이의 메모리 충돌이 발생하지 않도록 설계된다.
- 패딩 공간은 구조체 내부에서 멤버 변수들 간의 정렬을 유지하기 위한 용도로만 사용된다.

### **메모리 낭비**

- 패딩은 데이터를 저장하지 않으므로 구조체 크기가 커질 수 있다.
- 멤버 순서를 최적화하거나 `#pragma pack`을 사용하면 패딩을 줄일 수 있다.

### 메모리 최적화

- 멤버를 큰 자료형부터 선언하면 불필요한 패딩을 줄일 수 있다.
- 멤버의 순서를 적절히 조정하면 메모리를 절약하고 구조체 크기를 줄일 수 있다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Mixed1
{
    char a;    // 1 byte
    double b;  // 8 bytes
    int c;     // 4 bytes
};
struct Mixed2
{
    double a;  // 8 bytes
    char b;    // 1 byte
    int c;     // 4 bytes
};

int main(void)
{
    int size1 = sizeof(struct Mixed1);
    int size2 = sizeof(struct Mixed2);

    printf("Size of Mixed1:%d\n", size1);
    printf("Size of Mixed2:%d\n", size2);

    return 0;
}
```

```
Size of Mixed1:24
Size of Mixed2:16
```

- `size1` 은 1/8/4 순서로 8 Byte 틀 안에 겹치지 않도록 넣어야 한다.
- 따라서 (1/7)/(8)/(4/4) 총 24 Byte 를 소비하고, 패딩의 크기는 11 Byte 이다.
- `size2` 은 8/1/4 순서로 8 Byte 틀 안에 겹치지 않도록 넣어야 한다.
- 따라서 (8)/(1/4/3) 총 16 Byte 를 소비하고, 패딩의 크기는 3 Byte 이다.

## 구조체 포인터

### 문법

```c
struct 태그* 변수명;
```

- 구조체 포인터는 구조체의 메모리 주소를 저장하는 포인터이다.
- 구조체 포인터를 사용하면 구조체 변수의 주소를 통해 간접적으로 구조체 멤버에 접근할 수 있다.
- 선언 시 `struct` 키워드와 구조체 태그를 함께 사용하여 구조체 포인터 변수를 정의한다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Point
{
    int x;
    int y;
    int z;
};

int main(void)
{
    struct Point P = { 10,20,30 };
    struct Point* ptrP = &P;

    printf("%p\n", ptrP);
    // 포인터가 위치하는 주소
    printf("%p %p %p\n", &(P.x), &(P.y), &(P.z));
    // 각 멤버의 주소

    printf("%ld\n", (unsigned long)ptrP);
    // 포인터가 위치하는 주소
    // 10진수 표현
    printf("%ld %ld %ld\n", (unsigned long)&(P.x), (unsigned long)&(P.y), (unsigned long)&(P.z));
    // 각 멤버의 주소
    // 10진수 표현
    // 4 Byte 씩 증가

    return 0;
}
```

```
0000001608AFFB28
0000001608AFFB28 0000001608AFFB2C 0000001608AFFB30
145750824
145750824 145750828 145750832
```

## 구조체 간접 참조

### 문법

```c
(*구조체포인터).멤버
구조체포인터->멤버
```

- 구조체 포인터를 통해 구조체 멤버에 접근하려면 역참조(dereferencing)를 사용해야 한다.
- `(*구조체포인터).멤버`는 구조체 포인터를 역참조하여 멤버에 접근하는 방식이다.
- `구조체포인터->멤버`는 위 문법을 간단히 표현한 방식으로, 자주 사용된다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Point
{
    int x;
    int y;
    int z;
};

int main(void)
{
    struct Point P = { 10,20,30 };
    struct Point* ptrP = &P;

    printf("%d %d %d\n", (*ptrP).x, (*ptrP).y, (*ptrP).z);
    printf("%d %d %d\n", ptrP->x, ptrP->y, ptrP->z);
    return 0;
}
```

```
10 20 30
10 20 30
```