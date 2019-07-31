s는 런타임에 객체를 비교해주는 연산자이다.
    ```java
    public static void is() {
        
    }
    ```
    위와 같은 메소드를 사용하기 위해, 아래와 같이 사용한다.
    ```kotlin
    fun doStuff() {
        `is`()
    }
    ```
- 테스트
    - 테스트 파일에서 사용되는 함수 이름을 더 알기 쉽게 나타내기 위함
    ```kotlin
    fun `users should be signed out when they click logout`() {
        // 테스트 코드
    }
    ```
    다음과 같은 함수 이름보다 가독성이 좋다.
    ```kotlin
    fun usersShouldBeSignedOutWhenTheyClickLogout() {
        // 테스트 코드
    }
    ```
## Nothing 타입
> Unit 타입처럼 값을 반환하지 않는 타입
- Unit과 다른 점은 함수의 실행이 끝나더라도 호출 코드로 제어가 복귀되지 않는다.
- 의도적으로 예외를 발생시킬 때 사용
- TODO 함수에 사용된다.
    - 아직 할것이 남아있다는 것을 알려 주기 위해 사용
    - 예외를 발생시킨 후 제어가 복귀되지 않는다.
    - 개발하는 함수를 당장 구현하지 않고 다른 기능을 개발할 수 있다.
## 익명함수
> 함수 정의 부분에 이름이 없으며, 다른 함수의 인자로 전달되거나 반환되는 형태로 사용
- 익명 함수도 타입을 갖는다. -> 함수 타입
 `(parameters) -> Result`
- 익명 함수는 암시적으로 마지막 코드 결과를 반환한다.
    - 익명 함수 안에서 return 키워드의 사용이 금지되어 있다.
- 하나의 인자만 받는 익명 함수에는 매개변수 이름을 지정하는 대신 **it** 키워드를 사용할 수 있다.
- 타입 추론이 된다.
    - 매개변수 타입을 지정하여 변수 타입 추론이 가능하게 작성한다.
```kotlin
numLetters = "Mississipi".count({ it == 's' })   // 함수의 인자로  (Char) -> Boolean 타입의 익명함수를 전달
println(numLetters) // 4를 출력
println({val currentYear = 2019
        "현재 년도는 ${currentYear}년 입니다."}())  // () -> String 타입의 익명 함수를 호출
val greetingFunction = { name: String, number: Int ->
    val currentYear = 2019
    "$currentYear 의 $number 번째 방문자 $name 님, 환영합니다!"
    }
println(greetingFunction("김현준", 5))  // (String, Int) -> String 타입의 익명 함수를 greetingFunction 변수에 저장
```
- 함수에서 마지막 매개변수로 함수 타입을 받을 때, 람다 인자를 둘러싼 괄호를 생략할 수 있다.
```kotlin
"Mississippi".count({ it == 's'})
"Mississippi".count { it == 's' }
```

## 인라인 함수
> 람다를 정의하면 JVM에서 객체로 생성된다.
성능에 영향을 줄 수 있는 메모리 부담을 초래할 수 있다.
- 람다를 인라인 처리하면 객체 사용과 변수의 메모리 할당을 JVM이 하지 않아도 된다.
    - 코틀린 컴파일러가 바이트코드를 생성할 때 람다 코드가 포함된 함수의 전체 코드를 복사해서 함수를 호출하는 코드에 붙여넣어 준다.
    - C의 매크로 처럼 동작한다.
    - 재귀 함수에서 허용되지 않는다.
```kotlin
inline fun runSimulation(playerName: String, greetingFunction: (String, Int) -> String) {
    val numBuildings = (1..3).shuffled().last()
    println(greetingFunction(playerName, numBuildings))
}
```
## 함수 참조
> 람다 외에도 다른 방식으로 함수의 인자로 함수를 전달할 수 있다.
- 람다 표현식을 사용할 수 있는 곳이면 어디든 함수 참조를 사용할 수 있다.
```kotlin
fun main() {
    runSimulation("김현준", ::printConstructionCost) { playerName, numBuildings -> 
    val currentYear = 2019
    println("$numBuildings 채의 건물이 추가됨")
    "SimVillage 방문을 환영합니다, $playerName! (copyright $currentYear)"
    }
}
```
## 반환 타입으로 함수 타입 사용
> 함수를 반환하는 함수를 정의할 수 있다. **고차 함수** 라고도 한다.
```kotlin
fun runSimulation() {
    val greetingFunction = configureGreetingFunction()
    println(greetingFunction("김현준"))
    println(greetingFunction("김현준"))
}

fun configureGreetingFunction(): (String) -> String {
    val structureType = "병원"
    var numBuildings = 5
    return { playerName: String ->
        val currentYear = 2019
        numBuildings += 1
        println("$numBuildings 채의 $structureType 이 추가됨")
        "SimVillage 방문을 환영합니다, $playerName! (copyright $currentYear)"
    }
}
```
위 코드에서, configureGreetingFunction이 반환하는 람다에서 configureGreetingFunction 내의 지역 변수가 사용되지만 정상 실행된다.
- 코틀린의 람다는 **클로저**이기 때문이다.
    - 클로저란, 다른 함수에 포함된 함수에서 자신을 포함하는 함수의 매개변수와 변수를 사용할 수 있는것.
    - val로 선언된 변수는 그것을 사용하는 람다 코드에 저장
    - var로 선언된 변수는 별도의 객체에 저장, 객체의 참조값이 람다식 코드에 저장된다.
        
