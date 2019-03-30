## 생성자 대신 정적 팩토리 메소드를 고려하라.
> 클래스의 인스턴스를 얻는 전통적인 수단은 public 생성자
- 클래스의 인스턴스를 반환하는 단순한 정적 메소드

- 장점
    1. 이름을 가질 수 있다.
        - 반환될 객체의 특성을 쉽게 묘사할 수 있다.
    2. 호출될 때마다 인스턴스를 새로 생성하지는 않아도 된다.
        - 플라이웨이트 패턴과 비슷한 기법
        - 불변 클래스는 미리 만들어 놓거나, 재활용하는 식으로 불필요한 객체 생성을 피할 수 있다.
        - 인스턴스 통제 클래스 ( 인스턴스를 살아 있게 할지를 통제)
    3. 반환 타입의 하위 타입 객체를 반환할 수 있는 능력
        - 반환할 객체의 클래스를 자유롭게 선택
    4. 입력 매개변수에 따라 매번 다른 클래스의 객체를 반환할 수 있다.
        - 반환 타입의 하위 타입이기만 하면 어떤 클래스의 객체를 반환하든 상관없다.
        - 클라이언트는 팩토리가 건네주는 객체가 어느 클래스의 인스턴스인지 알 수도 없고 알 필요도 없다.
        하위클래스 이기만 하면 된다.
    5. 정적 팩토리 메소드를 작성하는 시점에는 반환할 객체의 클래스가 존재하지 않아도 된다.
        - 서비스 제공자 프레임워크를 만드는 근간 EX)JDBC
- 단점
    1. 상속을 하려면 public이나 protected 생성자가 필요하니 정적 팩토리 메소드만 제공하면
    하위 클래스를 만들 수 없다.
    2. 정적 팩토리 메소드는 프로그래머가 찾기 어렵다.
        - 사용자가 정적 팩토리 메소드 방식 클래스를 인스턴스화할 방법을 찾아야 한다.
        
        |명명 방식|의미|예|
        |---|---|---|
        |from|매개변수를 하나 받아서 해당 타입의 인스턴스를 반환하는 형변환 메소드|Date d = Date.from(instant)|
        |of|여러 매개변수를 받아 적합한 타입의 인스턴스를 반환하는 집계 메소드|Set<Rank> faceCards = Enumset.of(JACK, QUEEN, KING);|
        |valueOf|from과 of의 더 자세한 버전|BigInteger.valueOf(Integer.MAX_VALUE);|
        |instance 혹은 getInstance|매개변수를 받을때, 매개변수로 명시한 인스턴스를 반환, 같은 인스턴스임을 보장하지는 않는다.|StackWalker luke = StackWalker.getInstance(options);|
        |create 혹은 newInstance|instance 혹은 getInstance와 같지만, 매번 새로운 인스턴스를 생성해 반환함을 보장한다.|Object newArray = Araay.newInstance(classObject, arrayLen);|
        |getType|getInstance와 같으나, 생성할 클래스가 아닌 다른 클래스의 팩토리 메소드를 정의할 때 쓴다.|FileStore fs = Files.getFileStore(path);|
        |newType|newInstance와 같으나, 생성할 클래스가 아닌 다른 클래스의 팩토리 메소드를 정의할 때 쓴다.|BufferedReader br = Files.newBufferedReader(path);|
        |type|getType과 newType의 간결한 버전|List<Complaint> litany = Collections.list(legacyLitany);|

## 핵심 정리
- **정적 팩토리를 사용하는게 유리한 경우가 많다.**
- 무작정 public 생성자 사용하는 습관은 고치자.
