#include <stdio.h>

void Dec2Bin(int num);

int main()
{
  int num;
  printf("10진수 정수 입력: ");
  scanf("%d", &num);

  Dec2Bin(num);

  return 0;
}

void Dec2Bin(int num)
{
	int arr[32];
	int i;

  while(1)
	{
		if(num/2 ==0){
			arr[i] = num%2;
			break;
		}
		arr[i++] = num%2;
		num = num/2;
	}

	for(i;i>=0;i--)
		printf("%d ", arr[i]);

return;
}
