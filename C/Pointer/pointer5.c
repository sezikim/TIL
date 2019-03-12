#include <stdio.h>

// 1. 포인터를 배열의 연산으로 다룰 수 있다.
// arr[N]
// -> *(arr+[N]);
// &arr[0]
// -> &*(arr+0)
// -> (arr+0)
// -> arr

int main() {
	int arr[3] = { 1, 2, 3 };
	// int *p = arr;
	int *p = &arr[0];

	printf("%d\n", p[1]);
	printf("%d\n", *(p+1));
	printf("%d\n", arr[1]);
	printf("%d\n", *(arr+1));
	printf("%d\n", *(1+arr));
	printf("%d\n", 1[arr]);
}
