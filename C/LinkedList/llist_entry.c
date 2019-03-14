#include <stdio.h>

struct node {
	struct node *prev;
	struct node *next;
};

struct user {
	char name[32];
	struct node links;
	int age;
};

#if 0
p->age = *(31)
000     ------
				 name
31			------
				 age
35			------
				links
#endif

#define list_entry(ptr, type, member) /
								(type*)((char*)ptr - (unsinged long)&(((type*)0)->member))
								// 구조체의 시작점으로 부터 links까지의 주소값을 링크의 주소값에서 뺀다.
								// => 구조체의 시작 주소값
int main() {
	struct user user = { .name = "Tom", .age = 42 };
	struct node *current = &user.links;

	struct user *p = list_entry(current. struct user, links);
#if 0
	struct user *p = 
					(struct user*)((char*)current - (unsinged long)&(((struct user*)0)->links));
#endif
					printf("%s %d\n", p->name, p->age);
}
