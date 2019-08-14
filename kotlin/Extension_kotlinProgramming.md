# 확장 함수
> 기존 타입(클래스나 인터페이스)의 정의를 직접 변경하지 않고 새로운 기능을 추가할 수 있게 해준다.

# 확장 함수 정의하기
- 확장 함수를 추가할 타입(**수신자 타입**)을 같이 지정해야 한다.
```kotlin
fun String.addEnthusiasm(amount: Int = 1) = this + "!".repeat(amount)

fun main() {
    println("마드리갈이 그 건물에서 나왔습니다.".addEnthusiasm())
}
```
## 슈퍼 클래스에 확장 함수 정의하기
- 함수의 확장은 상속과 함께 사용될 수도 있다.
```kotlin
fun String.addEnthusiasm(amount: Int = 1) = this + "!".repeat(amount)

fun Any.easyPrint() = println(this)

fun main() {
    "마드리갈이 그 건물에서 나왔습니다".addEnthusiasm().easyPrint()
    42.easyPrint()
    // "마드리갈이 그 건물에서 나왔습니다"
    // 42 출력
}
```
# 제네릭 확장 함수
- 위에서 보인 easyPrint() 함수를 제네릭으로 바꾸어서 연쇄 호출이 가능하게 한다.
    - 제네릭 타입 매겨변수 T가 확장 함수의 수신자 타입으로 사용
```kotlin
fun String.addEnthusiasm(amount: Int = 1) = this + "!".repeat(amount)

fun <T> T.easyPrint(): T {
    println(this)
    return this
}

fun main() {
    "마드리갈이 그 건물에서 나왔습니다".easyPrint().addEnthusiasm().easyPrint()
    42.easyPrint()
}
```
- 제네릭 타입 확장 함수는 코틀린 표준 라이브러리에 많이 있다.
- let 함수
```kotlin
public inline fun <T, R> T.let(block: (T) -> R): R {
    return block(this)
}
```
- 람다를 인자로 받고, 람다에서는 수신자 객체를 인자로 받아 R 타입으로 반환한다.

# 확장 프로퍼티
- 확장 프로퍼티도 정의할 수 있다.
```kotlin
val String.numVowels
    get() = count { "aeiouy".contains(it) }
fun <T> T.easyPrint(): T {
    println(this)
}

fun main() {
    "How many vowels".numVowels.easyPrint() // 5 출력
}
```
- 확장 프로퍼티는 backing field를 갖지 않는다.
    - **반드시 get을 정의해야 한다**

# null 가능 타입의 확장 함수
- nullable 타입에 사용하기 위해 확장 함수를 정의할 수도 있다.
```kotlin
infix fun String?.printWithDefault(default: String) = print(this ?: default)

fun main() {
    val nullableString: String? = null
    nullableString printWithDefault "기본 문자열" 
    // 중위 함수로 수산지 객체와 함수 호출 사이의 점(.), 인자 주위의 괄호를 생략한다.
}
```
## 확장 함수의 바이트코드 구현
> 확장 함수와 프로퍼티는, 일반 함수와 프로퍼티와 같은 방법으로 사용되지만, 클래스에 정의된 것도 아니고 상속을 사용하지도 않는다.

- 바이트코드에서는 코틀린 확장 함수가 static 메서드로 되며, 수신자 타입이 첫 번째 인자로 전달된다.


