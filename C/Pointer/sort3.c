#include <stdio.h>
#include <stdlib.h>
// GCC는 void* 에 대한 연산을 char*로 취급해준다
// -> 1바이트 연산을 가능하게 해준다.
// -> + / - 만 지원한다.
// 
void swap(char *a, char *b, size_t size) {
	char *temp = malloc(size);
	int i;

	for(i = 0; i < size; ++i) {
		temp[i] = a[i];
		b[i] = a[i];
		a[i] = temp[i];
		
	}
	free(temp);
}

void bsort(void *arr, size_t n, int(*compare)(const void *, const void *), size_t size) {
	int i, j;
	
	for(i = 0; i < n - 1; ++i) {
		for(j = i + 1; j < n; ++j) {
			if(compare(arr + i * size, arr + j * size)>0)
				swap(arr + i * size, arr + j * size, size);
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
