#include <stdio.h>

int main() {
	FILE *fp = fopen("a.txt", "w");
	FILE *fp2 = fopen("a.txt", "r");
	char word[32];

	while(1) {
		int len = fprintf(fp, "hello\n");
		fflush(fp);
		getchar();
		fscanf(fp2, "%s", word);
		printf("%s\n", word);
		getchar();
	}
}
