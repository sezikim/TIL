# 클래스
## 클래스 계층 정의
- 코틀린 인터페이스는 자바 8 인터페이스와 비슷하다.
- 추상 메소드뿐 아니라 구현이 있는 메소드도 정의할 수 있다.
- 다만, 인터페이스에 아무런 필드도 들어갈 수 없다.
```kotlin
// 간단한 인터페이스
interface Clickable {
    fun click()
}
```
```kotlin
// 간단한 인터페이스 구현
class Button : Clickable {
    override fun click() = println("I was clicked")
}

>>> Button().click()
```
- 클래스 이름 뒤에 콜론(:)을 붙이고 인터페이스와 클래스 이름을 적어서 구현과 확장 처리
- 자바와 마찬가지로 인터페이스는 제한 없이 구현, 클래스는 오직 하나만 확장
- 코틀린에서는 override 변경자를 꼭 사용해야 한다.
    - override 변경자는 실수로 상위 클래스의 메소드를 오버라이드하는 경우를 방지한다.
- 인터페이스 메소드도 디폴트 구현을 제공할 수 있다.
    - 메소드 시그니처 뒤에 메소드 본문을 추가
```kotlin
interface Clickable {
    fun click()
    fun showOff() = println("I'm clickable!")
}
```
- 여러 인터페이스를 함께 구현 시, 같은 메소드 시그니처를 갖는 디폴트 메소드가 있을경우 오버라이딩 하지 않으면 컴파일 오류 발생.
```kotlin
class Button : Clickable, Focusable {
    override fun click() = println("I was clicked")
    override fun showOff() {
        super<Clickable>.showOff()
        super<Focusable>.showOff()
    }
}
```
- super 앞에 기반 타입을 적지만, 코틀린에서는 super<Clickable>.showOff() 처럼 꺾쇠 괄호 안에 기반타입 이름을 지정한다.

## open, final, abstract 변경자: 기본적으로 final
> 자바에서는 final로 명시적으로 상속을 금지하지 않는 모든 클래스를 상속할 수 있다.

- 취약한 기반 클래스 (fragile base class)
    - 기반 클래스를 변경하는 경우, 하위 클래스의 동작이 예기치 않게 바뀔 수도 있다.
        - '취약'하다.
    - **"상속을 위한 설계와 문서를 갖추거나, 그럴 수 없다면 상속을 금지하라"**, Effective Java
    - 코틀린의 클래스와 메소드는 기본적으로 **final**이다
- 어떤 클래스의 상속을 허용하려면 앞에 **open** 변경자를 붙여야 한다.
    - 메소드나 프로퍼티도 마찬가지
```kotlin
open class RichButton : Clickable {
    fun disable() {}    // final, 하위 클래스에서 오버라이드 불가
    open fun animate() {}   // 하위 클래스에서 오버라이드 가능
    final override fun click() {} // 상위 클래스의 open 메소드를 오버라이드
                        // 하위 클래스에서 오버라이드 불가
}
```
- abstract 클래스
    - 추상 멤버는 항상 열려있다.
    - 하위 클래스에서 추상 멤버를 오버라이드 해야만 하는게 보통이다.
```kotlin
abstract class Animated {
    abstract fun animate()  // 추상 메소드. 하위 클래스에서 반드시 오버라이드 해야한다.
    open fun stopAnimating() {} // 비추상 메소드는 기본적으로 final 이지만 open으로 오버라이드 허용 가능
    fun animateTwice() {}
}
```
## 가시성 변경자 (접근 제어자)
> 클래스 구현에 대한 접근을 제한함으로써 그 클래스에 의존하는 외부 코드를 깨지 않고도 클래스 내부 구현을 변경할 수 있다.

- 코틀린의 기본 가시성은 **public**
- **internal**이라는 새로운 가시성 변경자를 도입
    - 모듈 내부에서만 볼 수 있음
    - 코틀린은 패키지를 namespace를 관리하기 위한 용도로만 사용해, 패키지를 가시성 제어에 사용하지 않는다.
- 코틀린은 최상위 선언에 대해 private 가시성을 허용한다.

|변경자|클래스 멤버|최상위 선언|
|---|---|---|
|public(기본 가시성)|모든 곳에서 볼 수 있다.|모든 곳에서 볼 수 있다.|
|internal|같은 모듈 안에서만 볼 수 있다.|같은 모듈 안에서만 볼 수 있다.|
|protected|하위 클래스 안에서만 볼 수 있다.|최상위 선언에 적용할 수 없음|
|private|같은 클래스 안에서만 볼 수 있다.|같은 파일 안에서만 볼 수 있다.|
```kotlin
internal open class TakativeButton : Focusable {
    private fun yell() = println("Hey!")
    protected fun whisper() = println("Let's talk!")
}

fun TalkativeButton.giveSpeech() {  // public 멤버가 internal 을 호출해서 오류
    yell()  // private에 접근해서 오류
    whisper()   // protected에 접근해서 오류
}
```
## 내부 클래스와 중첩 클래스
- 코틀린의 중첩 클래스는 명시적으로 요청하지 않는 한 바깥쪽 클래스 인스턴스에 대한 접근 권한이 없다.
```kotlin
interface State: Serializable

interface View {
    fun getCurrentState(): State
    fun restoreState(state: State) {}
}
```
```kotlin
class Button : View {
    override fun getCurrentState() : State = ButtonState()
    override fun restoreState(state: State) {/*..*/}
    class ButtonState : State {/*..*/}
}
```
- 코틀린 중첩 클래스에 아무런 변경자가 붙지 않으면 자바 static 중첩 클래스와 같다.
- 바깥쪽 클래스에 대한 참조를 포함하게 만들고 싶다면 inner 변경자를 붙여야 한다.
    - 내부 클래스에서 바깥쪽 클래스의 참조에 접근하려면 this@Outer라고 써야 한다.
    ```kotlin
    class Outer {
        inner class Inner {
            fun getOuterReference(): Outer = this@Outer
        }
    }
    ```
## 봉인된 클래스
- 클래스 계층 정의 시, 계층 확장 제한
```kotlin
interface Expr
class Num(val value: Int) : Expr
class Sum(val left: Expr, val right: Expr) : Expr
fun eval(e: Expr) : Int = 
    when (e) {
        is Num -> e.value
        is Sum -> eval(e.right) + eval(e.left)
        else ->     // else 분기가 꼭 있어야 한다.
            throw IllegalArgumentException("Unknown expression")
    }
```
- when을 사용해 Expr 타입의 값을 검사할 때, 꼭 디폴트 분기인 else 분기를 덧붙인다.
    - 디폴트 분기가 없으면 when이 모든 경우를 처리하는지 제대로 검사할 수 없다.
- **sealed** 클래스를 통해 상위 클래스를 상속한 하위 클래스 정의를 제한할 수 있다.
    - **sealed** 클래스의 하위 클래스를 정의할 때 같은 파일 안에 있어야 한다.
    - sealed로 표시된 클래스는 자동으로 open이다.
    - 내부적으로 봉인된 클래스는 private 생성자를 갖는다.
    ```kotlin
    sealed class Expr
    class Num(val value: Int) : Expr()
    class Sum(val left: Expr, val right: Expr) : Expr()
    
    fun eval(e: Expr): Int =
        when (e) {
            is Expr.Num -> e.value
            is Expr.Sum -> eval(e.right) + eval(e.left)
        }
    ```
## 뻔하지 않은 생성자와 프로퍼티를 갖는 클래스
- 코틀린은 주 생성자와 부 생성자를 구분한다.
    - 주 생성자
        - 클래스를 초기화할 때 주로 사용하는 간략한 생성자, 클래스 본문 밖에서 정의
    - 부 생성자
        - 클래스 본문 안에서 정의

## 클래스 초기화 - 주 생성자와 초기화 블록
      class User(val nickname: String)
- 클래스 이름 뒤에 오는 괄호로 둘러싸인 코드를 주 생성자 라고 부른다.
- 주 생성자는 생성자 파라미터를 지정하고, 그 생성자 파라미터에 의해 초기화되는 프로퍼티를 정의하는 두 가지 목적에 쓰인다.
```kotlin
class User constructor(nickname: String) {
    val nickname: String
    init {
        // 객체가 만들어질 때 실행될 코드
        this.nickname = nickname
    }
}
```
- 별다른 annotation이나 변경자가 없다면 constructor를 생략해도 된다.
```kotlin
class User(nickname: String) {
    this.nickname = nickname
}
```
- 주 생성자의 파라미터로 프로퍼티를 초기화 한다면, 파라미터 이름앞에 val를 추가하는 방식으로 간략히 쓸 수 있다.
```kotlin
class User(val nickname: String)
```
- 함수 파라미터와 마찬가지도 생성자 파라미터에도 디폴트 값을 정의할 수 있다.
```kotlin
class User(val nickname: String, val isSubscribed: Boolean = true)
```
- 클래스에 기반 클래스가 있다면 주 생성자에서 기반 클래스의 생성자를 호출해야 할 필요가 있다.
```kotlin
open class User(val nickname: String) {...}
class TwitterUser(nickname: String) : User(nickname) {...}
```
## 부 생성자 : 상위 클래스를 다른 방식으로 초기화
- 인자에 대한 디폴트 값을 제공하기 위해 부 생성자를 여럿 만들지 말라. 대신 파라미터의 디폴트 값을 생성자 시그니처에 직접 명시하라.
- 클래스에 주 생성자가 없다면 반드시 상위 클래스를 초기화하거나 다른 생성자에게 생성을 위임해야 한다.
```kotlin
open class View {
    constructor(ctx: Context) {
        
    }
    
    constructor(ctx: Context, attr: AttributeSet) {
        
    }
}
```
```kotlin
class MyButton : View {
    constructor(ctx: Context): super(ctx) {
        
    }
    constructor(ctx: Context, attr: AttributeSet) : super(ctx) {
        
    }
}
```
```kotlin
class MyButton : View {
    constructor(ctx: Context): this(ctx, MY_STYLE) {
        
    }
    constructor(ctx: Context), attr: AttributeSet): super(ctx,attr) {
        
    }
}
```

## 인터페이스에 선언된 프로퍼티 구현
- 코틀린에서는 인터페이스에 추상 프로퍼티 선언을 넣을 수 있다.
```kotlin
interface User {
    val nickname: String
}
```
- 이는 User 인터페이스를 구현하는 클래스가 nickname의 값을 얻을 수 있는 방법을 제공해야 한다는 뜻이다.
- 인터페이스는 아무 상태도 포함할 수 없으므로 상태를 저장할 필요가 있다면 인터페이스를 구현한 하위 클래스에서 상태 저장을 위한 프로퍼티 등을 만들어야 한다.
```kotlin
class PrivateUser(override val nickname: String) : User
class SubscribingUser(val email: String) : User {
    override val nickname: String
        get() = email.substringBefore('@')
}
class FacebookUser(val accountId: Int) : User {
    override val nickname = getFacebookName(accountId)
}
```
- 인터페이스에는 추상 프로퍼티뿐 아니라 게터와 세터가 있는 프로퍼티를 선언할 수 도 있다.
    - 물론 게터와 세터를 뒷받침하는 필드를 참조할 수 없다.
    ```kotlin
    interface User {
        val email: String
        val nickname: String
            get() = email.substringBefore('@')
    }
    ```
    - 하위 클래스는 추상 프로퍼티인 email을 반드시 오버라이드 해야한다
        - nickname은 오버라이드하지 않고 상속할 수 있다.

## 게터와 세터에서 뒷받침하는 필드에 접근
> 값을 저장하는 동시에 로직을 실행할 수 있게 하기 위해서는 접근자 안에서 프로퍼티를 뒷받침하는 필드에 접근할 수 있어야 한다.

- 프로퍼티에 저장된 값의 변경 이력을 로그에 남기는 경우
```kotlin
class User(val name: String) {
    var address: String = "unspecified"
        set(value: String) {
            println("""
                Address was changed for $name: "$field" -> "$value".""".trimIndent())
            field = value
        }
}
```
- 접근자 본문에서는 field라는 특별한 식별자를 통해 뒷받침하는 필드에 접근할 수 있다.
    - get에서는 field 값을 읽고, set에서는 field값을 읽거나 쓸 수 있다.

## 접근자의 가시성 변경
- 접근자 가시성은 기본적으로 프로퍼티의 가시성과 같다.
```kotlin
class LengthCounter {
    var counter: Int = 0
        private set // 클래스 밖에서 프로퍼티 값을 밖을 수 없다.
    fun addWord(word: String) {
        counter += word.length
    }
}
```

## 모든 클래스가 정의해야 하는 메소드
> 코틀린 클래스도 toString, equals, hashCode 등 오버라이드할 수 있다.

- toString()
    ```kotlin
    class Client(val name: String, val postalCode: Int) {
        override fun toString() = "Client(name=$name, postalCode=$postalCode"
    }
    ```
- equals()
    ```kotlin
    class Client(val name: String, val postalCode: Int) {
        override fun equals(other: Any?): Boolean {
            if (other === null) //other가 null인지 검사
                return false
            
            if (this === other) //같은 객체를 참조하는지 검사
                return true
            
            if (other.javaClass !== Client::class.java)   // other가 Client 타입인지 검사
                return false
            
            other as User
            
            return name == other.name && postalCode == other.postalCode  // 두 객체의 프로퍼티 값이 같은지 검사
        }
    }
    - 코틀린의 is검사는 자바의 instanceof와 같다.
- hashCode()
> JVM 언어에서는 equals()가 true를 반환하는 두 객체는 반드시 같은 hashCode()를 반환해야 한다.
- hashCode()를 오버라이딩 해야 한다.
```kotlin
class Client(val name: String, val postalCode: Int) {
    override fun hashCode(): Int = name.hashCode() * 31 + postalCode
}
```

## 데이터 클래스
> 필요한 메소드를 컴파일러가 자동으로 만들어준다.
```kotlin
data class Client(val name: String, val postalCode: Int)
```
- 이는 이와 같은 메소드들을 포함한다
    - equals
    - hashCode
    - toString
    - copy
    - component
    
## copy
- data 클래스의 모든 프로퍼티를 읽기 전용으로 만들어서 데이터 클래스를 불변 클래스로 만드는게 권장사항이다.
    - HashMap 등의 컨테이너에 데이터 클래스 객체를 담는 경우엔 불변성이 필수적이다.
        - 불변이 아니면 컨테이너 상태가 잘못될 수 있다.
    - 스레드를 동기화할 필요가 줄어든다.
- copy 메소드를 사용하면 객체를 복사하면서 일부 프로퍼티를 바꿀 수 있다.
    - 원본을 참조하는 다른 부분에 영향이 없다.
    ```kotlin
    fun copy(name: String = this.name, postalCode: Int = this.postalCode) = 
        Client(name, postalCode)
        
    >>> val kim = Client("김현준", 6867)
    >>> println(kim.copy(postalCode=6887)
    //
    Client(name=김현준, postalCode=6887)
    ```
    
## 클래스 위임 by
> 대규모 객체지향 시스템을 설계할 때, 시스템을 취약하게 만드는 문제는 보통 구현 상속에 의해 발생한다.
- 상속을 허용하지 않는 클래스에 새로운 동작을 추가 할 때, 데코레이터 패턴을 사용한다.
    - 새로운 클래스를 만들되 기존 클래스와 같은 인터페이스를 데코레이터가 제공, 기존 클래스를 데코레이터 내부 필드로 유지
    - 새로 정의해야 하는 기능은 데코레이터 메소드에 정의, 기존 기능은 데코레이터 메소드가 기존 클래스 메소드에게 요청을 전달
    - 준비 코드가 상당히 많이 필요하다.
    ```kotlin
    class DelegatingCollection<T> : Collection<T> {
        private val innerList = arrayListOf<T>()
        
        override val size: Int get() = innerList.size
        override fun isEmpty(): Boolean = innerList.isEmpty()
        override fun contains(element: T): Boolean = innerList.contains(element)
        override fun iterator(): Iterator<T> = innerList.iterator()
        override fun containsAll(elements: Collection<T>): Boolean = innerList.containsAll(elements)
    }
    ```

- **by** 키워드를 통해 인터페이스에 대한 구현을 다른 객체에 위임중이라는 사실을 명시할 수 있다.
```kotlin
class DelegatingCollection<T>(
    innerList: Collection<T> = ArrayList<T>()
) : Collection<T> by innerList {}
```
- 메소드 중 일부의 동작을 변경하고 싶은 경우 메소드를 오버라이드하면 된다.
```kotlin
class CountingSet<T>(val innerSet: MutableCollection<T> = HashSet<T>()) : MutableCollection<T> by innerSet {
    var objectsAdded = 0
    
    override fun add(element: T): Boolean {
        objectsAdded++
        return innerSet.add(element)
    }
    
    override funaddAll(c: Collection<T>): Boolean {
        objectsAdded += c.size
        return innerSet.addAll(c)
    }
}
```

## object 키워드
- 코틀린에서는 object 키워드를 다양한 상황에서 사용한다
- 클래스를 정의하면서 동시에 인스턴스를 생성한다.

## 싱글턴을 쉽게 만들기
- 코틀린은 객체 선언 기능을 통해 싱글턴을 기본 지원한다.
    - 객체 선언은 클래스 선언과 그 클래스에 속한 단일 인스턴스의 선언을 합친 선언이다.
    - 싱글턴 객체는 객체 선언문이 있는 위치에서 생성자 호출 없이 즉시 만들어진다. -> 생성자 정의가 필요 없다.
    ```kotlin
    object Payroll {
        val allEmployees = arrayListOf<Person>()
        fun calculateSalary() {
            for (person in allEmployees) {
                ...
            }
        }
    }
    ```
    ```kotlin
    Payroll.allEmployees.add(Person(...))
    Payroll.calculateSalary()
    ```
- 객체 선언도 클래스나 인스턴스를 상속할 수 있다.
    - 프레임워크를 사용하기 위해 특정 인터페이스를 구현해야 하는데, 그 구현 내부에 다른 상태가 필요하지 않은 경우에 유용하다
    ```kotlin
    object CaseInsensitiveFileComparator : Comparator<File> {
        override fun compare(file1: File, file2: File): Int {
            return file1.path.compareTo(file2.path, ignoreCase = true)
        }
    }
    ```
    ```kotlin
    println(CaseInsensitiveFileComparator.compare(File("/User"), File("/User")))
    ```
- 클래스 안에서 객체를 선언할 수도 있다.
    - 그런 객체도 인스턴스는 단 하나뿐이다.
        - 바깥 클래스의 인스턴스마다 중첩 객체 선언에 해당하는 인스턴스가 따로 생기는 것이 아니다.
```kotlin
data class Person(val name: String) {
    object NameComparator : Comparator<Person> {
        override fun compare(p1: Person, p2: Person): Int = p1.name.compareTo(p2.name)
    }
}
```
```kotlin
val persons = listOf(Person("Bob"), Person("Alice"))
println(persons.sortedWith(Person.NameComparator))
```

## 동반 객체
- 코틀린 언어는 자바 static 키워드를 지원하지 않는다.
    - 코틀린은 패키지 수준의 최상위 함수, 객체 선언을 활용한다.
- 최상위 함수는 private으로 표시된 클래스 비공개 멤버에 접근할 수 없다.
    - 클래스 내부 정보에 접근해야 하는 함수가 필요할 때, 중첩된 객체 선언의 멤버 함수로 정의해야 한다.
- 클래스 안에 정의된 객체 중 하나에 **companion** 키워드를 붙이면 그 클래스를 동반 객체로 만든다.
    - 동반 객체의 멤버를 사용하는 구문은 자바의 정적 메소드 호출이나 정적 필드 사용 구문과 같아진다.
    - 동반 객체의 프로퍼티나 메소드에 접근하려면 그 동반 객체가 정의된 클래스 이름을 사용한다.
    ```kotlin
    class A {
        companion object {
            fun bar() {
                println("Companion object called")
            }
        }
    }
    ```
- 동반 객체는 자신을 둘러싼 클래스의 모든 private 멤버에 접근할 수 있다.
    - 동반 객체는 팩토리 패턴을 구현하기 가장 적합한 위치다.
    ```kotlin
    class User {
        constructor(email: String) {
            nickname = email.substringBefore('@')
        }
        
        constructor(facebookAccountId: Int) {
            nickname = getFacebookName(facebookAccountId)
        }
    }
    ```
    - 팩토리 메소드로
    ```kotlin
    class User private Constructor(val nickname: String) {
        companion object {
            fun newSubscribingUser(email: String) = User(email.substringBefore('@'))
            fun newFacebookUser(accountId: Int) =
            User(getFacebookName(accountId))
        }
    }
    ```
    - 목적에 따라 팩토리 메소드 이름을 정할 수 있다.
    - 팩토리 메소드는 선언된 클래스의 하위 클래스 객체를 반환할 수도 있다.
    - 새 인스턴스를 만들지 않고 캐시에 있는 기존 인스턴스를 반환할 수 있다.
## 동반 객체를 일반 객체처럼 사용
- 동반 객체에 이름을 붙이거나, 동반 객체가 인터페이스를 상속하거나, 동반 객체 안에 확장 함수와 프로퍼티를 정의할 수 있다.
- 상속
```kotlin
class Person(val name: String) {
    companion object Loader {
        fun fromJSON(jsonText: String): Person =...
    }
}
```
- 구현
```kotlin
interface JSONFactory<T> {
    fun fromJSON(jsonText: String): T
}
class Person(val name: String) {
    companion object : JSONFactory<Person> {
        override fun fromJSON(jsonText: String): Person = ...
    }
}
```
- JSON으로부터 각 원소를 다시 만들어내는 추상 팩토리가 있다면 Person 객체를 그 팩토리에게 넘길 수 있다.

## 동반 객체 확장
```kotlin
class Person(val firstName: String, val lastName: String) {
    companion ojbect {
    }
}

fun Person.Companion.fromJSON(json: String): Person {
    ...
}

val p = Person.fromJSON(json)
```

## 객체 식
> 무명 내부 클래스를 다른 방식으로 작성
```kotlin
window.addMoustListener(
    object : MouseAdapter() {
        override fun mouseClicked(e: MouseEvent) {
            //...
        }
        override fun mouseEntered(e: MouseEvent) {
            /...
        }
    }
)
```
- 객체에 이름을 붙여야 한다면 변수에 무명 객체를 대입한다.
```kotlin
val listener =
    object : MouseAdapter() {
        override fun mouseClicked(e: MouseEvent) { ... }
        override fun mouseEntered(e: MouseEvent) { ... }
    }
```
- 코틀린은 자바와 달리 여러 인터페이스를 구현하거나 클래스를 확장할 수 있다.
- 자바와 달리 final이 아닌 변수도 객체 식 안에서 사용할 수 있다.
```kotlin
fun countClicks(window: Window) {
    var clickCount = 0
    window.addMouseListener(object: MouseAdapter() {
        override fun mouseClicked(e: MouseEvent) {
            clickCount++
        }
    })
    //...
}
```
