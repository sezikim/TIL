#include <unistd.h>

int a = 42;
int main() {
	int b = 10;
	pid_t pid;

	pid = fork();
	if (pid > 0) {
		a += 10;
		b += 10;

		printf("parent a: %d b: %d\n", a, b); // 52, 20
	} else if (pid == 0) {
		sleep(1);
		printf("child a: %d b: %d\n", a, b); // 42, 10
	}
}

