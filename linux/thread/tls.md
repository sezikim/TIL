## Thread Local Storage
> 한 프로세스에 속한 스레드들은 그 프로세스의 데이터를 모듀 공유한다. 상황에 따라서는 각 스레드가 자기만 액세스할 수 있는 데이터를 가져야 할 필요가 있다.

- 각 스레드의 고유한 정보를 저장한다.
- Pthread, Windows, Java 등 대부분의 스레드 라이브러리 에서 TLS를 지원한다.

- POSIX
```C
int pthread_key_create(pthread_key_t *key, void (*destr_function) (void *));
int pthread_key_delete(pthread_key_t key);
```
- 초기화 및 해제
```C
pthread_key_t aKey;
if (0 != pthread_key_create(&aKey, free)) {
    // free는 malloc에 대응되는 것으로 자동으로 메모리 해제
    // 에러 처리
}
pthread_key_delete(aKey);
```

- 값 저장 및 획득
```C
int pthread_setspecific(pthread_key_t key,const void* pointer);
void* pthread_getspecific(pthread_key_t key);
```
```C
char *buf = malloc(100 * sizeof(char));
if (0 != pthread_setspecific(aKey, (const void*) buf)) {
    // 에러 처리
}
buf = (char*)pthread_getspecific(aKey);
```

- JAVA
```JAVA
private ThreadLocal myThreadLocal = new ThreadLocal<String>();
myThreadLocal.set("A thread local value");
String threadLocalValue = myThreadLocal.get();
```s
