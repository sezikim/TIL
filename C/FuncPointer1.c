#include <stdio.h>
#include <stdlib.h>

int filter_even(int num) {
    return num % 2 == 0;
}

int filter_odd(int num) {
    return num % 2 == 1;
}

int filter(int* arr, int arr_length, int (*filter_policy)(int), int* result, int result_length) {
    int i;
    int count = 0;

    for (i = 0; i < arr_length && i < result_length; ++i) {
        if (filter_policy(arr[i])) {
	    result[count++] = arr[i];    
	}
    }
    return count;
}

int main() {
    int arr[4] = { 1, 2, 3, 4 };
    
    int odd_arr[5] = {};
    int even_arr[5] = {};
    int odd_count = filter(arr, sizeof(arr) / sizeof(arr[0]), filter_odd, odd_arr, sizeof(odd_arr) / sizeof(odd_arr[0]));
    int even_count = filter(arr, sizeof(arr) / sizeof(arr[0]), filter_even, even_arr, sizeof(even_arr) / sizeof(even_arr[0]));

    printf("array\n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d\n", arr[i]);
    }

    printf("odd array\n");
    for (int i = 0; i < odd_count; ++i) {
        printf("%d\n", odd_arr[i]);
    }
    
    printf("even array\n");
    for (int i = 0; i < even_count; ++i) {
	printf("%d\n", even_arr[i]);
    }

}
