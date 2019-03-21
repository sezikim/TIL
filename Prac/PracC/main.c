#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "sort.h"
char *kinds[6] = { "CellDx", "Sports Car", "SUV", "Wagon", "Minivan", "Pickup" };
char *wds[3] = { "AWD", "RWD", "" };
int (*compare[10])(const void *a, const void *b) = {comparep1, comparep2, comparec1, comparec2, comparee1,
																	comparee2, comparewe1, comparewe2, comparewi1, comparewi2};
struct node head = { &head, &head };


int main() {
	int count = 0; //데이터 수
	int idx = 0;
	int choice = 0;
	char str[300] = {};			// 입력받는 문자 한줄
	FILE *frp = fopen("car_data.csv", "r");		// 입력스트림
	FILE *fwp;
	car *cArr;
	car *kindArr;
	int kindCount;
	
	fgets(str, sizeof(str) ,frp);	// 첫번째 줄
	
	while(fgets(str, sizeof(str),frp)) {
		count++;
	}
	printf("%d개의 데이터가 로드되었습니다.\n", count); // 입력된 데이터 갯수 출력

	cArr = malloc(sizeof(car) * count); // car 배열 선언, 메모리 할당


	fseek(frp, 0 , SEEK_SET);		// 파일 위치 지시자 초기화

	fgets(str, sizeof(str) ,frp);	// 첫번째 줄
	while (idx != count) {	// car 배열에 데이터 넣기
		char *token[14] = { NULL, };	// 문자 토큰 배열
		int i = 0;

		fgets(str, sizeof(str), frp);
		char *ptk = strtok(str, ",");  //토큰 하나
		
		while(ptk != NULL) {
				token[i++] = ptk;					// token parsing

				ptk = strtok(NULL, ",");
		}
		
		strcpy((cArr+idx)->name, token[0]);						// 구조체에 넣기
		for (i = 1; i < 7; ++i) {												
			if(strcmp(token[i], "1") == 0)	strcpy((cArr+idx)->kind, kinds[i-1]); 
		}
		strcpy((cArr+idx)->wd,  "\0");
		for(i = 7 ; i < 9; ++i) {
			if(strcmp(token[i], "1") == 0)	strcpy((cArr+idx)->wd, wds[i-7]);
		}
		(cArr+idx)->price = atoi(token[i++]);
		(cArr+idx)->dealer_cost = atoi(token[i++]);
		(cArr+idx)->engine = atof(token[i++]);
		(cArr+idx)->weight = atoi(token[i++]);
		(cArr+idx)->width = atoi(token[i++]);
		idx++;
	}
	while(1) {
		printf("1. 검색\n");
		printf("2. 종료\n");
		printf("선택 > ");
		scanf("%d", &choice);
	
		if(choice == 1){
			printf("1. CellDx\n");
			printf("2. Sports Car\n");
			printf("3. SUV\n");
			printf("4. Wagon\n");
			printf("5. Minivan\n");
			printf("6. Pickup\n");
			printf("선택> ");
			scanf("%d", &choice);
			kindCount = carCountA(cArr, count, kinds[choice-1]);
			kindArr = malloc(sizeof(car) * kindCount);
			mkindArrA(cArr, kindArr, count, kinds[choice-1]);
		} else {
			free(cArr);
			return 0;
		}
	
		printf("1. Retail Price\n");
		printf("2. Dealer Cost\n");
		printf("3. Engine Size\n");
		printf("4. Weight\n");
		printf("5. Width\n");
		printf("선택> ");
		scanf("%d", &choice);
		printf("1. 오름차순 정렬\n");
		printf("2. 내림차순 정렬\n");
		scanf("%d", &idx);
		int i;
		if (idx==1){
			qsort(kindArr, kindCount, sizeof(car), compare[choice*2-2]);
			for(i = 0; i < kindCount; ++i) {
				insert_car(&head, &((kindArr+i)->link));
			}
			print_list(&head);
		} else {
			qsort(kindArr, kindCount, sizeof(car), compare[choice*2-1]);
			for(i = 0; i < kindCount; ++i) {
				insert_car(&head, &((kindArr+i)->link));
			}
			print_list(&head);
		}

		printf("파일로 저장하시겠습니까?\n");
		printf("1. 예\n");
		printf("2. 아니요\n");
		printf("선택> ");
		scanf("%d", &choice);
		if (choice==1) {
			printf("파일이름> ");
			scanf("%s", str);
			save_list(&head, str, fwp);
			printf("%s에 저장되었습니다.\n", str);
		} else {
			free(kindArr);
		}
		head.next = &head;
		head.prev = &head;
	}
	fclose(frp);
	free(cArr);
	fclose(fwp);
	return 0;
}

