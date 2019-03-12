#include <stdio.h>

// 포인터를 왜 사용하는가 ?
// => 함수에서 전달받은 인자의 값을 변경하려고
// -> call by reference

// c언어는 인자를 전달할 때 값을 복사한다 -> call by value
//  주소전달을 통해 주소값을 변경해야 한다.

void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	swap(a,b);

	printf("swap : %d %d \n", a, b);
	// a, b 그대로 출력 -> call by value

	return 0;

}
