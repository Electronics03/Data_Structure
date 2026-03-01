# `const` 와 `volatile`

## `const` 키워드

### 문법

```c
const 자료형 변수이름 = 값;
```

- 변수 선언 시 `const` 키워드를 사용하면 해당 변수는 상수로 간주되며, 값을 변경할 수 없다.
- 주로 변경되어서는 안 되는 값을 보호하기 위해 사용된다.

### 특징

- 읽기 전용이다.
- 컴파일러가 `const`로 선언된 변수의 값을 변경하려는 시도를 에러로 처리한다.
- `const` 키워드는 포인터와 함께 사용되어 포인터가 가리키는 값이나 포인터 자체를 보호할 수 있다.

### 예시

```c
const int x = 10;
// x = 20;  
// 에러: x는 상수이므로 값을 변경할 수 없음

const int* ptr = &x; 
// ptr은 값을 변경하지 못하는 변수의 주소를 가리킴
// ptr 자체는 변경 가능
// *ptr = 20;
// 에러: ptr이 가리키는 값 변경 불가

int y = 30;

int* const cptr = &y; 
// cptr은 상수 포인터

*cptr = 40;          
// 가능: cptr이 가리키는 값은 변경 가능
// cptr = &x;
// 에러: cptr 자체 변경 불가

printf("%d\n", *cptr); 
// 출력: 40
```

## `volatile` 키워드

`volatile` 키워드는 컴파일러가 특정 변수의 값을 최적화하지 않도록 하는 데 사용된다. 

이는 주로 하드웨어 레지스터, 인터럽트 핸들러, 멀티스레드 프로그래밍 등 외부 요인에 의해 값이 변경될 수 있는 변수를 명시하기 위해 사용된다.

### 문법

```c
volatile 자료형 변수이름;
```

- `volatile` 키워드는 변수의 값이 외부 요인(하드웨어, 다른 스레드 등)에 의해 변경될 수 있음을 나타낸다.
- 컴파일러는 `volatile` 로 선언된 변수를 최적화하지 않는다.

### 특징

- 변수 값이 외부 이벤트(하드웨어 인터럽트 등)에 의해 변경될 가능성이 있음을 나타낸다.
- 컴파일러의 최적화를 방지한다.
- 컴파일러는 변수를 캐싱하지 않고, 항상 메모리에서 값을 읽도록 강제한다.

### 예시

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

volatile int flag = 0;
// 외부 요인으로 변경될 수 있는 변수

void hardware_interrupt() 
{
    // 하드웨어 인터럽트 발생 시 flag 변경
    flag = 1;
}

int main(void) 
{
    while (!flag)
        continue;
    // flag가 변경될 때까지 대기
   
    printf("Interrupt detected!\n");
    return 0;
}
```

## `const`와 `volatile`의 조합

### 설명

- `const`와 `volatile`은 함께 사용할 수 있으며, 이는 값을 코드에서 변경할 수 없지만, 외부 요인에 의해 변경될 수 있음을 의미한다.
- 주로 하드웨어 레지스터에 사용된다.

### 예시

```c
#include <stdio.h>
const volatile int hardware_register = 0xABCD;

int main(void) 
{
    printf("Register Value: %X\n", hardware_register);
    // hardware_register = 0x1234; 
    // 에러: const로 인해 코드에서 변경 불가
    return 0;
}
```