# typedef

`typedef` 는 C 언어에서 기존 자료형에 새로운 이름을 정의하기 위해 사용하는 키워드다. 이를 통해 복잡한 자료형을 간단하게 표현하거나, 가독성을 높이고 유지보수를 쉽게 할 수 있다.

## `typedef` 의 문법

```c
typedef 기존자료형 새로운이름;
```

- **`기존자료형`** : 새로운 이름을 정의할 자료형.
- **`새로운이름`** : 정의된 자료형의 새로운 이름.

## `typedef` 의 주요 특징

### 가독성 향상

- 긴 자료형 이름을 짧고 이해하기 쉬운 이름으로 대체.
- 복잡한 자료형을 단순화하여 코드의 가독성을 높임.

### 유지보수성 강화

- 프로그램에서 자료형을 변경할 때, `typedef` 로 정의된 이름만 수정하면 됨.
- 특히, 자료형이 자주 변경될 가능성이 있을 때 유용.

### 플랫폼 독립성 제공

- 플랫폼에 따라 자료형의 크기가 달라질 수 있으므로, 이를 `typedef` 로 통일된 이름으로 정의하여 플랫폼 독립적인 코드 작성 가능.

## `typedef` 의 사용 예시

### 1. 기본 자료형에 새 이름 부여

```c
typedef unsigned int uint;
typedef float real;

int main(void) 
{
    uint age = 25;  // unsigned int
    real pi = 3.14; // float

    printf("Age: %u, PI: %.2f\n", age, pi);
    return 0;
}
```

### 2. 구조체에 별칭 부여

```c
typedef struct 
{
    int x;
    int y;
} Point;

int main(void) 
{
    Point p1 = {10, 20};
    // struct 키워드를 사용하지 않고 구조체 사용 가능
    printf("Point: (%d, %d)\n", p1.x, p1.y);
    return 0;
}
```

```c
struct Point 
{
    int x;
    int y;
};
// 기존 방식은 struct 키워드가 필요
struct Point p1 = {10, 20};
```

### 3. 포인터에 별칭 부여

```c
typedef int* IntPtr;

int main(void) 
{
    int a = 10;
    IntPtr p = &a; 
    // int* p = &a;
    printf("Value: %d\n", *p);
    return 0;
}
```

### 4. 함수 포인터에 별칭 부여

```c
typedef int (*Operation)(int, int);

int add(int a, int b) 
{
    return a + b;
}

int main(void) 
{
    Operation op = add; 
    // int (*op)(int, int) = add;
    printf("Sum: %d\n", op(3, 4));
    return 0;
}
```

### 5. 플랫폼 독립적 자료형 정의

```c
typedef unsigned short ushort;
typedef unsigned long ulong;

ushort width = 100;
ulong largeNumber = 100000;

printf("Width: %hu, Large Number: %lu\n", width, largeNumber);
```

## `typedef` 와 `#define` 의 차이점

| 특징 | `typedef` | `#define` |
| --- | --- | --- |
| 컴파일러 관여 여부 | 컴파일러가 처리 | 전처리기가 처리 |
| 데이터 타입 | 자료형에 대한 새로운 이름 정의 가능 | 단순히 텍스트를 치환 |
| 문법 검사 | 자료형에 대한 문법 검사 수행 | 문법 검사 수행하지 않음 |
| 사용 용도 | 자료형 이름 정의 | 값, 상수, 매크로 정의 |
| 예시 | `typedef unsigned int uint;` | `#define uint unsigned int` |