#include <stdio.h>

int GCD(int, int);

int main(){
  int num1, num2;
  
  printf("두 정수 입력: ");
  scanf("%d %d", &num1, &num2);
  
  printf("두 수의 최대공약수: %d\n", GCD(num1,num2));
  
  return 0;
}

int GCD(int num1, int num2)
{
  int big = num1 > num2 ? num1 : num2;
  int small = num1 > num2 ? num2 : num1;
  if(small == 0) return big;
  return GCD(big%small,small);
}
