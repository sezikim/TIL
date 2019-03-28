## 인스턴스 멤버
- 객체를 생성한 후 사용할 수 있는 필드와 메소드
- **인스턴스 필드**, **인스턴스 메소드**라 부른다.
- 객체 없이는 사용할 수 없다.
```java
public class Car {
    //필드
    int gas;
    int speed
    
    //메소드
    void setSpeed(int speed) {
        this.speed = speed;
    }
}
```
- 인스턴스 필드 gas, speed는 생성한 객체마다 따로 존재하고, **인스턴스 메소드 setSpeed()는 메소드 영역에 저장, 공유**
- 객체 내부에서 인스턴스 멤버에 접근하기 위해 this를 사용할 수 있다.

## 정적 멤버 static
> 정적은 '고정된'이란 의미를 가지고 있다.
- 정적 멤버는 클래스에 고정된 멤버 ( 메소드 영역 )
- 객체를 생성하지 않고 사용할 수 있는 필드와 메소드
- **클래스 멤버**라고도 한다.
```java
public class 클래스 {
    //정적 필드
    static 타입 필드 [= 초기값];
    
    //정적 메소드
    static 리턴 타입 메소드 ( 매개변수선언 ) {   }
}
```
- 객체마다 가지고 있을 필요가 없는 **공용적인 데이터**를 정적 필드로 선언
- 정적 필드는 선언과 동시에 초기화 하는것이 보통이다.
- 인스턴스 필드를 이용하지 않는 메소드를 정적 메소드로 선언
```java
public class Calculator {
    //인스턴스 필드
    String color;
    //인스턴스 메소드
    void setColor(String color) {
        this.color = color;
    }
    //정적 메소드
    static int plus(int x, int y) { return x + y; }
    static int minus(int x, int y) { return x - y; }
}
```
- 정적 메소드와 블록 선언시, 인스턴스 필드, 메소드 , this를 사용하지 못한다.
- 객체를 먼저 생성 후 참조변수로 접근

## 싱글톤
- 전체 프로그램에서 단 하나의 객체만 만들도록 보장
- 외부에서 new 연산자로 생성자를 호출할 수 없도록 막아야 한다.
- 생성자 앞에 private 접근 제한자를 붙여준다.
```java
public class 클래스 {
    //정적 필드
    private static 클래스 singleton = new 클래스();
    
    //생성자
    private 클래스() {}
    
    //정적 메소드
    static 클래스 getInstance() {
        return singleton;
    }
}
```
- 외부에서 객체를 얻는 유일한 방법은 getInstance() 메소드를 호출하는 것.

## final
>최종적이란 뜻을 가지고 있다.
- 초기값이 저자되면 프로그램 실행 도중에 수정할 수 없다.
-     final 타입 필드 [=초기값];
- 필드 선언시에 초기화 or 생성자에서 초기화

## 상수(static final)
- 불변의 값.
- 객체마다 저장할 필요가 없는 공용성, 여러 가지 값으로 초기화 될 수 없다. (final과 다른점)
-     static final 타입 상수 [= 초기값];
- 필드 선언시에 초기화 or 정적 블록에서 초기화
- 모두 대문자로 작성하는 것이 관례이다.

