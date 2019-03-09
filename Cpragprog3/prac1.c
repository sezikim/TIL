#include <stdio.h>

void printRangle(int(*)[4]);

int main(void)
{
	int arr[4][4];
	int(*ptr)[4] = arr;
	int i,j;

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			arr[i][j]=4*i+j+1;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printRangle(ptr);
	printRangle(ptr);
	printRangle(ptr);
	return 0;
}

void printRangle(int(*ptr)[4])
{
	int i,j;
	int temp[4][4];
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			temp[i][j]=*(*(ptr+i)+j);
		}
	}	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			*(*(ptr+j)+3-i)=temp[i][j];
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%d ", *(*(ptr+i)+j));
		}
		printf("\n");
	}
	printf("\n");

	return;
}
