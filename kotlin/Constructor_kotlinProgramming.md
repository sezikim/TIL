# 초기화
> 코틀린에는 여러 생성자를 통해 객체를 만드는 방법이 있다.

## 기본 생성자
> 코틀린의 기본 생성자

```kotlin
class Player(_name: String,
            _healthPoints: Int,
            _isBlessed: Boolean,
            _isImmortal: Boolean) {
    var name = _name
        get() = field.captalize()
        private set(value) {
            field = value.trim()
        }
        
    var healthPoints = _healthPoints
    val isBlessed = _isBlessed
    private val isImmortal = _isImmortal
}
```
기본 생성자에 속성을 정의할 수 있다.
```kotlin
class Player(_name: String, var healthPoints: Int,
                val isBlessed: Boolean,
                private val isImmortal: Boolean) {
    var name = _name
        get() = field.capitalize()
        private set(value) {
            field = value.trim()
        }
}
```

## 보조 생성자
> 두 개 이상의 생성자가 필요할 때 사용한다.
- 보조 생성자에서 필요한 값만 인자로 받는다.
    - 나머지 속성에 초기값이 주어진다.
```kotlin
class Player(_name: String, var healthPoints: Int,
                val isBlessed: Boolean,
                private val isImmortal: Boolean) {
    var name = _name
        get() = field.capitalize()
        private set(value) {
            field = value.trim()
        }
    
    constructor(name: String) : this(name, 
                                    healthPoints = 100,
                                    isBlessed = true,
                                    isImmortal = false)
}
```
기본 생성자와 보조 생성자로 객체를 만들 때의 차이점
```kotlin
fun main() {
    val primaryPlayer = Player("Madrigal", 89, true, false)
    val secondaryPlayer = Player("Madrigal")
}
```

## 기본 인자
> 생성자를 정의할 때 인자의 기본값을 지정할 수 있다. 
- 함수의 기본 인자와 동일한 개념
```kotlin
class Player(_name: String,
            var healthPoints: Int = 100,    
            val isBlessed: Boolean,
            private val isImmortal: Boolean) {
    var name = _name
    get() = field.capitalize()
    private set(value) {
        field = value.trim()
    }
    
    constructor(name: String) : this(name, isBlessed = true,
                                isImmortal = false) {
                                    if (name.toLowerCase() == "Kar") healthPoints = 40
                                    }
}
```
다음과 같은 생성자들로 객체를 생성할 수 있다.
```kotlin
Player("Madrigal", 64, true, false) // primaryConstructor
Player("Madrigal", true, false) // 기본 인자
Player("Madrigal") // secondaryConstructor
```

## 지명 인자
> 기본 인자가 많아질수록 생성자를 호출할 때, 가독성이 떨어진다.
- 생성자 호출 시, 매개변수 이름을 포함시켜 호출한다.
- 매개변수가 정의된 순서와 다르게 인자를 전달할 수 있다.
```kotlin
val player = Player("Madrigal", 100, true, false)
// 어떤 종류의 데이터를 담고 있는지 판별하기 어렵다.
// -> 다음과 같이 매개변수 이름을 포함

val player = Player(name = "Madrigal",
                    healthPoints = 100
                    isBlessed = true
                    isImmortal = false)
```

## 초기화 블록
> 코틀린에는 기본과 보조 생성자 외에, 속성값의 검사와 설정을 할 수 있는 초기화 블록이 있다.
- 인스턴스 생성될 때, 자동으로 호출되어 실행
- 초기화 블록에서 사용되는 모든 속성은 초기화 블록이 정의되기 전에 초기화되도록 해야 한다.
```kotlin
class Player(_name: String,
            var healthPoints: Int = 100,    
            val isBlessed: Boolean,
            private val isImmortal: Boolean) {
    var name = _name
    get() = field.capitalize()
    private set(value) {
        field = value.trim()
    }
    
    init {
        require(healthPoints > 0, { "healthPoints는 0보다 커야 합니다."})
        require(name.isNotBlank(), {"플레이어는 이름이 있어야 합니다."})
    }
    
    constructor(name: String) : this(name, isBlessed = true,
                                isImmortal = false) {
                                    if (name.toLowerCase() == "Kar") healthPoints = 40
                                    }
}
```
위의 코드로 인스턴스 생성 시, healthPoints가 0 이하 이거나, name 값이 공백으로 주어지면 IllegalArgumentException이 발생한다.

## 속성 초기화
> 생성자에 포함되지 않는 속성을 정의하면, 반드시 초기화 해주어야 한다.
```kotlin
class PropertyInit(_name: String) {
    var name = _name
        get() = "${field.capitalize()} of $hometown"
    val hometown: String = selectHometown()
    
    // data 디렉토리의 도시 목록들이 쓰여있는 towns.txt 파일 사용
    private fun selectHometown() = File("data/towns.txt")
            .readText()
            .split("\n")
            .shuffled()
            .first()
}
```
## 초기화 지연시키기
> 생성자 호출 시점을 제어할 수 없는 경우가 있다. 대표적인 사례가 안드로이드 같은 외부 프레임워크다.
1. lateinit
    - 해당 속성을 사용하기 전에 초기화 해야한다.
        - 초기화전에 사용된다면 UninitializedPropertyAccessException 발생
    - var이면서 non-nullable 타입에서만 사용할 수 있다.
    ```kotlin
    class Wheel {
        lateinit var alignment: String
        
        fun initAlignment() {
            alignment = "Good"
        }
        
        fun printAlignment() {
            if (::alignment.isInitialized) println(alignment)
        }
    }
    ```
2. lazyinit
    - 속성이 초기화 될 때, 다수의 객체를 초기화해야 하거나, 여러 가지 작업이 수반될 때 사용한다.
    - 코틀린에서는 delegation을 사용해서 구현한다.
        - by 키워드를 통해 위임받은 일을 처리하는 delegate를 지정
    ```kotlin
    class PropertyInit(_name: String) {
        var name = _name
            get() = "${field.capitalize()} of $hometown"
        val hometown by lazy { selectHometown() }
        // 코드에서 최초 사용될 때, lazy 함수의 람다가 실행되어 초기화
        
        // data 디렉토리의 도시 목록들이 쓰여있는 towns.txt 파일 사용
        private fun selectHometown() = File("data/towns.txt")
                .readText()
                .split("\n")
                .shuffled()
                .first()
    }
    ```
