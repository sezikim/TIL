#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
};

struct node head = { 0,&head };
// s 뒤에 노드 삽입
void add_node(struct node *s, struct node *new) {
	new->next = s->next;
	s->next = new;
}
// s 노드 삭제
struct node* del_node(struct node *s) {
	struct node *del = malloc(sizeof(struct node));
	struct node *prev = &head;

	del->data = s->data;
	del->next = NULL;

	while(1) {
		if(prev->next == s) break;	
		prev = prev->next;
	}
	prev->next = s->next;

	return del;
}


void print_list(struct node *head) {
	struct node *current = head->next;

	printf("<head> ");

	while(current != head) {
		printf("-> [%d]", current->data);
		current = current->next;
	}
	printf("\n");
	getchar();
}

struct node data[5];

int main() {
	int i;

	for(i = 0; i < 5; ++i) {
		data[i].data = i + 1;
		add_node(&head, data+i);
		print_list(&head);
	}
	printf("\n 삭제노드의 데이터 : [%d]\n", (del_node((head.next)->next))->data);
	
	print_list(&head);
}
