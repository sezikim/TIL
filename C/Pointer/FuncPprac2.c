// 배열포인터를 반환하는 함수를 반환하는 함수 만들어보기.
#include <stdio.h>

int (*foo())[4]
{
	static int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	return arr;
}

int (*(*goo())())[4]
{
	return foo;
}

int main(void)
{
	printf("%d\n", goo()()[0][2]);
	return 0;
}
