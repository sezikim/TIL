#include <stdio.h>

typedef int (*PARR)[4];

PARR foo() {
	static int arr[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	return arr;
}

typedef PARR (*FP)();
FP goo() {
	return foo;
}

int main() {
	printf("%d\n", goo()()[1][1]);
}
