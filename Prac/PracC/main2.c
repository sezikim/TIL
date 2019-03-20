#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sort.h"

char *kinds[6] = { "CellDx", "Sports Car", "SUV", "Wagon", "Minivan", "Pickup" };
char *wds[3] = { "AWD", "RWD", "" };
int (*compare[10])(const void *a, const void *b) = {comparep1, comparep2, comparec1, comparec2, comparee1,
																	comparee2, comparewe1, comparewe2, comparewi1, comparewi2};
struct node head = { &head, &head };

int main() {
	int count = 0;
	int choice = 0;
	int i;
	int kindCount = 0;
	car *kindArr;
	char str[300];
	FILE *frp = fopen("car_data.csv", "r");
	FILE *fwp;	
	fgets(str, sizeof(str), frp); // 첫줄

	while(fgets(str, sizeof(str), frp)) {
		// 새로운 car 
		car *newCar = malloc(sizeof(car));

		// string parse
		char *token[14];
		token[0] = strtok(str, ",");
		for( i = 1; i < 14; ++i) {
			token[i] = strtok(NULL, ",");
		}
		
		//구조체에 넣기
		strcpy(newCar->name, token[0]);
		for( i = 1; i < 7; ++i ) {
			if(strcmp(token[i], "1") == 0) strcpy(newCar->kind, kinds[i-1]);
		}
		for( i = 7; i < 9; ++i ) {
			if(strcmp(token[i], "1") == 0) strcpy(newCar->wd, wds[i-7]);
		}
		newCar->price = atoi(token[i++]);
		newCar->dealer_cost = atoi(token[i++]);
		newCar->engine = atoi(token[i++]);
		newCar->weight = atoi(token[i++]);
		newCar->width = atoi(token[i++]);
		
		// 리스트에 추가
		insert_car(&head, &(newCar->link));
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
			kindCount = carCountL(&head, kinds[choice-1]);
			kindArr = malloc(sizeof(car) * kindCount);
			mkindArrL(&head, kindArr, kinds[choice-1]);
		} else return 0;
	
		printf("1. Retail Price\n");
		printf("2. Dealer Cost\n");
		printf("3. Engine Size\n");
		printf("4. Weight\n");
		printf("5. Width\n");
		printf("선택> ");
		scanf("%d", &choice);
		printf("1. 오름차순 정렬\n");
		printf("2. 내림차순 정렬\n");
		scanf("%d", &i);
		int i;
		if (i==1){
			qsort(kindArr, kindCount, sizeof(car), compare[choice*2-2]);
			printf("Name                                          Kind            WD       Price     Cost      Engine  Weight  Width\n");	
			for(i = 0; i < kindCount; ++i) {	
				printf("%-45s %-15s %-5s %8d %8d %8d %8d %8d\n", (kindArr+i)->name, (kindArr+i)->kind, (kindArr+i)->wd,
							(kindArr+i)->price, (kindArr+i)->dealer_cost, (kindArr+i)->engine, (kindArr+i)->weight, (kindArr+i)->width);
			}
		} else {
			qsort(kindArr, kindCount, sizeof(car), compare[choice*2-1]);
			printf("Name                                          Kind            WD       Price     Cost      Engine  Weight  Width\n");	
			for(i = 0; i < kindCount; ++i) {
				printf("%-45s %-15s %-5s %8d %8d %8d %8d %8d\n", (kindArr+i)->name, (kindArr+i)->kind, (kindArr+i)->wd,
							(kindArr+i)->price, (kindArr+i)->dealer_cost, (kindArr+i)->engine, (kindArr+i)->weight, (kindArr+i)->width);
			}
		}

		printf("파일로 저장하시겠습니까?\n");
		printf("1. 예\n");
		printf("2. 아니요\n");
		printf("선택> ");
		scanf("%d", &choice);
		if (choice==1) {
			printf("파일이름> ");
			scanf("%s", str);
			fwp = fopen(str, "w");
			fputs("Name,Kind,WD,Retail Price,Dealer Cost,EngineSize,Weight,Width\n",fwp);
			for(i = 0; i < kindCount; ++i) {
			fprintf(fwp, "%s,%s,%s,%d,%d,%d,%d,%d\n", (kindArr+i)->name, (kindArr+i)->kind, (kindArr+i)->wd,
								(kindArr+i)->price, (kindArr+i)->dealer_cost, (kindArr+i)->engine, (kindArr+i)->weight, (kindArr+i)-> width);
			}
			printf("%s에 저장되었습니다.\n", str);
		} else {
			free(kindArr);
		}
		head.next = &head;
		head.prev = &head;
	}
	fclose(frp);
	free(kindArr);
	fclose(fwp);
	return 0;
}
