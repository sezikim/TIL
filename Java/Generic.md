# 제네릭(Generic)
- 클래스와 인터페이스, 메소드를 정의할 때 타입을 파라미터로 사용할 수 있도록 한다.
- 컴파일 시 강한 타입 체크를 할 수 있다.
    - 실행 시 타입 에러가 나는 것보다는 컴파일 시에 미리 타입을 강하게 체크해서 에러를 사전에 방지
- 타입 변환을 제거한다.
    - 비 제네릭 코드는 불필요한 타입 변환을 해서 프로그램 성능에 악영향을 미친다.
    - 제네릭 코드로 수정하면 List에 저장되는 요소를 String 타입으로 국한하기 때문에 타입 변환을 할 필요가 없다.
```java
//비제네릭 코드
List list = new ArrayList();
list.add("hello");
String str = (String) list.get(0); // 타입 변환을 해야한다.
```
```java
//제네릭 코드
List<String> list = new ArrayList<String>();
list.add("hello");
String str = list.get(0); // 타입 변환을 하지 않는다.
```

## 제네릭 타입
> 타입을 파라미터로 가지는 클래스와 인터페이스.
- 제네릭 타입은 클래스 또는 인터페이스 뒤에 "<>"부호가 붙고, 사이에 타입 파라미터가 위치한다.
- 타입 파라미터는 일반적으로 대문자 알파벳 한 글자로 표현한다.
-     public class Box<T> {
          private T t;
          public T get() { return t; }
          public void set(T t) { this.t = t; }
      }
      
      타입 파라미터 T를 사용해서 Object 타입을 모두 T로 대체했다. T는 Box 클래스로 객체를
      생성할 때 구체적인 타입으로 변경된다.
      
      Box<String> box = new Box<String>();
      
      타입 파라미터 T는 String 타입으로 변경되어 Box 클래스의 내부는 다음과 같이 자동으로 재구성된다.
      
      public class Box<String> {
          private String t;
          public void set(String t) { this.t = t; }
          public String get() { return t; }
      }
      
      다음과 같이 저장할 때와 읽어올 때 전혀 타입 변환이 발생하지 않는다.
      box.set("hello");
      String str = box.get();
- String 외에도 Integer, Double 등의 타입으로 변경할 수 있다.
## 제네릭 메소드
-     public <T> Box<T> boxing(T t) { ... }
- 매개 타입과 리턴 타입으로 파라미터를 갖는 메소드
- 제네릭 메소드는 코드에서 타입 파라미터의 구체적인 타입을 명시적으로 지정해도 된다.
- 컴파일러가 매개값의 타입을 보고 구체적인 타입을 추정하도록 할 수도 있다.
```java
public class Util{
    public static <T> Box<T> boxing(T t) {
        Box<T> box = new Box<>();
        box.set(t);
        return box;
    }
}
```
```java
public class BoxingMethodExample {
    public static void main(String[] args) {
        Box<Integer> box1 = Util.<Integer>boxing(100); // 구체적인 타입을 명시적으로 지정
        int intValue = box1.get();
        
        Box<String> box2 = Util.boxing("홍길동");
        String strValue = box2.get(); // 컴파일러가 매개값의 타입올 보고 구체적인 타입을 추정
    }
}
```
## 제한된 타입 파라미터<T extends 최상위타입>
- 타입 파라미터에 지정되는 구체적인 타입을 제한할 필요가 종종 있다.
EX) 숫자를 연산하는 제네릭 메소드는 매개값으로 Number 타입 또는 하위 클래스 타입의 인스턴스를 가져야한다.
- 제한된 타입 파라미터를 선언하려면 타입 파라미터 뒤에 extends 키워드를 붙이고 상위 타입을 명시한다.
 인터페이스라고 해서 implements를 사용하지 않는다.
    
      public <T extends 상위타입> 리턴타입 메소드(매개변수, ...) { ... }
- 타입 파라미터에 지정되는 구체적인 타입은 상위 타입, 상위 타입의 하위 또는 구현 클래스만 가능하다.
- 메소드의 중괄호 안에서 타입 파라미터 변수로 사용 가능한 것은 상위 타입의 멤버로 제한.
```java
public class Util {
    public static <T extends Number> int compare(T t1, T t2) {
        double v1 = t1.doubleValue();
        double v2 = t2.doubleValue();
        return Double.compare(v1, v2);
    }
}
```
```java
public class BoundedTypeParameterExample {
    public static void main(String[] args) {
        //String result1 = Util.compare("a", "b");
        //Stringdms Number의 하위타입이 아님
        
        int result1 = Util.compare(10, 20); // int -> Integer (자동 Boxing)
        System.out.println(result1);
        
        int result2 = Util.compare(4.5, 3); // double -> Double (자동 Boxing)
        System.out.println(result2);
    }
}
```
## 와일드카드 타입 <?>, <? extends ...>, <? super ...>
- 코드에서 ?를 일반적으로 와일드카드 라고 부른다.
- 제네릭 타입을 매개값이나 리턴 타입으로 사용할 때 구체적인 타입 대신에 와일드카드를 사용
    1. 제네릭 타입<?> : Unbounded Wildcards(제한 없음)
        - 타입 파라미터를 대치하는 구체적인 타입으로 모든 클래스나 인터페이스 타입이 올 수 있다.
    2. 제네릭 타입<? extends 상위타입> : Upper Bounded Wildcards(상위 클래스 제한)
        - 타입 파라미터를 대치하는 구체적인 타입으로 상위 타입이나 하위 타입만 올 수 있다.
    3. 제네릭 타입<? super 하위타입> : Lower Bounded Wildcards(하위 클래스 제한)
        - 타입 파라미터를 대치하는 구체적인 타입으로 하위 타입이나 상위 타입이 올 수 있다.
```java
public class Course<T> {
    private String name;
    private T[] students;
    
    public Course(String name, int capacity) {
        this.name = name;
        students = (T[]) (new Object[capacity]);    //타입 파라미터로 배열을 생성하려면
    }                                               //new T[n] 형태로 배열을 생성할 수 없고
                                                    //(T[]) (new Object[n])으로 생성해야 한다.
    public String getName() { return name; }
    public T[] getStudents() { return students; }
    
    public void add(T t) {
        for(int i=0; i<students.length; i++) {
            if(students[i] == null) {               //배열에 비어있는 부분을 찾아서 수강생을 추가하는 메소드
                students[i] = t;                    //
                break;
            }
        }
    }
}
```

## 제네릭 타입의 상속과 구현
- 제네릭 타입도 부모 클래스가 될 수 있다.
- 자식 제네릭 타입은 추가적으로 타입 파라미터를 가질 수 있다.
```java
public class ChildProduct<T, M> extends Product<T, M> { ... }
public class ChildProduct<T, M, C> extends Product<T, M> { ... }
```
