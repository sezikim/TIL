#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

// 시그널의 한계
//  => 시그널이 동시에 발생하면, 하나만 처리된다.
//  => 시그널 핸들러 안에서는 절대 블록되는 함수를 호출하면 안된다.
//   : 시그널 핸들러안에서 블록되면, 시그널 핸들러를 호출한 프로세스가 대기하게 된다.


void foo(int signum) {
	int status;
	while (waitpid(0, &status, WNOHANG) > 0) {
		printf("status: %d\n", status);
	}
}


#if 0
void foo(int signum) {
	int status;
	while (wait(&status) > 0) {
		printf("status: %d\n", status);
	}
}
#endif

int main() {
	signal(SIGCHLD, foo);
	int i;
	pid_t pid;

	for (int j = 0 ; j < 10; ++j) {
		pid =	fork();
		if (pid == 0) { 
			for (i = 0; i < 3; ++i) {
				printf("child process..\n");
				if (j > 5) {
					sleep(1);
				}
			}
			exit(0);
		} 
	}
	for (i = 0; i < 30; ++i) {
		printf("parent process..\n");
		sleep(1);
	}
	exit(0);

}

