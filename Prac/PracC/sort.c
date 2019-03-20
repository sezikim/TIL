#include <stdio.h>
#include "list.h"
#include <string.h>
#include <stdlib.h>

int comparep2(const void *a, const void *b) {
	return ((car*)a)->price - ((car*)b)->price;
}
int comparep1(const void *a, const void *b) {
	return ((car*)b)->price - ((car*)a)->price;
}

int comparec2(const void *a, const void *b) {
	return ((car*)a)->dealer_cost - ((car*)b)->dealer_cost;
}
int comparec1(const void *a, const void *b) {
	return ((car*)b)->dealer_cost - ((car*)a)->dealer_cost;
}

int comparee2(const void *a, const void *b) {
	return ((car*)a)->engine - ((car*)b)->engine;
}
int comparee1(const void *a, const void *b) {
	return ((car*)b)->engine - ((car*)a)->engine;
}

int comparewe2(const void *a, const void *b) {
	return ((car*)a)->weight - ((car*)b)->weight;
}
int comparewe1(const void *a, const void *b) {
	return ((car*)b)->weight - ((car*)a)->weight;
}
int comparewi2(const void *a, const void *b) {
	return ((car*)a)->width - ((car*)b)->width;
}
int comparewi1(const void *a, const void *b) {
	return ((car*)b)->width - ((car*)a)->width;
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

// 배열로 할때
int carCountA(car* cArr, int count, char *s) {
	int i;
	int kindC = 0;
	for(i = 0; i < count; ++i) {
		if(strcmp((cArr+i)->kind, s) == 0 ) {
			kindC++;
		}
	}
	return kindC;
}

// 리스트로 할때
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

// 배열로 할때
void mkindArrA(car* cArr, car* kindArr, int count, char *s) {
	int i;
	int j = 0;
	for(i=0; i < count; ++i) {
		if(strcmp((cArr+i)->kind, s) == 0) kindArr[j++] = cArr[i];
	}
}

// 리스트로 할때
void mkindArrL(struct node *head, car *kindArr, char *s) {
	int i = 0;
	int j = 0;
	struct node *cur = head;
	cur = cur->next;
	while(cur != head) {
		car *curcar = (car*)((char*)cur - (unsigned long)&(((car*)0)->link));
		if(strcmp(curcar->kind, s) == 0) {
			strcpy((kindArr+j)->name, curcar->name);
			strcpy((kindArr+j)->kind, curcar->kind);
			strcpy((kindArr+j)->wd, curcar->wd);
			(kindArr+j)->price = curcar->price;
			(kindArr+j)->dealer_cost = curcar->dealer_cost;	
			(kindArr+j)->engine = curcar->engine;
			(kindArr+j)->weight = curcar->weight;
			(kindArr+j)->width = curcar->width;
			j++;
		}
		cur = cur->next;
	}
}
