#include <stdio.h>
#include <stdlib.h>
// int 뿐 아니라, 다양한 타입을 정렬해보자
// size를 받아서 char형 1바이트 연산을 통해 1바이트씩 바꿔준다.
// void* 를 사용해서 다양한 타입을 받기.

void swap(void *a, void *b, size_t size) {
	char *temp = malloc(size);
	int i;

	for(i = 0; i < size; ++i) {
		temp[i] = ((char*)a)[i];
		((char*)b)[i] = ((char*)b)[i];
		((char*)a)[i] = temp[i];
		
	}
	free(temp);
}

void bsort(void *arr, size_t n, int(*compare)(const void *, const void *), size_t size) {
	int i, j;
	
	for(i = 0; i < n - 1; ++i) {
		for(j = i + 1; j < n; ++j) {
			if(compare((char*)arr + i * size,(char*)arr + j * size)>0)
				swap((char*)arr + i * size,(char*)arr + j * size, size);
		}
	}
}

int compare1(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int i;
	bsort(arr, sizeof(arr)/sizeof(int), compare1, sizeof(int));

	for(i = 0; i < 10; ++i) {
		printf("%d\n", arr[i]);
	}
}
