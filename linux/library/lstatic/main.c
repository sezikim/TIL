#include <stdio.h>
#include <math.h>			// 정적 라이브러리를 링킹하지 않으면 컴파일이 않된다.
#include "add.c"
int main() {
	int a = 10;
	int b = 20;
	printf("%d + %d = %d\n", a, b, add(a, b));
	printf("%f\n", sqrt(a));
	printf("%f\n", sqrt(b));
	return 0;
}
