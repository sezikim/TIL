# LOOP

## while
- 특정조건을 만족하는 동안, 특정영역을 계속해서 반복하는 구조.
```
#include <stdio.h>

int main(void){

    int num = 0;
    
    while(num<3){
        printf("Hello world\n");
        num++;
    }
}
// 반복의 조건 num < 3
// printf("Hello world\n");
// num++;  을 반복
```
- 반복문의 조건을 빠져나가기 위한 연산이 중요함.
- 조건을 빠져나오지 못하는 반복문을  **무한루프**라 한다.

## do-while
- 반복조건을 뒷부분에서 검사하는 점이 while과 다르다.
- 반복조건을 만족시키지 못해도 **최소 한번은 실행하는 구조**.
```
#include <stdio.h>

int main(void){
    int num = 0;
    
    do{
        printf("Hello world\n");
        num++;
    } while(num<3);
}
// 반복 조건을 뒤에서 검사.
```
## for
- 가장 많이쓰이는 반복문의 형태.
- 반복을 위한 변수선언, 반복 조건, 조건을 만족시키기 위한 연산을 한줄에 표현함.
**`for`**(**`int a=0`**; **`a<4`**; **`a++`**){
    printf("Hello world\n");
}
괄호안의 조건들을 순서대로 **초기식**, **조건식**, **증감식** 이라고 한다.

- **초기식은 처음에만 진행**되고, **조건식을 만족하면 반복**을 진행, **반복한 후에는 증감식**을 실행한다.
