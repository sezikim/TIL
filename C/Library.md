# man page
- section 1 user commands
- section 2 system calls
- section 3 library funtions

# 라이브러리
## 정적 라이브러리
- Linux : .a
- Windows : .lib
- 실행 파일 안에 함수의 구현이 포함된다.
- 추가적인 로드가 필요 없다.
- 실행 파일의 크기가 커진다.
- 라이브러리가 변경되면, 컴파일을 다시 해야한다.
- 배포가 쉽다.
- ar rcv libadd.a add.o
- gcc main.o -ladd -L.
## ar rcv
- ar
    - archive파일을 만드는 도구
- r
    - archive에 새로운 file member를 삽입한다.
- c
    - archive가 존재하지 않으면 archive를 생성한다.
- v
    - library가 변화하는 과정을 보여준다.

## 동적 라이브러리
- Linux : .so(shared object)
- Windows : .dll(dynamic loading library)
- 실행 중에 필요한 라이브러리를 동적으로 메모리에 로드해서 사용.
- 실행 파일 안에 함수의 구현이 존재하지 않는다.
- 실행파일의 크기가 크지 않다.
- 추가적인 로드가 필요하다.
- 라이브러리가 변경되어도 다시 컴파일을 할 필요가 없다.
-     gcc add.o -shared -fpic -o libadd.so
      LD_LIBRARY_PATH =. ./a.out

## #include <dlfcn.h>
- void *dlopen (const char *filename, int flag);
    - shared library파일을 찾아서 메모리에 loading하거나 loading 준비를 한다.
    - shared library에 대한 참조 count를 1 증가시킨다.
    - filename이 full path가 아니면 LD_LIBRARY_PATH에 콜론으로 분리된 디렉토리 중에 filename 파일이 존재해야 한다.
    - flag : RTLD_LAZY, RTLD_NOW
    - RTLD_LAZY : 실제로 사용되는 시점에 loading 
    - RTLD_NOW : dlopen 함수 내에서 loading을 끝냄
    - 오류이면 NULL이 return
    - 정상이면 NULL이 아닌값이 return;

- void *dlsym (void *handle, const char *symbol);
    - open된 shared library에서 symbol(함수, 전역변수 등)의 시작번지를 return
    - handle : dlopen이 return한 handle값
    - symbol : 찾으려는 symbol명
    - symbol에 대한 위치값(Pointer) return
    - NULL이 return된다고 오류는 아니나, 함수 pointer인 경우, NULL이면 오류
- int dlclose (void *handle);
    - shared library에 대한 참조 count를 1 감소시킨다.

## -shared
- 동적 라이브러리를 만드는 옵션.
- 다른 오브젝트들에 링크되어 실행 가능한 형태가 될 수 있도록 하는 옵션.
## -fpic
- gcc를 호출할 때, 위치 독립적인 코드를 생성하게 하는 옵션
- 환경변수에 영향을 받지 않는다.
- -fpic -fPIC 모두 해주어야 한다.

