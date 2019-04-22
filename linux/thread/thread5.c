#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int thread_count = 1;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;
void *foo(void *arg) {
	int i;
	int local = 0;
	for (i = 0 ; i < 1000000000 / thread_count; ++i) {
		++local;
	}

	pthread_mutex_lock(&mutex);
	sum += local;
	pthread_mutex_unlock(&mutex);

	return 0;
}

// fork-join model
// $ ./a.out 4
int main(int argc, char* argv[]) {

	if (argc == 2) {
		thread_count = atoi(argv[1]);
	}

	int i;
	// pthread_t thread[thread_count]; // !!
	pthread_t *thread = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);

	for (i = 0 ; i < thread_count ; ++i) {
		pthread_create(thread + i, NULL, foo, NULL);
	}

	for (i = 0 ; i < thread_count ; ++i) {
		pthread_join(thread[i], NULL);
	}
	printf("sum: %d\n", sum);

	free(thread);
}
