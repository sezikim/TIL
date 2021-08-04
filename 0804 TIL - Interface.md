## 인터페이스

> '기능명세'

- 선언된 메소드의 구현을 강제한다.
- 다형성을 제공한다.

```java
interface HealthCare {
    void goFitness();
}

interface MentalCare {
    void coding();
}

public class Person implements HealthCare, MentalCare {
    private int health;
    private int mental;

    Person() {
        health = 0;
        mental = 0;
    }

    public static void main(String[] args) {
        HealthCare h = new Person();
        h.goFitness(); // --> 호출 O
        h.coding(); // --> 호출 X

        MentalCare m = new Person();
        m.goFitness(); // --> 호출 X
        m.coding();  // --> 호출 O
    }

    @Override
    public void goFitness() {
        this.health++;
    }
 
    @Override
    public void coding() {
        this.mental++;
    }
    
}
```

- 결합도를 낮춘다. (Dependency Injection을 통한 Dependency Inversion)
  - UserService, NaverLogin, KakaoLogin 모두 Login 인터페이스를 구현한다.
  - UserServcie 객체를 생성할 때, 의존성을 주입받아, 의존성을 낮출 수 있다.
    - KakaoLogin 혹은 NaverLogin의 선택을 UserService 객체를 생성하며 정할 수 있다.

```java
interface Login {
    void login();
}

enum LoginType {
    NaverLogin, KakaoLogin
}

class NaverLogin implements Login{
    @Override
    public void login() {
        System.out.println("네이버 로그인");
    }
}

class KakaoLogin implements Login{
    @Override
    public void login() {
        System.out.println("카카오 로그인");
    }
}

class UserService implements Login {
    // 로그인에 의존한다.
    private Login login;

    public UserService(LoginType loginType) {	// 의존성 주입하는 부분
        if (loginType == LoginType.KakaoLogin) this.login = new KakaoLogin();
        else this.login = new NaverLogin();
    }

    @Override
    public void login() {
        login.login();
    }

}

public class Main {
    public static void main(String[] args) {
        UserService userService = new UserService(LoginType.KakaoLogin);
        userService.login();
    }
}
```

### Default Method

- Java 8
  - default 메소드
    - interface도 구현된 메소드를 갖는다.
    - Adapter 역할
      - **디자인 패턴으로 얻는 이점들을 모던한 언어에서 문법으로 제공하는 경우**
  - **인터페이스 추가만으로 기능을 확장**할 수 있다.
  - static 메소드를 제공할 수 있다.

```java
interface Ability {
    static void sayHello() {
        System.out.println("Hello World");
    }
}

interface Flayble {
    default void fly() {
        System.out.println("FLY");
    }
}

interface Swimmable {
    default void swim() {
        System.out.println("SWIM");
    }
}

interface Walkable {
    default void walk() {
        System.out.println("WALK");
    }
}

class Duck implements Swimmable, Walkable {}

class Swan implements Flayble, Walkable {}

public class Main {
    public static void main(String[] args) {
        Swan s = new Swan();
        Duck d = new Duck();

        d.swim();
        d.walk();
        s.fly();
        s.walk();

        Ability.sayHello();
    }
}
```

### Functional Interface

- 추상메소드가 하나만 존재하는 인터페이스
  - default 메소드 혹은 static 메소드는 있어도 상관없다.
- @FunctionalInterface (생략가능)
  - FunctionalInterfaced의 추상메소드는 '함수'라고 부른다.
- 익명클래스를 사용해서 인터페이스의 인스턴스를 생성하고 구현을 바로 정의할 수 있다.

```java
@FunctionalInterface
interface MySupply {
    String supply();
}

@FunctionalInterface
interface MyRunnable {
    void run();
}

interface MyMap {
    void map();
    default void sayHello() {
        System.out.println("Hello");
    }

    static void sayBye() {
        System.out.println("Bye");
    }
}

public class Main {
    public static void main(String[] args) {
      
        new MySupply() {
            @Override
            public String supply() {
                return "Hello World";
            }
        }.supply();

        MyRunnable r = new MyRunnable() {
            @Override
            public void run() {
                MySupply mySupply = new MySupply() {
                    @Override
                    public String supply() {
                        return "Hello Hello";
                    }
                };
                System.out.println(mySupply.supply());
            }
        };

        r.run();
    }
}

```



### Lambda

- 익명 메소드를 사용해서 간결한 인터페이스 인스턴스 생성 방법
- FunctionalInterface에서만 가능. (메소드가 하나로 지정되어야 하기 때문에)
- 간결하게 표현이 가능하다.

```java
//위의 main 함수의 코드를 람다 표현식으로 다음과 같이 표현할 수 있다.
	public static void main(String[] args) {
    
        ((MySupply) () -> "Hello World").supply();

        MyRunnable r = () -> {
            MySupply mySupply = () -> "Hello Hello";
            System.out.println(mySupply.supply());
        };

        r.run();
    }
```



### 메소드 레퍼런스

- 람다 표현식에서 입력되는 값을 변경없이 바로 사용하는 경우 적용될 메소드의 레퍼런스를 지정해 주는 표현 방식
  - 개발자의 개입을 차단함으로서 안정성을 얻을 수 있다.
  - 유지보수 면에서 효율적인 의사소통이 가능하다.

```java
(i)->System.out.println(i);
System.out::println
```



