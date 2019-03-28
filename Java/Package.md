# 패키지
- 자바에서 클래스를 체게적으로 관리하기 위해 사용
- 클래스를 유일하게 만들어주는 식별자 역할

## 패키지 선언
- 패키지는 클래스를 컴파일하는 과정에서 자동적으로 생성되는 폴더
- 모두 소문자로 작성하는 것이 관례
```java
package 상위패키지.하위패키지;

public class ClassName { }
```
## import문
- 다른 패키지에 속하는 클래스를 사용하는데 두 가지 방법이 있다.
    1. 패키지와 클래스를 모두 기술
    ```java
    package com.mycompany;
    
    public class Car {
        com.hankook.Tire tire = new com.hankook.Tire();
    }
    ```
    2. import문 사용
    ```java
    package com.mycompany;
    
    import com.hankook.Tire;
    
    public class Car {
        Tire tire = new Tire();
    }
    ```
    - import문으로 지정된 패키지의 하위 패키지는 import 대상이 아니다.
- 패키지 이름 전체를 기술하는 방법이 꼭 필요한 경우가 존재.
    - 서로 다른 패키지에 동일한 이름의 클래스가 존재하고 import 되어 있을경우.

