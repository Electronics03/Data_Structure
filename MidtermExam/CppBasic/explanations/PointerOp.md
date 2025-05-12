# 포인터 연산

포인터는 변수이므로 다른 자료형과 같이 연산이 가능하다.

포인터의 덧셈과 뺄셈을 통해 인접한 다른 메모리의 접근할 수 있다. 다만, 포인터의 연산은 덧셈과 뺄셈만 가능하고 포인터의 자료형에 따라 증감되는 크기가 다르다.

## 포인터의 덧셈과 뺄셈

### **덧셈**

- 포인터는 주소를 담는 변수이므로 기준 단위는 Byte 이다.
- 포인터의 자료형에 기본 단위로 해당 자료형의 크기를 사용한다.
- 포인터에 정수를 더하면, 해당 자료형 크기 만큼의 메모리 주소가 증가한다.

### **뺄셈**

- 포인터에 정수를 빼면, 해당 자료형 크기만큼 메모리 주소가 감소한다.
- 두 포인터 간의 뺄셈은 두 메모리 주소 사이의 거리를 계산하며, 결과는 자료형 크기 단위로 나뉜 정수 값이다.

### 자료형에 따른 메모리의 크기

| 자료형 | 메모리 크기 | 설명 |
| --- | --- | --- |
| `char` | 1 byte | 단일 문자 또는 작은 정수 저장 |
| `short` | 2 bytes | 작은 정수 저장 |
| `int` | 4 bytes | 정수 저장 (기본 자료형) |
| `long` | 8 bytes | 큰 정수 저장 |
| `long long` | 8 bytes | 더 큰 정수 저장 |
| `float` | 4 bytes | 단정밀도 부동소수점 |
| `double` | 8 bytes | 배정밀도 부동소수점 |
| `long double` | 16 bytes | 확장 정밀도 부동소수점 |
| `void*` (포인터) | 8 bytes | 메모리 주소를 저장 |

### 예시

```c
int arr[5] = { 10, 20, 30, 40, 50 };
int* ptr = arr;  
// 배열의 첫 번째 요소를 가리킴
printf("First ptr: %p Value: %d\n", ptr, *ptr);

ptr++;  
// 포인터를 한 칸 증가시킴
// 4 Byte 증가시킴
// 두 번째 요소를 가리킴
printf("ptr++    : %p Value: %d\n", ptr, *ptr);

ptr += 2;  
// 포인터를 두 칸 이동
// 8 Byte 증가시킴
// 네 번째 요소를 가리킴
printf("ptr += 2 : %p Value: %d\n\n", ptr, *ptr);

int* ptr1 = &arr[3];  // 배열의 네 번째 요소를 가리킴
int* ptr2 = &arr[0];  // 배열의 첫 번째 요소를 가리킴

printf("First ptr1: %p Value1: %d\n", ptr1, *ptr1);
printf("First ptr2: %p Value2: %d\n", ptr2, *ptr2);

ptr1--;  
// 포인터를 한 칸 뒤로 이동
// 4 Byte 감소시킴
// 두 번째 요소를 가리킴
printf("ptr1--    : %p Value1: %d\n", ptr1, *ptr1);

int diff = ptr1 - ptr2;  
// 두 포인터 간의 거리 계산
printf("ptr1-ptr2 : %d (Distance, int (%d * 4 Byte))\n", diff, diff);
```

```
First ptr: 0000006AF0FCFB58 Value: 10
ptr++    : 0000006AF0FCFB5C Value: 20
ptr += 2 : 0000006AF0FCFB64 Value: 40

First ptr1: 0000006AF0FCFB64 Value1: 40
First ptr2: 0000006AF0FCFB58 Value2: 10
ptr1--    : 0000006AF0FCFB60 Value1: 30
ptr1-ptr2 : 2 (Distance, int (2 * 4 Byte))
```

## 역참조와 증감

### 1. `*ptr++`

- **의미**: 포인터가 가리키는 값을 먼저 참조한 후, 포인터를 다음 위치로 이동시킨다.
- **동작 순서**:
    1. `*ptr` 을 역참조.
    2. `*ptr` 을 1 증가 (다음 주소로 이동).
- **결과**: 현재 `ptr` 이 가리키는 값을 사용한 후, `ptr` 이 다음 주소를 가리키게 된다.

### 2. `(*ptr)++`

- **의미**: 포인터가 가리키는 값 자체를 먼저 사용하고, 그 값을 1 증가 시킨다.
- **동작 순서**:
    1. `*ptr` 을 역참조.
    2. `ptr` 의 값을 1 증가 (주소는 그대로).
- **결과**: `ptr` 은 이동하지 않으며, `ptr` 이 가리키는 주소의 값만 증가.

### 3. `++*ptr`

- **의미**: 포인터가 가리키는 값을 먼저 1 증가시키고, 증가된 값을 사용한다.
- **동작 순서**:
    1. `ptr` 의 값을 1 증가.
    2. 증가된 주소의 값을 역참조.
- **결과**: `ptr` 은 그대로 유지되며, 가리키는 값만 증가.

### 4. `++(*ptr)`

- **의미**: `++*ptr` 과 동일하다. 괄호는 우선순위를 명확히 하기 위한 것.
- **동작 순서**:
    1. `ptr` 의 값을 1 증가.
    2. 증가된 주소의 값을 역참조.
- **결과**: `ptr` 은 그대로 유지되며, 가리키는 값만 증가.

### 5. `*ptr--`

- **의미**: 포인터가 가리키는 값을 먼저 참조한 후, 포인터를 이전 위치로 이동시킨다.
- **동작 순서**:
    1. `*ptr` 을 역참조.
    2. `*ptr` 을 1 감소 (이전 주소로 이동).
- **결과**: 현재 `ptr` 이 가리키는 값을 사용한 후, `ptr` 이 이전 주소를 가리키게 된다.

### 6. `(*ptr)--`

- **의미**: 포인터가 가리키는 값 자체를 먼저 사용하고, 그 값을 1 감소시킨다.
- **동작 순서**:
    1. `*ptr` 을 역참조.
    2. `ptr` 의 값을 1 감소.
- **결과**: `ptr` 은 이동하지 않으며, `ptr` 이 가리키는 값만 감소.

### 7. `--*ptr`

- **의미**: 포인터가 가리키는 값을 먼저 1 감소시키고, 감소된 값을 사용한다.
- **동작 순서**:
    1. `ptr` 의 값을 1 감소.
    2. 감소된 주소의 값을 역참조.
- **결과**: `ptr` 은 그대로 유지되며, 가리키는 값만 감소.

### 8. `--(*ptr)`

- **의미**: `--*ptr` 과 동일하다. 괄호는 우선순위를 명확히 하기 위한 것.
- **동작 순서**:
    1. `ptr` 의 값을 1 감소.
    2. 감소된 주소의 값을 역참조.
- **결과**: `ptr` 은 그대로 유지되며, 가리키는 값만 감소.

### 정리

| 표현 | 포인터 이동 | 값 변경 | 동작 설명 |
| --- | --- | --- | --- |
| `*ptr++` | **O** | X | 값을 참조 후 포인터 이동 |
| `(*ptr)++` | X | **O** | 값을 참조 후 값 증가 |
| `++*ptr` | X | **O** | 값을 먼저 증가 후 반환 |
| `++(*ptr)` | X | **O** | `++*ptr`과 동일 |
| `*ptr--` | **O** | X | 값을 참조 후 포인터 감소 |
| `(*ptr)--` | X | **O** | 값을 참조 후 값 감소 |
| `--*ptr` | X | **O** | 값을 먼저 감소 후 반환 |
| `--(*ptr)` | X | **O** | `--*ptr`과 동일 |
- **포인터 이동**: `*ptr++`, `*ptr--`와 같은 연산이 포함될 때 발생.
- **값 변경**: `(*ptr)++`, `++*ptr` 등에서 포인터가 가리키는 값이 변경됨.
- **괄호**: 괄호는 연산 우선순위를 명확히 하기 위한 것이며, 동작은 동일하다.

### 예시

```c
int arr[5] = { 10, 20, 30, 40, 50 };
int* ptr = arr; 
// 배열의 첫 번째 요소를 가리킴

printf("First ptr: %p Value: %d\n", ptr, *ptr);

// 1. *ptr++
printf("\n*ptr++\n");
printf("Before: %p Value: %d\n", ptr, *ptr);
int tmp = *ptr++;
printf("After : %p Value: %d\n", ptr, *ptr);

// 2. (*ptr)++
printf("\n(*ptr)++\n");
printf("Before: %p Value: %d\n", ptr, *ptr);
(*ptr)++;
printf("After : %p Value: %d\n", ptr, *ptr);

// 3. ++*ptr
printf("\n++*ptr\n");
printf("Before: %p Value: %d\n", ptr, *ptr);
++(*ptr);
printf("After : %p Value: %d\n", ptr, *ptr);

// 4. ++(*ptr)
printf("\n++(*ptr)\n");
printf("Before: %p Value: %d\n", ptr, *ptr);
++(*ptr);
printf("After : %p Value: %d\n", ptr, *ptr);

// 5. *ptr--
printf("\n*ptr--\n");
printf("Before: %p Value: %d\n", ptr, *ptr);    
tmp = *ptr--;
printf("After : %p Value: %d\n", ptr, *ptr);

// 6. (*ptr)--
printf("\n(*ptr)--\n");
printf("Before: %p Value: %d\n", ptr, *ptr);
(*ptr)--;
printf("After : %p Value: %d\n", ptr, *ptr);

// 7. --*ptr
printf("\n--*ptr\n");
printf("Before: %p Value: %d\n", ptr, *ptr);
--(*ptr);
printf("After : %p Value: %d\n", ptr, *ptr);

// 8. --(*ptr)
printf("\n--(*ptr)\n");
printf("Before: %p Value: %d\n", ptr, *ptr);
--(*ptr);
printf("After : %p Value: %d\n", ptr, *ptr);
```

```
First ptr: 000000FB908FFB58 Value: 10

*ptr++
Before: 000000FB908FFB58 Value: 10
After : 000000FB908FFB5C Value: 20

(*ptr)++
Before: 000000FB908FFB5C Value: 20
After : 000000FB908FFB5C Value: 21

++*ptr
Before: 000000FB908FFB5C Value: 21
After : 000000FB908FFB5C Value: 22

++(*ptr)
Before: 000000FB908FFB5C Value: 22
After : 000000FB908FFB5C Value: 23

*ptr--
Before: 000000FB908FFB5C Value: 23
After : 000000FB908FFB58 Value: 10

(*ptr)--
Before: 000000FB908FFB58 Value: 10
After : 000000FB908FFB58 Value: 9

--*ptr
Before: 000000FB908FFB58 Value: 9
After : 000000FB908FFB58 Value: 8

--(*ptr)
Before: 000000FB908FFB58 Value: 8
After : 000000FB908FFB58 Value: 7
```

## 포인터의 형변환

- 포인터는 특정 자료형의 메모리 주소를 저장하는 변수이다. 포인터는 자료형에 따라 접근하는 데이터 크기와 의미가 다르기 때문에, 특정 경우 포인터의 형 변환이 필요하다.
- `void*`는 특정 자료형을 명시하지 않은 범용 포인터로, 어떤 자료형의 데이터든 가리킬 수 있다.
- 포인터 형 변환은 자료형에 맞게 데이터를 해석하거나, 범용 포인터`void*` 를 특정 자료형 포인터로 변환할 때 사용된다.

### 문법

```c
(자료형*)포인터
```

- **명시적 형 변환:** `(자료형*)` 을 사용하여 포인터를 원하는 자료형으로 변환.
- **`void*` 변환:** 다른 자료형 포인터를 `void*` 로 변환하거나, 그 반대의 변환도 가능.

### 예시

```c
int x = 10;
void* ptr = &x;  
// void* 로 저장
printf("%d\n", *(int*)ptr);  
// int 형으로 변환해야 한다
```

```
10
```