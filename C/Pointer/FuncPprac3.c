// 배열포인터나 함수포인터를 반환할 때는 typedef 으로 재정의해서 간단히 표현.

#include <stdio.h>

typedef int(*PARF)[4];	//배열포인터 타입을 재정의.

//int(*foo())[4]
PARF foo() {
	static int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	return arr;
}

typedef PARF (*FP)();		//함수포인터 타입을 재정의.

FP goo(){
	return foo;
}

int main(void){
	printf("%d \n", goo()()[0][2]);
}



