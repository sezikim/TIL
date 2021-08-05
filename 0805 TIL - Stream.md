## Collection 함수형 데이터 처리

### Collection

- 여러 데이터의 묶음을 컬렉션이라고 합니다.  --> **추상체**
- Collection
  - List 
    - LinkedList,  ArrayList, Vector, Stack
  - Set
    - HashSet
  - 등

### Iterator

- 컬렉션을 풀어서 하나씩 처리할 수 있는 수단
- **Iterator를 사용하여 컬렉션 안의 데이터를 안전하게 삭제할 수 있다.**
- 역으로 움직일 수 없다.
  - 이전 데이터를 조회할 수 없다.

### Stream

> 자주 써봅시다..!

- 연속된 데이터 처리에 대한 강력하고 풍부한 **고차함수**(함수를 인자로 받는 함수)를 제공한다.
- **표현이 직관적**이다.

- 생성 -> 가공 -> 결과

  - **결과 함수를 호출해야 실행** 된다.

- 생성

  - Arrays.stream(), Stream.builder(), Stream.generate() 등

- 가공

  - filter(), map(), forEach(), groupingBy() 등

- 결과

  - collect(), toArray(), anyMatch() 등

- **ParallelStream을 제공하여, 병렬처리 가능**하다.

  - 사용 예시

  ```java
  Arrays.asList("A", "AB", "CCC", "DDDD", "EEEEE")
                  .stream()
                  .map(String::length)
                  .filter(i -> i % 2 == 1)
                  .forEach(System.out::println);
  
  Random r = new Random();
  Stream.generate(r::nextInt)
        .limit(10)
        .forEach(System.out::println);
  
  Stream.iterate(0, (i) -> i + 2)
        .limit(10)
        .forEach(System.out::println);
  ```

### Optional

> NPE : Null Pointer Exception 을 해결하기 위한 방법 중 하나

- 자바에서는 (거의) 모든것이 레퍼런스 ==> (거의) 모든것이 null이 될 수 있다.

- 항상 null을 확인할 필요가 있습니다.

- null 대신 가능한 경우

  1. EMPTY 클래스
  2.  Optional 클래스
     - null 데이터 : Optional.empty()
     - 데이터 : Optional.of({DATA})
     - 데이터 유무: isPresent()

  ```java
  public class Main {
      public static void main(String[] args) {
          
          /*
          User user1 = new User(0, "");
          User user2 = null;
          if (user2 == null) {
              System.out.println("null!");
          }
          */
          
          // 위의 방식을 Optional을 이용하여 아래와 같이!
          
          Optional<User> optionalUser = Optional.empty();
          optionalUser.isPresent();
          
          optionalUser = Optional.of(new User(1, "2"));
          optionalUser.isPresent();
  
          optionalUser.ifPresent(System.out::println);
      }
  }
  ```

  