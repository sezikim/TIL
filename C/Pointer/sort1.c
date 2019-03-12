#include <stdio.h>

// sort에서 내림차순 , 오름차순의 정책을 사용자에 의해서 정해보자
// 함수의 정책을 결정하는 함수포인터 사용!
void swap(int *a, int *b) {
	int *temp;
	temp = a;
	a = b;
	b = temp;
}

void bsort(int *arr, int n, int(*compare)(int, int)) {
	int i, j;
	
	for(i = 0; i < n - 1; ++i) {
		for(j = i + 1; j < n; ++j) {
			if(compare(arr[i], arr[j])>0)
				swap(arr+i, arr+j);
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
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int i;
	bsort(arr, sizeof(arr)/sizeof(int), compare2);

	for(i = 0; i < 10; ++i) {
		printf("%d\n", arr[i]);
	}
}
