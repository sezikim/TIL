#include <unistd.h>
#include <stdio.h>

#include <signal.h>

void foo(int signum) {
	printf("foo\n");
}

int main() {
	signal(SIGINT, foo);

	while (1) {
		sleep(1);
		printf("hello...\n");
	}
}

