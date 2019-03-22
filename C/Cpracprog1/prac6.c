#include <stdio.h>

void Clock(int second);

int main(){
  int second;
  
  printf("초 입력: ");
  scanf("%d", &second);

  Clock(second);
}

void Clock(int second)
{
  int hour = second / 3600;
  int min = (second % 3600) / 60;
  int sec = (second % 3600) % 60;
  
  printf("[h: %d, m: %d, s: %d]", hour, min, sec);
}
