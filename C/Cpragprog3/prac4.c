#include <stdio.h>


int main() {
	int a = 4;

	int *p = &a;

	void *ppa = p;

	printf("%d\n", *(int*)ppa);
}
