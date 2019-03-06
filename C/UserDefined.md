# 구조체 (structure)
- **구조체**는 **하나 이상의 변수(포인터 변수, 배열 포함)를 묶어서 새로운 자료형을 정의**하는 도구.
- **사용자 정의 자료형** 이라 한다.
- **구조체를 통해서 연관있는 데이터를 하나로 묶을 수 있는 자료형을 정의**하면, 데이터의 표현 및 관리가 용이해지고 **합리적인 코드를 작성**할 수 있다.
- EX
-        struct point
        {
            int xpos;   //point 구조체를 구성하는 멤버 xpos
            int ypos;   //point 구조체를 구성하는 멤버 ypos
        };
-       struct person
        {
        char name[20];
        char phoneNum[20];
        int age;
        };

## 구조체 변수 선언
## **`struct`** **`type_name`** **`val_name`**;
EX
**struct point pos;**
**struct person man;**

## 구조체 변수 접근
- 접근의 기본형식은 다음과 같다.
- 구조체 변수의 이름.구조체 멤버의 이름
pos.xpos = 20;
printf("%s \n", man.name);
- 구조체 변수의 주소값은 구조체 변수의 첫 번째 멤버의 주소 값과 동일하다.

```
#include <stdio.h>
#include <math.h>

struct point
{
    int xpos;
    int ypos;
};

int main(void)
{
    struct point pos1, pos2;
    double distance;
    
    fputs("point1 pos: ", stdout);
    scanf("%d %d", &pos1.xpos, &pos1.ypos);
    
    fputs("point2 pos: ", stdout);
    scanf("%d %d", &pos2.xpos, &pos2.ypos);
    
    distance = sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos-pos2.xpos) + (pos1.ypos-pos2.ypos)*(pos1.ypos-pos2.ypos)));
    
    printf("두 점의 거리는 %g 입니다. \n", distance);
    return 0;
}
```
위 코드와 같이 구조체 변수에 접근할 때 . 연산자를 사용한다.

## 구조체 변수의 초기화
- 배열의 초기화와 동일하다.
- 초기화 과정에서 문자열 저장을 위해 strcpy를 호출 않해도 된다.
```
#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

struct person
{
    char name[20];
    char phoneNum[20];
    int age;
};

int main(void)
{
    struct point pos = {10, 20};
    struct person man = {"이승기", "010-1212-0001", 21};
    printf("%d %d\n", pos.xpos, pos.ypos);
    printf("%s %s %d \n", man.name, man.phoneNum, man.age);
    return 0;
}
```
## 구조체 배열
- 일반적인 배열을 선언하는 방법과 동일하다.
## **`struct`** **`point`** **`arr[10]`**;

- 구조체 배열을 초기화 할때는 배열의 길이만큼 중괄호를 이용한다.
- EX
-       struct person arr[2]={
            {"김현준", "010-1234-5678", 27},
            {"최은정", "010-5678-1234", 23}
        };

## 구조체 변수와 포인터
- 구조체 포인터 변수의 선언 및 연산 방법도 일반적인 포인터의 방법과 다르지 않다.
- struct point pos = {11,12};
- struct point* pptr = &pos;
다음과 같이 접근.
-       (*pptr).xpos = 10;// pptr이 가리키는 구조체 변수의 xpos에 10 저장.
        (*pptr).ypos = 20;// pptr이 가리키는 구조체 변수의 ypos에 20 저장.
- **위의 두문장은 다음과 같이 쓸 수 있으며 대체로 사용된다.**
-       pptr -> xpos = 10;
        pptr -> ypos = 20;
```
#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

int main(void)
{
    struct point pos1 = {1,2};
    struct point pos2 = {100,200};
    struct point* pptr = &pos1;
    
    (*pptr).xpos = 4;
    pptr->ypos = 5;
    printf("[%d %d]\n", pptr->xpos,  (*pptr).ypos);
    
    return 0;
}
```
## 포인터 변수를 구조체 멤버로 선언
```
struct point
{
    int xpos;
    int ypos;
    struct point* ptr;
};

int main(void)
{
    struct point pos1 = {1,2};
    struct point pos2 = {2,3};
    struct point pos3 = {3,1};
    
    pos1.ptr = &pos2; // pos1이 pos2를 가리킨다
    pos2.ptr = &pos3; // pos2가 pos3을 가리킨다
    pos3.ptr = &pos1; // pos3이 pos1을 가리킨다.
    
    printf("%d %d %d\n", (pos1.ptr)->xpos, (pos2.ptr)->xpos, (pos3.ptr)->xpos);
    
    return 0;
}
```
위 코드의 결과는 다음과 같다.
```
2 3 1
```
이와 같이, **구조체 변수로 포인터 변수가 올 수 있으며, 같은 타입의 구조체 포인터 변수를 둘 수 있다.**


## typedef
- typedef는 기존에 존재하는 자료형의 이름에 새 이름을 부여하는것.
-
        typedef int INT;
        INT num;
        INT* ptr;
        
        
## 구조체의 정의와 typedef의 선언
-       struct point
        {
            int xpos;
            int ypos;
        };
        
        struct point pos;
-       typedef struct point Point;
        Point pos;

- 두가지를 묶어서
-       typedef struct point
        {
            int xpos;
            int ypos;
        }Point;
- 다음과 같이 표현도 가능하다.
-       typedef struct
        {
            int xpos;
            int ypos;
        }Point;

## 구조체 변수로 가능한 연산
- 대입연산, &연산 , sizeof 연산 정도만 가능
- 나머지는 함수를 정의해서 해야한다.

## 공용체(union)
- 정의 방식은 구조체와 매우 유사하다. (struct만 union으로 바뀜)
- 공용체가 선언되면 크기가 가장 큰 멤버의 변수만 하나 할당되어 이를 공유함.
- 하나의 메모리 공간을 둘 이상의 방식으로 접근할 수 있다.
```
#include <stdio.h>

typedef struct dbshort
{
    unsigned short upper;
    unsigned short lower;
}DBshort;

typedef union rdbuf
{
    int iBuf;
    char bBuf[4];
    DBshort sBuf;
}RDBuf;

int main(void)
{
    RDBuf buf;
    printf("정수 입력: ");
    scanf("%d", &(buf.iBuf));
    
    printf("상위 2바이트: %u \n", buf.DBshort.upper);
    printf("하위 2바이트: %u \n", buf.DBshort.lower);
    printf("상위 1바이트 아스키코드 : %c \n", buf.bBuf[0]);
    printf("하위 1바이트 아스키코드 : %c \n", buf.bBuf[3]);
    
    return 0;
}
```
위 코드의 결과값은 다음과 같다.
```
정수 입력: 1145258561
상위 2바이트: 16961
하위 2바이트: 17475
상위 1바이트 아스키코드 : A
하위 1바이트 아스키코드 : B
```
이와 같이, 공용체는 같은 공간의 메모리를 공유하므로, 다양하게 출력할 수 있다.

## 열거형
- syllable형 변수에 저장이 가능한 정수 값들을 결정
-       enum syllable{
         Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7    
        };
- 열거형은 **둘 이상의 연관이 있는 이름을 상수로 선언함으로써 프로그램의 가독성을 높인다.**
