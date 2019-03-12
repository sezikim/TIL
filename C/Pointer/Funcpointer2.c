#include <stdio.h>

// 함수포인터
// : 함수를 가리키는 포인터

// 함수의 타입
// : 함수의 시그니쳐에 의해서 결정된다.
// -> 함수의 인자와 반환 타입으로 결정된다.

// 함수 포인터?
// 런타임때 어떤 함수를 호출할지 결정하기위해.

//add: int(int a, int b)
int add(int a, int b) {
	return a + b;
}

//sub: int(int a, int b)
int sub(int a, int b) {
	return a - b;
}


int main() {
	int (*p)(int, int);

	// 함수의 이름은 함수 포인터로 해석.
	// add -> &add
	// sub -> &sub

	//1번 방법
	p = &add;
	printf("%d\n", (*p)(10, 20));
	//2번 방법
	p = sub;
	printf("%d\n", p(30, 20));
}
