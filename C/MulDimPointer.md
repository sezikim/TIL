## 2차원 배열
## **`TYPE`** **`arr`** **`[열]`** **`[행]`**;

![2차원 배열](http://cfile218.uf.daum.net/image/240F8D3D5270EB961332C6)
## 2차원 배열의 메모리상 할당
int arr[3][2];
0x1000 arr[0][0]
0x1004 arr[0][1]
0x1008 arr[1][0]
0x100C arr[1][1]
0x1010 arr[2][0]
0x1014 arr[2][1]
## 2차원 배열 선언과 동시에 초기화
- 선언과 동시에 초기화
```
int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
int arr[3][3] = {{1},{4,5},{7,8,9}};
arr[3][3] == {{1,0,0},{4,5,0},{7,8,9}};
int arr[3][3] = {1,2,3,4,5,6,7};
arr[3][3] == {1,2,3,4,5,6,7,0,0};

1차원 배열과 같이 초기화 할때, 안채워진 부분은 0으로 초기화가 된다.
```
- 크기를 알려주지 않고 초기화
int arr[][] = {1,2,3,4,5,6,7,8}; //컴파일 에러
    - 배열 요소의 행과 열을 결정짓는 경우의 수가 다수 존재함으로, 하나를 가르쳐 줘야한다

- int arr1[][4] = {1,2,3,4,5,6,7,8};
- int arr2[][2] = {1,2,3,4,5,6,7,8};

## 3차원 배열
- 다수의 2차원 배열로 이루어진 배열.

## 더블 포인터
## **`int`** **`**`** **`dptr`**
- 이와 같이 **`*`연산자를 두 개 사용해서 선언하는 이중 포인터 변수를 더블포인터**, **하나**만 사용해서 선언하는 포인터 변수를 **싱글포인터** 라고 한다.
- 포인터는 종류에 상관없이 주소 값을 저장하는 변수.
- 더블 포인터는 포인터 변수를 가리킨다.
![더블 포인터](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRfzvaJn4mrzr4sUoa8OgeZaLvlloQXgRZ50xTMFCFkrbRRoZ34)

```
#include <stdio.h>

int main(void)
{
    double num = 3.14;
    double *ptr = &num;
    double **dptr = &ptr; //dptr은 ptr을 가리킴
    double *ptr2;
    
    printf("%9p %9p \n", ptr, *dptr); // 같은표현
    printf("%9g %9g \n", num, **dptr); //같은표현
    ptr2 = *dptr // ptr2에 ptr을 대입
    *ptr2 = 10.99;
    printf("%9g %9g \n", num, **dptr);
    return 0;
}
```
위 코드의 실행결과는 다음과 같다.
```
0032FD00    0032FD00
3.14        3.14
10.99       10.99
```
## 포인터 변수 대상의 Call-by-reference
```
#include <stdio.h>

void Swap(int** dp1, int** dp2)
{
    int* temp = *dp1;
    *dp1 = *dp2;
    *dp2 = temp;
}

int main(void)
{
   int num1 = 10, num2 = 20;
   int *ptr1, *ptr2;
   ptr1 = &num1, ptr2 = &num2;
   printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);
  
  Swap(&ptr1, &ptr2);
  printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);
  return 0;
}
```
위 코드의 실행결과는 다음과 같다.
```
*ptr1, *ptr2: 10 20
*ptr1, *ptr2: 20 10
```
- Swap 함수에 ptr1과 ptr2의 주소값을 전달해 포인터가 가리키는 num값을 변경하였다.
- Swap 함수가 싱글포인터 매개변수를 사용하면 단순히 함수내에서만 주소값의 교환이 일어날 것이다.

## 다중 포인터
- 포인터 변수의 선언에 있어서 `*`연산자가 둘 이상 사용되어 선언되는 포인터 변수.

## 2차원 배열이름의 포인터형
- 2차원 배열이라고 더블 포인터가 아니다.
## **int arr2d[2][3]**;
- arr2d는 [0][0]에 위치한 첫번째 요소를 가리킨다. (배열 전체를 의미)
- arr2d[0], arr2d[1], arr2d[2]는 각각 1행, 2행, 3행의 첫 번째 요소를 가리킨다. (각각의 행을 의미)

## 2차원 배열이름의 포인터 변수 증감
- arr2d+1 -> arr2d[1]와 같음.
- arr2d[0]+1 -> arr2d[0][1]와 같음.
```
#include <stdio.h>
int main(void)
{
    int arr1[3][2];
    int arr2[2][3];
    
    printf("arr1: %p \n", arr1);
    printf("arr1+1: %p \n", arr1+1);
    printf("arr1+2: %p \n", arr1+2);
    printf("arr1[0]+1: %p \n", arr1[0]+1);
    
    printf("arr2: %p \n", arr2);
    printf("arr2+1: %p \n", arr2+1);
    printf("arr2[0]+1: %p \n", arr2[0]+1);
    return 0;
}
```
위 코드의 실행결과는 다음과 같다.
```
arr1: 004BFBE0
arr1+1: 004BFBE8
arr1+2: 004BFBF0
arr1[0]+1: 004BFBE4


arr2: 004BFBC0
arr2+1: 004BFBCC
arr2[0]+1: 004BFBC4
```
이와 같이, 배열 이름에 증감연산을 하면 sizeof(int)*(행의 크기) 만큼의 증감이 이루어지고, 각각의 행에 증감연산을 하면 sizeof(int) 만큼의 증감이 이루어진다.

## 2차월 배열의 포인터 변수 선언
## **`int`****`(*ptr)`****`[4]`**
- int형 변수이며 sizeof(int)*4의 크기단위로 증감하는 포인터 변수 ptr
## **`float`****`(*ptr)`****`[7]`**
- float형 변수이며 sizeof(float)*7의 크기단위로 증감하는 포인터 변수 ptr

```
#include <stdio.h>

int main(void)
{
    int arr1[2][2] = { {1, 2}, {3, 4} };
   
    int (*ptr)[2];
    int i;
    int j;
    
    ptr = arr1;
    
    for(i=0; i<2; i++){
        for(j=0; j<2; j++)
            printf("%d ", *(*(ptr+i)+j);
        printf("\n");
        printf("%d ", **(ptr+i));
        printf("\n");
    }
   
    return 0;
}
```
위 코드의 실행결과는 다음과 같다.
```
1 2
1
3 4
3
```
- 위와 같이 배열 포인터의 이름에 참조연산자 한번을 붙이면 행을 의미하고, 두번을 붙이면 값을 의미한다.
- 배열 포인터의 이름에 증감연산을 하면 sizeof(타입)*행의 크기 만큼 주소값이 증감이 된다.
