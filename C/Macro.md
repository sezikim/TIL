# 선행처리
- 컴파일 이전의 처리.
- **선행처리의 과정을 거쳐도 소스파일의 형태**가 그대로 유지된다.

## macro
- object like  macro
    - 매크로 상수
    -     #define PI 3.1415

- function like macro
    - 매크로 함수
    - **전달인자 하나하나에 괄호**를 하고, **전체를 괄호**로 한번 더 묶어줘야 한다.
    -     #define SQUARE(X) X*X
          SQUARE(3+2) -> 3+2*3+2 -> 11
          //전달인자 하나하나를 괄호로 묶지 않으면 원하지 않는 결과를 초래.
    -     #define SQUARE(X) (X)*(X)
          int num = 120 / SQUARE(2);
          //전달인자 전체를 괄호로 묶지 않으면 원하지 않는 결과를 초래.
          -> 120 / (2) * (2) -> 60
    -     #define SQUARE(X) ((X)*(X))
- 매크로 함수의 장점
    - 일반 함수에 비해 **실행속도가 빠름**
        - 함수가 호출되며 생기는 사항들을 동반할 필요가 없음.
    - **자료형에 따라서 별도로 함수를 정의하지 않아도 된다.**
- 매크로 함수의 단점
    - 정의하기가 까다롭다
    - 디버깅하기가 쉽지 않다.
- **크기가 작으나 호출의 빈도수가 높은 함수를 매크로로 정의한다.**

## 조건부 컴파일 매크로
- #if ~ #endif
```
#include <stdio.h>

int main(void)
{
    int num1 = 5;
    int num2 = 5;
#if 1   //0이면 실행이 되지 않는다.
    printf("num1과 num2의 합은 %d\n", num1+num2);
#endif
    return 0;
}
```
 #if~#endif 까지의 코드는 #if 뒤에 오는 숫자가1 이면 실행, 0이면 실행이 되지 않는다.

- #ifdef ~ #endif
```
#include <stdio.h>
#define ADD 1 // 주석처리시 덧셈연산 코드 실행X
#define MIN 0

int main(void)
{
    int num1 = 5;
    int num2 = 5;
#ifdef ADD
    print("%d + %d = %d\n", num1, num2, num1+num2);
#endif

#ifdef MIN
    printf("%d - %d = %d\n", num1, num2, num1-num2);
#endif
    return 0;
}
```
 #ifdef ~ #endif 까지의 코드는 #ifdef뒤에 오는 매크로가 define 되어있으면 실행, 아니면 실행시키지 않는다.
