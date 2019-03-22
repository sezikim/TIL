#ifndef _LIST_H_
#define _LIST_H_
#define ADD_TYPE(car, type) (car)->kind[(type)/32] |= 1 << ((type) %32)
#define HAS_TYPE(car, type) (car)->kind[(type)/32] & 1 << ((type) % 32)

struct node{
	struct node *prev;
	struct node *next;
};

enum {
	CELL_DX,
	SPORTS_CAR,
	SUV,
	WAGON,
	MINIVAN,
	PICKUP,
	AWD,
	RWD,
	MAX_TYPE = 8,
};

typedef unsigned int bitset[MAX_TYPE / (sizeof(unsigned int) * 8) + 1];

typedef struct {
	char *name;
	bitset kind;
	int retail_price;
	int dealer_cost;
	double engine_size;
	int weight;
	int width;
	struct node link;
}car;

void insert_data(struct node *prev, struct node *next, struct node *new);
void insert_car(struct node *s, struct node *next);
void print_car(car *kindarr, int kindcount);
void save_car(car *kindarr, int kindcount, FILE *fp);
int cKind(struct node *head, int kind);
void mArr(struct node *head, car *kindarr, int kind); 
#endif
