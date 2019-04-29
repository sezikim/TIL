# 공유중인 가변데이터는 동기화해 사용하라
>synchronized 키워드는 해당 메소드나 블록을 한번에 한 스레드씩 수행하도록 보장한다.

- 동기화는 배타적 실행뿐 아니라 스레드 사이의 안정적인 통신에 꼭 필요하다.
    - 스레드가 필드를 읽을 때 **항상 수정이 완전히 반영된 값을 얻는다고 보장**하지만,
      한 스레드가 **저장한 값이 다른 스레드에게 보이는가는 보장하지 않는다.**
    ```java
    import java.util.concurrent.TimeUnit;

    public class StopThread {
        private static boolean stopRequested;
    
        public static void main(String[] args) throws InterruptedException{
            Thread backgroundThread = new Thread(() -> {
               int i = 0;
               while(!stopRequested)
                   i++;
            });
            backgroundThread.start();
    
            TimeUnit.SECONDS.sleep(1);
            stopRequested = true;
            // 메인 스레드가 변경한 stopRequested 값이 다른 스레드에 보이지 않는다.
            // 프로그램이 루프에 빠짐.
        }
    }
    ```
    - 동기화를 통해 스레드가 정상 종료하는 코드
    ```java
    import java.util.concurrent.TimeUnit;

    public class StopThread {
        private static boolean stopRequested;
        
        private static synchronized void requestStop() {
            stopRequest = true;
        }
        
        private static synchronized boolean stopRequested() {
            return stopRequested;
        }
        // 쓰기와 읽기 모두가 동기화되지 않으면 동작을 보장하지 않는다. 
        public static void main(String[] args) throws InterruptedException{
            Thread backgroundThread = new Thread(() -> {
               int i = 0;
               while(!stopRequested)
                   i++;
            });
            backgroundThread.start();
    
            TimeUnit.SECONDS.sleep(1);
            requestStop();
            // 동기화를 통해서 스레드간 통신을 가능하게 한다.
        }
    }
    ```
    - 스레드간 통신만을 위해 volatile 한정자를 사용한 코드
    ```java
    import java.util.concurrent.TimeUnit;

    public class StopThread {
        private static volatile boolean stopRequested;
    
        public static void main(String[] args) throws InterruptedException{
            Thread backgroundThread = new Thread(() -> {
               int i = 0;
               while(!stopRequested)
                   i++;
            });
            backgroundThread.start();
    
            TimeUnit.SECONDS.sleep(1);
            stopRequested = true;
        }
    }
    ```
    - 올바로 사용하기가 까다롭다
## 결론
- 여러 스레드가 가변 데이터를 공유하면, 그 데이터를 읽고 쓰는 동작은 반드시 동기화 해야 한다.
