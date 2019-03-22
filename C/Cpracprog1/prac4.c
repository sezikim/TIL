#include <stdio.h>

int main(){
  int money = 3500;
  int cnum;  //크림빵의 개수
  int snum;  //새우깡의 개수
  int cola;  //콜라의 개수
  printf("소유중인 금액: %d\n", money);
  
  for(cnum=1; cnum<5; cnum++)
  	for(snum=1; snum<5; snum++)
  		for(cola=1; cola<7; cola++){
			  int sum = 500*cnum + 700*snum + 400*cola;
			  if(sum == 3500) printf("크림빵 %d개, 새우깡 %d개, 콜 라 %d개\n"
			  	, cnum, snum, cola);
			}
	return 0;
}
