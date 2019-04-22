#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

// main thread는 main()함수를 수행한다.
// pthread_create
//   : 새로운 스레드가 수행할 함수를, 지정해야 한다.

// $ gcc thread1.c -lpthread
// or
// $ gcc thread1.c -pthread

void *foo(void *arg) {
	int i;
	for (i = 0; i < 5; ++i) {
		printf("foo thread...\n");
		sleep(1);
	}
}

// 1. main 함수가 반환하면, 프로세스가 종료한다.
//   => 프로세스가 종료하면, 프로세스 내의 모든 스레드도 종료한다.

// 2. 프로세스 내의 모든 스레드가 종료하면, 프로세스가 종료한다.

int main() {
	pthread_t thread;
	pthread_create(&thread, NULL, &foo, NULL);

	// 아래 함수를 호출한 스레드가 종료한다.
	pthread_exit(NULL);
}
