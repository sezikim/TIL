#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void *foo(void *arg) {
	for (int i = 0; i < 3; ++i) {
		sleep(1);
		printf("Hello, world..\n");
	}

	return 0;
}

int main() {
	pthread_t thread;
	pthread_create(&thread, NULL, foo, NULL);
	pthread_join(thread, NULL);
	pthread_detach(thread);
	
	for (int i = 0; i < 5; ++i) {
		sleep(1);
		printf("main..\n");
	}
}
