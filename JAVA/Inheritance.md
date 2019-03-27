# 상속
> 부모가 자식에게 물려주는 행위
- 객체 지향 프로그램에서 부모 클래스의 멤버를 자식 클래스
에게 물려줄 수 있다.
- 부모 클래스 - 상위 클래스
자식 클래스 - 하위 클래스
- 부모 클래스의 private 접근 제한을 갖는 필드와 메소드는 상속 대상에서 제외된다.
- 클래스의 수정을 최소화 시킨다. -> 유지 보수 시간을 최소화

## 클래스 상속
> 프로그램에서는 자식이 부모를 선택한다.
```java
class 자식클래스 extends 부모클래스 {   // 자바는 다중 상속을 허용하지 않는다.
    //필드
    //생성자
    //메소드
}
```
- 객체 생성시, 부모 객체가 먼저 생성되고, 자식 객체가 그 다음에 생성된다.
- 자식 객체의 생성자에서 부모 객체의 생성자를 호출한다.
그렇지 않으면 컴파일 오류 발생.

## 메소드 오버라이딩
> 부모 클래스의 어떤 메소드는 자식 클래스가 사용하기에 적합하지 않을 수 있다.
일부 메소드는 자식 클래스에서 수정해서 사용.
- 메소드 오버라이딩 주의점
    - 부모 메소드와 동일한 시그니처( 리턴 타입, 메소드 이름, 매개 변수 리스트 )
    - 접근 제한을 더 강하게 할 수 없다.
    - 새로운 예외를 throw할 수 없다.
- 부모 메소드 호출
    - 자식 클래스에서 부모 클래스의 메소드를 오버라이딩 하면, 오버라이딩 된 자식 메소드만 사용
    부모 메소드를 호출해야 하는 상황이 발생한다면 다음과 같이 사용한다
    -     super.부모메소드();

## final 클래스, final 메소드
>해당 선언이 최종 상태, 결코 수정될 수 없다.
- final 키워드는 클래스, 필드, 메소드 선언 시에 사용할 수 있다.
- 필드 선언 시에 final이 지정되면 초기값 설정 후, 더 이상 값을 변경할 수 없다.
- 클래스를 선언할 때 final 키워드를 붙이면, 상속할 수 없는 클래스
    - String 클래스가 대표적인 final 클래스이다.
- 메소드를 선언할 때 final 키워드를 붙이면, 오버라이딩할 수 없는 메소드

## 타입 변환과 다형성
>같은 타입이지만 실행 결과가 다양한 객체를 이용할 수 있는 성질
- 자바는 부모 클래스로 타입 변환을 허용한다. -> 부모 타입에 자식 객체가 대입될 수 있다.
- 자동 타입 변환(Promotion)
    - 상속 계층에서 상위 타입이면, 자동 타입 변환이 일어난다.
    - 부모 타입으로 자동 타입 변환된 이후에는, 부모 클래스의 필드와 메소드만 접근이 가능하다.
    - 변수는 자식 객체를 참조하지만, 변수로 접근 가능한 멤버는 부모 클래스 멤버이다.
    - 오버라이딩된 메소드는 타입 변환 이후에도 자식 메소드가 호출된다.
![오버라이딩 메소드](http://postfiles6.naver.net/20151228_101/rain483_1451295254815cHQQs_PNG/3.png?type=w1)
```java
public class Parent{
    public void method1() {
        System.out.println("Parent-method1()");
    }
    
    public void method2() {
        System.out.println("Parent-method2()");
    }
}
```
```java
public class Child extends Parent {
    @Override
    public void method2()  {
        System.out.println("Child-method2()");
    }
    
    public void method3() {
        System.out.println("Child-method3()");
    }
}
```
```java
public class ChildExample {
    public sttic void main(String[] args) {
        Child child = new Child();
        
        Parent parent = child;  // 자동 타입 변환
        parent.method1();   
        parent.method2();   // 오버라이딩된 메소드가 호출됨
        //parent.method3();  (호출 불가능)
    }
}
```
위 코드의 실행 결과는 다음과 같다.
-     Parent-mehotd1()
      Child-method2()

## 매개 변수의 다형성
>매개 변수의 타입이 클래스일 경우, 해당 클래스의 객체 뿐만 아니라,
자식 객체까지도 매개값으로 사용할 수 있다.
- 매개값으로 어떤 자식 객체가 제공되느냐에 따라 메소드의 실행 결과는 다양해질 수 있다.

## 강제 타입 변환 (Casting)
>강제 타입 변환은 부모 타입을 자식 타입으로 변환하는 것.
- 자식 타입이 부모 타입으로 자동 변환한 후, 다시 자식 타입으로 변활할 때 사용가능
```java
class Parent {
    String field1;
    void method1() { }
    void method2() { }
}

class Child extends Parent {
    String field2;
    void method3() { }
}

class ChildExample {
    public static void main(String[] args) {
        Parent parent = new Child();
        parent.field1 = "xxx";
        parent.method1();
        parent.method2();
        //parent.filed2 = "yyy";  --> 불가능
        //parent.method3(); --> 불가능
        
        Child child = (Child) parent;
        child.filed2 = "yyy";
        child.method3();
    }
}
```

## 객체 타입 확인 (instanceof)
>객체가 어떤 클래스의 인스턴스인지 확인하려면 instanceof 연산자를 사용할 수 있다.
- 강제 타입 변환이 필요할 경우 매개값이 어떤 객체인지 확인하고 변환
-     public void method(Parent parent) {
        if(parent instanceof Child) {
            Child child = (Child) parent;  
        }
      }
- 확인하지 않고 캐스팅시, ClassCastException이 발생할 수 있다.

## 추상 클래스 
>사전적 의미로 추상은 실체 간에 공통되는 특성을 추출한 것을 말한다.
- 실체 클래스들의 **공통된 필드와 메소드의 이름을 통일할 목적**
- 실체 클래스를 작성할 때 시간을 절약
- **객체를 직접 생성해서 사용할 수 없다.** - > 상속을 통해 자식 클래스만 만들 수 있다.
- 자식 객체가 생성될 때, super()를 호출해야 함으로 생성자는 반드시 있어야 한다.
```java
public abstract class Phone {
    //필드
    public String owner;
    
    //생성자
    public Phone(String owner) {
        this.owner = owner;
    }
    
    //메소드
    public void turnOn() {
        System.out.println("폰 전원을 켭니다");
    }
    publicvoid turnOff() {
        System.out.println("폰 전원을 끕니다.");
    }
}
```
```java
public class SmartPhone extends Phone {
    //생성자
    public SmartPhone(String owner) {
        super(owner);
    }
    
    //메소드
    public void internetSearch() {
        System.out.println("인터넷 검색을 합니다.");
    }
}
```
## 추상 메소드
>추상 클래스에서 메소드의 선언만 통일화하고 내용은  실체 클래스마다 달라야 하는 경우에 사용
- 메소드의 선언부만 있고 메소드 실행 내용인 중괄호가 없는 메소드
- 자식 클래스는 반드시 추상 메소드를 오버라이딩 해야한다.
-     [public | protected] abstact 리턴타입 메소드명(매개변수);

