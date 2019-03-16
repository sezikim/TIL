#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;
	int i,j;
	int count = 1;
	
	printf("숫자를 입력하시오 : ");
	scanf("%d", &num);
	
	int** arr = (int**)malloc(sizeof(int*)*num);
	
	for(i=0;i<num;i++)
		arr[i] = (int*)malloc(sizeof(int)*num);
	for(i=0;i<num;i++)
		*(*(arr)+i) = count++;
	for(i=0;i<num;i++)
		printf("%d ", *(*(arr)+i));
	return 0;
}
