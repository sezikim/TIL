# 람다식
> 수학자 알론소 처치가 발표 그의 제자인 존 매카시가 프로그래밍 언어에 도입 객체 지향 언어보다는
함수 지향 언어에 가깝다. 자바 코드가 매우 간결해지고, 컬렉션의 요소를 필터링하거나 매핑해서
원하는 결과를 쉽게 집계할 수 있기 때문이다.

-     람다식 -> 매개 변수를 가진 코드 블록 -> 익명 구현 객체
```java
Runnable runnnable = new Runnable() {
    public void run() { ... }
};
```
- 위의 익명 구현 객체를 람다식으로 표현하면 다음과 같다.
-     Runnable runnable = () -> {...};
> 마치 함수 정의 형태를 띠고 있지만 런타임 시에 인터페이스의 익명 구현 객체로 생성됨.

## 람다식 기본 문법
-     (타입 매개변수, ...) -> { 실행문; ... }
- **매개변수**를 이용해서 **중괄호를 실행**한다는 뜻
```java
(int a) -> { System.out.println(a); }
(a) -> { System.out.println(a); }
a -> System.out.println(a)
( ) -> { 실행문; ... }
(x, y) -> { return x + y; };
(x, y) -> x + y
```

## 타겟 타입과 함수적 인터페이스
>람다식은 매개 변수를 가진 코드 블록이기 때문에 마치 자바의 메소드를 선언하는 것처럼 보여진다.
메소드는 단독으로 선언될 수 없고 항상 클래스의 구성 멤버로 선언되기 때문에 람다식은 이 메소드를 
가지고 있는 객체를 생성해 낸다.
-     인터페이스 변수 = 람다식;
- 람다식은 **익명 구현 클래스를 생성하고 객체화**한다. **대입될 인터페이스를 람다식의 타겟 타입**이라고 한다.
- 람다식은 하나의 메소드를 정의하기 때문에 **하나의 추상 메소드가 선언된 인터페이스만이 람다식의 타겟 타입**이 될
수 있는데, 이러한 인터페이스를 **함수적 인터페이스**라 한다.
(@FunctionalInterface 어노테이션을 붙이면 추상 메소드가 하나가 넘는지 확인)
```java
@FunctionalInterface
public interface MyFunctionalInterface {
    public void method();
    public void otherMethod(); // 컴파일 오류 발생
}
```
## 람다식은 추상 메소드의 선언 형태에 따라서 작성 방법이 달라진다.
- 매개 변수와 리턴값이 없는 람다식
```java
@FunctionalInterface
public interface MyFunctionalInterface {
    public void method();
}
```
```java
MyFunctionalInterface fi = () -> { ... }
```
- 매개 변수가 있는 람다식
```java
@FunctionalInterface
public interface MyFunctionalInterface {
    public void method(int x);
}
```
```java
MyFunctionalInterface fi = (x) -> { ... } 또는 x -> { ... }
```
- 리턴값이 있는 람다식
```java
@FunctionalInterface
public interface MyFunctionalInterface {
    public int method(int x, int y);
}
```
```java
MyFunctionalInterface fi = (x, y) -> { ...; return 값; }
```

## 클래스 멤버와 로컬 변수 사용
> 람다식의 실행 블록에는 클래스의 멤버 및 로컬 변수를 사용할 수 있다.
 클래스의 멤버는 제약 사항 없이 사용 가능, 로컬 변수는 제약 사항이 따른다.
- 클래스 멤버 사용
    - 람다식에서 this는 람다식을 실행한 객체의 참조.
```java
public interface MyFunctionalInterface {
    public void method();
}
```
```java
public class UsingThis {
    public int outterField = 10;
    
    class Inner {
        int innerField = 20;
        
        void method() {
            //람다식
            MyFunctionalInterface fi = ()-> {
                System.out.println("outterFiled: " + outterFiled);
                System.out.println("outterField: " + UsingThis.this.outterField + "\n");
                //둘다 10을 출력한다.
                System.out.println("innerField: " + innerField);
                System.out.println("innerFiled: " + this.innerField + "\n");
                //둘다 20을 출력한다.
            };
            fi.method();
        }
    }
}
```
```java
public class UsingThisExample {
    public static void main(String... args) {
        UsingThis usingThis = new UsingThis();
        UsingThis.Inner inner = usingThis.new Inner();
        inner.method();
    }
}
```
- 로컬 변수 사용
    - 람다식은 메소드 내부에서 주로 작성되기 때문에 로컬 익명 구현 객체를 생성시킨다.
    - 메소드의 매개 변수 또는 로컬 변수를 사용하면 이 두변수는 final 특성을 가져야 한다.
```java
public interface MyFunctionalInterface {
    public void method(); 
}
```
```java
public class UsingLocalVariable {
    void method(int arg) {
        int localVar = 40;
        
        //arg = 31;     //final 특성 때문에 수정 불가
        //localVar = 41;    //final 특성 때문에 수정 불가
    
        //람다식
        MyFunctionalInterface fi = () -> {
            //로컬 변수 읽기
            System.out.println("arg: " + arg);
            System.out.println("localVar: " + localVar + "\n");
        };
        fi.method();
    }
}
```
```java
pulic class UsingLocalVariableExample {
    public static void main(String... args) {
        UsingLocalVariable ulv = new UsingLocalVariable();
        ulv.method(20);
    }
}
```
## 표준 API의 함수적 인터페이스
> 표준 API에서 **한 개의 추상 메소드를 가지는 인터페이스들**은 모두 람다식을 이용해
익명 구현 객체로 표현 가능하다.
```JAVA
public class RunnableExample {
    public static void main(String[] args) {
        Runnable runnable = () -> {
            for(int i=0; i<10; i++) {
                System.out.println(i);
            }
        };
        Thread thread = new Thread(runnable);
        /*
        Thread thread = new Thread(() -> {
           for(int i=0; i<10; i++) {
               System.out.println(i);
           }
        });
        */
        thread.start();
    }
}
```
- 자바 8부터는 빈번하게 사용되는 함수적 인터페이스를 표준 API 패키지로 제공한다.
- 메소드 또는 생성자의 매개 타입으로 람다식을 대입할 수 있도록 하기 위해서 쓰인다.

|종류|추상 메소드 특징||추상 메소드 종류|
|---|---|---|---|
|Consumer|-매가값은 있고, 리턴값은 없음|매개값 --> **`consumer`**|accept()|
|Supplier|-매개값은 없고, 리턴값은 있음|**`Supplier`** --> 리턴값|getX()|
|Function|-매가값도 있고, 리턴값도 있음 (주로 매개값을 리턴값으로 매핑)|매개값 --> **`Function`** --> 리턴값|applyX()|
|Operator|-매가값도 있고, 리턴값도 있음 (주로 매가값을 연산하고 결과를 리턴)|매개값 --> **`Operator`** --> 리턴값|applyX()|
|Predicate|-매가값은 있고, 리턴 타입은 boolean (매개값을 조사해서 true/false를 리턴)|매개값 --> **`Predicate`** --> boolean|testX()|
