// 프로세스 내의 스레드는 환경을 공유한다.
//  => 같은 주소 공간을 사용한다.
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int thread_count = 1;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;
void *foo(void *arg) {
	int i;
	for (i = 0 ; i < 100000000 / thread_count; ++i) {
		//----
		pthread_mutex_lock(&mutex);
		++sum;
		pthread_mutex_unlock(&mutex);
		//----
	}

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
