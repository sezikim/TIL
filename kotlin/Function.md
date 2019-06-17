## 코틀린에서 컬렉션 만들기
- 코틀린에서 컬렉션을 만드는 방법
-     val set = hashSetOf(1, 7, 53)
-     val list = arrayList(1, 7, 53)
-     val map = hashMapOf(1 to "one", 7 to "seven", 53 to "fifty-three")
- 위 세 컬렉션은 각각 자바의 HashSet, ArrayList, HashMap 클래스에 속한다.
    - 코틀린이 자신만의 컬렉션 기능을 제공하지 않는다.
    - 자바 코드와 상호작용하기 쉽다.
    - 자바보다 더 많은 기능을 쓸 수 있다.

## 함수를 호출하기 쉽게하기
1. 디폴트 toString 출력 형식과 다르게 출력하는 함수
```kotlin
fun <T> joinToString(
    collection: Collection<T>,
    separator: String,
    prefix: String,
    postfix: String
): String {
    val result = StringBuilder(prefix)
    for ((index, element) in collection.withIndex()) {
        if (index > 0) result.append(separator)
        result.append(element)
    }
    result.append(postfix)
    return result.toString()
}
```
- 이 함수를 이용해 출력하는 코드는 다음과 같다.
-     println(joinToString(list, "; ", "(", ")"))
        - 가독성에 문제가 있다.
        - 코틀린에서는 다음과 같이 인자에 이름을 명시할 수 있다.
        - joinToString(collection, separator = "; ", prefix = "(", postfix = ")")
2. 디폴트 파라미터 값
- 코틀린에서는 함수 선언에서 파라미터의 디폴트 값을 지정할 수 있다.
    - 메소드 오버로드 중 상당수를 피할 수 있다.
```kotlin
fun <T> joinToString(
    collection: Collection<T>,
    separator: String = ", ",
    prefix: String = "",
    postfix: String = ""
): String
```
- 다음과 같이 함수를 호출할 수 있다.
-     joinToString(list, ", ", "", "")
-     joinToString(list)
-     joinToString(list, "; ")
-     joinToString(list, postfix = ";", prefix = "# ")

3. 정적인 유틸리티 클래스 없애기: 최상위 함수와 프로퍼티
- 코틀린에서는 함수를 소스 파일의 최상위 수준에 위치시켜 무의미한 클래스를 쓰지 않는다.
    - 이런 함수들은 여전히 그 파일의 맨 앞에 정의된 패키지의 멤버 함수이므로,
    다른 패키지에서 사용하기 위해서는 이 함수가 정의된 패키지를 임포트 해야한다.
- 함수와 마찬가지로 프로퍼티도 파일의 최상위 수준에 놓을 수 있다.
```kotlin
var opCount = 0
const val UNIX_LINE_SEPARATOR = "\n"

fun performOperation() {
    opCount++
}
fun reportOperationCount() {
    println("Operation performed $opCount times")
}
```
## 확장 함수
- 확장함수?
    - 기존 자바 API를 재작성하지 않고 코틀린이 제공하는 기능을 사용할 수 있게해준다.
    - 확장함수는 어떤 클래스의 멤버 메소드처럼 호출할 수 있지만, 클래스 밖에서 선언된 함수이다.
    - 추가하려는 함수 이름 앞에 함수가 확장할 클래스의 이름을 덧붙인다.
- 클래스 이름을 receiver type, 확장 함수가 호출되는 대상이 되는 값을 receiver object라고 부른다.
    -     fun String.lastChar(): Char = this.get(this.length - 1)
    - String이 수신 객체 타입, this가 수신 객체
        - 수신 객체 멤버에 this 없이 접근할 수 있다.
- 확장함수가 **캡슐화를 깨지는 않는다.**
    - 클래스 내부에서만 사용할 수 있는 private, protected 멤버를 사용할 수 없다.
    - 확장함수를 사용하려면 다른 클래스나 함수와 마찬가지로 import 해야한다.
    ```kotlin
    import strings.lastChar as last
    
    val c = "Kotlin".last()
    ```
- 확장 함수로 유틸리티 함수 정의
```kotlin
fun <T> Collection<T>.joinToString(
    separator: String = ", ",
    prefix: String = "",
    postfix: String = ""
): String {
    val result = StringBuilder(prefix)
    
    for ((index,element) in this.withIndex()) {
        if (index > 0) result.append(separator)
        result.append(element)
    }
    result.append(postfix)
    return result.toString()
}
```
- 문자열 컬렉션에 대해서만 호출할 수 있게 하려면
```kotlin
fun Collection<String>.join(
    separator: String = ", ",
    prefix: String = "",
    postfix: String = ""
) = joinToString(separator, prefix, postfix)
```
- 확장함수는 오버라이드 할 수 없다.
    - 코틀린은 호출될 확장 함수를 정적으로 결정하기 때문이다.

## 확장 프로퍼티
- 프로퍼티라는 이름으로 불리기는 하지만 상태를 저장할 방법이 없어 아무 상태도 가질 수 없다.
- 뒷받침하는 필드가 없어서 기본 Getter 구현을 제공할 수 없어서 최소한 Getter는 정의를 해야 한다.
```kotlin
val String.lastChar: Char
    get() = get(length - 1)
    
var StringBuilder.lastChar: Char
    get() = get(length - 1)
    set(value: Char) {
        this.setCharAt(length - 1, value)
    }
```
- 자바에서 확장 프로퍼티를 사용하고 싶다면 항상 StringUtilKt.getLastChar("Java")
처럼 Getter와 Setter를 명시적으로 호출해야 한다.

## 컬렉션 처리
- 가변인자 함수
```kotlin
//다음과 같이 함수를 호출할 때 원하는 만큼 원소를 전달할 수 있다.
val list = listOf(2, 3, 5, 7, 11)
```
- 이는 다음과 같이 정의한다.
```java
fun listOf<T>(vararg values: T): List<T> { ... }
```
- 자바에서는 배열을 그냥 넘기면 되지만, 코틀린에서는 배열을 명시적으로 풀어서
배열의 각 원소가 인자로 전달되게 해야 한다.
- 스프레드 연산자가 이러한 역할을 해준다.
```kotlin
fun main(args: Array<String>) {
    val list = listOf("args: ", *args)
    println(list)
}
```
- 중위 호출
-     val map = mapOf(1 to "one", 7 to "seven", 53 to "fifty-three")
- to라는 단어는 코틀린 키워드가 아니라, 중위 호출이라는 특별한 방식으로
to라는 일반 메소드를 호출한 것이다.
- 중위 호출 시에는 수신 객체와 유일한 메소드 인자 사이에 메소드 이름을 넣는다.
- 다음은 to 함수의 정의를 간략하게 줄인 코드다.
-     infix fun Any.to(other: Any) = Pair(this, other)
- 이 to 함수는 Pair의 인스턴스를 반환한다.
    - Pair는 코틀린 표준 라이브러리 클래스
    - 두 원소로 이뤄진 순서쌍을 표현한다
-         val(number, name) = 1 to "one"
- Pair의 내용으로 두 변수를 즉시 초기화할 수 있다.
    - 이런 기능을 구조 분해 선언 이라고 부른다.
```kotlin
for ((index, element) in collection.withIndex()) {
    println("$index: $element")
}
```
-     fun <K, V> mapOf(vararg values: Pair<K, V>): Map<K, V>

## 문자열과 정규식
>코틀린 문자열은 자바 문자열과 같다.
 다양한 확장 함수를 제공한다.
1. 문자열 나누기
    - 코틀린에서는 자바의 split 대신에 여러 다른 조합의 파라미터를 받는 split 확장 함수를 제공한다.
        - 정규식을 파라미터로 받는 함수는 Regex 타입의 값을 받는다.
    -     println("12.345-6.A".split("\\.|-".toRegex())
    -     println("12.345-6.A".split(".","-"))
2. 정규식과 3중 따옴표로 묶은 문자열
- String 확장 함수
```kotlin
fun parsePath(path: String) {
    val directory = path.substringBeforeLast("/")
    val fullName = path.substringAfterLast("/")
    val fileName = fullName.substringBeforeLast(".")
    val extension = fullName.substringAfterLast(".")
    println("Dir: $directory, name: $fileName, ext: $extension")
}
```
- 정규식과 3중 따옴표 문자열 사용
```kotlin
fun parsePath(path: String) {
    val regex = """(.+)/(.+)\.(.+)""".toRegex()
    val matchResult = regex.matchEntire(path)
    if (matchResult != null) {
        val (directory, filename, extension) = matchResult.destructured
        println("Dir: $directory, name: $filename, ext: $extension")
    }
}
```
- 여러 줄 3중 따옴표 문자열
    - 3중 따옴표 문자열에는 들여쓰기나 줄 바꿈을 포함한 모든 문자가 들어간다.
```kotlin
val kotlinLogo = """|  //
                   .| //
                   .|/ \"""
println(kotlinLogo.trimMargin("."))
// trimMargin(".")를 이용해 3중 "."와 그 직전의 공백을 제거해서 출력한다.
```
- 문자열 템플릿을 넣을 때
    - 문자열 템플릿의 시작을 표현하는 $를 3중 따옴표 문자열 안에 넣을 수 없다는 문제가 생긴다.
    - 3중 따옴표 안에 \$를 넣어야 한다면 문자열 템플릿 안에 $를 넣어야 한다.
    -     val price = """${'$'}99.9"""
- 3중 따옴표 문자열은 테스트의 예상 출력을 작성할 때 가장 완벽한 해법이다.

## 로컬 함수와 확장
> 많은 개발자들이 좋은 코드의 중요한 특징 중 하나가 중복이 없는 것이라 믿는다.
DRY(Don't Repeat Yourself)라는 문구도 있다. 자바 코드를 작성할 때, 메소드 추출 리팩토링을 하면,
작은 메소드가 많아지고 각 메소드 사이의 관계를 파악하기 힘들어서 코드를 이해하기 어려워 질 수 있다.

- 코틀린에서는 함수에서 추출한 함수를 원 함수 내부에 중첩시킬 수 있다.
```kotlin
// 필드 검증 코드 중복
class User(val id: Int, val name: String, val address: String)

fun saveUser(user: User) {
    if (user.name.isEmpty()) {
        throw IllegalArgumentException(
        "Cant't save user ${user.id}: empty Name")
    }
    if (user.address.isEmpty()) {
        throw IllegalArgumentException(
        "Cant't save user ${user.id}: empty Address")
    }
}
```
- 검증 코드를 로컬 함수로 분리한다.
```kotlin
class User(val id: Int, val name: String, val address: String)

fun saveUser(user: User) {
    fun validate(user: User,
                value: String,
                fieldName: String) {
        if (value.isEmpty()) {
            throw IllegalArgumentException(
            "Can't save user ${user.id}: empty $fieldName")
        }
    }
    validate(user, user.name, "Name")
    validate(user, user.address, "Address")
}
```
- 로컬 함수는 자신이 속한 바깥함수의 모든 파라미터와 변수를 사용할 수 있다.
```kotlin
class User(val id: Int, val name: String, val address: String)

fun saveUser(user: User) {
    fun validate(value: String, fieleName: String) {
        if (value.isEmpty()) {
            throw IllegalArgumentException(
            "Can't save user ${user.id}: " +
            "empty $fieldName")
        }
    }
    validate(user.name, "Name")
    validate(user.address, "Address")
}
```
- 검증 로직을 User 클래스를 확장한 함수로
```kotlin
class User(val id: Int, val name: String, val address: String)

fun User.validateBeforeSave() {
    fun validate(value: String, fieldName: String) {
        if (value.isEmpty()) {
            throw IllegalArgumentException(
            "Can't save user $id: empty $fieldName")
        }
    }
    validate(name, "Name")
    validate(address, "Address")
}

fun saveUser(user: User) {
    user.validateBeforeSave()
}
```

