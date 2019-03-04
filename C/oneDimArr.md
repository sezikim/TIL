# 배열 (Array)
- 둘 이상의 변수를 모아 놓은 것.
- 다수의 데이터를 저장하고 처리하는 경우에 유용하게 사용할 수 있는 것.

## 1차원 배열
- 1차원 배열의 선언에 필요한 세가지
## `int` `arr` `[4]`
**자료형** **배열이름** **배열크기**

## 1차원 배열의 접근
- **배열의 위치정보를 표시하는 숫자 인덱스**를 이용.
- **인덱스 값은 0에서부터 시작**한다.
- **배열의 모든 요소는 반복문**을 통해 순차적으로 접근 가능하다.
```
#include <stdio.h>

int main(void)
{
    int arr[5];
    int sum = 0;
    int i;
    
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    
    for(i=0; i<5; i++)
      sum += arr[i];
    
    printf("배열요소에 저장된 값의 합 : %d \n", sum);
    
    return 0;
}
```
## 배열 선언과 동시에 초기화하기
1. int arr[5] = {1, 2, 3, 4, 5};
    - 순차적으로 1, 2, 3, 4, 5로 초기화
2. int arr[] = {1, 2, 3, 4, 5};
    - 컴파일러에 의해서 자동으로 5가 삽입됨
3. int arr[5] = {1, 2};
    - 순차적으로 채워나가되, 나머지는 0으로 초기화됨.
## 배열을 이용한 문자열 변수의 표현
- char str[14] = "Good morning!";
- char str[] = "Good morning!";
    - 컴파일러가 배열의 길이를 14로 결정.
- **문자열을 끝에 null값이 삽입되어, 문자의 갯수는 13이어도 실제 문자열의 길이는 14가된다.**
```
#include <stdio.h>

int main(void)
{
    char str[] = "Good Morning!";
    
    printf("배열 str의 크기: %d \n", sizeof(str));
    printf("null 문자 문자형 출력: %c \n", str[13]);
    printf("null 문자 정수형 출력: %d \n", str[13]);
    
    str[12] = '?';
    printf("문자열 출력: %s \n", str);
    
    return 0;
}
```
```
배열 str의 크기: 14
null 문자 문자형 출력:
null 문자 정수형 출력: 0
문자열 출력: Good Morning?
```
- null 문자의 아스키 코드값은 0, 문자로 출력시 아무것도 출력이 안됨.
- **공백 문자와는 다르다.** 공백 문자의 아스키 코드값은 32.

- scanf를 통해 문자열 입력받기
```
#include <stdio.h>

int main(void)
{
    char str[50];
    int idx = 0;
    
    printf("문자열 입력: ");
    scanf("%s", str); 
    // str에 &를 안붙인다. str이 str[50]의 시작주소를 갖고있기 때문이다.
    
    printf("문자 단위 출력: ");
    while(str[idx != '\0') // null 문자를 만날 때 까지
    {
        printf("%c", str[idx]);
        idx++;
    }
    printf("\n");
    
    return 0;
}
```

- scanf 함수호출을 통해서 입력 받은 문자열의 끝에도 null 문자가 삽입되어 있다.
- **C 언어에서 표현하는 모든 문자열의 끝에는 null 문자가 자동으로 삽입된다.**
    - char형 배열은 null 문자가 없다.
- **문자열에서 null문자는 문자열의 끝을 의미한다.**
