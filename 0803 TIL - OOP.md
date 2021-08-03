## OOP

> 객체지향 프로그래밍

- 프로그램을 객체로 구성하는 것

  - 프로그램이 점점 커지면서 등장하게 되었다.
  - 어떻게 큰 프로그램을 만들것인가?
    - 해결책 : **프로그램을 작게 나누어서 만들고 합친다**.

- 프로그램의 동작을 객체들에게 나눠서 수행.

  - **객체**는 **한 기능**을 수행
  - 객체간 서로 협력
    - 객체에게 **책임**을 주고, **책임을 다하도록 구성**하는 것.

- 객체생성 예

  ```java
  import java.lang.*;
  
  class Sezi extends Object implements Runnable {
      //필드
      private String name;
    	private int age;
    
  	  //메소드
    	public void code() {
      		System.out.println("매일 같이 코딩하자");
      }
  }
  
  Sezi sezi = new Sezi();
  ```

  

### 객체지향의 특성

1. **캡슐화**

   1. **완성도**가 있다.
      - 기능을 수행하는 단위로서 완전함을 갖는다.
        - **의존성 낮추고 완결성 높이고**
   2. **정보가 은닉**되어 있다.
      - 객체의 정보를 밖으로 전달하거나, 밖에서 객체 내의 정보에 접근하지 못한다.
   3. **객체는 스스로 동작할 수 있는 환경을 갖고 있어야 한다.**
      - 외부에 의존하거나, 외부에서의 직접 변경을 제한해야 한다. 
        - **접근제어자로 제어**
          - private : 해당 객체에서만 접근 가능
          - protected : 상속된 객체에서도 접근 가능
          - (friendly) : 같은 패키지 내에서 접근 가능
          - public : 모두 접근 가능

   ```java
   class Human {
     	private Heart heart;
     	private Blood blood;
     	protected Gene gene;
     
     	Blood donation() {
         	return null;
       }
   }
   
   Human h = new Human();
   h.heart.stop(); // --> 직접 접근을 막기 위해 private 접근제어자 사용
   h.donation(); // 
   
   class Child extends Human {
     	void run() {
         	super.heart; // --> 접근 불가
         	this.blood; // --> 접근 불가
         	this.gene; // --> 접근 가능
       }
   }
   ```

2. **상속**

   - 상위 클래스 - 부모 - super - 추상
   - 하위 클래스 - 자식 - this - 구체
     - Ex) 원자 > 물질 > 생물 > 동물 > 포유류 > 사람 > 남자 > 짱구
   - **주의** : 공통된 기능을 여러 객체에게 전달하는 용도로 사용되는 것이 아니다.

3. **추상화**

   - 추상화된 객체 : 추상체
   - 구체화된 객체 : 구상체
   - 객체간의 관계에서 상위에 있는 것이 항상 하위보다 추상적이어야 한다.

   ```java
   // 의미적 추상체
   class Login {
     	void login(){};
   }
   
   class KakaoLogin extends Login{
     	void login(){};
   }
   ```

   ```java
   // 추상기능을 갖는 객체
   abstract class Login {
     	abstract void login();
   }
   
   class KakaoLogin extends Login {
     	@Override void login() {};
   }
   ```

   ```java
   // 객체 자체가 추상적
   interface Login {
   		void login();
   }
   
   class KakaoLogin implements Login {
     	@Override void login() {};
   }
   ```

4. **다형성**

   - 형(type)을 여러가지로 표현할 수 있다.
   - 인터페이스를 통해서 객체를 받아, 객체에게 기능별로 권할을 달리할 수 있다.
     - **객체를 안전하게 이용하기 위해서**

   ```java
   class KakaoLogin implements Login {
     	void kakao() {}
   		@Override void login() {}
   }
   
   interface Portal {
     	void portal();
   }
   
   class NaverLogin implements Login, Portal {
   	  void naver() {}
   		@Override void login() {}
     	@Override void portal() {}
   }
   
   KakaoLogin K = new KakaoLogin();
   Login K = new KakaoLogin();
   ```

   ```java
   Login login = new Login();
   login.login();
   Login login = new KakaoLogin();
   login.kakao(); // --> 호출불가
   Login login = new NaverLogin();
   login.naver(); // --> 호출불가
   
   Portal portal = new NaverLogin();
   portal.portal(); // --> 이 메소드만 접근 가능
   ```

   

### 객체지향 설계

>  어떻게 하면 객체지향적인 설계인 것인가?

- **객체지향 5가지 설계원칙 ( SOLID )**
  - S
    - SRP (Single responsibility principle)
      - 모든 클래스는 하나의 책임만 가지며, 클래스는 그 책임을 완전히 캡슐화해야 한다.
  - O
    - OCP (Open-closed Principle)
      - 확장에 대해 열려 있어야 하고, 수정에 대해서는 닫혀 있어야 한다
  - L
    - LSP (Liskov substitution principle)
      - 추상객체로 사용되는 부분에 구상객체가 들어가도 아무 문제 없어야 한다.
  - I
    - ISP (Interface segregation principle)
      - 큰 덩어리의 인터페이스들을 구체적이고 작은 단위들로 분리시킴으로써 클라이언트들이 꼭 필요한 메서드들만 이용할 수 있게 한다.
  - D
    - DIP (Dependency inversion principle)
      - 상위 계층이 하위 계층에 의존하는 전통적인 의존관계를 반전시킴으로써 상위 계층이 하위 계층의 구현으로부터 독립되게 한다.
- **디자인 패턴**
  - 객체지향적인 소프트웨어를 설계하는 23가지 솔루션
  - **검증된 소프트웨어 디자인** 솔루션
  - **효율적인 의사소통 공통 언어**

- 설명하기 위한 도구 UML
  - UseCase Diagram
  - Sequence Diagram
  - Package Diagram
  - **Class Diagram**
  - 작성 툴
    - https://draw.io