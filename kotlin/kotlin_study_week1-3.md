## 코틀린의 예외
- 코틀린의 모든 예외는 unchecked 예외이다.
    - 컴파일러가 try/catch문으로 반드시 처리하도록 강요하지 않는다.

## precondition function
> 입력값의 검사와 흔히 생기는 문제의 발견을 쉽게 할 수 있도록 코틀린에서 표준 라이브러리의 일부로 전제 조건 함수를 제공한다.

- checkNotNull, require, requireNotNull, error, assert가 있다.

## 문자열
- 자바와 동일하게 String은 불변이다.
- 문자열 비교는 동등 비교 연산자인 `==`로, 같은 문자열 객체를 참조하는지는 참조 동등 비교 연산자 `===`로
    - 자바에서는 각각 equals, == 연산자로 비교

- 문자열 처리 함수

|함수명|내용|
|---|---|
|substring|인덱스 범위를 인자로 받아 해당 범위 만큼의 문자열을 추출해 반환|
|split|구분자를 인자로 받아, 분리된 각 부분의 문자열을 List로 반환|
|indexOf|문자열에서 찾고자 하는 문자를 인자로 받아 같은 것을 찾은 후 인덱스를 반환|
|replace|정규 표현식과 변경을 위해 정의한 익명 함수를 인자로 받는다. 대체한 문자열을 반환|

# 표준함수
> 코틀린 표준 함수는 내부적으로 확장 함수이며, 확장 함수를 실행하는 주체를 수신자 객체라고 부른다.

## apply
- 구성 함수라 할 수 있다.
```kotlin
val menuFile = File("menu-file.txt")
menuFile.setReadable(true)
menuFile.setWritable(true)
menuFile.setExecutable(false)
```
위와 같은 코드를 apply 함수를 통해 다음과 같이 표현 가능하다.
```kotlin
val menuFile = File("menu-file.txt").apply {
    setReadable(true)
    setWritable(true)
    setExectuable(false)
}
```

## let
- let은 인자로 전달된 람다를 실행한 후 결과를 반환한다.
```kotlin
val firstItemSquared = listOf(1, 2, 3).first().let {
    it * it
}
```
## run
- apply와 동일한 연고나 범위를 제공한다.
    - apply와 다르게 수신자 객체를 반환하지 않는다.
- 함수 연쇄 호출로 중첩된 함수보다 코드를 알기 쉽게 해준다.
```kotlin
fun nameIsLong(name: String) = name.length >= 20
fun playerCreateMessage(nameTooLong: Boolean): String {
    return if (nameTooLong) {
        "Name is too long. Please choose another name."
    } else {
        "Welcome, adventurer"
    }
}

"Polarcubis, Supreme Master of NyetHack"
    .run(::nameIsLong)
    .run(::playerCreateMessage)
    .run(::println)

// 위 코드는 다음과 같다
// println(playerCreateMessage(nameIsLong("Polarcubis, Supreme Master of NyetHack")))
```
## with
- run과 동일하게 동작하지만 호출 방식이 다르다.
    - 수신자 객체를 첫 번째 매개변수의 인자로 받는다.

## also
- let함수와 비슷하게 동작한다.
- also는 람다의 결과를 반환하지 않고 수신자 객체를 반환한다.
```kotlin
var fileContents: List<String>
File("file.txt")
    .also {
        print(it.name)
    }.also {
        fileContents = it.readLines()
    }
}
```

## takeIf
- 람다에 제공된 조건식을 실행한 후,
    - true면 수신자 객체 반환
    - false면 null이 반환
```kotlin
val fileContents = File("myfile.txt")
    .takeIf { it.canRead() && it.canWrite() }
    ?,readText()
```

## takeUnless
- takeIf와 동일하나 조건식이 false 일 때, 원래 값 반환.
