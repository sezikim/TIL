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
	if (((car*)a)->engine > ((car*)b)->engine)	return 1;
	else return -1;
}
int comparee1(const void *a, const void *b) {
	if (((car*)a)->engine < ((car*)b)->engine)	return 1;
	else return -1;
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

void mkindArrA(car* cArr, car* kindArr, int count, char *s) {
	int i;
	int j = 0;
	for(i=0; i < count; ++i) {
		if(strcmp((cArr+i)->kind, s) == 0) kindArr[j++] = cArr[i];
	}
}
