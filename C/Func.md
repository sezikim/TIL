# 함수
- Divide and Conquer!
## `int` `main` `(void)`
**반환형태** **함수이름** **입력형태**

## return문의 의미
1. 함수를 빠져나간다.
2. 값을 반환한다.

## 함수의 정의와 선언
- main 함수내에서 정의한 함수를 **사용하기 전에 함수가 정의되어 있어야 한다.**
```
#include <stdio.h>

int Increment(int n) {
    n++;
    return n;
}

int main(void)
{
    int num = 2;
    num = Increment(num);
    return 0;
}
```
- 다음과 같이 **함수를 main함수 위에 선언하고 뒤에 정의하는 식으로 작성도 가능하다.**
```
#include <stdio.h>

int Increment(int n);
//매개변수 이름을 생략하여 int Increment(int); 로도 표현이 가능하다.

int main(void) {
    int num  = 2;
    num = Incrementn(num);
    return 0;
}

int Increment(int n)
{
    n++;
    return n;
}
```

## 지역변수
- 함수 내에만 존재 및 접근 가능함.
- 해당 지역을 벗어나면 자동으로 소멸
```
#include <stdio.h>

int SimpleFuncOne(void)
{
    int num = 10;   // SimpleFuncOne의 num 유효
    num++;
    printf("SimpleFuncOne num: %d \n", num);
    return 0;   // SimpleFuncOne의 num 소멸
}

int SimpleFuncTwo(void)
{
    int num1 = 20;  // SimpleFuncTwo의 num1 유효
    int num2 = 30;  // SimpleFuncTwo의 num2 유효
    num1++, num2--;
    printf("num1 & num2: %d %d \n", num1, num2);
    return 0;   // SimpleFuncTwo의 num1, num2 소멸
}

int main(void)
{
    int num = 17; // main의 num 유효
    SimpleFuncOne();
    SimpleFuncTwo();
    printf("main num: %d \n", num);
    return 0; // main의 num 소멸
}
```
이는 다음과 같은 출력값을 갖는다.
```
SimpleFuncOne num: 11
num1 & num2: 21 29
main num: 17
```
## 전역변수
- 프로그램의 **시작과 동시에 메모리 공간에 할당되어 종료전까지 존재**.
- **별도의 값으로 초기화하지 않으면 0으로 초기화.**
- 프로그램 전체 영역 어디서든 접근가능.
- **전역변수 사용이 많으면 프로그램이 꼬이는 주범**이 될 수 있기 때문에, 신중하게 사용
```
#include <stdio.h>

void Add(int val);
int num;

int main(void)
{
    printf("num: %d \n", num);
    Add(3);
    printf("num: %d \n", num);
    num++; // 전역변수 num의 값 1 증가
    printf("num: %d \n", num);
    return 0;
}

void Add(int val)
{
    num += val; // 전역변수 num의 값 val만큼 증가
}
```
- 전역변수와 **동일한 이름을 갖는 지역변수가 선언**되면, 해당 지역 내에서는 **지역변수로의 접근**이 이루어진다.

## 지역변수 static
- 선언된 함수 내에서만 접근.
- 1회만 초기화되고 프로그램 종료 시까지 메모리 공간에 존재.
```
#include <stdio.h>

void SimpleFunc(void)
{
    static int num1 = 0;    // 초기화 하지 않으면 0으로 초기화
    int num2 = 0;
    num1++, num2++;
    printf("static: %d, local: %d\n", num1, num2);
}

int main(void)
{
    int i;
    for(i=0; i<3; i++){
        SimpleFunc();
    }
    return 0;
}
```
위코드의 결과값은 다음과 같다.
```
static: 1, local :1
static: 2, local :1
static: 3, local :1
```

## 재귀함수
- 함수 내에서 자기 자신을 다시 호출하는 함수.
![재귀함수](http://mblogthumb4.phinf.naver.net/20150818_71/kibum1223_14398961949147aQMO_JPEG/%C0%E7%A4%CC%B1%E21.jpg?type=w2)
- **탈출조건**을 구성하는 것이 매우 중요하다.
```
#include <stdio.h>

int Factorial(int n)
{
    if(n==0)
        return 1;   //Factorial 함수의 탈출조건.
        // Factorial(0)부터 반환하기 시작
    else 
        return n * Factorial(n-1);
}

int main(void)
{
    printf("1! = %d \n", Factorial(1));
    printf("2! = %d \n", Factorial(2));
    printf("3! = %d \n", Factorial(3));
    printf("4! = %d \n", Factorial(4));
    printf("9! = %d \n", Factorial(9));
    return 0;
}
```

