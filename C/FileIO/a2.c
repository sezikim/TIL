#include <stdio.h>

// c언어에서 타입을 보는 방법
// int i;
// 이름을 뺀 나머지가 타입
// int
// int arr[3]
// int[3]
// 배열의 이름은 배열의 첫번째 원소의 시작주소
// Decay
// -> 예외 sizeof, &
#if 0
void foo(int *arr) {
	int i;
	for(i = 0; i < 3; ++i) {
		arr[i] += 10;		
	}
	printf("sizeof(arr): %ld\n", sizeof(arr));
}
#endif

void foo(int (*arr)[3]) {
	int i;
	for(i = 0; i < 3; ++i) {
		(*arr)[i] += 10;
	}
	printf("%d\n", sizeof(*arr));
}


int main() {
	int i;
	int arr[3] = { 1, 2, 3 };

	printf("sizeof(arr): %ld\n", sizeof(arr));

	foo(&arr);
	//foo(&arr[0]);

	for (i = 0; i < 3; ++i) {
		printf("%d\n", arr[i]);
	}
}
