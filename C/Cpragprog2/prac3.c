#include <stdio.h>

void getNum(int* arr);
void printArr(int* arr);

int main(void)
{
	int arr[10];
	getNum(arr);
	printArr(arr);

	return 0;
}

void getNum(int* arr)
{
	int num;
	int odd=0;
	int even=9;
	int count=0;

	printf("총 10개의 숫자 입력 \n");
	
	while(count<10)
	{
	  printf("입력: ");
	  scanf("%d", &num);
	  if(num%2==0) *(arr+even--)=num;
	  else *(arr+odd++)=num;
		count++;
	}
}

void printArr(int* arr)
{
	int i;
	
	printf("배열 요소의 출력: ");
	for(i=0;i<10;i++)
		printf("%d", *(arr+i));
	printf("\n");
}
