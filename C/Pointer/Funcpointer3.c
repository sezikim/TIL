#include <stdio.h>

int(*foo())[4] {
	static int arr[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	return arr;
}

void a(){}
// void(*p)()

//pointer to
//array of
//function

int(*(*goo())())[4] {
	return foo;
}

int main() {
	printf("%d\n", goo()()[1][2]);
}
