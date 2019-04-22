#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

// 병행 프로그래밍
// 1. 멀티 프로세스 프로그래밍 - system call
// 2. 멀티 스레드 프로그래밍 - pthread API

// fork()
//  => 반환값을 통해 부모 프로세스와 자식 프로세스를 분리한다.
//  => 부모 프로세스는 자식의 PID를 반환한다.
//  => 자식 프로세스는 0을 반환한다.
//  => 자식 프로세스는 부모 프로세스에게 자신의 종료 상태값을 알려야 한다.
//   : 자식 프로세스는 종료 상태값을 전달하기 전까지는 좀비 프로세스가 된다.

int main() {
	int i;
	pid_t pid;

	pid =	fork();
	if (pid > 0) {  // 부모 프로세스
		int status;
		wait(&status);
		printf("status: %d\n", status);

		for (i = 0; i < 30; ++i) {
			printf("parent process..\n");
			sleep(1);
		}
		exit(0);

	} else if (pid == 0) { // 자식 프로세스
		for (i = 0; i < 3; ++i) {
			printf("child process..\n");
			sleep(1);
		}
		exit(0);

	} else {
		perror("fork");
		exit(1);
	}
	// fork()가 반환될 때, 자식 프로세스도 fork() 함수를 반환한다.
	printf("hello, world...\n");

}

