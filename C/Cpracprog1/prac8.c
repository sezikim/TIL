#include <stdio.h>

int pow2(int num);

int main(){
  int n;
  
  printf("정수 입력: ");
  scanf("%d", &n);
  
  printf("2의 %d승은 %d\n", n, pow2(n));

  return 0;
}

int pow2(int num)
{
  if(num == 0) return 1;
  return 2*pow2(--num);
}
