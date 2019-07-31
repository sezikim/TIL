## null 안전과 예외
> 코틀린에서는 nullable이 아니면 null값을 가질 수 없다.
null 값으로 생기는 문제를 컴파일 시점에 방지할 수 있다.

- `Type?`과 같이 표현한다.
- nullable과 non-nullable은 다른 타입이다.
```kotlin
fun main() {
    var beverage = readLine().capitalize()
}
```
- capitalize()는 non-nullable에 사용 가능한 함수여서, 위 코드를 실행하면 컴파일 에러가 발생한다.
    1. nullable 타입을 처리하기 위해 safe call operator인 `?.`를 사용한다
        ```kotlin
         var beverage = readLine()?.capitalize()
        ```
        - 런타임에 readLine 함수의 반환값이 null이면 capitalize 함수가 호출 되지 않고 그 다음 코드를 수행한다.
            - NullPointerException 방지
        - **let 함수**를 사용해서 변수에 새로운 값을 지정하거나 다른 함수를 호출하는 등 추가 작업을 수행할 수 있다.
        ```kotlin
        var beverage = readLine()?.let {
                if (it.isNotBlank()) {
                    it.capitalize()
                } else {
                    "맥주"
                }
            }
        ```
        - let 함수 에서는 it 키워드를 사용할 수 있다.
        - let 함수 인자로 전달된 익명 함수에서 마지막으로 실행된 표현식의 결과를 반환한다.
    2. non-null assertion operation `!!`를 사용한다.
        ```kotlin
        var beverage = readLine!!.capitalize()
        ```
        - 왼쪽의 피연산자 값이 null이 아니면 정상적으로 코드를 수행하고, null이면 런타임 시에 NullPointerException 예외를 발생시킨다.
        - 컴파일러가 null 발생을 미리 알 수 없는 상황일 때 사용한다.
            - nullable 타입의 변수값이 null이 아닌지 한 함수에서 확인한 후 다른 함수에서 사용할 때
            - 시스템 라이브러리 변수를 참조하거나 함수들을 호출할 때 언제 발생할지 모르는 NullPointerException을 명시적으로 파악하고자 할 때
    3. if로 null체크
        ```kotlin
        var beverage = readLine()
        
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
        ```
        - **if와 != 연산자를 사용하는 것보다는 안전 호출 연산자를 사용하는 것이 좋다**
            - 가독성이 좋다.
    4. 엘비스 연산자 `?:`
        - 검사값이 null일때 null이 아닌 기본값을 제공한다.
        - 피연산자의 결과가 null이면 오른쪽의 피연산자를 실행, null이면 왼쪽 피연산자의 결과를 반환
        ```kotlin
        var beverage = readLine()
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
    
        val beverageServed: String = beverage ?: "맥주"
        ```ble이 아니면 null값을 가질 수 없다.
null 값으로 생기는 문제를 컴파일 시점에 방지할 수 있다.

- `Type?`과 같이 표현한다.
- nullable과 non-nullable은 다른 타입이다.
```kotlin
fun main() {
    var beverage = readLine().capitalize()
}
```
- capitalize()는 non-nullable에 사용 가능한 함수여서, 위 코드를 실행하면 컴파일 에러가 발생한다.
    1. nullable 타입을 처리하기 위해 safe call operator인 `?.`를 사용한다
        ```kotlin
         var beverage = readLine()?.capitalize()
        ```
        - 런타임에 readLine 함수의 반환값이 null이면 capitalize 함수가 호출 되지 않고 그 다음 코드를 수행한다.
            - NullPointerException 방지
        - **let 함수**를 사용해서 변수에 새로운 값을 지정하거나 다른 함수를 호출하는 등 추가 작업을 수행할 수 있다.
        ```kotlin
        var beverage = readLine()?.let {
                if (it.isNotBlank()) {
                    it.capitalize()
                } else {
                    "맥주"
                }
            }
        ```
        - let 함수 에서는 it 키워드를 사용할 수 있다.
        - let 함수 인자로 전달된 익명 함수에서 마지막으로 실행된 표현식의 결과를 반환한다.
    2. non-null assertion operation `!!`를 사용한다.
        ```kotlin
        var beverage = readLine!!.capitalize()
        ```
        - 왼쪽의 피연산자 값이 null이 아니면 정상적으로 코드를 수행하고, null이면 런타임 시에 NullPointerException 예외를 발생시킨다.
        - 컴파일러가 null 발생을 미리 알 수 없는 상황일 때 사용한다.
            - nullable 타입의 변수값이 null이 아닌지 한 함수에서 확인한 후 다른 함수에서 사용할 때
            - 시스템 라이브러리 변수를 참조하거나 함수들을 호출할 때 언제 발생할지 모르는 NullPointerException을 명시적으로 파악하고자 할 때
    3. if로 null체크
        ```kotlin
        var beverage = readLine()
        
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
        ```
        - **if와 != 연산자를 사용하는 것보다는 안전 호출 연산자를 사용하는 것이 좋다**
            - 가독성이 좋다.
    4. 엘비스 연산자 `?:`
        - 검사값이 null일때 null이 아닌 기본값을 제공한다.
        - 피연산자의 결과가 null이면 오른쪽의 피연산자를 실행, null이면 왼쪽 피연산자의 결과를 반환
        ```kotlin
        var beverage = readLine()
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
    
        val beverageServed: String = beverage ?: "맥주"
        ```ble이 아니면 null값을 가질 수 없다.
null 값으로 생기는 문제를 컴파일 시점에 방지할 수 있다.

- `Type?`과 같이 표현한다.
- nullable과 non-nullable은 다른 타입이다.
```kotlin
fun main() {
    var beverage = readLine().capitalize()
}
```
- capitalize()는 non-nullable에 사용 가능한 함수여서, 위 코드를 실행하면 컴파일 에러가 발생한다.
    1. nullable 타입을 처리하기 위해 safe call operator인 `?.`를 사용한다
        ```kotlin
         var beverage = readLine()?.capitalize()
        ```
        - 런타임에 readLine 함수의 반환값이 null이면 capitalize 함수가 호출 되지 않고 그 다음 코드를 수행한다.
            - NullPointerException 방지
        - **let 함수**를 사용해서 변수에 새로운 값을 지정하거나 다른 함수를 호출하는 등 추가 작업을 수행할 수 있다.
        ```kotlin
        var beverage = readLine()?.let {
                if (it.isNotBlank()) {
                    it.capitalize()
                } else {
                    "맥주"
                }
            }
        ```
        - let 함수 에서는 it 키워드를 사용할 수 있다.
        - let 함수 인자로 전달된 익명 함수에서 마지막으로 실행된 표현식의 결과를 반환한다.
    2. non-null assertion operation `!!`를 사용한다.
        ```kotlin
        var beverage = readLine!!.capitalize()
        ```
        - 왼쪽의 피연산자 값이 null이 아니면 정상적으로 코드를 수행하고, null이면 런타임 시에 NullPointerException 예외를 발생시킨다.
        - 컴파일러가 null 발생을 미리 알 수 없는 상황일 때 사용한다.
            - nullable 타입의 변수값이 null이 아닌지 한 함수에서 확인한 후 다른 함수에서 사용할 때
            - 시스템 라이브러리 변수를 참조하거나 함수들을 호출할 때 언제 발생할지 모르는 NullPointerException을 명시적으로 파악하고자 할 때
    3. if로 null체크
        ```kotlin
        var beverage = readLine()
        
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
        ```
        - **if와 != 연산자를 사용하는 것보다는 안전 호출 연산자를 사용하는 것이 좋다**
            - 가독성이 좋다.
    4. 엘비스 연산자 `?:`
        - 검사값이 null일때 null이 아닌 기본값을 제공한다.
        - 피연산자의 결과가 null이면 오른쪽의 피연산자를 실행, null이면 왼쪽 피연산자의 결과를 반환
        ```kotlin
        var beverage = readLine()
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
    
        val beverageServed: String = beverage ?: "맥주"
        ```ble이 아니면 null값을 가질 수 없다.
null 값으로 생기는 문제를 컴파일 시점에 방지할 수 있다.

- `Type?`과 같이 표현한다.
- nullable과 non-nullable은 다른 타입이다.
```kotlin
fun main() {
    var beverage = readLine().capitalize()
}
```
- capitalize()는 non-nullable에 사용 가능한 함수여서, 위 코드를 실행하면 컴파일 에러가 발생한다.
    1. nullable 타입을 처리하기 위해 safe call operator인 `?.`를 사용한다
        ```kotlin
         var beverage = readLine()?.capitalize()
        ```
        - 런타임에 readLine 함수의 반환값이 null이면 capitalize 함수가 호출 되지 않고 그 다음 코드를 수행한다.
            - NullPointerException 방지
        - **let 함수**를 사용해서 변수에 새로운 값을 지정하거나 다른 함수를 호출하는 등 추가 작업을 수행할 수 있다.
        ```kotlin
        var beverage = readLine()?.let {
                if (it.isNotBlank()) {
                    it.capitalize()
                } else {
                    "맥주"
                }
            }
        ```
        - let 함수 에서는 it 키워드를 사용할 수 있다.
        - let 함수 인자로 전달된 익명 함수에서 마지막으로 실행된 표현식의 결과를 반환한다.
    2. non-null assertion operation `!!`를 사용한다.
        ```kotlin
        var beverage = readLine!!.capitalize()
        ```
        - 왼쪽의 피연산자 값이 null이 아니면 정상적으로 코드를 수행하고, null이면 런타임 시에 NullPointerException 예외를 발생시킨다.
        - 컴파일러가 null 발생을 미리 알 수 없는 상황일 때 사용한다.
            - nullable 타입의 변수값이 null이 아닌지 한 함수에서 확인한 후 다른 함수에서 사용할 때
            - 시스템 라이브러리 변수를 참조하거나 함수들을 호출할 때 언제 발생할지 모르는 NullPointerException을 명시적으로 파악하고자 할 때
    3. if로 null체크
        ```kotlin
        var beverage = readLine()
        
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
        ```
        - **if와 != 연산자를 사용하는 것보다는 안전 호출 연산자를 사용하는 것이 좋다**
            - 가독성이 좋다.
    4. 엘비스 연산자 `?:`
        - 검사값이 null일때 null이 아닌 기본값을 제공한다.
        - 피연산자의 결과가 null이면 오른쪽의 피연산자를 실행, null이면 왼쪽 피연산자의 결과를 반환
        ```kotlin
        var beverage = readLine()
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
    
        val beverageServed: String = beverage ?: "맥주"
        ```l 값으로 생기는 문제를 컴파일 시점에 방지할 수 있다.

- `Type?`과 같이 표현한다.
- nullable과 non-nullable은 다른 타입이다.
```kotlin
fun main() {
    var beverage = readLine().capitalize()
}
```
- capitalize()는 non-nullable에 사용 가능한 함수여서, 위 코드를 실행하면 컴파일 에러가 발생한다.
    1. nullable 타입을 처리하기 위해 safe call operator인 `?.`를 사용한다
        ```kotlin
         var beverage = readLine()?.capitalize()
        ```
        - 런타임에 readLine 함수의 반환값이 null이면 capitalize 함수가 호출 되지 않고 그 다음 코드를 수행한다.
            - NullPointerException 방지
        - **let 함수**를 사용해서 변수에 새로운 값을 지정하거나 다른 함수를 호출하는 등 추가 작업을 수행할 수 있다.
        ```kotlin
        var beverage = readLine()?.let {
                if (it.isNotBlank()) {
                    it.capitalize()
                } else {
                    "맥주"
                }
            }
        ```
        - let 함수 에서는 it 키워드를 사용할 수 있다.
        - let 함수 인자로 전달된 익명 함수에서 마지막으로 실행된 표현식의 결과를 반환한다.
    2. non-null assertion operation `!!`를 사용한다.
        ```kotlin
        var beverage = readLine!!.capitalize()
        ```
        - 왼쪽의 피연산자 값이 null이 아니면 정상적으로 코드를 수행하고, null이면 런타임 시에 NullPointerException 예외를 발생시킨다.
        - 컴파일러가 null 발생을 미리 알 수 없는 상황일 때 사용한다.
            - nullable 타입의 변수값이 null이 아닌지 한 함수에서 확인한 후 다른 함수에서 사용할 때
            - 시스템 라이브러리 변수를 참조하거나 함수들을 호출할 때 언제 발생할지 모르는 NullPointerException을 명시적으로 파악하고자 할 때
    3. if로 null체크
        ```kotlin
        var beverage = readLine()
        
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
        ```
        - **if와 != 연산자를 사용하는 것보다는 안전 호출 연산자를 사용하는 것이 좋다**
            - 가독성이 좋다.
    4. 엘비스 연산자 `?:`
        - 검사값이 null일때 null이 아닌 기본값을 제공한다.
        - 피연산자의 결과가 null이면 오른쪽의 피연산자를 실행, null이면 왼쪽 피연산자의 결과를 반환
        ```kotlin
        var beverage = readLine()
        if (beverage != null) {
            beverage = beverage.capitalize()
        } else {
            println("beverage가 null입니다!")
        }
    
        val beverageServed: String = beverage ?: "맥주"
        ```
