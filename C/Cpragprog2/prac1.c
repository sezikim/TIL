#include <stdio.h>

void printOdd(int*);
void printEven(int*);

int main(void)
{
  int arr[10];
  int i;
  
  printf("총 10개의 숫자 입력\n");

	for(i=0;i<10;i++){
		printf("입력: ");
		scanf("%d", arr+i);
	}

	printOdd(arr);
	printEven(arr);

	return 0;
}

void printOdd(int* arr)
{
	int i=0;
  printf("홀수 출력: ");
  for(i=0;i<10;i++){
	  if(*(arr+i)%2!=0) printf("%d ", *(arr+i));
	}
	printf("\n");
}

void printEven(int* arr)
{
	int i=0;
	printf("짝수 출력: ");
	for(i=0;i<10;i++){
		if(*(arr+i)%2==0)	printf("%d ", *(arr+i));
	}
	printf("\n");
}
