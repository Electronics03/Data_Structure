# Overflow
Overflow(오버플로우)는 컴퓨터에서 데이터가 저장할 수 있는 범위를 초과했을 때 발생하는 현상이다. 이는 특히 정수형 자료형과 부동소수점 자료형에서 자주 발생하며, 예기치 않은 값으로 변하거나 오류를 초래할 수 있다.

## 1. 오버플로우의 발생 원리

### 1) 고정된 데이터 크기

- 컴퓨터는 메모리를 효율적으로 사용하기 위해 변수에 할당된 고정된 크기의 비트를 사용하여 값을 저장한다.
- 변수의 자료형에 따라 저장 가능한 값의 범위가 제한된다.
- 이 범위를 초과하면 오버플로우가 발생한다.

### 2) 비트 순환

- 값을 범위를 초과할 경우, 최대값에서 최소값으로 순환하거나 반대로 동작한다.
- 이는 데이터의 음수 표현 방식에 따른 것이다.

## 2. 정수형 오버플로우

### 1) 부호 있는 정수

- 부호 있는 정수(`signed int`)는 **양수와 음수**를 모두 표현할 수 있다.
- 최대값을 초과하면 **음수의 최소값**으로 순환.

### 2) 부호 없는 정수

- 부호 없는 정수(`unsigned int`)는 양수만 표현 가능하다.
- 최대값을 초과하면 **0부터 다시 시작**.

### 예제:

```cpp
int max = INT_MAX; 
// 정수 최대값: 2147483647
printf("Max: %d\n", max);
printf("Overflow: %d\n", max + 1); 
// 오버플로우 발생

unsigned int unsigned_max = UINT_MAX; 
// 부호 없는 정수 최대값: 4294967295
printf("Max Unsigned: %u\n", unsigned_max);
printf("Overflow Unsigned: %u\n", unsigned_max + 1); 
// 오버플로우 발생
```

```
Max: 2147483647
Overflow: -2147483648
Max Unsigned: 4294967295
Overflow Unsigned: 0
```

## 3. 부동소수점 오버플로우

### 1) 발생 원리

- 부동소수점 자료형(`float`, `double`)은 매우 큰 값을 표현할 수 있지만, 표현 가능한 범위를 초과하면 Infinity(무한대)로 처리된다.

### 2) 부동소수점의 `NaN`

- 특정 연산이 불가능한 경우(`0.0 / 0.0`) 결과가 NaN(Not a Number)로 표시된다.

### 예제:

```cpp
float large = FLT_MAX; 
// float 최대값
printf("Max float: %e\n", large);
printf("Overflow: %e\n", large * (float)2.0); 
// 오버플로우 발생
```

```
Max float: 3.402823e+38
Overflow: inf
```

## 4. 오버플로우와 언더플로우

### 1) 오버플로우 (Overflow)

- 값이 **최대값을 초과**했을 때 발생.
- 예: `2147483647 + 1` → `2147483648` (부호 있는 정수)

### 2) 언더플로우 (Underflow)

- 값이 **최소값보다 작아졌을 때** 발생.
- 정수형에서는 **최소값에서 최대값으로 순환**.
- 부동소수점에서는 값이 0에 가까워지고, 결국 **0으로 소멸**.

### 예제:

```cpp
float small = 1.0e-45; 
// 매우 작은 값
printf("Small value: %e\n", small);
printf("Underflow: %e\n", small / (float)10);
// 언더플로우 발생
```

```
Small value: 1.401298e-45
Underflow: 0.000000e+00
```