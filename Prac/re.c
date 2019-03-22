#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node *prev;
	struct node *next;
};

typedef struct cAR {
	char name[50];
	char kind[15];
	char wd[4];
	int price;
	int dealer_cost;
	double engine;
	int weight;
	int width;
	struct node link;
}car;

char *kinds[6] = { "CellDx", "Sports Car", "SUV", "Wagon", "Minivan", "Pickup" };
char *wds[3] = { "AWD", "RWD", "" };
int pivot;
int asd;
struct node head = { &head, &head };

void insert_data(struct node *prev, struct node *next, struct node *new) {
	new->next = next;
	new->prev = prev;
	prev->next = new;
	next->prev = new;
}

void insert_car(struct node *s, struct node *new) {
	insert_data(s, s->next, new);
}

int compare(const void *a, const void *b) {
	if (asd == 1)
	switch (pivot) {
		case 1:
			return ((car*)a)->price - ((car*)b)->price;
		case 2:
			return ((car*)a)->dealer_cost - ((car*)b)->dealer_cost;
		case 3:
			if (((car*)a)->engine > ((car*)b)->engine) return 1;
			else return -1;
		case 4:
			return ((car*)a)->weight - ((car*)b)->weight;
		case 5:
			return ((car*)a)->width - ((car*)b)->width;
	}
	else
		switch (pivot) {
		case 1:
			return ((car*)b)->price - ((car*)a)->price;
		case 2:
			return ((car*)b)->dealer_cost - ((car*)a)->dealer_cost;
		case 3:
			if (((car*)b)->engine > ((car*)a)->engine) return 1;
			else return -1;
		case 4:
			return ((car*)b)->weight - ((car*)a)->weight;
		case 5:
			return ((car*)b)->width - ((car*)a)->width;
	}
}

int carCountL(struct node *head, char *s) {
	int kindC = 0;
	
	struct node *cur = head;
	cur = cur->next;
	
	while(cur != head) {
		car *curcar = (car*)((char*)cur - (unsigned long)&(((car*)0)->link));
		if(strcmp(curcar->kind, s) == 0)	kindC++;
		cur = cur->next;
	}
	return kindC;
}

void mkindArrL(struct node *head, car *kindArr, char *s) {
	int i = 0;
	
	struct node *cur = head;
	cur = cur->next;
	
	while(cur != head) {
		car *curcar = (car*)((char*)cur - (unsigned long)&(((car*)0)->link));
		if(strcmp(curcar->kind, s) == 0) {
			*(kindArr+i) = *(curcar);
			i++;
		}
		cur = cur->next;
	}
}

int main() {
	int kind; // car 종류
	int menu; // 선택 || 종료
	int i = 0;
	int kindCount = 0;
	car *kindArr;
	char buf[300];

	FILE *frp = fopen("car_data.csv", "r");
	if (frp == NULL) {
		printf("File open error....\n");
		return 1;
	}

	while(fgets(buf, sizeof(buf), frp)) {
		if (i++ == 0) continue;
		car *newCar = malloc(sizeof(car));

		// string parse
		char *token[14];
		token[0] = strtok(buf, ",");
		for(i = 1; i < 14; ++i) {
			token[i] = strtok(NULL, ",");
		}
		
		//구조체에 넣기
		strcpy(newCar->name, token[0]);
		for (i = 1; i < 7; ++i) {
			if (strcmp(token[i], "1") == 0) strcpy(newCar->kind, kinds[i-1]);
		}
		for (i = 7; i < 9; ++i) {
			if (strcmp(token[i], "1") == 0) strcpy(newCar->wd, wds[i-7]);
		}
		newCar->price = atoi(token[i++]);
		newCar->dealer_cost = atoi(token[i++]);
		newCar->engine = atof(token[i++]);
		newCar->weight = atoi(token[i++]);
		newCar->width = atoi(token[i++]);
		
		// 리스트에 추가
		insert_car(&head, &(newCar->link));
	}

	while (1) {
		printf("1. 검색\n");
		printf("2. 종료\n");
		printf("선택 > ");
		scanf("%d", &menu);
	
		if (menu == 1) {
			printf("1. CellDx\n");
			printf("2. Sports Car\n");
			printf("3. SUV\n");
			printf("4. Wagon\n");
			printf("5. Minivan\n");
			printf("6. Pickup\n");
			printf("선택> ");
			scanf("%d", &kind);
			kindCount = carCountL(&head, kinds[kind-1]);
			kindArr = malloc(sizeof(car) * kindCount);
			mkindArrL(&head, kindArr, kinds[kind-1]);
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

		qsort(kindArr, kindCount, sizeof(car), compare);
		printf("Name                                          Kind            WD       Price     Cost  Engine      Weight  Width\n");	
		for (i = 0; i < kindCount; ++i) {	
			printf("%-45s %-15s %-5s %8d %8d %8lf %8d %8d\n",
								(kindArr+i)->name,
								(kindArr+i)->kind,
								(kindArr+i)->wd,
								(kindArr+i)->price, 
								(kindArr+i)->dealer_cost,
								(kindArr+i)->engine,
								(kindArr+i)->weight,
								(kindArr+i)->width);
		}
		printf("파일로 저장하시겠습니까?\n");
		printf("1. 예\n");
		printf("2. 아니요\n");
		printf("선택> ");
		scanf("%d", &menu);
		if (menu==1) {
			printf("파일이름> ");
			scanf("%s", buf);

			FILE *fwp = fopen(buf, "w");
			fputs("Name,Kind,WD,Retail Price,Dealer Cost,EngineSize,Weight,Width\n",fwp);
			
			for (i = 0; i < kindCount; ++i) {
			fprintf(fwp, "%s,%s,%s,%d,%d,%lf,%d,%d\n",
								   (kindArr+i)->name,
									 (kindArr+i)->kind,
								 	 (kindArr+i)->wd,
								 	 (kindArr+i)->price,
								   (kindArr+i)->dealer_cost,
								   (kindArr+i)->engine,
								   (kindArr+i)->weight,
								   (kindArr+i)-> width);
			}
			printf("%s에 저장되었습니다.\n", buf);
			fclose(fwp);
		} else {
			free(kindArr);
		}
	}
	head.next = &head;
	head.prev = &head;
	fclose(frp);
	free(kindArr);
	return 0;
}
