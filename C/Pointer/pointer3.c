#include <stdio.h>

void foo(int (*arr)[3]) {
	int i;
	for (i = 0; i < 3; ++i) {
		(*arr)[i] += 10;
	}
	printf("%ld\n", sizeof(*arr));
	// 
}

int main() {
	int i;
	int arr[3] = { 1, 2, 3 };

	foo(&arr);
	// int(*p)[3] = &arr;

	return 0;

}
