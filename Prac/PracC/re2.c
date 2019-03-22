#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	struct node *prev;
	struct node *next;
};

struct node head = { &head, &head };

typedef struct {
	char *name;
	unsigned char type;
	int retail_price;
	int dealer_cost;
	double engine_size;
	int weight;
	int width;
	struct node link;
}car;

enum {
	CELL_DX,
	SPORTS_CAR,
	SUV,
	WAGON,
	MINIVAN,
	PICKUP,
	AWD,
	RWD
};

void insert_data(struct node *prev, struct node *next, struct node *new) {
	new->next = next;
	new->prev = prev;
	prev->next = new;
	next->prev = new;
}

void insert_car(struct node *s, struct node *new) {
	insert_data(s, s->next, new);
}

void print_car(car *kindarr, int kindcount) {
	int i;
	for (i = 0; i < kindcount; ++i) {
		fprintf(stdout, "%-45s ", kindarr[i].name);
		if (kindarr[i].type & 1 << (7-CELL_DX)) fprintf(stdout, "%-5s", "CellDx ");
		if (kindarr[i].type & 1 << (7-SPORTS_CAR)) fprintf(stdout, "%-5s", "Spots Car ");
		if (kindarr[i].type & 1 << (7-SUV)) fprintf(stdout, "%-5s", "SUV ");
		if (kindarr[i].type & 1 << (7-WAGON)) fprintf(stdout, "%-5s", "Wagon ");
		if (kindarr[i].type & 1 << (7-MINIVAN)) fprintf(stdout, "%-5s", "Minivan ");
		if (kindarr[i].type & 1 << (7-PICKUP)) fprintf(stdout, "%-5s", "Pickup ");
		if (kindarr[i].type & 1 << (7-AWD)) fprintf(stdout, "%-5s", "AWD ");
		else if (kindarr[i].type & 1 << (7-RWD)) fprintf(stdout, "%-5s", "RWD ");
		else fprintf(stdout, "%-5s", "   ");
		printf("%8d ", kindarr[i].retail_price);
		printf("%8d ", kindarr[i].dealer_cost);
		printf("%8lf ", kindarr[i].engine_size);
		printf("%8d ", kindarr[i].weight);
		printf("%8d\n", kindarr[i].width);
		}
}

void save_car(car *kindarr, int kindcount, FILE *fp) {
	int i;
	for (i = 0; i < kindcount; ++i) {
		fprintf(fp, "%s,", kindarr[i].name);
		if (kindarr[i].type & 1 << (7-CELL_DX)) fprintf(fp, "CellDx,");
		if (kindarr[i].type & 1 << (7-SPORTS_CAR)) fprintf(fp, "Spots Car,");
		if (kindarr[i].type & 1 << (7-SUV)) fprintf(fp, "SUV,");
		if (kindarr[i].type & 1 << (7-WAGON)) fprintf(fp, "Wagon,");
		if (kindarr[i].type & 1 << (7-MINIVAN)) fprintf(fp, "Minivan,");
		if (kindarr[i].type & 1 << (7-PICKUP)) fprintf(fp, "Pickup,");
		if (kindarr[i].type & 1 << (7-AWD)) fprintf(fp, "AWD,");
		if (kindarr[i].type & 1 << (7-RWD)) fprintf(fp, "RWD,");
		fprintf(fp, "%d,", kindarr[i].retail_price);
		fprintf(fp, "%d,", kindarr[i].dealer_cost);
		fprintf(fp, "%lf,", kindarr[i].engine_size);
		fprintf(fp, "%d,", kindarr[i].weight);
		fprintf(fp, "%d\n", kindarr[i].width);
		}
}

int cKind(struct node *head, unsigned char type) {
	int count = 0;
	struct node *cur = head->next;

	while (cur != head) {
		car *curcar = (car*)((char*)cur - (unsigned long)&(((car*)0)->link));
		if(curcar->type & type) count++;
		cur = cur->next;	
	}
	return count;
}

void mArr(struct node *head, car *kindarr, unsigned char type) {
	int i = 0;
	struct node *cur = head->next;
	while (cur != head) {
		car *curcar = (car*)((char*)cur - (unsigned long)&(((car*)0)->link));
		if (curcar->type & type) {
			*(kindarr+i) = *curcar;
			i++;
		}
		cur = cur->next;
	}
}

int pivot, asd;
int compare(const void *a, const void *b) {
	if (asd == 1)
	switch (pivot) {
		case 1:
			return ((car*)a)->retail_price - ((car*)b)->retail_price;
		case 2:
			return ((car*)a)->dealer_cost - ((car*)b)->dealer_cost;
		case 3:
			if (((car*)a)->engine_size > ((car*)b)->engine_size) return 1;
			else return -1;
		case 4:
			return ((car*)a)->weight - ((car*)b)->weight;
		case 5:
			return ((car*)a)->width - ((car*)b)->width;
	}
	else
		switch (pivot) {
		case 1:
			return ((car*)b)->retail_price - ((car*)a)->retail_price;
		case 2:
			return ((car*)b)->dealer_cost - ((car*)a)->dealer_cost;
		case 3:
			if (((car*)b)->engine_size > ((car*)a)->engine_size) return 1;
			else return -1;
		case 4:
			return ((car*)b)->weight - ((car*)a)->weight;
		case 5:
			return ((car*)b)->width - ((car*)a)->width;
	}
}

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
				if (atoi(p)==1)	new->type |= 1 << (8 - i);
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
			kindcount = cKind(&head, 1 << (8-type));
			kindarr = malloc(sizeof(car) * kindcount);
			mArr(&head, kindarr, 1 << (8-type));
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
		printf("Name                                          Kind      WD      Price    Cost  Engine      Weight   Width\n");	
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
			fputs("Name,Kind,WD,Retail Price,Dealer Cost,EngineSize,Weight,Width\n",fwp);
			save_car(kindarr, kindcount, fwp);	
			printf("%s에 저장되었습니다.\n", buf);
			fclose(fwp);
		} else {
			free(kindarr);
		}
		head.next = &head;
		head.prev = &head;
	}
	fclose(frp);
	free(kindarr);
	return 0;	
}
