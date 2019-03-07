## C언어의 메모리 구성

- 코드 영역
    - 실행할 프로그램의 코드가 저장되는 메모리 공간. CPU가 코드영역에 저장된 명령문들을 하나씩 가져가서 실행.
- 데이터 영역
    - 전역변수와 static으로 선언되는 변수가 할당된다. **프로그램 시작과 동시에 메모리 공간에 할당되어 프로그램 종료시까지** 남아있게 된다.
- 스택 영역
    - 지역변수와 매개변수가 할당된다.
    - 함수를 빠져나가면 소멸된다.
- 힙 영역
    - **데이터 영역과 스택 영역은 생성과 소멸의 시점이 결정되어 있다.** **이와 다른 성격의 변수**가 필요할 때 사용되는 영역.

## 힙 영역의 메모리 공간 할당,해제
## malloc
- **heap영역**에 메모리 공간 할당
- 반환형이 void* 이므로, **사용자가 형 변환을 하여 결정**해야 한다.
- **할당된 메모리 공간은 초기화 하지 않으면 쓰레기값이 들어가 있다.**
- stdlib.h에 있다.
-     int* ptr1 = (int*)malloc(sizeof(int));
      double* ptr2 = (double*)malloc(sizeof(double));
      int* ptr3 = (int*)malloc(sizeof(int)*7);
      double* ptr4 = (double*)malloc(sizeof(double)*9);
## free
- 할당된 메모리 공간 해제
-     #include <stdlib.h>
      void* malloc(size_t size);
      void free(void* ptr);
- **힙에 할당된 메모리 공간은 포인터 변수를 이용하는 수 밖에 없다.**

## calloc
- malloc은 할당할 메모리 공간의 사이즈를 인자로 받지만, calloc은 할당할 블록의 갯수와, 블록의 사이즈를 인자로 받는다.
- **할당된 메모리 공간의 모든 비트를 0으로 초기화 시킨다.**
-     #include<stdlib.h>
      void* calloc(size_t elt_count, size_t elt_size);
      
## realloc
- 힙에 할당된 영역에서 realloc을 사용해서 메모리 공간을 확장할 수 있다.
-     int main(void){
        int* arr = (int*)malloc(sizeof(int)*3); // 길이가 3인 int형 배열 할당
        arr = (int*)realloc(arr, sizeof(int)*5); // 길이가 5인 int형 배열로 확장
     		return 0;
     }
