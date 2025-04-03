# Character

C++ 에서 문자형(Character Type)은 단일 문자를 저장하고 처리하기 위한 자료형이다. 문자형은 메모리에서 정수값으로 저장되며, 주로 ASCII 코드를 사용하여 문자와 숫자를 매핑한다.

## 1. 문자형 자료형의 특징

### 자료형 및 크기

- C++ 에서 문자를 저장하기 위해 `char` 자료형을 사용한다.
- 1Byte를 차지한다.

### 문자의 저장 방식

- 문자형 변수에는 실제로 문자가 아닌 해당 문자의 ASCII 코드 값이 저장된다.
- 자 `'A'`는 ASCII 코드로 65이며, 변수에 정수 65가 저장된다.

### 문자 리터럴

- 단일 문자는 작은따옴표(`'`)로 묶어서 표현한다.
- `'A'`, `'z'`, `'0'`, `'@'`.

## 2. ASCII Code

| 값 | 기호 | 값 | 기호 | 값 | 기호 | 값 | 기호 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | NULL | 32 | Space | 65 | A | 97 | a |
| 1 | SOH | 33 | ! | 66 | B | 98 | b |
| 2 | STX | 34 | " | 67 | C | 99 | c |
| 3 | ETX | 35 | # | 68 | D | 100 | d |
| 4 | EOT | 36 | $ | 69 | E | 101 | e |
| 5 | ENQ | 37 | % | 70 | F | 102 | f |
| 6 | ACK | 38 | & | 71 | G | 103 | g |
| 7 | BEL | 39 | ' | 72 | H | 104 | h |
| 8 | BS  | 40 | ( | 73 | I | 105 | i |
| 9 | TAB | 41 | ) | 74 | J | 106 | j |
| 10 | LF | 42 | * | 75 | K | 107 | k |
| 11 | VT | 43 | + | 76 | L | 108 | l |
| 12 | FF | 44 | , | 77 | M | 109 | m |
| 13 | CR | 45 | - | 78 | N | 110 | n |
| 14 | SO | 46 | . | 79 | O | 111 | o |
| 15 | SI | 47 | / | 80 | P | 112 | p |
| 16 | DLE | 48 | 0 | 81 | Q | 113 | q |
| 17 | DC1 | 49 | 1 | 82 | R | 114 | r |
| 18 | DC2 | 50 | 2 | 83 | S | 115 | s |
| 19 | DC3 | 51 | 3 | 84 | T | 116 | t |
| 20 | DC4 | 52 | 4 | 85 | U | 117 | u |
| 21 | NAK | 53 | 5 | 86 | V | 118 | v |
| 22 | SYN | 54 | 6 | 87 | W | 119 | w |
| 23 | ETB | 55 | 7 | 88 | X | 120 | x |
| 24 | CAN | 56 | 8 | 89 | Y | 121 | y |
| 25 | EM | 57 | 9 | 90 | Z | 122 | z |
| 26 | SUB | 58 | : | 91 | [ | 123 | { |
| 27 | ESC | 59 | ; | 92 | \ | 124 | | |
| 28 | FS | 60 | < | 93 | ] | 125 | } |
| 29 | GS | 61 | = | 94 | ^ | 126 | ~ |
| 30 | RS | 62 | > | 95 | _ | 127 | DEL |
| 31 | US | 63 | ? | 96 | ` |  |  |

## 3. 제어 문자

### 제어 문자의 특징

1. **ASCII 코드 0~31 및 127**에 해당하는 문자.
2. **주요 용도**:
    - 데이터 흐름 제어(통신 프로토콜에서 사용).
    - 텍스트 서식 지정(줄 바꿈, 탭 등).
    - 장치 제어(프린터, 터미널 등).
3. **표현 방식**:
    - 키보드에서 입력하기 어려우므로 보통 이스케이프 시퀀스나 약어로 표현된다.

### 제어 문자 표

| **ASCII** | **약어** | **제어 문자 이름** | **설명** |
| --- | --- | --- | --- |
| 0 | NUL | Null | 문자열 종료 또는 아무것도 하지 않음 |
| 1 | SOH | Start of Header | 헤더의 시작 |
| 2 | STX | Start of Text | 본문 텍스트의 시작 |
| 3 | ETX | End of Text | 본문 텍스트의 끝 |
| 4 | EOT | End of Transmission | 데이터 전송 종료 |
| 5 | ENQ | Enquiry | 응답 요청 |
| 6 | ACK | Acknowledge | 확인 신호 |
| 7 | BEL | Bell | 벨 소리 출력 (터미널에서 경고음) |
| 8 | BS | Backspace | 커서를 한 칸 뒤로 이동 |
| 9 | TAB | Horizontal Tab | 수평 탭 |
| 10 | LF | Line Feed | 줄 바꿈 |
| 11 | VT | Vertical Tab | 수직 탭 |
| 12 | FF | Form Feed | 새 페이지 시작 |
| 13 | CR | Carriage Return | 커서를 줄의 처음으로 이동 |
| 14 | SO | Shift Out | 확장 문자 모드 시작 |
| 15 | SI | Shift In | 표준 문자 모드 시작 |
| 16 | DLE | Data Link Escape | 데이터 링크 확장 |
| 17 | DC1 | Device Control 1 | 장치 제어 (XON) |
| 18 | DC2 | Device Control 2 | 장치 제어 |
| 19 | DC3 | Device Control 3 | 장치 제어 (XOFF) |
| 20 | DC4 | Device Control 4 | 장치 제어 |
| 21 | NAK | Negative Acknowledge | 확인 거부 |
| 22 | SYN | Synchronous Idle | 동기화 유지 |
| 23 | ETB | End of Transmission Block | 데이터 블록 전송 종료 |
| 24 | CAN | Cancel | 전송 취소 |
| 25 | EM | End of Medium | 미디어 종료 |
| 26 | SUB | Substitute | 대체 문자 |
| 27 | ESC | Escape | 이스케이프 문자 |
| 28 | FS | File Separator | 파일 구분자 |
| 29 | GS | Group Separator | 그룹 구분자 |
| 30 | RS | Record Separator | 레코드 구분자 |
| 31 | US | Unit Separator | 단위 구분자 |
| 127 | DEL | Delete | 삭제 |

### 이스케이프 시퀀스

| **ASCII** | **약어** | **제어 문자 이름** | **이스케이프 시퀀스** | **설명** |
| --- | --- | --- | --- | --- |
| 0 | NUL | Null | `\0` | 문자열 종료 또는 아무것도 하지 않음 |
| 7 | BEL | Bell | `\a` | 벨 소리 출력 (경고음) |
| 8 | BS | Backspace | `\b` | 커서를 한 칸 뒤로 이동 |
| 9 | TAB | Horizontal Tab | `\t` | 수평 탭 |
| 10 | LF | Line Feed | `\n` | 줄 바꿈 |
| 11 | VT | Vertical Tab | `\v` | 수직 탭 |
| 12 | FF | Form Feed | `\f` | 새 페이지 시작 |
| 13 | CR | Carriage Return | `\r` | 커서를 줄의 처음으로 이동 |
| 27 | ESC | Escape | `\e` (GCC 확장) | 이스케이프 문자 |
| 92 | \ | Backslash | `\\` | 백슬래시 문자 |
| 39 | `'` | Single Quote | `\'` | 작은따옴표 문자 |
| 34 | `"` | Double Quote | `\"` | 큰따옴표 문자 |
| 63 | `?` | Question Mark | `\?` | 물음표 문자 |