#include <stdio.h>
#include "add.h"

int main() {
	int a = 20;
	int b = 10;
	
	printf("%d + %d = %d \n", a, b, add(a, b));
	printf("%d - %d = %d \n", a, b, sub(a, b));

	return 0;
}
