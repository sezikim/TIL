
## 파일 스트림
- 파일과 프로그램사이에 스트림을 형성해야 데이터를 주고 받을 수 있다.

## 스트림의 생성 - fopen
```
#include <stdio.h>
FILE* fopen(const char* filename, const char* mode);
//호출 성공시 FILE구조체의 포인터, 실패시 null 반환
```
- 함수의 첫번째 인자로는, 스트림을 형성할 파일의 이름
- 두번째 인자로는, 스트림의 종류.
- 스트림을 형성하고 스트림 정보를 FILE구조체 변수에 담아 주소값을 반환.
- EX
-       FILE* fp = fopen("data.txt", "wt"); 
        //출력스트림
        FILE* fp = fopen("data.txt", "rt");
        //입력스트림

## 스트림의 소멸 - fclose
```
#include <stdio.h>
FILE* fclose(FILE* stream);
호출 성공시 0, 실패시 EOF반환
```
- 운영체제가 할당한 자원의 반환
- 버퍼링 되었던 데이터의 출력
- 운영체제에 할당된 메모리는 **fclose를 하기 전까지 할당된 채로 남아있어 자원의 손실을 초래**한다. -> 반드시 사용후 fclose를 해야한다.

## fflush
- 출력버퍼를 비우는 함수.
- 출력버퍼를 비운다는 것
    - 출력버퍼에 저장된 데이터를 목적지로 전송하는것.

## 텍스트 파일과 바이너리 파일
- 텍스트파일
    - 사람이 인식할 수 있는 문자를 담고 있는 파일
    - 도서의 목록, 슈퍼마켓 물품 가격
- 바이너리 파일
    - 컴퓨터가 인식할 수 있는 데이터를 담고 있는 파일
    - 타이타닉 영상파일, 윤종신의 히트곡 음원파일

## 파일의 개방모드

|모드|스트림의 성격|파일이 없으면?|
|---|---|---|
|r|읽기|에러|
|w|쓰기|생성|
|a|파일의 끝에 덧붙여 쓰기|생성|
|r+|읽기/쓰기|에러|
|w+|읽기/쓰기|생성|
|a+|읽기/덧붙여 쓰기|생성|
- **r, w, a 중에서 선택하여 스트림을 형성하는 것이 일반적.**
- r+, w+, a+는 쓰기에서 읽기로 작업을 변경할 때마다 메모리 버퍼를 비워줘야함.
- 파일의 개방 모드에 텍스트 모드와 바이너리 모드를 함께 써서 사용한다.

## feof
- 파일의 마지막에 저장된 데이터까지 모두 읽었는지 확인하는 함수.
-       #include <stdio.h>
        int feof(FILE* stream);
- 파일의 끝에 도달한 경우 0이 아닌 값 반환.
- 다음과 같이 사용된다.
```
#include <stdio.h>

int main(void)
{
    FILE* src = fopen("src.txt", "rt");
    FILE* des = fopen("des.txt", "wt");
    int ch;
    
    if(src==NULL || des==NULL){
        puts("파일오픈 실패!");
        return -1;
    }
    
    while((ch=fgetc(src))!=EOF)
        fputc(ch, des);
        
    if(feof(src)!=0)
        puts("파일복사 완료!");
    else
        puts("파일복사 실패!");

    fclose(src);
    fclose(des);
    
    return 0;
}
```

## 바이너리 데이터의 입출력: fread, fwrite
-       #include <stdio.h>
        size_t fread(void* buffer, size_t size, size_t count, FILE* stream);
        size_t fwitre(const void* buffer, size_t size, size_t count, FILE* stream);
- 둘다 성공시 전달인자 count를 반환하고, 실패하거나 파일의 끝에 도달시 count보다 작은값을 반환.
```
int buf1[12];
fread((void*)buf, sizeof(int), 12, fp);
// sizeof(int)크기의 데이터 12개를 fp로부터 읽어서 buf1에 저장
int buf2[7] = {1, 2, 3, 4, 5, 6, 7};
fwrite((void*)buf2, sizeof(int), 7, fp);
// sizeof(int)크기의 데이터 7개를 buf2로부터 읽어서 fp에 저장
```
```
#include <stdio.h>

int main()
{
    FILE* src = fopen("src.bin", "rt");
    FILE* des = fopen("des.bin", "wt");
    char buf[20];
    int readCnt;
    
    if(src==NULL || des==NULL){
        puts("파일오픈 실패");
        return -1;
    }
    
    while(1)
    {
        readCnt = fread((void*)buf, sizeof(char), sizeof(buf), src);
        
        if(readCnt<sizeof(buf){
            if(feof(src)!=0){
                fwrite((void*)buf, sizeof(char), readCnt, des);
                puts("파일복사 완료");
            } else
                puts("파일복사 실패");
        }
        fwrite((void*)buf,sizeof(char),sizeof(buf),des);
    }
    fclose(src);
    fclose(des);
    return 0;
}
```

## fscanf, fprintf
- 텍스트 데이터와 바이너리 데이터를 동시에 입출력 할 수 있다.
- scanf, printf와의 차이점은 구조체 포인터가 첫번째 전달인자로 들어가는 점이다.
- EX
-      char name[10] = "홍길동";
       char sex = 'M';
       int age = 24;
       fprintf(fp, "%s %c %d", name, sex, age);
-      char name[10];
       char sex;
       int age;
       fscanf(fp, "%s %c %d", name, &sex, &age);

## 구조체 변수의 입출력
- 구조체 변수를 하나의 바이너리 데이터로 인식하고 처리.
```
#include <stdio.h>

typedef struct fren
{
    char name[10];
    char sex;
    int age;
}Friend;

int main(void)
{
    FILE* fp;
    Friend myfren1;
    Friend myfren2;
    
    fp = fopen("friend.bin", "wb");
    printf("이름 성별 나이 순 입력: ");
    scanf("%s %c %d", myfren1.name, &(myfren1.sex), &(myfren1.age));
    fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);
    fclose(fp);
    
    fp = fopen("friend.bin", "rb");
    fread((void*)&myfren2, sizeof(myfren2), 1, fp);
    printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);
    fclose(fp);
    return 0;
}
```

## 파일 위치 지시자
- FILE 구조체의 멤버 중 **파일 위치 정보를 저장하고 있는 멤버.**
- 파일 위치 지시자는 파일이 **처음 개방되면 무조건 파일의 맨 앞부분을 가리킨다.**
- 파일의 중간 혹은 마지막 부분부터 읽거나 쓰기를 원한다면, 파일 위치 지시자를 이동시켜야 함

## fseek
- 파일 위치 지시자를 이동시키는 함수.
-     #include <stdio.h>
      int fseek(FILE* stream, long offset, int wherefrom);
- strea의 파일 위치 지시자를 wherefrom 부터 offset만큼 이동시킨다.

## ftell
- 파일 위치 지시자 정보를 확인하는 함수
-     #include <stdio.h>
      long ftell(FILE* stream);
- 지시자가 첫번째 바이트를 가리키면 0을 반환하고 세번째 바이트를 가리키면 2를 반환한다.
