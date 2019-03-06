## 스트림
- 데이터를 입출력 하기위해 이들을 연결시켜 주는 다리
- 운영체제는 외부장치와 프로그램의 데이터 송수신의 도구가 되는 스트림을 제공.

# 문자 단위 입출력 함수
## 문자 출력 함수
- **putchar**
    - int putchar(int c);
    - 인자로 전달된 문자정보를 stdout 표준 출력 스트림으로 전송하는 함수.
- **fputc**
    - int fputc(int c, FILE* stream);
    - 문자를 전송할 스트림을 지정할 수 있는 함수. stream을 stdout으로 지정하면 putchar와 동일한 함수가 된다.
- 두 함수 오류 발생시, EOF반환.

## 문자 입력 함수
- **getchar**
    - int getchar(void);
    - stdin 표준 입력 스트림으로부터 하나의 문자를 입력 받아 반환하는 함수.
- **fgetc**
    - int fgetc(FILE* stream);
    - 문자를 입력할 스트림을 지정할 수 있는 함수. puchar, fputc 관계와 동일.
- 함수 호출 실패시, EOF 반환
```
#include <stdio.h>

int main(void)
{
    int ch1, ch2;
    
    ch1 = getchar();
    ch2 = fgetc(stdin);
    
    putchar(ch1);
    fpuc(ch2, stdout);
    return 0;
}
```
- 위 코드를 실행하면, 입력한 하나의 문자를 그대로 출력하는 결과를 보인다.

## 문자 입출력에서의 EOF
- End Of File의 약자.
- 파일의 끝을 표현하기 위해 정의해 놓은 상수.
- '파일의 끝에 도달해서 더이상 읽을 내용이 없다.'
- 윈도우에서 CTRL+Z, 리눅스에서 CTRL+D

## getchar, fgetc 반환형이 int인 이유?
- EOF는 -1로 정의된 상수.
- char형을 unsigned char로 처리하는 컴파일러에서 양의 정수로 형 변환이 될 수 있다.
- 따라서 어떠한 상황에서도 EOF를 인식할 수 있는 int형으로 반환.

## 문자열 출력 함수
- **puts**
    - int puts(const char* s);
- **fputs**
    - int fputs(const char* s, FILE* stream);
- 두 함수의 차이점
    - puts 함수는 문자열 출력 후 자동으로 개행, fputs 함수는 자동으로 개행X

## 문자열 입력 함수
- **gets**
    - char* gets(char* s);
    - 할당 받은 메모리 공간을 넘어서는 문자열이 입력되면, 오류 발생.
- **fgets**
    - char* fgets(chars* s, int n, FILE* stream);
    - 파일의 끝에 도달하거나 함수호출 실패 시 NULL 포인터 반환.
    - stdin으로부터 문자열을 입력받아, n의 길이만큼 저장.
    - 문자열의 길이는 NULL까지 이므로, n의 값이 7이면 6개의 문자 + NULL 저장.
    - fgets 함수는 \n 을 만날 때 까지 문자열을 읽어드린다.
```
#include <stdio.h>

int main(void)
{
    char str[7];
    int i;
    
    for(i=0; i<3; i++)
    {
        fgets(str, sizeof(str), stdin);
        printf("Read %d: %s\n", i+1, str;)
    }
    return 0;
}
```
## 표준 입출력 기반의 버퍼
- 메모리 버퍼
    - 데이터를 임시로 모아두는 메모리 공간.
- 키보드를 통해 입력되는 데이터는, 입력버퍼에 저장된 다음에 프로그램에서 읽혀진다.
- 데이터가 입력 스트림을 거쳐 입력버퍼로 들어가는 시점은 엔터키가 눌리는 시점이다.

## 출력버퍼를 비우는 함수 fflush
- int fflush(FILE* stream);
- 출력버퍼가 비워진다. -> 출력버퍼에 저장된 데이터가 버퍼를 떠나서 목적지로 이동됨

## 입력버퍼는 어떻게?
- 입력버퍼가 비워진다. -> 데이터의 소멸을 의미
- fflush 는 출력버퍼를 비우는 함수
- while(getchar() != '\n';와 같이 지운다.

## 문자열 관련 함수

## strlen
- 문자열의 길이를 반환하는 함수
- string.h에 선언
- size_t strlen(const char* s);

## strcpy, strncpy
- 문자열을 복사하는 함수
- string.h에 선언
- char* strcpy(char* dest, const char* src);
- char* strncpy(char* dest, const char* src, size_t n);
    - 널 문자가 삽입된 공간을 남겨두고 복사를 진행하고, 배열의 끝에 널 문자를 삽입해야 한다.
    - strncpy(dest, src, sizeof(dest)-1);
    - dest[sizeof(dest)-1] = 0;

## strcat, strncat
- 문자열의 뒤에 다른 문자열을 복사하는 함수
- string.h에 선언
- char* strcat(char* dest, const char* src);
    - null문자가 저장된 위치에서부터 복사가 진행된다.
- char* strncat(char* dest, const char* src, size_t n);
    - src의 길이가 n보다 크다면 n만큼 복사, null문자 삽입 -> 총 n+1개의 문자가 덧붙여 진다.

## strcmp, strncmp
- 아스키 코드값을 기준으로 두 문자열을 비교하는 함수
- string.h에 선언
- int strcmp(const char* s1, const char* s2);
    - s1이 더 크면 양수 반환.
    - 내용이 같으면 0반환
    - s2가 더 크면 음수 반환.
- int strncmp(const char* s1, const char* s2, size_t n);

## atoi, atol, atof
- 문자열의 내용을 int, long, double 형으로 변환 
- stdlib.h에 선언
- int atoi(const char* str);
- long atol(const char* str);
- double atof(const char* str);
