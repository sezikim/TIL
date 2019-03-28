>컴퓨터의 하드웨어의 오동작 또는 고장으로 인해 응용프로그램의 실행 오류가 발생하는것을
자바에서는 에러(error)라고 한다. 에러는 JVM 실행에 문제가 생겼다는 것이므로 JVM 위에서 
실행되는 프로그램을 아무리 견고하게 만들어도 결국 실행 불능이 된다.

# 예외(Exception)
>사용자의 잘못된 조작 또는 개발자의 잘못된 코딩으로 발생하는 프로그램 오류
 예외처리(Exception Handling)를 통해 프로그램을 종료하지 않고 정상 실행 상태가 유지되도록 한다.
- 자바는 예외를 클래스로 관리한다.
- 일반 예외(Exception)
    - 컴파일러 체크 예외
    - Exception을 상속받지만 Runtime Exception을 상속받지 않는 클래스들
- 실행 예외(Runtime Exception)
    - 컴파일 과정에서 예외처리 코드를 검사하지 않는 예외
    - RuntimeException을 상속했는지 여부를 보고 실행 예외를 판단

    
## 자주 발생되는 실행 예외
1. NullPointerException
    - 객체 참조가 없는 상태
    - null값을 갖는 참조 변수로 객체 접근 연산자인 도트를 사용했을 때 발생
2. ArrayIndexOutOfBoundsException
    - 배열에서 인덱스 범위를 초과하여 사용할 때 발생
3. NumberFormatException
    - Wrapper 클래스의 parse 메소드를 이용할 때, 숫자로 변환될 수 없는 문자가 포함되어 있을 때 발생
4. ClassCastException
    - 상위,하위 클래스 간, 인터페이스, 구현 클래스 간의 관계가 아닌데 다른 클래스 타입으로
    변환하려 할때 발생
    - instanceof 연산자로 타입 변환전에 변환이 가능한지 확인하는 것이 좋다.

## 예외 처리 코드
>프로그램에서 예외가 발생했을 경우 갑작스러운 종료를 막고, 정상 실행을 유지할 수 있도록 
처리하는 코드. 자바 컴파일러는 일반 예외가 발생할 가능성이 있는 코드를 발견하면 컴파일
오류를 발생시켜, 예외 처리 코드를 작성하도록 요구한다.

- try-catch-finally
![try-catch-finally](https://cdn2.howtodoinjava.com/wp-content/uploads/2018/11/java-try-catch-finally.jpg)
    - try 블록에는 예외 발생 코드가 위치
    - 예외 발생 없이 정상 실행되면 catch 블록의 코드는 실행되지 않고 finally 블록의 코드를 실행
    - 예외가 발생하면 catch 블록으로 이동하여 예외 처리 코드를 실행. 그다음 finally 블록의 코드를 실행
    - try와 catch 블록에서 return문을 사용하더라도 finally 블록은 항상 실행된다.
    ```java
    public class TryCatchFinallyRuntimeExceptionExample {
        public static void main(String[] args) {
            String data1 = null;
            String data2 = null;
            try {
                data1 = args[0];
                data2 = args[1];
            } catch(ArrayIndexOutOfBoundsException e) {
                System.out.println("실행 매가값의 수가 부족합니다.");
                System.out.println("[실행 방법]");
                System.out.println("java TryCatchFinallyRuntimeExceptionExample num1 num2");
                return;
            }
            
            try {
                int value1 = Integer.parseInt(data1);
                int value2 = Integer.parseInt(data2);
                int result = value1 + value2;
                System.out.println(data1 + "+" + data2 + "=" + result);
            } catch(NumberFormatException e) {
                System.out.println("숫자로 변환할 수 없습니다.");
            } finally {
                System.out.println("다시 실행하세요.");
            }
        }
    }
    ```
- 다중 catch
    - 발생되는 예외별로 예외 처리 코드를 다르게 할 수 있다.
    - 상위 예외 클래스가 하위 클래스보다 아래쪽에 위치해야 한다.
        - catch 블록이 위에서부터 차례대로 검색되기 때문.

- try-with-resources
    - 에외 발생 여부와 상관없이 사용했던 리소스 객체의 close() 메소드를 호출
    - try-catch를 사용할 때보다 코드가 간단해진다.
    ```java
    FileInputStrea fis = null;
    try {
        fis = new FileInputStream("file.txt");
        ...
    } catch(IOException e) {
        ...
    } finally {
        if(fis != null) {
            try {
                fis.close();
            } catch (IOException e) { }
        }
    }
    ```
    ```java
    try(FileInputStream fis = new FileInputStream("file.txt") {
        ...
    } catch(IOException e) {
        ...
    }
    ```
    - try-with-resources를 사용하기 위해서는 리소스 객체가 java.lang.AutoCloseable 인터페이스를
    구현하고 있어야 한다.

## 예외 떠넘기기
- throws 메소드를 호출한 곳으로 에외를 떠넘긴다.
- throws 키워드가 있는 메소드는 반드시 try 블록 내에서 호출되어야 한다.
```java
public void method1() {
    try {
        method2();
    } catch(ClassNotFoundException e) {
        //예외 처리 코드
        System.out.println("클래스가 존재하지 않습니다.");
    }
}

public void method2() throws ClassNotFoundException {
    Class clazz = Class.forName("java.lang.String2");
}
```
- method1()에서도 throws 키워드로 다시 예외를 떠넘길 수 있다.
```java
public void method1() throws ClassNotFoundException {
    method2();
}
```

## 예외 발생시키기
- throw 를 사용해서 예외를 발생시킨다. throws 키워드로 발생시킨 예외를 떠넘긴다.
-     public void method() throws XXXException {
        throw new XXXException("메시지");
      }
      
## 예외 정보 얻기
- getMessage()로 예외 정보를 얻을 수 있다.
- printStackTrace()
