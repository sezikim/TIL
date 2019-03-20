#include <stdio.h>

void foo(int (*arr)[3]) {
	int i;
	for (i = 0; i < 3; ++i) {
		(*arr)[i] += 10;
	}
	printf("sizeof(arr): %ld\n", sizeof(*arr));
}




int main() {
	int i;
	int arr[3] = { 1, 2, 3 };

	printf("sizeof(arr) : %ld\n", sizeof(arr));

	foo(&arr);

	for (i = 0; i < 3; ++i) {
		printf("%d\n", arr[i]);
	}
}
