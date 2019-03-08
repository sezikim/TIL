#include <stdio.h>
#include <string.h>

void Palindrome(char*, int);

int main(void)
{
	char str[30];
	
	printf("문자열 입력: ");
	scanf("%s", str);
	Palindrome(str, strlen(str));

	return 0;
}

void Palindrome(char* str, int len)
{
	for(int i=0;i<len;i++)
		if(str[i]!=str[--len]){
			printf("화문이 아닙니다.\n");
			return;
		}
		printf("화문 입니다.\n");
	return;
}

