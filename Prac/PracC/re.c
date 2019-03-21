#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define list_entry(ptr, type, member) (type*)((char*)ptr - (unsigned long)&(((type*)0)->member))

struct node {
	struct node *prev;
	struct node *next;
};

typedef struct caR {
	char *name;
	unsigned char type;
	int price;
	int cost;
	double engine;
	int weight;
	int width;
	struct node link;
}car;

typedef enum {
	CELL_DX = 1 << 7,
	SPORTS_CAR = 1 << 6,
	SUV = 1 << 5,
	WAGON = 1 << 4,
	MINIVAN = 1 << 3,
	PICKUP = 1 << 2,
	AWD= 1 << 1,
	RWD= 1 << 0
}car_type;

const char *types[] = {
	"CellDx",
	"Sports Car",
	"SUV",
	"Wagon",
	"Minivan",
	"Pickup",
	"AWD",
	"RWD"
}
	
void insert_data(struct node *prev, struct node *next, struct node *new) {
	new->next = next;
	new->prev = prev;
	prev->next = new;
	next->prev = new;
}

void insert_car(struct node *s, struct node *new) {
	insert_data(s, s->next, new);
};

void print_car(struct node *head) {
	struct node *cur = head->next;
	
	while(cur != head) {
		car *car = list_entry(cur, car, link);
		printf("%s ", car->name);
		switch(cur->type) {
			case CELL_DX: case SPORTS_CAR: case SUV: case WAGON: case MINIVAN:
			case PICKUP: printf("%s ", type[
		}
	}
}

struct node head = { &head, &head };

int main() {

	char buf[512];
	FILE *fp = ("car_data.csv", "r");

	if (fp == NULL) {
		fprintf(stderr, "File open error...\n");
		return 1;
	}

	int i = 0;
	while (fgets(buf, sizeof(buf), fp)) {
		if (i++ == 0) continue;
		unsigned char data = 0;
		car *car = malloc(sizeof(car));

		char *p = strtok(buf, ",");
		for (i = 0 ; p != NULL; p = strtok(NULL, ","), i++) {
			switch(i) {
				case 0:
					car->name = p;
					printf("%s \n", car->name);
					break;
				case 1: case 2 : case 3: case 4: case 5: case 6: case 7:
				case 8: 
					data |= 1 << (8-i);
					break;
				case 9: 
					car->price = atoi(p);
					break;
				case 10:
					car->cost = atoi(p);
					break;
				case 11:
					car->engine = atoi(p);
					break;
				case 12:
					car->weight = atoi(p);
					break;
				case 13:
					car->width = atoi(p);
					break;
			}
			car->type = data;
		}
		insert_car(&head, car);
	}
	print_car(&head);
	
}

