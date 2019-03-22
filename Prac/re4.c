#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "sort.h"

struct node head = { &head, &head };
int pivot;
int asd;

int main() {

	FILE* frp = fopen("car_data.csv", "r");
	char buf[512];
	int data_n = 0;
	int kindcount;
	car *kindarr;

	while(fgets(buf, sizeof(buf), frp)) {
		if (data_n++ == 0) continue;
		
		car *new = malloc(sizeof(car));
		
		int i;
		char *p = strtok(buf ,",");

		for (i = 0; p != NULL; p = strtok(NULL, ","), ++i) {
			switch (i) {
			case 0:
			  new->name = malloc(sizeof(char) * strlen(p));
				strcpy(new->name, p);
				break;
			case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				if (atoi(p)==1)	ADD_TYPE(new, 8-i);
				break;
			case 9:
				new->retail_price = atoi(p);
				break;
			case 10:
				new->dealer_cost = atoi(p);
				break;
			case 11:
				new->engine_size = atof(p);
				break;
			case 12:
				new->weight = atoi(p);
				break;
			case 13:
				new->width = atoi(p);
				break;
			}
		}
		insert_car(&head, &(new->link));
	}
	printf("총 %d개의 데이터가 로드되었습니다.\n", data_n-1);
	int menu;
	while (1) {
		printf("1. 검색\n");
		printf("2. 종료\n");
		printf("선택 > ");
		scanf("%d", &menu);
		
		int type;
		if (menu == 1) {
			printf("1. CellDx\n");
			printf("2. Sports Car\n");
			printf("3. SUV\n");
			printf("4. Wagon\n");
			printf("5. Minivan\n");
			printf("6. Pickup\n");
			printf("선택> ");
			scanf("%d", &type);
			kindcount = cKind(&head, 8-type);
			kindarr = malloc(sizeof(car) * kindcount);
			mArr(&head, kindarr, 8-type);
		} else return 0;
	
		printf("1. Retail Price\n");
		printf("2. Dealer Cost\n");
		printf("3. Engine Size\n");
		printf("4. Weight\n");
		printf("5. Width\n");
		printf("선택> ");
		scanf("%d", &pivot);
		printf("1. 오름차순 정렬\n");
		printf("2. 내림차순 정렬\n");
		scanf("%d", &asd);

		qsort(kindarr, kindcount, sizeof(car), compare);
		print_car(kindarr, kindcount);
		
		printf("파일로 저장하시겠습니까?\n");
		printf("1. 예\n");
		printf("2. 아니요\n");
		printf("선택> ");
		scanf("%d", &menu);
		if (menu==1) {
			printf("파일이름> ");
			scanf("%s", buf);

			FILE *fwp = fopen(buf, "w");
			save_car(kindarr, kindcount, fwp);	
			printf("%s에 저장되었습니다.\n", buf);
			fclose(fwp);
		} else {
			free(kindarr);
		}
	}
	fclose(frp);
	head.next = &head;
	head.prev = &head;
	free(kindarr);
	return 0;	
}
