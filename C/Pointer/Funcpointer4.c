#include <stdio.h>

typedef int (*FAPR)[4];

FAPR foo() {
	static int arr[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	return arr;
}

typedef FAPR (*FP)();

FP goo() {
	return foo;
}

int main() {
	printf("%d\n", goo()()[1][2]);
}

