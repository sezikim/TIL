#include <stdio.h>

void foo(int *arr) {
	int i;
	for (i = 0; i < 3; ++i) {
		arr[i] += 10;
	}
	
	printf("sizeof(arr): %ld\n", sizeof(*arr));
	// arr의 주소값이 들어가기 때문에 포인터의 크기인 8출력.
}

// C언어에서 타입을 보는 방법
// int i;
// 함수의 심볼을 뺀 나머지.
// => int
// int arr[3];
// => int[3]
// => 배열의 이름은 첫번째 원소의 시작 주소로 해석된다.
// : Decay
// Decay예외 : sizeof, &

int main() {
	int i;
	int arr[3] = { 1, 2, 3 };

	printf("sizeof(arr): %ld\n", sizeof(arr));
	// 12출력
	foo(arr);
	// foo(&arr[0])

	for (i = 0; i < 3; ++i) {
		printf("%d\n", arr[i]);
	}

	return 0;

}
