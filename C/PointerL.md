# 포인터?
- 포인터는 주소를 담을 수 있는 타입이다.
- 포인터를 사용하는 이유
    - 함수에서 전달받은 인자의 값을 변경할 수 없기 때문에
    - Call by reference를 통해서 변경
- DRY 원칙
    - Don't Repeat Yourself

- C언어는 인자를 전달할 때, 복사를 수행한다.
    - Call by value

``` C
#include <stdio.h>

void swapr(int *a, int *b)
{
    int *temp = *a;
    *a = *b;
    *b = *temp;
}

void swapv(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;
    
    swapv(a,b);
    printf("%d %d\n", a, b);
    // a b 값이 변경이 되지 않는다.
    
    swapr(&a, &b);
    printf("%d %d\n", a, b);
    // a b 값이 변경되어 출력된다.
    
    return 0;
}
```

## 배열과 포인터
- 배열의 이름은 배열의 첫번째 원소의 시작주소를 의미한다.
- C에서의 모든 배열은 1차원 배열이다.
    - int arr[2][3] -> 원소가 int[3]인 배열.
- 함수의 인자로 배열을 전달할 때, 배열의 길이를 추가적으로 전달해야 한다.

## C언어에서 타입을 보는 방법
- **`int`** **`i`**;
    - 이름을 뺀 나머지가 타입이다.
    - int
- int arr[3]
    - int[3]
    - 배열의 이름은 배열의 첫번째 원소의 시작주소로 해석된다.

```C
#include <stdio.h>

void foo1(int (*arr)[3]){
    int i;
    
    for(i=0; i<3; ++i){
        (*arr)[i] += 10;
    }
}

void foo2(int (*arr)[4], int n){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<4;j++){
            printf("%d\n", arr[i][j]);
        }
    }
}

int main(){
    int i;
    int arr1[3] = {1, 2, 3};
    int arr2[3][4] = {0};
    
    
    
    foo1(&arr1);
    // int[3] *p = &arr;
    // int(*p)[3] = &arr;
    
    for(i=0; i<3; i++)
        printf("%d\n", arr1[i]);
    
    foo2(arr2, 3);
    // &arr2[0]
    // arr2[0]: int[4]
    // &arr2[0]: int(*)[4]
        
    return 0;
}
```
## 포인터를 배열의 연산으로 다룰 수 있다.
-     arr[N]
      -> *(arr+N)
      &arr[0]
      -> &*(arr+0)
      -> &*: 상쇄
      -> (arr+0)
      -> arr
```
int arr[3] = {1, 2, 3};
int *p = &arr[0];
// int *p = arr;
일 때, 다음은 모두 같은 표현이다
p[1]    *(p+1)  arr[1]  *(arr+1)    *(1+arr)    1[arr]
허나, *(1+arr) 1[arr]같은 표현은 사용하지는 않는다.
```

## 함수 포인터
- 함수를 가르키는 포인터
- 런타임에 어떤 함수를 호출할지 결정하고 싶다.
- 함수의 시그니쳐에 의해서 결정된다.
    - type(*fp)(type, type);

```C
int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int main(){
    int(*p)(int, int);
    
    //함수의 이름은 함수 포인터로 해석된다.
    
    //1번 방법
    p = &add;
    printf("%d\n", (*p)(10,20));
    //2번 방법
    p = sub;
    printf("%d\n", p(30,20);
    
    return 0;
}
```
## 함수포인터를 반환하는 함수
- 함수 포인터를 반환하는 함수를 만들어 보자.
```C
#include <stdio.h>

// 반환할 함수 add
int add(int a, int b)
{
    return a+b
}
int (*foo())(int, int)
{
    return add;
}

int main()
{
    printf("%d\n", foo()(10,20));
}

```

## 배열포인터를 반환하는 함수 포인터를 반환하는 함수
```C
#include <stdio.h>
int (*foo())[4] { 
    static int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    return arr;
}

int (*(*goo())()[4] {
    return foo;
}
int main() {
    printf("%d\n", goo()()[1][2]); 
}
