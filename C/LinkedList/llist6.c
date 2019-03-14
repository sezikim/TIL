#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node head = { 0, &head, &head };

void add_next(struct node *s, int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;

	temp->prev = s;
	temp->next = s -> next;
	s->next->prev = temp;
	s->next = temp;
}

void add_front(struct node *s, int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;

	temp->prev = s->prev;
	temp->next = s;
	s->prev->next = temp;
	s->prev = temp;
}

void print_list(struct node *head) {
	struct node *current = head->next;
	system("clear");

	printf("<head> ");
	while(current != head) {
		printf(" -> [%d]", current->data);
		current = current->next;
	}
	getchar();
}

void print_list2(struct node *head) {
	struct node *current = head->prev;
	system("clear");

	printf("<head> ");
	while(current != head) {
		printf(" -> [%d]", current->data);
		current = current->prev;
	}
	getchar();
}
int main() {
	int i;
	for (i = 0; i < 10; ++i) {
		add_next(&head, i+1);
		print_list2(&head);
	}
}
