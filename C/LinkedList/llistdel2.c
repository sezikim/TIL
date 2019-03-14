#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node head = {0, &head, &head};

void add_node(struct node *prev, struct node *next, struct node *new) {
	new->prev = prev;
	new->next = next;
	prev->next = new;
	next->prev = new;
}

struct node* del_node(struct node *s) {
	struct node* del = malloc(sizeof(struct node));
	struct node* prev = s->prev;
	struct node* next = s->next;
	
	del->data = s->data;
	del->prev = NULL;
	del->next = NULL;
	
	prev->next = next;
	next->prev = prev;

	return del;
}

void print_node(struct node *head) {
	struct node *current = head->next;
	
	printf("<head> ");
	while(current != head) {
		printf("-> [%d]", current->data);
		current = current -> next;
	}
	
	printf("\n");

}

struct node data[5];

int main() {
	int i;

	for (i = 0; i < 5; ++i) {
		data[i].data = i+1;
		add_node(&head, (&head)->next, data+i);
		print_node(&head);
	}
//
	printf("삭제된 노드의 데이터는 [%d]", del_node((&head)->next)->data);
	print_node(&head);
}



