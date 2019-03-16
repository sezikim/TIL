#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int (*foo())(int, int) {
	return add;
}

int main() {
	printf("%d\n", foo()(10, 20));
}
