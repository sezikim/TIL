#include <stdio.h>

// 포인터를 사용하는 이유?
// - > 함수에서 전달받은 인자의 값을 변경할 수 없어서
// - > call by reference

// C 언어는 인자를 전달할 때, 복사를 수행한다
// - > call by value
// - > 값을 전달하지 말고, 주소를 전달해서, 주소의 값을 변경

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a = 10;
	int b = 20;

	swap(&a, &b);

	printf("swap : %d %d\n", a, b);
	return 0;
}
