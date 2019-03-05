## 배열의 이름
- 배열의 이름은 **상수 포인터**(주소값 변경이 불가능)이다.
- 배열의 첫번째 요소의 주소값을 가지고있다.
- **배열요소간 주소 값의 차는 자료형의 크기만큼** 이다.
```
#include <stdio.h>

int main(void)
{
    int arr1[3] = {1, 2, 3};
    double arr2[3] = {1.1, 2.2, 3.3};
    
    printf("%d %g \n", *arr1, *arr2);
    //배열의 이름이 상수 형태의 포인터로 작용함.
    
    *arr1 += 100;
    *arr2 += 120.5;
    
    printf("%d %g \n", *arr1, *arr2);
    
    return 0;
}
```
위 코드의 실행결과는 다음과 같다.
```
1 1.1
101 121.6
```
## 포인터 연산
- 포인터 변수를 대상으로 증가 및 감소연산을 할 수 있다.
```
#include <stdio.h>

int main(void)
{
    int* ptr1 = 0x0010;
    double* ptr2 = 0x0010;
    // 적절한 초기화가 아니다. 값을 확인하기 위해 부적절한 초기화를 진행.
    printf("%p %p \n", ptr1+1, ptr2+1);
    // 4증가 , 8증가
    printf("%p %p \n", ptr2+2, ptr2+2);
    // 8증가, 16증가
    
    printf("%p %p \n", ptr1, ptr2);
    ptr1++; // 4증가
    ptr2++; // 8증가
    
    printf("%p %p \n", ptr1, ptr2);
    return 0;
}
```
- 위와 같이 포인터를 대상으로 연산을 했을때, sizeof(타입)만큼의 크기변화가 있다.
![포인터 연산](https://t1.daumcdn.net/cfile/tistory/194F6B014C51825C33)
## 배열에서의 연산
- 배열의 이름도 포인터 이므로, 포인터에서의 연산과 같이 접근할 수 있다.
```
#include <stdio.h>

int main(void)
{
    int arr[3] = {11, 22, 33};
    printf("%d %d %d", *arr, *(arr+1), *(arr+2));
    return 0;
}
```
위 코드의 출력값은 다음과 같다.
```
11 22 33
```

## 상수 형태의 문자열을 가리키는 포인터
- 변수 형태의 문자열
    - char str1[] = "My String";
    - 문자열 전체를 저장하는 배열
- 상수 형태의 문자열
    - char* str2 = "Your String";
    - 메모리 공간에 문자열 "Your String"이 저장되고, 문자열의 첫 번째 문자 Y의 주소값이 반환. 그 값을 포인터변수 str2에 저장한다.

- 변수, 상수 형태의 문자열의 차이점
    1. 변수 형태의 문자열은 다른 문자열을 가리킬 수 없다.
    2. 상수 형태의 문자열은 다른 문자열을 가리킬 수 있다.
    3. 변수 형태의 문자열은 문자열 요소의 변경이 가능하다.
    4. 상수 형태의 문자열은 문자열 요소의 변경이 불가능하다.
```
#include <stdio.h>
int main(void)
{
    char str1[] = "My team";
    char* str2 = "Your team";
    //str1[] = "their team"; 으로 변경 불가
    str2 = "Our team";
    
    str1[0] = 'X';
    //str2[0] = 'X'; 으로 변경 불가
    
}
```
## 포인터 배열
- 포인터 변수로 이루어진 배열
- 주소값이 저장 가능한 배열
## **`int`*** **`arr[20]`**;
```
#include <stdio.h>

int main(void)
{
    int num1=10, num2=20, num3=30;
    int* arr[3] = {&num1, &num2, &num3};
    char* str[3] = {"Simple", "String", "Array"};
    
    printf("%d %d %d", *arr[0], *arr[1], *arr[2]);
    printf("%s\n", *str[0]);
    printf("%s\n", *str[1]);
    printf("%s\n", *str[2]);
    return 0;
}

```

