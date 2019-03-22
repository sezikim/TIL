#include <stdio.h>
#include "list.h"

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
		printf("Name                                          Kind       WD      Price    Cost  Engine      Weight   Width\n");	
	for (i = 0; i < kindcount; ++i) {
		printf("%-45s ", kindarr[i].name);
		if (HAS_TYPE(kindarr+i, 7-CELL_DX)) fprintf(stdout,"%-5s","CellDx ");
		if (HAS_TYPE(kindarr+i, 7-SPORTS_CAR)) fprintf(stdout,"%-5s","Sports Car ");
		if (HAS_TYPE(kindarr+i, 7-SUV)) fprintf(stdout,"%-5s","SUV ");
		if (HAS_TYPE(kindarr+i, 7-WAGON)) fprintf(stdout,"%-5s","Wagon ");
		if (HAS_TYPE(kindarr+i, 7-MINIVAN)) fprintf(stdout,"%-5s","Minivan ");
		if (HAS_TYPE(kindarr+i, 7-PICKUP)) fprintf(stdout,"%-5s","Pickup ");
		if (HAS_TYPE(kindarr+i, 7-AWD)) fprintf(stdout,"%-5s","AWD");
		else if (HAS_TYPE(kindarr+i, 7-RWD)) fprintf(stdout,"%-5s","RWD");
		else fprintf(stdout, "%-5s","   ");
		printf("%8d ", kindarr[i].retail_price);
		printf("%8d ", kindarr[i].dealer_cost);
		printf("%8lf ", kindarr[i].engine_size);
		printf("%8d ", kindarr[i].weight);
		printf("%8d\n", kindarr[i].width);
		}
}

void save_car(car *kindarr, int kindcount, FILE *fp) {
	int i;
	fputs("Name,Kind,WD,Retail Price,Dealer Cost,EngineSize,Weight,Width\n",fp);
	for (i = 0; i < kindcount; ++i) {
		fprintf(fp, "%s,", kindarr[i].name);
		if (HAS_TYPE(kindarr+i, 7-CELL_DX)) fprintf(fp, "CellDx,");
		if (HAS_TYPE(kindarr+i, 7-SPORTS_CAR)) fprintf(fp, "Sports Car,");
		if (HAS_TYPE(kindarr+i, 7-SUV)) fprintf(fp, "SUV,");
		if (HAS_TYPE(kindarr+i, 7-WAGON)) fprintf(fp, "Wagon,");
		if (HAS_TYPE(kindarr+i, 7-MINIVAN)) fprintf(fp, "Minivan,");
		if (HAS_TYPE(kindarr+i, 7-PICKUP)) fprintf(fp, "Pickup,");
		if (HAS_TYPE(kindarr+i, 7-AWD)) fprintf(fp, "AWD,");
		if (HAS_TYPE(kindarr+i, 7-RWD)) fprintf(fp, "RWD,");
		fprintf(fp, "%d,", kindarr[i].retail_price);
		fprintf(fp, "%d,", kindarr[i].dealer_cost);
		fprintf(fp, "%lf,", kindarr[i].engine_size);
		fprintf(fp, "%d,", kindarr[i].weight);
		fprintf(fp, "%d\n", kindarr[i].width);
		}
}

int cKind(struct node *head, int kind) {
	int count = 0;
	struct node *cur = head->next;

	while (cur != head) {
		car *curcar = (car*)((char*)cur - (unsigned long)&(((car*)0)->link));
		if(HAS_TYPE(curcar, kind)) count++;
		cur = cur->next;	
	}
	return count;
}

void mArr(struct node *head, car *kindarr, int kind) {
	struct node *cur = head->next;
	int i = 0;
	while (cur != head) {
		car *curcar = (car*)((char*)cur - (unsigned long)&(((car*)0)->link));
		if (HAS_TYPE(curcar, kind)) {
			*(kindarr+i) = *curcar;
			i++;
		}
		cur = cur->next;
	}
}
