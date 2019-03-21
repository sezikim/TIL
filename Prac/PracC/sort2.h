#ifndef _SORT2_H_
#define _SORT2_H_
#include "list.h"

int pivot;
int asd;
int compare(const void *a, const void *b);
void swap(char* a, char* b, size_t size); 
int carCountL(struct node *head, char *s);
void mkindArrL(struct node *head, car* kindArr, char *s); 
#endif
