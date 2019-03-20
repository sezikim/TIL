#include <stdio.h>

#define MUL(x,y) ((x) * (y))
#define POW(x) ((x) * (x))

int xpow(int x) {
	return x * x;
}

int mul(int a, int b) {
	return a * b;
}

int main() {
	int a = 10;
	int b = 32;

	printf("mul: %d\n", mul(a + b, a + b));
	printf("MUL: %d\n", MUL(a + b, a + b));

	int n = 2;
	printf("pow: %d\n", xpow(++n));
	printf("Pow: %d\n", POW(++n));
}
