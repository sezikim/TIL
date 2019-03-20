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

void print_list(struct node *head) {
	struct node *current = head;
	current = current -> next;
	printf("Name                                          Kind            WD       Price     Cost      Engine  Weight  Width\n");	
	while (current != head) {	
		car *cur = (car*)((char*)current - (unsigned long)&(((car*)0)->link));
		printf("%-45s %-15s %-5s %8d %8d %8d %8d %8d\n", cur->name, cur->kind, cur->wd,
								cur->price, cur->dealer_cost, cur->engine, cur->weight, cur->width);
		current = current -> next;
	}
		
}
void save_list(struct node *head, char* filename, FILE *fwp) {
	
	fwp = fopen(filename, "w");
	struct node *current = head;
	current = current -> next;
	fputs("Name,Kind,WD,Retail Price,Dealer Cost,EngineSize,Weight,Width\n",fwp);	
	while (current != head) {	
		car *cur = (car*)((char*)current - (unsigned long)&(((car*)0)->link));
		fprintf(fwp, "%s,%s,%s,%d,%d,%d,%d,%d\n", cur->name, cur->kind, cur->wd,
								cur->price, cur->dealer_cost, cur->engine, cur->weight, cur-> width);
		current = current -> next;
	}
	printf("%s에 저장되었습니다.\n", filename);
}
/*
struct node* delete_car(struct node *s, struct node *prev, struct node *next) {
	
}
*/



