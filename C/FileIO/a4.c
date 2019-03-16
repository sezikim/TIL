#include <stdio.h>

//함수 포인터
// 함수를 가리키는 포인터

//함수의 타입
// 함수의 시그니쳐에 의해서 결정
// 함수의 인자의 타입, 갯수, 반환 타입

// 함수포인터를 사용하는 이유?
// 런타임에 어떤 함수를 호출할지 결정

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int main() {
	int (*p)(int ,int);

	p = &add;
	printf("%d\n", (*p)(10, 20));

	p = sub;
	printf("%d\n", p(30, 20));
}
