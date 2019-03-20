#include <stdio.h>

// 아래 코드는 a.out같은 바이너리에서 제대로 작동하지 않는다.

//getchar() / getc() / fgetc()
// : 반환타입이 int인 이유는?
// -> 0xFF를 EOF로 인식하는 문제가 발생할 수 있어서.

int main() {
	int c;
	int filesize = 0;

	// c: char
	// 0xFF == EOF

	// 0x000000FF == EOF(0xFFFFFFFF)

	while(c = getchar() != EOF) {
		++filesize;
	}

	printf("filesize: %d\n", filesize);
}
