// 함수를 포인터를 리턴하는 함수를 만들어보자.

#include <stdio.h>

// 반환할 함수 add
int add(int a, int b)
{
	return a+b;
}

int(*foo())(int, int)
{
	return add;
}

int main(void)
{
	printf("%d \n", foo()(10,20));
	return 0;
}
