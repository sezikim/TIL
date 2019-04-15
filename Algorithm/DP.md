# 동적 계획법
> Dyanamic Programming
- **큰 문제를 작은 문제로 나눠서** 푸는 알고리즘.
- 분할 정복과 비슷하다.
    - 차이점 : 분할 정복은 계산한 부분문제를 한번만 쓰고 더 이상 쓰지 않는다.(메모이제이션이 필요하지 않다.)

## 메모이제이션
- 계산된 값을 버리지 말고 저장했다가, 필요한
경우에 계산없이 호출
- 메모이제이션을 적용한 TOP-DOWN방식 DP
```java
long long fib(long long n) {
    if(n == 1 || n == 2)
    return 1;
    if(!memo[n])
    return memo[n];
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}
```
- BOTTOM-UP방식
```JAVA
long long fib(int n) {
    memo[0] = 0;
    memo[1] = 1;
    for(int i = 2; i <= n; i++)
        memo[i] = memo[i-1] + memo[i-2];
    return memo[n];
}
```

## 동적 계획법의 이용
- 최적값을 구할때 주로 사용한다.
