#include <stdio.h>

void Gugu(int, int);

int main(){
	int num1, num2;

	printf("두 정수를 입력하세요: ");
	scanf("%d %d", &num1, &num2);
	
	Gugu(num1,num2);
	
	return 0;
}

void Gugu(int num1, int num2)
{
  int start = num1 > num2 ? num2 : num1;
  int end = num1 > num2 ? num1 : num2;

  for(start; start<=end; start++){
	  int num=1;
	  for(num; num<10; num++){
		  printf("%d * %d = %d\n", start, num, start*num);
		}
	}
}

