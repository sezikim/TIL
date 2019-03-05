## 함수의 인자로 배열 전달.
- void func(int* arr, int len){ ... }
- void func(int[] arr, int len){ ... }
- 두 선언 완전 동일한 선언
- 둘이 같은 선언으로 간주되는 경우는 매개변수의 선언으로 제한된다.


## Call by value
- 단순히 값을 전달하는 형태의 함수호출
```
#include <stdio.h>

void Swap(int n1, int n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
    printf("n1 n2 : %d %d \n", n1, n2);
}

int main(void)
{
    int num1 = 10;
    int num2 = 20;
    printf("num1 num2 : %d %d \n", num1, num2);
    
    Swap(num1,num2);
    printf("num1 num2 : %d %d \n", num1, num2);
    return 0;
}
```
위 코드의 실행결과는 다음과 같다.
```
num1 num2 : 10 20
n1 n2 : 20 10
num2 num1 : 10 20
```
- 이와 같이, 단순히 값을 함수의 매개변수에 복사해서 호출한 함수를 작동시키고, 전달한 변수 값에는 변화가 없다.
## Call by reference
- 메모리 접근에 사용되는 주소값을 전달하는 형태의 함수호출
```
#include <stdio.h>

void Swap(int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(void)
{
    int num1 = 10;
    int num2 = 20;
    printf("num1 num2: %d %d\n", num1, num2);
    Swap(&num1,&num2);
    printf("num1 num2: %d %d\n", num1, num2);
    return 0;
}
```
위 코드의 실행결과는 다음과 같다.
```
num1 num2: 10 20
num1 num2: 20 10
```
- 이와 같이, 메모리의 주소를 함수의 매개변수로 전달하여 전달한 주소가 참조하는 값을 바꿀 수 있다.

## 포인터 대상의 const 선언
## **`const`** int* ptr = &num
- 포인터 변수 ptr을 이용해서 참조하는 값의 변경을 불허한다.
## int* **const** ptr = &num
- 한번 가리키기 시작한 변수를 끝까지 가리켜야 한다.
