#인터페이스
> 인터페이스는 클래스가 구현해야 할 '기능 명세'
- 인터페이스를 구현할 개체에 공통적인 속성과 함수를 **정의**
- 속성은 초기화하는 코드가 없으며, 함수 abstract function이다.
- 코틀린에서는 인터페이스에 정의된 속성에 기본으로 구현된 게터를, 함수에도 기본으로 구현된 몸체 코드를 제공한다.
```kotlin
interface Fightable {
    var healthPoints: Int
    val diceCount: Int
    val diceSides: Int
    val damageRoll: Int
        get() = (0 until diceCount).map { 
            Random.nextInt(diceSides) + 1
        }.sum()
    
    fun attack(opponent: Fightable): Int
}

```
위 인터페이스를 구현한 클래스
```kotlin
import kotlin.random.Random

interface Fightable {
    var healthPoints: Int
    val diceCount: Int
    val diceSides: Int
    val damageRoll: Int
        get() = (0 until diceCount).map {
            Random.nextInt(diceSides) + 1
        }.sum()

    fun attack(opponent: Fightable): Int
}

class Player(_name: String,
             override var  healthPoints: Int = 100,
             var isBlessed:Boolean = false,
             private var isImmortal: Boolean) : Fightable {
    override val damageRoll = 0
    override val diceCount = 3
    override val diceSides = 6

    override fun attack(opponent: Fightable): Int {
        val damageDealt = if (isBlessed) {
            damageRoll * 2
        } else {
            damageRoll
        }
        opponent.healthPoints -= damageDealt
        return damageDealt
    }
}
```
- 상속과 마찬가지로 인터페이스에 정의된 것을 구현하는 클래스의 속성과 함수에는 override 키워드를 지정한다.
    - open 키워드를 지정하지는 않는다.

## 추상클래스
- 인터페이스와 비슷하게 추상 함수와 속성을 갖는다.
- 구현 코드가 있는 일반 함수도 가질 수 있다.
- 상속을 하는것이 주 목적이다. 인스턴스를 생성할 수 없다.
- abstract 키워드로 정의
```kotlin
abstract class Monster(val name: String,
                       val description: String,
                       override var healthPoints: Int) : Fightable {
    override fun attack(opponent: Fightable): Int {
        val damageDealt = damageRoll
        opponent.healthPoints -= damageDealt
        return damageDealt
    }
}
```

## 인터페이스 vs 추상클래스
- 공통점
    - 공통 속성과 함수를 정의할 수 있다.
    - 둘 다 인스턴스화 할 수 없다.
- 차이점
    - 인터페이스는 약한 결합을 만든다.
        - 관련성이 덜한 클래스들의 공통적인 기능을 구현할 때 사용한다.
            - 특정 데이터의 기능을 명시하는데 사용된다.
    - 추상클래스는 강한 결합을 만든다.
        - 관련성이 높은 클래스 간의 상속 관계를 만들 때 사용한다.
    - 인터페이스는 다중 상속이 가능하다.
