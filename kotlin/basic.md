# 함수
- 함수 선언은 **`fun`** 키워드로 시작한다.
- 다음에는 함수 이름, 함수 파라미터, 함수 반환 타입 순이며, 콜론(:)으로 구분한다.
- 코틀린 if는 문장이 아니고 결과를 만드는 식이다.
```kotlin
fun max(a: Int, b: Int): Int {
    return if (a > b) a else b
}
```

## 식이 본문인 함수
- 본문이 중괄호로 둘러싸인 함수를 **블록이 본문인 함수**라고 부르고, 등호와 식으로 이뤄진 함수를 **식이 본문인 함수**라고 부른다.
- 식이 본문인 함수는, 컴파일러가 타입을 분석해 프로그래머 대신 프로그램 구성 요소의 타입을 정해준다.
    - 이를 **타입 추론**이라고 부른다.
```kotlin
fun max(a: Int, b: Int) : Int = if (a > b) a else b
```

# 변수
- 코틀린은 타입 지정을 생략하는 경우가 흔하다.
- 초기화를 하지 않고 변수를 선언하려면, 변수 타입을 반드시 명시해야 한다.
```kotlin
val question =
    "삶, 우주, 그리고 모든 것에 대한 궁극적인 질문"
val answer = 42

////
val answer: Int
answer = 42
```
## 변경 가능한 변수, 변경 불가능한 변수
- val
    - 변경 불가능한 참조를 저장하는 변수
    - 자바로 말하면 final 변수
    - val 참조 자체는 불변이라도, 참조가 가리키는 객체의 내부 값은 변경될 수 있다.
- var
    - 변경 가능한 참조.
    - 자바의 일반 변수
- 기본적으로 모든 변수를 val 키워드로 선언하고 꼭 필요한 경우에 var로 변경한다.

## 문자열 템플릿
- 문자열 리터럴의 필요한 곳에 변수를 넣되 변수 앞에 $를 추가한다.
- 문자열 템플릿 안에 사용할 수 있는 대상은 중괄호로 둘러싸서 문자열 템플릿 안에 넣을 수 있다.
```kotlin
fun main(args: Array<String>) {
    val name = if (args.size > 0) args[0] else "Kotlin"
    println("Hello, $name!")
}

fun main(args: Array<String>) {
    if (args.size > 0) {
        println("Hello, ${args[0]}!")
    }
}

fun main(args: Array<String>) {
    println("Hello, ${if (args.size > 0) args[0] else "someone"}!)
}
```

# 클래스와 프로퍼티
```kotlin
class Person(val name: String)
```
- 코틀린은 자바의 생성자 등의 필드 대입 로직을 훨씬 더 적은 코드로 작성할 수 있다.
- 코틀린의 기본 가시성은 public이다.

## 프로퍼티
- 자바에서는 필드와 접근자를 한데 묶어 프로퍼티(Property) 라고 부르며, 프로퍼티라는 개념을 활용하는 프레임워크가 많다.
- 코틀린 프로퍼티는 자바의 필드와 접근자 메소드를 완전히 대신한다.
- 코틀린의 name 프로퍼티를 자바에서 getName이라는 이름으로 볼 수 있다.
    - 이름이 is로 시작하는 프로퍼티의 Getter에는 원래 이름을 그대로 사용한다.
    - Setter는 is를 set으로 바꾼 이름을 사용한다.
```kotlin
class Person(
    val name: String,           // 읽기전용, Getter를 만듬
    var isMarried: Boolean      // 쓸 수 있음, Getter, Setter를 만듬
)

val person = Person("Bob", true)
println(person.name)
println(person.isMarried)
person.isMarried = false
```

## 커스텀 접근자
- 프로퍼티의 접근자를 직접 작성하는 방법
```kotlin
class Rectangle(val heigh: Int, val width: Int) {
    val isSquare: Boolean
    get() {
        return height == width
    }
    /*
    혹은 get() = height == width
    */
}

fun main() {
    val rec = Rectangle(41, 43)
    println(rec.isSquare)
}
```

## 코틀린의 패키지
- 모든 코틀린 파일의 맨 앞에 package문을 넣을 수 있다.
- 파일 안에 있는 모든 선언(클래스, 함수, 프로퍼티 등)이 해당 패키지에 들어간다.
- 같은 패키지에 속하면, 다른 파일에서 정의한 선언도 직접 사용 가능하다.
- 코틀린에서는 여러 클래스를 한 파일에 넣을 수 있고, 파일의 이름도 마음대로 정할 수 있다.
    - 하지만, 대부분의 경우 자바와 같이 패키지별로 디렉토리를 구성하는 편이 낫다.
- 여러 클래스를 한 파일에 넣는 것을 주저해서는 안 된다.

## enum
- enum class Color {} 와 같이 선언한다.
- enum에서도 일반적인 클래스와 마찬가지로 생성자와 프로퍼티를 선언한다.
- enum 상수를 정의할 때는 그 상수에 해당하는 프로퍼티 값을 지정해야만 한다.
- enum 클래스 안에 메소드를 정의하는 경우 반드시 enum 상수 목록과 메소드 정의 사이에 세미콜론을 넣어야 한다.
```kotlin
enum class Color (
    val r: Int, val g: Int, val b: Int
) {
    RED(255,0,0), ORAGNE(255,165,0),
    YELLOW(255,255,0), GREEN(0,255,0), BLUE(0,0,255),
    INDIGO(75,0,130), VIOLET(238,130,238);
    
    fun rgb() = (r * 256 + g) * 256 + b
}

fun main() {
    println("Hello, world!!!")
    println(Color.BLUE.rgb())
}
```

## when
- 자바의 switch에 해당하는 코틀린 구성 요소
- if 와 마찬가지로 when도 값을 만들어내는 식
- 식이 본문인 함수에 when을 바로 사용할 수 있다.
- 자바와 달리 각 분기의 끝에 break를 넣지 않아도 된다.
- 코틀린의 when의 분기 조건은 임의의 객체를 허용한다.
```kotlin
enum class Color (
    val r: Int, val g: Int, val b: Int
) {
    RED(255,0,0), ORANGE(255,165,0),
    YELLOW(255,255,0), GREEN(0,255,0), BLUE(0,0,255),
    INDIGO(75,0,130), VIOLET(238,130,238);
    
    fun rgb() = (r * 256 + g) * 256 + b
}

fun getMnemonic(color: Color) =
    when (color) {
        Color.RED -> "RICHARD"
        Color.ORANGE -> "OF"
        Color.YELLOW -> "YORK"
        Color.GREEN -> "GAVE"
        Color.BLUE, Color.INDIGO, Color.VIOLET -> "COLD"
    }

fun main() {
    println("Hello, world!!!")
    println(Color.BLUE.rgb())
    println(getMnemonic(Color.BLUE))
}
```
- 인자가 없는 when
    - when에 아무 인자도 없으려면 각 분기의 조건이 boolean 결과를 계산하는 식이어야 한다.
```kotlin
fun mixOptimized(c1: Color, c2: Color) =
    when {
        (c1 == RED && c2 == YELLOW) ||
        (c1 == YELLOW && c2 == RED) ->
            ORANGE
            
        (c1 == YELLOW && c2 == BLUE) ||
        (c1 == BLUE && c2 == YELLOW) ->
            GREEN
        
        else -> throw Exception("Dirty color")
    }
```
- 스마트 캐스트
    - 타입 검사와 타입 캐스트를 조합
    - is를 사용해 변수 타입을 검사
        - is로 검사하고 나면 컴파일러가 캐스팅을 자동으로 수행해줌
        - **스마트 캐스트**라고 부른다.
    - 스마트 캐스트는 is로 변수에 든 값의 타입을 검사한 다음에 그 값이 바뀔 수 없는
    경우에만 작동한다.
```kotlin
interface Expr
class Num(val value: Int) : Expr
class Sum(val left: Expr, val right: Expr) : Expr

fun main() {
    println(eval(Sum(Sum(Num(1), Num(2)), Num(4))))
}

fun eval(e: Expr): Int {
    if (e is Num) {
        // 컴파일러가 e의 타입을 Num으로 해석
        // 스마트 캐스트가 되려면 n은 반드시 val이어야 한다.
        val n = e as Num
        return n.value;
    }
    
    if (e is Sum) {
        // 컴파일러가 e의 타입을 Sum으로 해석
        return eval(e.right) + eval(e.left)
    }
    
    throw IllegalArgumentException("Unknown expression")
}
```

## 이터레이션
- while은 자바와 동일, for는 자바의 for-each 루프에 해당하는 형태만 존재한다.
- 코틀린은 range를 사용한다.
    - 기본적으로 두 값으로 이뤄진 구간
    - **`..`** 연산자로 시작 값과 끝 값을 연결해서 범위를 만든다.
    -     val oneToTen = 1..10
    - 어떤 범위에 속한 값을 일정한 순서로 이터레이션 하는것을 progression이라고 부른다.
```kotlin
interface Expr
class Num(val value: Int) : Expr
class Sum(val left: Expr, val right: Expr) : Expr

fun main() {
    for (i in 1..100) {
        println(fizzBuzz(i))
    }
    for (i in 100 downTo 1 step 2) {
        println(fizzBuzz(i))
    }
}

fun fizzBuzz(i: Int) = when {
    i % 15 == 0 -> "FizzBuzz "
    i % 3 == 0 -> "Fizz "
    i % 5 == 0 -> "Buzz "
    else -> "$i "
}
```
- 맵에 대한 이터레이션
```kotlin
val binaryReps = TreeMap<Char, String>()
for (c in 'A'..'F') {
    val binary = Integer.toBinaryString(c.toInt())
    binaryReps[c] = binary // c를 키로 c의 2진 표현을 맵에 넣는다.
}

for ((letter, binary) in binaryReps) {
    println("$letter = $binary")
}
```
- in 연산자를 사용해 어떤 값이 범위에 속하는지 알 수 있다.
```kotlin
fun isLetter(c: Char) = c in 'a'..'z' || c in 'A'..'Z'  // 'a' <= c && c <= 'z'로 변환된다.
fun isNotDigit(c: Char) = c !in '0'..'9'
```

## 예외처리
- 코틀린의 기본 예외 처리 구문은 자바와 비슷하다.
- 자바와 달리 throw는 식이므로 다른 식에 포함될 수 있다.
```kotlin
val percentage =
    if (number in 0..100)
        number
    else
        throw IllegalArgumentException(
            "A percentage value must be between 0 and 100: $number")
```

- try, catch, finally
    - 자바 코드와 가장 큰 차이는 throws 절이 코드에 없다.
    - 체크 예외와 언체크 예외를 구별하지 않는다.
```kotlin
fun readNumber(reader: BufferReader): Int? {
    try {
        val line = reader.readLine()
        return Integer.parseInt(line)
    }
    catch (e: NumberFormatException) {
        return null
    }
    finally {
        reader.close()
    }
}
```
- try를 식으로 사용
    - 코틀린의 try 키워드는 if나 whten과 마찬가지로 식이다.
    - try 값을 변수에 대입할 수 있다.
    - if와 달리 본문을 반드시 중괄호로 둘러싸야 한다.
```kotlin
fun readNumber(reader: BufferedReader) {
    val number = try {
        Integer.parseInt(reader.nextInt())
    } catch (e: NumberFormatException) {
        null
    }
    println(number)
}
```
