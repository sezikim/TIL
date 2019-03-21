#ifndef _LIST_H_
#define _LIST_H_

struct node {
	struct node *prev;
	struct node *next;
};
struct node head = { &head, &head };

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

void insert_data(struct node *prev, struct node *next, struct node *new);
void insert_car(struct node *s, struct node *new);
void print_list(struct node *s);
//struct node* delete_car(struct node *s, struct node *prev, struct node *next);
#endif
