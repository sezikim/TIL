# 컬렉션 프레임워크
> 자바는 널리 알려져 있는 자료구조를 바탕으로 객체들을 효율적으로 추가, 삭제, 검색할 수 있도록
java.util 패키지에 컬렉션과 관련된 인터페이스와 클래스들을 포함시켜 놓았다.
- 컬렉션 프레임워크의 주요 인터페이스는 List, Set, Map이 있다.

|인터페이스 분류||특징|구현 클래스|
|:---|:---|:---|:---|
|Collection|List|순서를 유지하고 저장, 중복 저장 가능|ArrayList, Vector, LinkedList|
|```|Set|순서를 유지하지 않고 저장, 중복 저장 안 됨|HashSet, TreeSet|
|Map||키와 값의 쌍으로 저장, 키는 중복 저장 안됨|HashMap, Hashtable, TreeMap, Properties|

## List
- 객체를 일렬로 늘어놓은 구조
- 객체를 인덱스로 관리, 객체를 저장하면 자동 인덱스가 부여되고 검색, 삭제 기능을 제공한다
- List 컬렉션은 객체 자체를 저장하는 것이 아니라 객체의 번지를 참조
    - 동일한 객체를 중복 저장할 수 있는데, 이 경우 동일한 번지가 참조된다.
    - null도 저장이 가능한데, 이 경우 해당 인덱스는 객체를 참조하지 않는다.
- List 컬렉션의 주요 메소드

|기능|메소드|설명|
|:---|:---|:---|
|객체 추가|boolean add(E e)|주어진 객체를 맨 끝에 추가|
|```|void add(int index, E element)|주어진 인덱스에 객체를 추가|
|```|set(int index, E element)|주어진 인덱스에 저장된 객체를 주어진 객체로 바꿈|
|객체 검색|boolean contains(Object o)|주어진 객체가 저장되어 있는지 여부|
|```|E get(int index)|주어진 인덱스에 저장된 객체를 리턴|
|```|isEmpty()|컬렉션이 비어 있는지 조사|
|```|int size()|저장되어 있는 전체 객체 수를 리턴|
|객체 삭제|void clear()|저장된 모든 객체를 삭제|
|```|E remove(int index)|주어진 인덱스에 저장된 객체를 삭제|
|```|boolean remove(Object o)|주어진 객체를 삭제|
```java
List<String> list = ...;
list.add("홍길동"); //맨 끝에 객체 추가
list.add(1, "신용권");  //지정된 인덱스에 객체 삽입
String str = list.get(1);   //인덱스로 객체 찾기
list.remove(0); //인덱스로 객체 삭제
list.remove("신용권");  //객체 삭제
```

## ArrayList
>일반 배열과 ArrayList는 인덱스로 객체를 관리한다는 점에서 유사하지만
저장 용량을 초과한 객체들이 들어오면 자동적으로 저장 용량이 늘어난다는 차이점이 있다.
-     List<E> list = new ArrayList<E>();
- 기본 생성자로 ArrayList 객체를 생성하면 내부에 10개의 객체를 지정할 수 있는 초기용량을 가지게 된다.
-     List<String> list = new ArrayList<String>(30);
- 위와 같이 크기를 지정해서 생성할 수도 있다.
- ArrayList에 객체를 추가하면 인덱스 0부터 차례대로 저장된다.
- 특정 인덱스의 객체를 제거하면 바로 뒤 인덱스부터 마지막 인덱스 까지 모두 앞으로 1씩 당겨진다.
- 빈번한 삽입과 삭제가 일어나는 곳에서는 LinkedList를 사용하는 것이 좋다.
-     List<T> list = Arrays.asList(T... a);
- 고정된 객체들로 구성된 List를 생성할 때 위와같이 생성한다.

## Vector
- ArrayList와 동일한 내부 구조를 가지고 있다.
- Vector는 동기화된 메소드로 구성되어 있기 때문에 멀티 스레드가 동시에 이 메소드들을 실행할 수 없다.
    - 멀티 스레드 환경에서 안전하게 객체를 추가, 삭제할 수 있다.
    - 스레드가 안전(Thread safe)하다라고 말한다.

## LinkedList
- ArrayList와 사용 방법은 같지만 내부 구조는 완전 다르다.
- LinkedList는 인접 참조를 링크해서 체인처럼 관리한다.
![ArrayList, LinkedList](http://www.nextree.co.kr/content/images/2016/09/jdchoi_20140225_arrayvslinkedlist11.png)
- LinkedList는 특정 인덱스의 객체를 제거하면 앞뒤 링크만 변경되고 나머지 링크는 변경되지 않는다
- 빈번한 객체 삽입과 삭제가 일어나는 곳에서는 ArrayList보다 LinkedList가 좋은 성능을 발휘한다.
-     List<E> list = new LinkedList<E>();

## Set
- Set 컬렉션은 저장 순서가 유지되지 않는다.
- 중복해서 저장할 수 없고, 하나의 null만 저장할 수 있다.
- 수학의 집합에 비유될 수 있다.
- Set 컬렉션의 주요 메소드들

|기능|메소드|설명|
|---|---|---|
|객체 추가|boolean add(E e)|주어진 객체를 저장, 객체가 저장되면 true반환, 중복 객체면 false 반환|
|객체 검색|boolean contains(Object o)|주어진 객체가 저장되어 있는지 여부|
|```|isEmpty()|컬렉션이 비어 있는지 조사|
|```|Iterator< E> iterator()|저장된 객체를 한 번씩 가져오는 반복자 리턴|
|```|int size()|저장되어 있는 전체 객체 수 리턴|
|객체 삭제|void clear()|저장된 모든 객체를 삭제|
|```|boolean remove(Object o)|주어진 객체를 삭제|

- Set 컬렉션은 인덱스로 객체를 검색해서 가져오는 메소드가 없다.
    - 전체 객체를 대상으로 한번씩 반복해서 가져오는 Iterator를 제공
    ```java
    Set<String> set = ...;
    Iterator<String> iterator = set.iterator();
    ```
    - Iterator 인터페이스에 선언된 메소드
        - boolean hasNext()
            - 가져올 객체가 있으면 true 리턴, 없으면 false 리턴
        - E next()
            - 컬렉션에서 하나의 객체를 가져온다
        - void remove()
            - Set 컬렉션에서 객체를 제거한다

## HashSet
- Set 인터페이스의 구현 클래스
- 
      Set<E> set = new HashSet<E>();
- HashSet은 객체들을 순서 없이 저장하고 동일한 객체는 중복 저장하지 않는다.
    - hashCode() 메소드를 호출해서 해시코드를 얻어내, 저장되어 있는 객체들의 해시코드와 비교한다.
    - 동일한 해시코드가 있으면 equals() 메소드로 비교, true가 나오면 저장X

## Map
- Map 컬렉션은 키와 값으로 구성된 Entry 객체를 저장하는 구조를 가지고 있다.
- 키와 값은 모두 객체이며, 키는 중복 저장될 수 없지만 값은 중복 저장될 수 있다.
- Map 인터페이스의 주요 메소드
 
|기능|메소드|설명|
|---|---|---|
|객체 추가|V put(K key, V value)|주어진 키와 값을 추가, 저장되면 값을 리턴|
|객체 검색|boolean containsKey(Object key)|주어진 키가 있는지 확인|
|```|boolean containsValue(Object value)|주어진 값이 있는지 확인|
|```|Set<Map.Entry<K, V> entrySet()|키와 값의 쌍으로 구성된 모든 Map.Entry 객체를 Set에 담아서 리턴|
|```|V get(Object Key)|주어진 키가 있는 값을 리턴|
|```|boolean isEmpty()|컬렉션이 비어 있는지 여부|
|```|Set<K> keySet()|모든 키를 Set 객체에 담아서 리턴|
|```|int size()|저장된 키의 총 수를 리턴|
|```|Collection<V> values()|저장된 모든 값을 Collection에 담아서 리턴|
|객체 삭제|void clear()|모든 Map.Entry(키와 값)를 삭제|
|```|V remove(Object key)|주어진 키와 일치하는 Map.Entry를 삭제하고 값을 리턴|
```java
Map<K, V> map = ~;
Set<K> keySet = map.ketSet();
Iterator<K> keyIterator = keySet.iterator();
while(keyIterator.hasNext()) {
    K key = keyIterator.next();
    V value = map.get(key);
}
```

## HashMap
- Map 인터페이스를 구현한 대표적인 Map 컬렉션
- 동일한 키가 될 조건은 hasCode() 리턴값이 같고 equals()가 true를 리턴할 때이다.
- 키와 값의 타입은 클래스 및 인터페이스 타입만 가능하다.
```java
Map<K, V> map = new HashMap<K, V>();
```
## Hashtable
- Hashtable은 HashMap과 동일한 내부 구조를 가지고 있다.
- Hashtable의 차이점은 동기화된 메소드로 구성되어 있기 때문에 스레드가 안전(thread safe)하다.

## Properties
- Hashtable의 하위 클래스, 모든 특징을 그대로 가지고 있다.
- Properties의 차이점은 키와 값을 String 타입으로 제한한다.
- 앱 옵션 정보, 데이터베이스 연결 정보, 국제화 정보가 저장된 프로퍼티 파일을 읽을 때 주로 사용.
```java
import java.io.FileReader;
import java.net.URLDecoder;
import java.util.Properties;

public class PropertiesExample {
    public static void main(String[] args) throws Exception {
        Properties properties = new Properties();
        String path = PropertiesExample.class.getResource("database.properties").getPath();
        path = URLDecoder.decode(path, "utf-8");
        properties.load(new FileReader(path));
        
        String driver = properties.getProperty("driver");
        String url = properties.getProperty("url");
        String username = properties.getProperty("username");
        String password = properties.getProperty("password");
        
        System.out.println("driver : " + driver);
        System.out.println("url : " + url);
        System.out.println("username : " + username);
        System.out.println("password : " + password);
    }
}
```
## TreeSet
- 이진 트리를 기반으로 한 Set 컬렉션
- 검색기능을 강화시킨 컬렉션
- 노드값인 value와 왼쪽 오른쪽 자식 노드를 참조하기 위한 두 개의 변수로 구성
```java
TreeSet<E> treeSet = new TreeSet<E>();
```
- 주요 메소드들

|리턴 타입|메소드|설명|
|---|---|---|
|E|first()|제일 낮은 객체를 리턴|
|E|last()|제일 높은 객체를 리턴|
|E|lower(E e)|주어진 객체보다 바로 아래 객체를 리턴|
|E|higher(E e)|주어진 객체보다 바로 위 객체를 리턴|
|E|floor(E e)|주어진 객체와 동등한 객체가 있으면 리턴, 만약 없다면 주어진 객체의 바로 아래의 객체를 리턴|
|E|ceiling(E e)|주어진 객체와 동등한 객체가 있으면 리턴, 만약 없다면 주어진 객체의 바로 위의 객체를 리턴|
|E|pollFirst()|제일 낮은 객체를 꺼내오고 컬렉션에서 제거|
|E|pollLast()|제일 높은 객체를 꺼내오고 컬렉션에서 제거|
|Iterator< E >|descendingIterator()|내림차순으로 정렬된 Iterator를 리턴|
|NavigableSet< E >|descendingSet()|내림차순으로 정렬된 NavigableSet을 반환|
|NavigableSet< E >|headSet(E toElement, boolean inclusive)|주어진 객체보다 낮은 객체들을 리턴|
|NavigableSet< E >|tailSet(E fromElement, boolean inclusive)|주어진 객체보다 높은 객체들을 리턴|
|NavigableSet< E >|subSet(E fromElement, boolean frominclusive, E toElement, boolean toInclusive)|시작과 끝으로 주어진 객체 사이의 객체들을 리턴|

## TreeMap
- 이진 트리를 기반으로 한 Map 컬렉션
- TreeSet과의 차이점은 키와 값이 저장된 Map.Entry를 저장한다는 점이다.
```java
TreeMap<K, V> treeMap = new TreeMap<K, V>();
```
- TreeSet과 동일한 역할을 하는 주요 메소드들을 가지고 있다.(Entry를 리턴하는 차이점을 가지고 있다)

## Comparable과 Comparator
> TreeSet과 TreeMap은 정렬을 위해 java.lang.Comparable을 구현한 객체를 요구한다
Integer, Double, String은 모두 Comparable 인터페이스를 구현하고 있다. 사용자 정의 클래스도
Comparable을 구현한다면 자동 정렬이 가능하다. 사용자 정의 클래스는 Comparable의 compareTo()
메소드를 오버라이딩하여 다음과 같이 리턴값을 만들어야 한다.

      int compareTo(T o);
- 주어진 객체와 같으면 0을 리턴
- 주어진 객체보다 적으면 음수를 리턴
- 주어진 객체보다 크면 양수를 리턴

## LIFO FIFO
- LIFO : Last In First Out
    - 나중에 넣은 객체가 먼저 빠져나가는 자료구조
    - Stack
- FIFO : First In First Out
    - 먼저 넣은 객체가 먼저 빠져나가는 구조
    - Queue

## Stack
- LIFO 자료구조를 구현한 클래스
```java
Stack<E> stack = new Stack<E>();
```
- Stack의 주요 메소드

|리턴 타입|메소드|설명|
|---|---|---|
|E|push(E item)|주어진 객체를 스택에 넣는다.|
|E|peek()|스택의 맨 위 객체를 가져온다. 객체를 스택에서 제거X|
|E|pop()|스택의 맨 위 객체를 가져온다. 객체를 스택에서 제거|

## Queue
- FIFO 자료구조에서 사용되는 메소드를 정의한 인터페이스
- Queue 인터페이스를 구현한 대표적인 클래스는 LinkedList
```java
Queue<E> queue = new LinkedList<E>();
```
- Queue의 주요 메소드

|리턴 타입|메소드|설명|
|---|---|---|
|boolean|offer(E e)|주어진 객체를 넣는다.|
|E|peek()|객체 하나를 가져온다. 객체를 큐에서 제거X|
|E|poll()|객체 하나를 가져온다. 객체를 큐에서 제거한다.|

## 동기화된 컬렉션
> 대부분의 클래스들은 싱글 스레드 환경에서 사용할 수 있돌고 설계되었다.
경우에 따라서는 싱글 스레드 환경에서 사용하다가 멀티 스레드 환경으로 전달할 필요도 있을 것이다.
컬렉션 프레임워크는 비동기화된 메소드를 동기화된 메소드로 래핑하는 메소드를 제공한다.

|리턴 타입|메소드(매개 변수)|설명|
|---|---|---|
|List< T >|synchronizedList(List< T > list)|List를 동기화된 List로 리턴|
|Map< K, V >|synchronizedMap(Map< K, V > m)|Map을 동기화된 Map으로 리턴|
|Set< T >|synchronizedSet(Set< T > s)|Set을 동기화된 Set으로 리턴|
    List<T> list = Collections.synchronizedList(new ArrayList<T>());
    Set<E> set = Collections.synchronizedSet(new HashSet<E>());
    Map<K, V> map = Collections.synchronizedMap(new HashMap<K, V>());

## 병렬 처리를 위한 컬렉션
> 자바는 멀티 스레드가 컬렉션의 요소를 병렬적으로 처리할 수 있도록 특별한 컬렉션을 제공하고 있다.

```java
Map<K, V> map = new ConcurrentHashMap<K, V>();
Queue<E> queue = new ConcurrentLinkedQueue<E>();

```

