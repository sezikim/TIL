#include <stdio.h>
#include <stdlib.h>

// 선형 자료구조
// 1) 배열
// - 연속적인 메모리
// 장점
//	임의접근(RandomAcccess)가 용이하다.
// 단점
//	중간 삽입과 삭제시 처리가 힘들다.

// 2) 연결 리스트
// - 연속적인 메모리가 아닌, 논리적으로 연속적인 형태
// 장점
//	삽입 삭제시 시간이 동일하다.
// 단점
//	임의 접근이 불가능하다.

// 단일 연결리스트

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;

void add_front(int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if(head == NULL)
		head = temp;
	else{
		temp->next = head;
		head = temp;
	}
}

void print_list() {
	struct node *current = head;
	system("clear");

	printf("<head> ");
	while(current) {
		printf(" -> [%d]", current->data);
		current = current->next;
	}
	getchar();
}

int main() {
	int i;
	for(i = 0; i < 10; ++i) {
		add_front(i + 1);
		print_list();
	}
	return 0;
}
