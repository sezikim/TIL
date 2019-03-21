#include <stdio.h>
#include "list.h"
#include "sort2.h"
#include <string.h>
#include <stdlib.h>

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


void swap(char* a, char* b, size_t size) {
	char *temp = malloc(sizeof(size));
	int i;

	for (i = 0; i < size; ++i) {
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}
	free(temp);
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
