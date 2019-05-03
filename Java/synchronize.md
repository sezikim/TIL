## Blocking / Non Blocking
- 블로킹 방식은 A라는 함수를 호출했을 때, A함수가 진행되는 동안 프로세스(또는 스레드)는 자신의 작업을 중단한채 대기하다 즉석에서 완료 통지를 받는다.
- 넌 블로킹 방식은 A함수가 진행되는 동안 프로세스(또는 스레드)의 작업을 중단시키지 않고 작업의 완료를 나중에 통지 받는다.

## 동기식 / 비동기식
- 동기식
    - 작업들이 순서대로 작업이 시작되면, 순서대로 끝난다
        - 작업의 순서가 보장된다.
- 비동기식
    - 작업의 순서가 보장되지 않는다.
    - 주로 Callback 함수를 통해 결과물을 가져온다.
```java
package io.thethelab;

import java.util.concurrent.*;
// 비동기 블로킹
public class Blocking extends Thread {
    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(
                Runtime.getRuntime().availableProcessors()
        );

        CompletionService<Integer> completionService =
                new ExecutorCompletionService<>(executorService);

        System.out.println("[작업 처리 요청]");
        int i;
        for (i = 0; i < 3; ++i) {
            completionService.submit(new Callable<Integer>() {
                @Override
                public Integer call() throws Exception {
                    int sum = 0;
                    int i;
                    for (i = 1; i <= 10; ++i) {
                        sum += i;
                    }
                    return sum;
                }
            });
        }
        System.out.println("[처리 완료된 작업 확인]");
        executorService.submit(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    try {
                        //완료된 작업이 있을 때 까지 블로킹
                        //완료된 작업이 있으면 리턴
                        Future<Integer> future = completionService.take();
                        int value = future.get();
                        System.out.println("[처리 결과]" + value);
                    } catch (Exception e) {
                        break;
                    }
                }
            }
        });

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
        }
        executorService.shutdownNow();
    }
}
```
```java
package io.thethelab;

import java.nio.channels.CompletionHandler;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// 비동기 넌 블로킹
public class NonBlocking {
    private ExecutorService executorService;

    public NonBlocking() {
        executorService = Executors.newFixedThreadPool(
               Runtime.getRuntime().availableProcessors()
        );
    }
    private CompletionHandler<Integer, Void> callback =
            new CompletionHandler<Integer, Void>() {
                @Override
                public void completed(Integer result, Void attachment) {
                    System.out.println("completed() 실행: " + result);
                }

                @Override
                public void failed(Throwable exc, Void attachment) {
                    System.out.println("failed() 실행: " + exc.toString());
                }
            };
    public void doWork(final String x, final String y) {
        // 작업 완료시, callback 메소드를 호출
        Runnable task = new Runnable() {
            @Override
            public void run() {
                try {
                    int intX = Integer.parseInt(x);
                    int intY = Integer.parseInt(y);
                    int result = intX + intY;
                    callback.completed(result, null);
                } catch (NumberFormatException e) {
                    callback.failed(e, null);
                }
            }
        };
        executorService.submit(task);
    }

    public void finish() {
        executorService.shutdown();
    }

    public static void main(String[] args) {
        NonBlocking example = new NonBlocking();
        example.doWork("3", "3");
        example.doWork("3","삼");
        example.finish();
    }
}
```

