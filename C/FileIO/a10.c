#include <stdio.h>

int main() {
	char word[32];
	FILE* fp = fopen("test.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "File open error...\n");
		return 1;
	}
	
	while (fscanf(fp, "%s", word) != EOF) {
		printf("%s\n", word);
		// rewind(fp); // offset: 0
		// fseek(fp, -5, SEEK_CUR); 
		fseek(fp, 0, SEEK_END);
		// ftell(fp);
	}
}
