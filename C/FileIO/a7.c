#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bsort(int *arr, int n, int(*compare)(int, int)) {
	int i, j;
	for(i = 0; i < n - 1; ++i) {
		for(j = i + 1; j < n; ++j) {
			if(compare(arr[i], arr[j]) > 0)
				swap(arr + i, arr + j);
		}
	}
}

int compare1(int a, int b) {
	return a - b;
}

int compare2(int a, int b) {
	return b - a;
}

int main() {
	int i;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	bsort(arr, 10, compare2);

	for(i = 0; i < 10; ++i) {
		printf("%d\n", arr[i]);
	}
}
