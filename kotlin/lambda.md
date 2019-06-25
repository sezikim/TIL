#lambda
- 람다 식 또는 람다는 기본적으로 다른 함수에 넘길 수 있는 작은 코드 조각

# 람다 식, 멤버 참조
## 코드 블록을 함수 인자로 넘기기
- 일련의 동작을 변수에 저장하거나 다른 함수에 넘겨야 하는 경우,
자바에서는 **무명 내부 클래스**를 통해 이런 목적을 달성했다.
    - 코드를 함수에 넘기거나, 변수에 저장할 수 있기는 하지만 번거롭다.
- **함수형 프로그래밍**에서는 함수를 값처럼 다루는 접근 방법을 택함
    - 클래스의 인스턴스를 함수에 넘기는 대신 함수를 직접 다른 함수에 전달
    - 람다 식을 이용해, 코드 블록을 직접 함수의 인자로 전달
    ```java
    button.setOnClickListener(new OnClickListener() {
        @Override
        public void onClick(View view) {
            // 클릭 시, 수행할 동작
        }
    }
    ```
    ```kotlin
    button.setOnClickListener {
        // 클릭 시, 수행할 동작
    }
    ```
## 람다와 컬렉션
-     data class Person
- 컬렉션을 직접 검색
```kotlin
fun findTheOldest(people: List<Person>) {
    var maxAge = 0
    var theOldest: Person? = null
    for (person in people) {
        if (person.age > maxAge) {
            maxAge = person.age
            theOldest = person
        }
    }
    println(theOldest)
}
```
- 코틀린에서는 라이브러리 함수를 쓰면 더 좋다.
```kotlin
val people = listOf(Person("Alice", 29), Person("Bob", 31))
println(people.maxBy { it.age })
```
- 모든 컬렉션에 대해 maxBy 함수를 호출할 수 있다.
- { it.age } 와 같이 단지 함수나 프로퍼티를 반환하는 역할을 수행하는 람다는 멤버 참조로 대치할 수 있다.
-     people.maxBy(Person::age)

## 람다 식의 문법
- 람다는 값처럼 여기저기 전달할 수 있는 동작의 모음이다.
- 람다를 따로 선언해서 변수에 저장할 수도 있다.
```kotlin
val sum = { x: Int, y: Int -> x + y }
println(sum(1, 2))
```
- 컬렉션에서의 람다식
```kotlin
people.maxBy({ p: Person -> p.age })
```
- 코틀린에는 함수 호출 시, 맨 뒤에 있는 인자가 람다 식이라면 그 람다를 괄호 밖으로 빼낼 수 있다.
 ```kotlin
people.maxBy() { p: Person -> p.age }
```
- 람다가 어떤 함수의 유일한 인자이고 괄호 뒤에 람다를 썼다면 호출 시 빈 괄호를 없애도 된다.
```kotlin
people.maxBy { p: Person -> p.age }
```
- 더 복잡한 함수 호출에 적용한 모습
```kotlin
val people = listOf(Person("이몽룡", 29), Person("성춘향", 31))
val name = people.joinToString(separator = " ", transform = { p: Person -> p.name })
/// 같은 표현
/*
people.joinToString(" ") { p: Person -> p.name }
*/
```
- 로컬 변수처럼 컴파일러는 람다 파라미터의 타입도 추론할 수 있다.
```kotlin
people.maxBy { p -> p.age }
```
- 람다의 파라미터 이름을 디폴트 이름인 it으로 바꾸면 람다 식을 더 간단하게 만들 수 있다.
```kotlin
people.maxBy { it.age }
```
- 람다를 변수에 저장할 때는 파라미터의 타입을 추론한 문맥이 존재하지 않는다.
    - 파라미터 타입을 명시해야 한다.
    ```kotlin
    val getAge = { p: Person -> p.age }
    people.maxBy(getAge)
    ```
- 여러 줄로 이뤄진 람다식은 맨 마지막에 있는 식이 결과 값이 된다.
```kotlin
val sum = { x: Int, y: Int -> 
            println("Computing the sum of $x and $y...")
            x + y
        }
``` 

## 현재 영역에 있는 변수에 접근
- 람다를 함수 내에서 정의시, 람다 정의의 앞에 선언된 로컬 변수를 사용할 수 있다.
```kotlin
fun printMessagesWithPrefix(messages: Collection<String>, prefix: String) {
    messages.forEach {
        println("$prefix $it")
    }
}
```
- 자바와 다른 점 중 중요한 한가지는 코틀린 람다 안에서는 **파이널 변수가 아닌 변수에 접근할 수 있다**는 점이다.
- 람다 안에서 사용하는 외부 변수를 **람다가 포획한 변수**라고 부른다.
    - 파이널 변수를 포획한 경우에 람다 코드를 변수 값과 함께 저장한다.
    - 파이널이 아닌 변수를 포획한 경우에는 변수를 래퍼로 감싸서 나중에 변경하거나 읽을 수 있게 한 다음, 래퍼에 대한 참조를 람다 코드와 함께 저장한다.
```kotlin
fun printProblemCounts(responses: Collection<String>) {
    var clientErrors = 0
    var serverErrors = 0
    responses.forEach {
        if (it.startsWith("4")) {
            clientErrors++
        } else if (it.startWith("5")) {
            serverErrors++
        }
    }
    println("$clientErrors client errors, $serverErrors server errors")
}
```
- 인스턴스에 대한 참조를 파이널로 만들면 쉽게 람다로 포획할 수 있고, 람다 안에서 인스턴스의 필드를 변경할 수 있다.
- 람다를 이벤트 핸들러나 다른 비동기적으로 실행되는 코드로 활용하는 경우, 함수 호출이 끝난 다음에 로켤 변수가 변경될 수 있다.
```kotlin
fun tryToCountButtonClicks(button: Button): Int {
    var clicks = 0
    button.onClick { clicks++ }
    return clicks
}
```
## 멤버 참조
-     val getAge = Person::age
- :: 를 사용하는 식을 **멤버 참조**라고 부른다.
-     val getAge = { person: Person -> person.age }
- 다음의 람다 식을 더 간략하게 표현한 것이다.
- 최상위에 선언된 함수나 프로퍼티도 참조 가능하다.
-     fun salute() = println("Salute!")
      run(::salute)
- 람다가 인자가 여럿인 다른 함수한테 작업을 위임하는 경우, 직접 위임 함수에 대한 참조를 제공하면 편리하다.
```kotlin
val action = { person: Person, message: String -> sendEmail(person, message) }
val nextAction = ::sendEmail
```
- 생성자 참조를 사용하면 클래스 생성 작업을 연기하거나 저장해둘 수 있다. :: 뒤에 클래스 이름을 넣으면 생성자 참조를 만들 수 있다.
```kotlin
data class Person(val name: String, val age: Int)
val createPerson = ::Person
val p = createPerson("Alice", 29)
println(p)
Person(name=Alice, age=29)
```
- 확장 함수도 멤버 함수와 똑같은 방식으로 참조할 수 있다.
```kotlin
fun Person.isAdult() = age >= 21
val predicate = Person::isAdult
```
# 컬렉션 함수형 API
## filter 와 map
- filter
    - 컬렉의 원소 중에서 주어진 술어를 만족하는 원소만으로 이뤄진 새로운 컬렉션을 리턴
    ```kotlin
    val people = listOf(Person("Alice", 29), Person("Bob", 31))
    ```
- map
    - 주어진 람다를 컬렉션의 각 원소에 적용한 결과를 모아서 새 컬렉션을 만들어 리턴
    ```kotlin
    val list = listOf(1, 2, 3, 4)
    println(list.map { it * it })
    ```
- Map에서는 filterKeys, mapKeys, filterValues, mapValues를 사용해서 값을 걸러 내거나 변환한다.
## all, any, count, find: 컬렉션에 술어 적용
- all
    - 모든 원소가 이 술어를 만족하는지
- any
    - 술어를 만족하는 원소가 하나라도 있는지
- count
    - 술어를 만족하는 원소의 개수
- find
    - 술어를 만족하는 원소를 하나 찾음
    - 없으면 Null 반환

## groupBy
- 특성을 파라미터로 전달하면, 컬렉션을 자동으로 구분해 준다.
```kotlin
val people = listOf(Person("Alice", 31), Person("Bob", 29), Person("Carol", 31))
println(people.groupBY { it.age })
```
- 각 그룹은 리스트이며, groupBy의 결과 타입은 Map<Int, List<Person>>이다.

## flatMap과 flatten
- 중첩된 리스트의 원소를 한 리스트로 모아야 할때 사용.

## 지연 계산 컬렉션 연산
- **시퀀스**를 사용하면 중간 임시 컬렉션을 사용하지 않고도 컬렉션 연산을 연쇄할 수 있다.
```kotlin
people.asSequence()
    .map(Person::name)
    .filter{ it.startsWith("A") }
    .toList()
```
- 큰 컬렉션에 대해서 연산을 연쇄시킬 때는 시퀀스를 사용하는 것을 규칙으로 삼아라.

## 시퀀스 연산
- 중간 연산
    - 다른 시퀀스를 반환한다.
- 최종 연산
    - 결과를 반환한다.








