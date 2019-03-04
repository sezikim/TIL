## if
- 분기의 가장 기본
```
if(num1 > num2){
    printf("num1이 num2보다 큽니다.\n");
    printf("%d > %d \n", num1, num2);
}
```
- 위와 같이 if문 뒤의 ()안에 조건문이 들어감.
- **조건문이 '참'이면** 뒤에 코드를 실행시킨다.

## if else
- else는 if와 더불어 하나의 문장을 구성하는 형태
- if절의 조건이 '참'이면 if 블록이 실행, '참'이 아니면 else 블록이 실행되는 구조.
```
#include <stdio.h>

int main(void){
    int num;
    
    printf("정수 입력:");
    scanf("%d", &num);
    
    if(num<0)
        printf("입력값은 0보다 작다. \n");
    else
        printf("입력값은 0보다 작지 않다.\n");
    
    return 0;
}
```

## if ~ else if ~ else
- if else 문을 중첩시킨 형태
- if와 else 중간에 else if를 삽입해 조건을 더 넣을 수 있다.
```
#include <stdio.h>

int main(void){
    int num;
    
    printf("정수 입력: ");
    scanf("%d", &num);
    
    if(num<0)
        printf("입력값은 0보다 작다. \n");
    else if(num == 0)
        printf("입력값은 0이다. \n");
    else
        printf("입력값은 0보다 크다. \n");
    
    return 0;
}
```

## 삼항연산자
- if ~else문을 일부 대체할 수 있는 조건 연산자
- **`(조건문)`** **`?`** **`data1`** : **`data2`**
- 조건문이 '참'이면 data1이 반환, '거짓'이면 data2 반환

```
include <stdio.h>

int main(void){
    int num, abs;
    
    printf("정수 입력: ");
    scanf("%d", &num);
    
    abs = num>0 ? num : -num;
    printf("절댓값: %d\n", abs);
    
    return 0;
}
```
## break
- **반복문**을 탈출할 때 사용하는 키워드
- break문을 가장 가까이서 감싸고 있는 반복문을 하나 빠져나옴.
```
#include <stdio.h>

int main(void){
    int sum = 0, num = 0;
    while(1)
    {
        sum += num;
        if(sum>5000)
            break;
            // sum이 5000을 넘어가면, while문을 탈출
        num++;
    }
    printf("sum: %d\n", sum);
    printf("num: %d\n", num);
    
    return 0;
}
```
## continue
- continue를 사용하면, 반복문의 조건검사 문으로 이동, '참'이면 반복영역을 다시 실행.


## switch
- 아래의 코드처럼 num값으로 조건을 분기함.
- if else 문보다 사용하기 한정적. 하지만 많은 분기가 필요한 시점에 유용하다.
```
#include <stdio.h>

int main(void){
    int num;
    
    printf("1이상 5이하의 정수 입력: ");
    scanf("%d", &num);
    // num값이 2이면 case2 부터의 코드를 실행한다. -> case 2, 3, 4, 5, default 모두 실행. -> break을 통해서 이를 제어함
    // num값이 1, 2, 3, 4, 5가 모두 아니면, default영역이 실행. 
    switch(num){
        case 1:
            printf("1");
            //break;
        case 2:
            printf("2");
            //break;
        case 3:
            printf("3");
            //break;
        case 4:
            printf("4");
            //break;
        case 5:
            printf("5");
            //break;
        default:
            printf("1이상 5이하의 정수가 아닙니다. \n");
    }
    return 0;
}
```

