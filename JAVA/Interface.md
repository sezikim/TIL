# 인터페이스
>객체의 사용 방법을 정의한 타입
- 개발 코드와 객체가 서로 통신하는 접점 역할
- 개발 코드를 수정하지 않고, 사용하는 객체를 변경할 수 있도록 하기위함

## 인터페이스 선언
- 상수와 메소드만을 구성 멤버로 갖는다.
```java
interface 인터페이스명 {
    //상수
    타입 상수명 = 값;
    //추상 메소드
    타입 메소드명(매개변수);
    //디폴트 메소드
    default 타입 메소드명(매개변수) { }
    //정적 메소드
    static 타입 메소드명(매개변수) { }
}
```
- 상수 필드
    >인터페이스는 객체 사용설명서 이므로 런타임시 데이터를 저장할 수 없다.
    - 상수 필드를 제외한 필드는 선언할 수 없다.
    - 상수는 인터페이스에 고정된 값이다.
    - 상수 선언 시에, 반드시 초기값을 대입해야 한다.
    - 인터페이스에 선언된 상수 필드는 모두 public static final의 특성을 갖는다.

- 추상 메소드
    - 객체가 가지고 있는 메소드를 설명한 것.
    - 매개값과 리턴타입, 메소드명만 있고, 실행부는 구현 객체가 가지고 있다.
    - 인터페이스에 선언된 추상 메소드는 모두 public abstract의 특성을 갖는다.

- 디폴트 메소드
    - 기존 인터페이스를 확장해서 새로운 기능을 추가하기 위해서 자바8로 도입.
    - 구현 객체가 가지고 있는 인스턴스 메소드라고 생각해야 한다.
    - 클래스의 인스턴스 메소드와 형태가 동일한데, default 키워드가 리턴 타입 앞에 붙는다.

- 정적 메소드
    - 객체가 없어도 인터페이스만으로 호출이 가능하다.
    - 클래스의 정적 메소드와 형태가 동일하다.

## 인터페이스 구현
## 구현 클래스
- 클래서 선언부에 implements 키워드를 추가하고 인터페이스명을 명시
-     public class 구현클래스명 implements 인터페이스명 {
        //인터페이스에 선언된 추상 메소드의 실체 메소드 선언
      }
-  인터페이스의 모든 메소드는 기본적으로 public 접근 제한을 갖기 때문에,
    public보다 더 낮은 접근 제한으로 작성할 수 없다.
- 인터페이스에 선언된 추상 메소드에 대응하는 실체 메소드를 구현 클래스가,
    작성하지 않으면 자동적으로 추상 클래스가 된다. - > abstract 키워드를 추가해야한다
- 인터페이스로 구현 객체를 사용하는법
    ```java
    public class RemoteControlExample {
        public static void main(String[] args) {
            RemoteControl rc; // 인터페이스
            rc = new Television();  // 인터페이스를 구현한 Television
            rc = new Audio();   // 인터페이스를 구현한 Audio 
        }
    }
    ```
## 익명 구현 객체
>일회성의 구현 객체를 만들기 위해 소스파일을 만들고 클래스를 선언하는 것은 비효율적이다.
- 소스 파일을 만들지 않고 구현 객체를 만드는 방법.
- UI 프로그래밍 이벤트 처리, 임시 작업 스레드를 만들 때 많이 사용된다.
```JAVA
public class RemoteControlExample {
    public static void main(String[] args) {
        RemoteControl rc = new RemoteControl() {
            public void turnOn() { }
            public void turnOff() { }
            public void setVolume(int volume) { }
        };
    }
}
```
- 추가적으로 익명 객체 안에서만 사용할 필드와 메소드를 선언할 수 있다.
- RemoteControllerExample.java를 컴파일하면 RemoteControlExample$1.class 파일이 만들어진다.

## 다중 인터페이스 구현 클래스
```java
public class 구현클래스명 implements 인터페이스A, 인터페이스B {
    //인터페이스 A에 선언된 추상 메소드의 실체 메소드 선언
    //인터페이스 B에 선언된 추상 메소드의 실체 메소드 선언
}
```
- 위와 같이 구현 클래스는, 모든 인터페이스 추상메소드의 실체 메소드를 작성해야 한다.
- 하나라도 없으면, 추상 클래스로 선언

## 디폴트 메소드, 정적 메소드 사용
- 디폴트 메소드
    - 인터페이스에 선언되지만, 인스턴스 메도스이므로 바로 사용할 수 없다.
    - 구현객체를 생성 후 사용가능
- 정적 메소드
    - 인터페이스로 바로 호출 가능

## 타입 변환과 다형성
>인터페이스를 통해서 다형성을 구현하는 경우가 더 많다.
- 인터페이스를 사용해서 메소드를 호출하도록 코딩을 했다면, 구현 객체를 손쉽고
빠르게 교체할 수 있다.
- 인터페이스 타입으로 매개 변수를 선언하면 메소드 호출 시 여러 구현 객체를 줄 수 있다.
-     public void useRemoteControl( RemoteControl rc ) { }
      Television    Audio 등 RemoteControl을 구현한 객체를 매개값으로 선택적으로 줄 수 있다.
- 아래 코드를 통해서 사용 예를 봅시다.
```java
public interface Vehicle {
    public void run();
}
```
```java
public class Bus implements Vehicle {
    @Override
    public void run() {
        System.out.println("버스가 달립니다.");
    }

    public void checkFare() {
        System.out.println("승차요금을 체크합니다.");
    }
}
```
```java
public class Taxi implements Vehicle {
    @Override
    public void run() {
        System.out.println("택시가 달립니다.");
    }
}
```
```java
public class VehicleExample {
    public static void main(String[] args) {
        Vehicle vehicle = new Bus();

        vehicle.run();
        //vehicle.checkFare();

        Bus bus = (Bus) vehicle;

        bus.run();
        bus.checkFare();
    }
}
```
## 인터페이스 상속
>인터페이스도 다른 인터페이스를 상속할 수 있다.
- 인터페이스는 클래스와 달리 다중 상속을 허용한다.
-     public interface 하위인터페이스 extends 상위인터페이스1, 상위인터페이스2 { }
- 구현 객체는 하위 인터페이스, 상위 인터페이스의 모든 추상 메소드의 실체 메소드를 가져야 한다.
- 하위 인터페이스, 상위 인터페이스 타입으로 변환이 가능

## 디폴트 메소드와 인터페이스 확장
- 기존 인터페이스를 확장해서 새로운 기능을 추가하기 위해 디폴트 메소드를 사용
- 이전에 개발한 구현 클래스를 그대로 사용할 수 있고, 새롭게 개발하는 클래스는 디폴트 메소드를 활용

