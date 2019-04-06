# 스레드
> 운영체제에서 실행 중인 하나의 애플리케이션을 프로세스(process) 라고 부른다. 
하나의 프로세스가 두 가지 이상의 작업을 처리할 수 있을까 ?  --> 멀티 스레드
- 스레드는 사전적 의미로 한 가닥의 실이라는 뜻이다. 
- 한 가지 작업을 실행하기 위해 순차적으로 실행할 코드를 실처럼 놓았다.
- 한 프로세스 내에 스레드가 두 개 --> 두 개의 코드 실행 흐름이 생긴다.
- 스레드에서 예외 발생시, 프로세스가 종료 되기 때문에 멀티 스레드에서 예외처리가 매우 중요하다.

## 작업 스레드 생성과 실행
- 메인 작업 이외에 추가적인 병렬 작업의 수만큼 스레드를 생성.
- Thread 클래스를 직접 객체화 하거나, 상속해서 하위 클래스를 만들어 생성.
```java
Thread thread = new Thread(Runnable target);
```
- 코드를 좀더 절약하기 위해 Runnable 익명 객체를 만들어 사용할 수 있다.
```java
Thread thread = new Thread( new Runnable() {
    public void run() {
        //스레드가 실행할 코드;
    }
});
```
- 이를 람다식으로 표현하면
```java
Thread thread = new Thread(() -> {
    //스레드가 실행할 코드;
});
```
## 스레드 우선순위
>멀티 스레드는 동시성 또는 병렬성으로 실행되기 때문에 이 용어들에 대해 정확히 이해하는 것이 좋다.
- 동시성
    - 멀티 작업을 위해 하나의 코어에서 멀티 스레드가 번갈아가며 실행하는 성질
- 병렬성
    - 멀티 작업을 위해 멀티 코어에서 개별 스레드를 동시에 실행하는 성질

- 스레드 스케쥴링
    >스레드의 개수가 코어의 수보다 많을 경우, 스레드를 어떤 순서에 의해 동시성으로 실행할 것인가를 결정
    - 우선순위 방식
        - 우선순위가 높은 스레드가 실행 상태를 더 많이 가지도록 스케줄링
        - 개발자가 코드로 제어가능
    - 순환 할당 방식
        - 시간 할당량을 정해서 하나의 스레드를 정해진 시간만큼 실행하고 다시 다른 스레드를 실행하는 방식
        - 개발자가 코드로 제어할 수 없다.

## 스레드 동기화
- 공유 객체를 사용할 때, 한 스레드를 사용하던 객체가 다른 스레드에 의해 상태가 변경될 수 있다.
- 스레드 작업이 끝날 때까지 객체에 잠금을 걸어서 다른 스레드가 사용하지 못하도록 한다. -> 코드 임계영역(critical section)
- 코드 임계영역을 지정하기 위해 동기화 메소드, 블록을 제공한다
```java
public synchronized void method() {
    임계영역; // 단 하나의 스레드만 실행
}
```
- 메소드 일부 내용만 임계영역 (동기화 블록)
```java
synchronized(공유객체) {
    임계영역; // 단 하나의 스레드만 실행
}
```

## 스레드 상태
- 실행 대기 상태
    - 아직 스케줄링이 되지 않아서 실행을 기다리고 있는 상태
- 실행 상태
    - 실행 대기 상태에 있는 스레드 중에서 스레드 스케줄링으로 선택된 스레드가 CPU를 점유하고 run()메소드 실행.
    - run() 메소드를 모두 실행하기 전에 스레드 스케줄링에 의해 다시 실행 대기 상태로 돌아갈 수 있다.
    - run() 메소드가 종료되면, 종료 상태가 된다.
- 일시 정지 상태
    - 스레드가 실행할 수 없는 상태
    - 실행 상태로 다시 가기위해서는 실행 대기 상태로 가야한다.

|열거 상수|상태|설명|
|---|---|---|
|NEW|객체 생성|스레드 객체가 생성, 아직 start() 메소드가 호출되지 않은 상태|
|RUNNABLE|실행 대기|실행 상태로 언제든지 갈 수 있는 상태|
|WAITING|일시 정지|다른 스레드가 통지할 때까지 기다리는 상태|
|TIME_WAITING|일시 정지|주어진 시간 동안 기다리는 상태|
|BLOCKED|일시 정지|사용하고자 하는 객체의 락이 풀릴 때까지 기다리는 상태|
|TERMINATED|종료|실행을 마친 상태|

## 스레드 상태 제어
- 멀티 스레드 프로그램을 만들기 위해서는 정교한 스레드 상태 제어가 필요하다.
- 스레드의 상태 변화를 가져오는 메소드들을 파악하고 있어야한다.
![스레드 상태제어](https://t1.daumcdn.net/cfile/tistory/2135CD42566BC7D825)

## sleep()
- 실행 중인 스레드를 일정 시간 멈추게 할때 사용.

## yiled()
- yield() 메소드를 호출한 스레드는 실행 대기 상태로 돌아가고 동일한 우선순위 또는 높은 우선순위를
갖는 다른 스레드가 실행 기회를 가질 수 있도록 해준다.

## join()
- join() 메소드를 호출한 스레드의 run() 메소드가 종료할 때까지 일시 정지 상태.

## wait(), notify(), notifyAll()
- notify() 메소드는 일시 정지 상태에 있는 다른 스레드를 실행 대기 상태로 만든다.
- wait() 메소드는 일시 정지 상태로 만든다.
- 이 메소드들은 Thread 클래스가 아닌 Object 클래스에 선언된 메소드이므로 모든 공유 객체에서 호출 가능.

## stop 플래그, interrupt()
>실행 중인 스레드를 즉시 종료할 때 사용된다.
- stop 플래그
```java
public clss XXXThread extends Thread {
    private boolean stop;
    
    public void run() {
        while( !stop ) {
            스레드가 반복 실행하는 코드;
        }
        //스레드가 사용한 자원 정리
    }
}
```
- interrupt() 메소드
    - 스레드가 일시 정지 상태에 있을 때, InterruptedException 예외를 발생시켜 run() 메소드를
    종료시킨다.
```java
public class InterruptExample {
    public static void main(String[] args) {
        Thread thread = new PrintThread2();
        thread.start();

        try {
            Thread.sleep(1000);             
        } catch (InterruptedException e) {}
        thread.interrupt();     //스레드를 종료시키기 위해 InterruptedException을 발생시킨다.
    }
}
```
```java
public class PrintThread2 extends Thread {
    @Override
    public void run() {
        try {
            while(true) {
                System.out.println("실행 중");
                Thread.sleep(1);    //InterruptedException 발생
            }
        } catch (InterruptedException e) {}
        System.out.println("자원 정리");
        System.out.println("실행 종료");
    }
}
```
- 일시 정지를 만들지 않고도 interrupt() 호출 여부를 알 수 있는 방법이 있다.
    - interrupted() -> 정적 메소드로 현재 스레드가 interrupted 되었는지 확인
    - isInterrupted() -> 인스턴스 메소드로 현재 스레드가 interrupted 되었는지 확인
-     boolean status = Thread.interrupted();
      boolean status = objThread.isInterrupted();
```java
public class PrintThread2 extends Thread {
    @Override
    public void run() {
        try {
            while(true) {
                System.out.println("실행 중");
                if(Thread.interrupted()) break;
            }
        } catch (InterruptedException e) {}
        System.out.println("자원 정리");
        System.out.println("실행 종료");
    }
}
```
## 데몬 스레드
> 보조적인 역할을 수행하는 스레드 (주 스레드가 종료되면 데몬 스레드는 자동 종료)
 주 스레드가 종료되면 데몬 스레드의 존재 의미가 없어진다.

- setDaemon(true) : 스레드를 데몬 스레드로 만들어 준다.

## 스레드 그룹
> 관련된 스레드를 묶어서 관리할 목적. JVM이 실행되면 system 스레드 그룹을 만들고 
JVM 운영에 필요한 스레드들을 생성해서 system 스레드 그룹에 포함시킨다.
- 스레드 그룹 생성
```JAVA
ThreadGroup tg = new  ThreadGroup(String name);
ThreadGroup tg = new ThreadGropu(ThreadGroup parent, String name);
```
- 새로운 스레드 그룹을 생성한 후, 이 그룹에 스레드를 포함시키려면 Thread 객체를
생성할 때 생성자 매개값으로 스레드 그룹을 지정
```java
Thread t = new Thread(ThreadGroup group, Runnable target);
Thread t = new Thread(ThreadGroup group, Runnable target, String name);
Thread t = new Thread(ThreadGroup group, Runnable target, String name, long stackSize);
Thread t = new Thread(ThreadGroup group, String name);
```

- ThreadGroup 이 가지고 있는 주요 메소드들

|메소드||설명|
|---|---|---|
|int|activeCount()|현재 그룹 및 하위 그룹에서 활동 중인 모든 스레드의 수를 리턴|
|int|activeGroupCount()|현재 그룹에서 활동 중인 모든 하위 그룹의 수를 리턴|
|void|checkAccess()|현재 스레드가 스레드 그룹을 변경할 권한이 있는지 체크. 권한이 없으면 SecurityException|
|void|destroy()|현재 그룹 및 하위 그룹을 모두 삭제한다. 단, 그룹 내에 포함된 모든 스레드들이 종료 상태가 되어야한다.|
|boolean|isDestroyed()|현재 그룹이 삭제되었는지 여부를 리턴|
|int|getMaxPriority()|현재 그룹에 포함된 스레드가 가질 수 있는 최대 우선순위 리턴|
|void|setMaxPriority()|현재 그룹에 포함된 스레드가 가질 수 있는 최대 우선순위 설정|
|String|getName()|현재 그룹의 이름을 리턴|
|ThreadGroup|getParent()|현재 그룹의 부모 그룹을 리턴|
|boolean|parentOf(ThreadGroup g)|현재 그룹이 매개값으로 지정한 스레드 그룹의 부모인지 여부를 리턴|
|boolean|isDaemon()|현재 그룹이 데몬 그룹인지 여부를 리턴|
|void|setDaemeon(boolean daemon)|현재 그룹을 데몬 그룹으로 설정|
|void|list()|현재 그룹에 포함된 스레드와 하위 그룹에 대한 정보를 출력|
|void|interrupt()|현재 그룹에 포함된 모든 스레드들을 interrupt|

## 스레드풀
>병렬 작업 처리가 많아지면 스레드 개수가 증가되고 그에 따른 스레드 생성과 스케줄링으로
인해 CPU가 바빠져 메모리 사용량이 늘어난다. 따라서 애플리케이션의 성능이 저하된다. 스레드의 폭증을 막
으려면 스레드풀을 사용해야 한다. 사용되는 스레드를 제한된 개수만큼 정해 놓고 작업 큐에 들어오는 작업들을 하나씩 스레드가 맡아 처리한다.

## 스레드풀 생성
- **ExecutorService 인터페이스**와 **Executor 클래스**를 이용한다.
- 스레드풀 생성 메소드.
-     ExecutorService executorService = Executors.newCachedThreadPool()
    - 스레드 개수보다 작업 개수가 많으면 새 스레드를 생성시켜 작업을 처리한다.
    - 60초 동안 스레드가 아무 작업을 하지 않으면 추가된 스레드를 종료하고 풀에서 제거한다.
-     ExecutorService executorService = Executors.newFixedThreadPool(
        Runtime.getRuntime().availableProcessors()
      );
    - 작업을 처리하지 않고 놀고 있더라도 스레드 개수가 줄지 않는다.
- **직접 ThreadPoolExecutor 객체를 생성**할 수 있다.
```java
ExecutorService threadPool = new ThreadPoolExecutor(
    3,  //코어 스레드 개수
    100,    //최대 스레드 개수
    120L,   //놀고 있는 시간
    TimeUnit.SECONDS,   //놀고 있는 시간 단위
    new SynchronousQueue<Runnable>()    //작업 큐
);
```

## 스레드풀 종료
- void shutdown()
    - 작업 큐에 대기하고 있는 모든 작업을 처리한 뒤에 스레드풀을 종료
- List<Runnable> shuntdownNow()
    - 현재 작업 처리 중인 스레드를 interrupt해서 작업 중지를 시도하고 스레드풀 종료
    - 리턴값은 미처리된 작업의 목록

## 작업 생성과 처리 요청
> 하나의 작업은 Runnable 또는 Callable 구현 클래스로 표현한다. 작업 처리 완료 후 리턴값이 있느냐 없느냐가 차이점이다.

- 작업 처리 요청
    - ExecutorService의 작업 큐에 Runnable 또는 Callable 객체를 넣는 행위를 말한다.
    아래와 같은 메소드를 호출해서 작업 처리 요청을 보낸다.
    
    |리턴 타입|메소드명|설명|
    |---|---|---|
    |void|execute(Runnable command)|Runnable을 작업 큐에 저장, 작업 처리 결과를 받지 못함|
    |Future<?>|submit(Runnable task)|Runnable 또는 Callable을 작업 큐에 저장, 리턴된 Future를 통해 처리 결과를 얻음|
    |Future<V>|submit(Runnable task, V result)|```|
    |Future<V>|submit(Callable<V> task)|```|
- execute()는 작업 처리 결과를 받지 못하고 submit()은 작업 처리 겨로가를 받을 수 있다.(Future를 리턴)
- execute()는 작업 처리 도중 예외가 발생하면 스레드가 종료, 해당 스레드풀에서 제거
- submit()은 작업 처리 도중 예외가 발생해도 스레드가 종료 않됨, 다음 작업에서 재사용
- 생성 오버헤더를 줄이기 위해 submit()을 사용하는게 좋다.

## 블로킹 방식의 작업 완료 통보
- submit() 메소드는 매개값으로 준 Runnable 또는 Callable 작업을 스레드풀의 작업 큐에 저장하고 Future 객체 리턴
- 작업이 완료될 때까지 기다렸다가 최종 결과를 얻는데 사용(Future를 지연 완료 객체라고 한다.)
- Future의 get() 메소드를 호출하면 스레드가 작업을 완료할 때까지 블로킹 되었다가, 작업 완료시 처리 결과를 리턴
    - 블로킹 방식의 작업 완료 통보 방식

## 리턴값이 없는 작업 완료 통보
- Runnable 객체로 생성하면 된다.
```java
Runnable task = new Runnable() {
    @Override
    public void run() {
        //스레드가 처리할 작업 내용
    }
};
```
- 결과값이 없는 작업 처리 요청은 submit(Runnable task) 메소드를 이용하면 된다.
- 결과값이 없어도 Future 객체를 리턴해서 스레드가 작업 처리를 정상적으로 완료했는지, 예외가 발생했는지 확인한다.
-     Future future = executorService.submit(task);
- 작업 처리가 정상적으로 완료되면 Future의 get()메소드는 null을 리턴
- 작업 처리 도중 interrupt되면 InterruptedException을 발생시키고, 작업 처리 도중 예외가 발생하면 ExecutionException
을 발생시킨다.
```java
try {
    future.get();
} catch(InterruptedException e) {
    //작업 처리 도중 스레드가 interrupt 될 경우 실행할 코드
} catch(ExecutionException e) {
    //작업 처리 도중 예외가 발생된 경우 실행할 코드
}
```
## 리턴값이 있는 작업 완료 통보
- 스레드풀의 스레드가 작업을 완료한 후에 애플리케이션이 처리 결과를 얻어야 된다면 작업 객체를
Callable로 생성해야 한다.
- 제네릭 타입 파라미터 T는 call() 메소드가 리턴하는 타입이 되도록한다.
```java
Callable<T> task = new Callable<T>() {
    @Override
    public T call() throws Exception {
        //스레드가 처리할 작업 내용
        return T;
    }
};
```
- Callable 작업의 처리 요청은 Runnable 작업과 마찬가지로 ExecutorService의 submit() 메소드를 호출한다.
- submit() 메소드는 작업 큐에 Callable 객체를 저장하고 즉시 Future<T>를 리턴한다.
-     Future<T> future = executorService.submit(task)
- 스레드풀의 스레드가 Callable 객체의 call() 메소드를 모두 실행하고 T 타입의 값을 리턴하면, 
Future<T> 의 get() 메소드는 블로킹이 해제되고 T 타입의 값을 리턴한다.

## 작업 처리 결과를 외부 객체에 저장
- 스레드가 작업 처리를 완료하고 외부 Result 객체에 작업 결과를 저장
- 대게 Result 객체를 사용해서 두 개 이상의 스레드 작업을 취합할 목적으로 이용.
```java
Result result = ...;
Runnable task = new Task(result);
Future<Result> future = executorService.submit(task, result);
result = future.get();
```

## 작업 완료 순으로 통보
> 작업 요청 순선대로 작업 처리가 완료되는 것은 아니다. 
CompletionService를 이용해 작업 처리가 완료된 것만 통보받는 방법이 있다.
- poll(), take() 메소드 이용
- 둘다 완료된 작업의 Future를 가져온다
    - poll()는 완료된 작업이 없으면 null 반환
    - take()는 완료된 작업이 없으면 있을 때까지 블로킹
    - poll(long timeout, TimeUnit unit)은 완료된 작업이 없으면 timeout까지 블로킹
- submit() 메소드로 작업 처리 요청을 하고 처리 완료된 작업의 Future를 얻는다.

## 콜백 방식의 작업 완료 통보
- 어플리케이션이 스레드에게 작업 처리를 요청한 후, 스레드가 작업을 완료하면
특정 메소드를 자동 실행하는 기법.
![콜백과 블로킹 방식](https://t1.daumcdn.net/cfile/tistory/222A844E58CBE02C02)
- 작업 처리를 요청한 후 결과를 기다릴 필요 없이 다른 기능을 수행할 수 있다.
    - 작업 처리가 완료되면 자동적으로 콜백 메소드가 실행
- Runnable 구현 클래스를 작성할 때 콜백 기능을 구현한다.
- 콜백 메소드를 직접 정의하거나 CompletionHandler를 이용한다.
```java
CompletionHandler<V, A> callback = new CompletionHandler<V, A>() {
    @Override
    public void completed<V result, A attachment) {
    }
    @Override
    public void failed(Throwable exc, A attachment) {
    }
};
```
```java
Runnable task = new Runnable() {
    @Override
    public void run() {
        try {
            //작업 처리
            V result = ...;
            callback.completed(result, null);
        } catch(Exception e) {
            callback.failed(e, null);
        }
    }
};
```
