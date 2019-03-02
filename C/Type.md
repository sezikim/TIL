# 자료형
- Data type
- 데이터를 표현하는 방법

## C언어의 기본 자료형
|자료형|크기|값의 표현범위|
|---|---|---|
|char|1 byte|-128~127|
|short|2 byte|-32,768 ~ 32,767|
|int|4 byte|-21억 ~ 21억|
|long|4 byte|-21억 ~ 21억|
|long long|8 byte|-(2^63) ~ (2^63)-1/
|float|4 byte|위는 정수형, 아래는 실수형|
|double|8 byte||
|long double|more than 8 byte||
- 정수를 표현 및 처리하기 위해 일반적으로 int를 사용한다.
    - CPU가 성능을 내기에 가장 좋은 자료형
- 실수를 표현 및 처리하기 위해 일반적으로 double을 사용한다.
    - 정밀도를 중요하게 생각하는 실수형 자료형에서, long double은 크기가 부담스럽고 float은 정확성이 떨어짐으로.
- unsigned를 붙여 양의 정수만 표현가능
    - MSB까지 데이터의 크기를 표현하는데 사용
    - 표현 범위가 0이상으로 두배가 된다.
    - 실수형은 표현 방식이 다르기 때문에 적용이 안된다

## 문자의 표현
- 컴퓨터는 숫자를 이용해서 무엇인가를 인식함.
- 따라서, 숫자를 문자에 연결시켜 문자를 표현.
- C언어는 ASCII 코드 표준을 선택해 문자를 표현.
![아스키 코드](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQjjZlShrDu1_gE4tVKz6lE_0AUQfjwfLJ9zEBQLceXgU2edCnS)

```
#include <stdio.h>

int main(void){
    char ch1 = 'A';
    //다음과 같이 문자는 ''로 감싸서 표현.
    //실제로 ch1에 저장되는 값은 A의아스키코드 값인 65이다.
    
    int ch2 = 'B';
    //따라서 int형으로도 문자를 받을 수 있다.
    
    //어떤 서식문자를 사용하는지에 따라서 정수로, 문자로 출력할 수 있다.
    printf("%d\n", ch1);
    printf("%d\n", ch2);
    
    return 0;
}
```
## 자료형 변환
- 묵시적 형 변환
    - 자동 형 변환
    1. 대입 연산자의 왼편과 오른편에 존재하는 두 피연산자의 자료형이 일치하지 않으면 왼편에 있는 피연산자를 대상으로 형 변환이 자동으로 일어남.
        - double num1 = 245; 에서 num1값에 245.0이 들어간다.
        - 정수를 실수로 형 변환 하면 데이터의 손실은 일어나지 않지만, 오차가 존재.
        - 실수를 정수로 형 변환 하면 소수점 이하의 값이 버려짐.
        - 바이트 크기가 큰 정수를 작은 정수로 형 변환 하면, **작은 정수의 바이트 크이게 맞춰서 상위 바이트를 버림으로, 주의**
    2. 정수의 승격에 의한 자동 형 변환
        - 산술연산시, **CPU가 처리하기 가장 적합한 크기의 정수 자료형인 int**로 자동 형변환 된다.
            - shor num1 = 15, num2 = 25;
        short num3 = num1 + num2;
        num3에 num1 + num2을 연산한 int형을 대입한다. -> num3 이 short형이기 때문에 자동 형 변환이 일어난다.
    3. 산술연산에서 두개의 피연산자가 일치하지 않은경우, 자동 형변환이 일어난다.
        - **데이터 손실을 최소화 하는 방향**으로 자동 형변환.
        ![산술연산 형변환규칙](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTqMiDaHSHZLa5Wy6fNhy6Ic1y-_m4-6YIglvWcU5f1K9s18kvTig)
        - 형변환의 우선순위는 **정수 자료형보다 실수 자료형이 무조건 앞서는 형태**.
    - 명시적 형 변환
        - 형 변환 연산자를 이용해 강제로 형변환을 하는것.
        ```
        #include <stdio.h>
        
        int main(void)
        {
            int num1 = 3, num2 = 4;
            double divResult;
            //divResult = num1 / num2; 하면 결과가 0.000000
            divResult = (double)num1 / num2;
            printf("Result: %f \n",divResult);
            //명시적 형 변환을 해서 결과가 0.75가 출력됨.
            return 0;
        }
        ```
