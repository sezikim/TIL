#include <stdio.h>

int main() {
	char name[32];
	int age;

	while(scanf("%s %d", name, &age) != EOF) {
			printf("%s %d\n", name, age);
			fprintf(stderr, "shit...\n");
		}
}
