#include <stdio.h>
#include <stdlib.h>

void swap(void *a, void *b, size_t size) {
	char* temp = malloc(size);
	int i;

	for(i = 0; i < size; ++i) {
		temp[i] = *((char*)a + i);
		*((char*)a + i) = *((char*)b + i);
		*((char*)b + i) = temp[i];
	}

	free(temp);
}

void bsort(void *arr, size_t n, size_t size, int(*compare)(const void *, const void *)) {
	int i, j;
	for(i = 0; i < n - 1; ++i) {
		for(j = i + 1; j < n; ++j) {
			if(compare((char*)arr + i * size, (char*)arr + j * size) > 0)
				swap((char*)arr + i * size, (char*)arr + j * size, size);
		}
	}
}

int compare1(int a, int b) {
	return a - b;
}

int compare2(const void * b, const void * a) {
	return *(int*)a - *(int*)b;
}

int main() {
	int i;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	bsort(arr, 10, sizeof(arr[0]),compare2);

	for(i = 0; i < 10; ++i) {
		printf("%d\n", arr[i]);
	}
}
