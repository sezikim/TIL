#include <stdio.h>

int max2pow(int num);

int main(){
  int n;
  
  printf("상수 입력: ");
  scanf("%d", &n);

  printf("공식을 만족하는 k의 최댓값은 %d\n", max2pow(n));

  return 0;
}

int max2pow(int num)
{
  int k = 0;
  int knum = 1;
  while(1)
	{
	  if(num >= knum){
		  knum *= 2;
		  k++;
		}
	  else break;
	}
	return k-1;
}
