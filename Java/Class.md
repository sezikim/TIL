# 클래스
>객체의 **설계도**
- 클래스로부터 만들어진 객체를 해당 클래스의 **인스턴스**라 한다.
- 클래스로부터 객체를 생성하는 것을 **인스턴스화**라 한다.
- 다음과 같이 선언을 한다.
```JAVA
public class 클래스명 {
    
}
```
- 두 개 이상의 클래스 선언도 가능하다.
    - 바이트 코드 파일은 클래스를 선언한 갯수만큼 생긴다.
    - 파일 이름과 동일한 이름의 클래스 에만 public 접근 제한자를 붙일 수 있다.
- 클래스 객체는 다음과 같이 생성한다.
```JAVA
Class var;
var = new Class();
//var 은 Class 객체를 참조하고 있다.
Class var2 = new Class();
//var2 는 Class 객체를 참조하고 있다.
```

## 클래스의 구성 멤버
- 클래스에는 객체가 가져야 할 구성 멤버가 선언된다.
- 필드, 생성자, 메소드가 있다.
    1. 필드
        - 객체의 고유 데이터, 부품 객체, 상태 정보를 저장
        - 생성자와 메소드 전체에서 사용, 객체가 소멸되지 않는 한 객체와 함께 존재
        ```JAVA
        public class Car {
            //필드
            String company = "현대자동차";
            String model = "그랜저";
            String color = "검정";
            int maxSpeed = 350;
            int speed;
        }
        ```
        ```JAVA
        public class CarExample {
            public static void main(String args[]) {
                Car myCar = new Car();
                
                myCar.speed = 60;
                
                System.out.println("최고 속도 : " + myCar.maxSpeed);
                System.out.println("현재 속도 : " + myCar.speed);
            }
        }
        ```
    2. 생성자
        - 객체 생성 시 초기화 담당
        - 필드를 초기화 하거나 메소드를 호출해서 객체를 사용할 준비
        - 클래스 이름으로 되어있고 리턴타입이 없다.
        - 클래스 내부에 생성자 선언을 생략하면, 컴파일러는 기본 생성자를 바이트 코드에 자동 추가시킨다.
        ```JAVA
        public class Korean {
            //필드
            String nation = "대한민국";
            String name;
            String ssn;
        
            //생성자
            public Korean(String name, String ssn) {
                this.name = name;
                this.ssn = ssn;
            }
            
        }
        ```
        ```JAVA
        public class KoreanExample {
            public static void main(String args[]) {
                Korean k1 = new Korean("박자바", "011225-1234567");
                System.out.println("k1.name : " + k1.name);
                System.out.println("k1.ssn : " + k1.ssn);
                
                Korean k2 = new Korean("김자바", "930525-0654321");
                System.out.println("k2.name : " + k2.name);
                System.out.println("k2.ssn : " + k2.ssn);
            }
        }
        ```
        - 생성자 오버로딩
            - 다양한 방법으로 객체를 생성할 수 있도록 한다.
            - 매개 변수를 달리하는 생성자를 여러개 선언.
            - 매개 변수의 타입과 개수, 선언된 순서가 같은경우 매개 변수 이름만 바꾸는 것은 생성자 오버로딩이라고 볼 수 없다.
            - 다른 생성자를 호출해서 중복 코드를 개선할 수 있다
            ```JAVA
            public class Car {
                //필드
                String company = "현대자동차";
                String model;
                String color;
                int maxSpeed;
                
                //생성자
                Car(){ }
                Car(String model) {
                    this.model = model;
                    this.color = "은색";
                    this.maxSpeed = 250;
                }
                Car(String model, String color) {
                    this.model = model;
                    this.color = color;
                    this.maxSpeed = 250;
                }
                Car(String model, String color, int maxSpeed) {
                    this.model = model;
                    this.color = color;
                    this.maxSpeed = maxSpeed;
                }
            }
            ```
            ```JAVA
            public class Car {
                //필드
                String company = "현대자동차";
                String model;
                String color;
                int maxSpeed;
                
                //생성자
                Car() {
                    
                }
                Car(String model) {
                    this(model, "은색", 250);
                }
                Car(String model, String color) {
                    this(model, color, 250);
                }
                Car(String model, String color, int maxSpeed) {
                    this.model = model;
                    this.color = color;
                    this.maxSpeed = maxSpeed;
                }
            }
            ```
            
    3. 메소드
        - 객체의 동작에 해당한다.
        - 객체 간의 데이터 전달의 수단.
        - 외부로 부터 매개값을 받을 수 있으며, 실행 후 어떤 값을 리턴할 수도 있다.
        
        ## 리턴타입 메소드이름 (매개변수 선언) {   실행코드    }
        리턴타입, 메소드이름, 매개변수를 **메소드 선언부** 혹은 **메소드 시그니처**라 한다.
        - 메소드 이름은 관례적으로 소문자로 작성한다.
        - 매개 변수의 수를 모를 경우, 배열로 전달하거나, ...를 사용한다
        ```JAVA
        int sum2(int... values) { }
        ```
        ```JAVA
        int result = sum2(1, 2, 3, 4, 5);
        int result2 = sum2(new int[] {1, 2, 3, 4, 5});
        ```
        - return문 이후에 실행문이 오면 "Unreachable code"라는 컴파일 오류가 발생.
        - 메소드를 호출할 때, 객체 내부에서는 다음과 같이 호출하면 된다.
        ```java
        method1(type param);
        ```
        - 객체 외부에서는 메소드를 갖고있는 객체를 생성하고, 도트 연산자를 사용해서 호출한다.
        ```java
        class var = new class();
        var.method2();
        ```
        ## 메소드 오버로딩
        - 클래스 내에 같은 이름의 메소드를 여러 개 선언하는 것을 메소드 오버로딩 이라고 한다.
        - 매개 변수의 타입, 개수, 순서 중 하나가 달라야 한다.
        ```java
        int plus(int x, int y) {
            int result = x + y;
            return result;
        }
        double plus(double x, double y) {
            double result = x + y;
            return result;
        }
        ```
        
