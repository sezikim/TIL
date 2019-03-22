#include <stdio.h>

void Prime(int);

int count;

int main(void){
  int n = 1; 
  
  while(count!=10)
	{
	    Prime(++n);
	}
	
	return 0;
}

void Prime(int num)
{
  int div=2;
  for(div; div<num; div++){
	  if(num%div == 0) return;
	}
	printf("%d \n", num);
	count++;
}
