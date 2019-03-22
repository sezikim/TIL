#include <stdio.h>

int main()
{
	FILE* fp = fopen("abc.txt", "r+t");
	int menu;
	char str[100];
	if(fp==NULL){
		puts("open fail");
		return 0;
	}
	while(1){
	printf("1. 파일읽기 2. 파일쓰기 3. 종료\n");
	scanf("%d", &menu);
	
		switch(menu)
		{
	  	case 1:
	  		fseek(fp, 0, SEEK_SET);
	  		fgets(str,sizeof(str),fp);
	 			puts(str);
				break;
	 		 case 2:
	 			scanf(" %s", str);
				fputs(str,fp);
				break;
	 		 default:
	  		printf("종료");
	  		fclose(fp);
	  		return 0;
		}
	}
}
