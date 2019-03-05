# 함수의 이름
- **함수의 이름**은 **함수가 저장된 메모리 공간의 주소값**을 의미.

# 함수 포인터
- 함수이름의 포인터형은 **반환형**과 **매개변수**의 선언을 통해서 결정된다.
## **`int`** **`(*fptr)`** **`(int, int)`**;
- 반환형이 int이고, 두개의 int 매개변수를 갖는 포인터 fptr

```
#include <stdio.h>

// 함수 포인터가 매개변수로 들어간다.
int WhoIsFirst(int age1, int age2, int (*cmp)(int n1, int n2))
{
    return cmp(age1,age2);
}

int OlderFirst(int age1, int age2)
{
    if(age1>age2)
        return age1;
    else if(age1<age2)
        return age2;
    else
        return 0;
}

int YoungerFirst(int age1, int age2)
{
     if(age1<age2)
        return age1;
    else if(age1>age2)
        return age2;
    else
        return 0;
}

int main(void)
{
    int age1 = 20;
    int age2 = 30;
    int first;
    
    printf("입장순서1 \n");
    first = WhoIsFirst(age1, age2, OlderFirst); // 함수의 이름은 함수의 주소를 가리키므로, 함수포인터 매개변수로 쓰임.
    printf("%d세와 %d세 중 %d세가 먼저 입장! \n", age1, age2, first);
    
    printf("입장순서2 \n");
    first = WhoIsFirst(age1, age2, YoungerFirst); // 함수의 이름은 함수의 주소를 가리키므로, 함수포인터 매개변수로 쓰임.
    printf("%d세와 %d세 중 %d세가 먼저 입장! \n", age1, age2, first);
    return 0;
}
```
위 코드의 실행결과는 다음과 같다.
```
입장순서 1
20세와 30세 중 30세가 먼저 입장!
입장순서 2
20세와 30세 중 20세가 먼저 입장!
```
-이와 같이, **함수의 이름**은 **함수가 저장된 메모리 공간의 주소값**을 의미하므로, 함수포인터 매개변수 값으로 들어간다.

## void 포인터
## **`void*` **`ptr`**** ;
- void형 포인터 변수는 **어떠한 변수의 주소 값이든 담을 수 있다**.
- **함수의 주소값도** 담을 수 있다.
- void 포인터의 변수를 가지고는 **포인터 연산을 하지 못한다.**
