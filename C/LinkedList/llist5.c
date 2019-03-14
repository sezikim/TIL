#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
};

//struct node tail={0, &tail};
struct node head={0, &head};
// -> 환형 연결리스트

void insert_data(struct node *s, int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;

	temp->next = s->next;
	s->next = temp;
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

int main() {
	int i;
	for(i = 0; i < 10; ++i) {
		insert_data(&head, i + 1);
		print_list(&head);
	}
	return 0;
}
