#ifndef _SORT_H_
#define _SORT_H_
#include "list.h"

int comparep1(const void *a, const void *b);
int comparep2(const void *a, const void *b);
int comparec1(const void *a, const void *b);
int comparec2(const void *a, const void *b);
int comparee1(const void *a, const void *b);
int comparee2(const void *a, const void *b);
int comparewe1(const void *a, const void *b);
int comparewe2(const void *a, const void *b);
int comparewi1(const void *a, const void *b);
int comparewi2(const void *a, const void *b);
void swap(char* a, char* b, size_t size); 
int carCountA(car* cArr, int count, char *s);
void mkindArrA(car* cArr, car* kindArr, int count, char *s); 
#endif
