>정적 팩토리 메소드와 생성자에는 똑같은 제약이 있다. 선택적 매개변수가 많을때 적절히 대응하기 어렵다는 점이다.
프로그래머들은 이럴 때, 점층적 생성자 패턴을 즐겨 사용했다. 하지만 이는 매개변수 개수가 많아지면 클라이언트
코드를 작성하거나 읽기 어렵다.

## 점층적 생성자 패턴
- 필수 매개변수만 받는 생성자 부터, 매개변수를 전부다 받는 생성자까지 늘려가는 방식
- 클래스를 불변으로 만든다.
- 안정성이 높다.
- 확장하기 어렵다.
```java
public class NutritionFacts {
    private final int servingSize;
    private final int servings;
    private final int calories;
    private final int fat;
    private final int sodium;
    private final int carbohydrate;
    
    public NutritionFacts(int servingSzie, int servings) {
        this(servingSize, servings, 0);
    }
    public NutritionFacts(int servingSzie, int servings, int calories) {
        this(servingSize, servings, calories, 0);
    }
    public NutritionFacts(int servingSzie, int servings, int calories,
                        int fat) {
        this(servingSize, servings, calories, fat, 0);
    }
    public NutritionFacts(int servingSzie, int servings, int calories,
                        int fat, int sodium) {
        this(servingSize, servings, calories, fat, sodium, 0);
    }
    public NutritionFacts(int servingSzie, int servings, int calories,
                        int fat, int sodium, int carbohydrate) {
        this.servingSize = servingSize;
        this.servings = servings;
        this.calories = caloires;
        this.fat = fat;
        this.sodium = sodium;
        this.carbohydrate = carbohydrate;
    }
}
```
```java
NutritionFacts cocaCola = new NutritionFacts(240, 8, 100, 0, 35, 27);
```
## 자바빈즈 패턴
- 매개변수가 없는 생성자를 객체로 만든 후, Setter 메소드들을 호출해 원하는 값을 설정하는 방식
- 가독성이 좋다
- 객체 하나를 만드려면 메소드를 여러개 호출해야 한다, 객체가 완전히 생성되기 전에는 일관성이 무너진 상태
- 클래스를 불변으로 만들 수 없다.
```java
public class NutritionFacts {
    private int servingSize = -1;
    private int servings = -1;
    private int calories = 0;
    private int fat = 0;
    private int sodium = 0;
    private int carbohydrate = 0;
    
    public NutritionFacts() { }
    
    public void setServingSize(int val) { servingSize = val; }
    public void setServings(int val) { servings = val; }
    public void setCalories(int val) { calories = val; }
    public void setFat(int val) { fat = val; }
    public void setSodium(int val) { sodium = val; }
    public void setCarbohydrate(int val) { carbohydrate = val; }
}
```
```java
NutritionFacts cocaCola = new NutritionFacts();
cocaCola.setServingSize(240);
cocaCola.setServings(8);
cocaColat.setCaloires(100);
cocaCola.setSodium(35);
cocaCola.setCarbohydrate(27);
```
# 빌더 패턴
- 점층적 생성자 패턴의 안전성, 자바빈즈 패턴의 가독성
- 필요한 객체를 직접 만들고, 매개변수만으로 생성자(혹은 정적 팩토리 메소드)를 호출해 빌더 객체를 얻는다.
```java
public class NutritionFacts {
    private final int servingSize;
    private final int servings;
    private final int calories;
    private final int fat;
    private final int sodium;
    private final int carbohydrate;
    
    public static class Builder {
        private final int servingSize;
        private final int servings;
        
        private int calories = 0;
        private int fat = 0;
        private int sodium = 0;
        private int carbohydrate = 0;
        
        public Builder(int servingSzie, int servings) {
            this.servingSize = servingSize;
            this.servings = servings;
        }
        
        public Builder calories(int val) {
            calories = val; return this;
        }
        public Builder fat(int val) {
            fat = val; return this;
        }
        public Builder sodium(int val) {
            sodium = val; return this;
        }
        public Builder carbohydrate(int val) {
            carbohydrate = val; return this;
        }
        
        public NutritionFacts build() {
            return new NutritionFacts(this);
        }
    }
    
    private NutritionFacts(Builder builder) {
        servingSize = builder.servingSize;
        servings = builder.servings;
        calories = builder.calories;
        fat = builder.fat;
        sodium = builder.sodium;
        carbohydrate = builder.carbohydrate;
    }
}
```
```java
NutritionFacts cocaCola = new NutritionFacts.Builder(240, 8).
                            calories(100).sodium(35).carbohydrate(27).build();
// 빌더의 setter 메소드들이 빌더 자신을 반환하기 때문에 연쇄적으로 호출 가능
// 플루언트 API 혹은 메소드 연쇄라 한다.
// 빌더 패턴은 파이썬과 스칼라에 있는 명명된 선택적 매갭변수를 흉내 낸 것이다.
```
- 빌더 패턴은 계층적으로 설계된 클래스와 함께 쓰기에 좋다.
- 추상 클래스 - 추상 빌더, 구체 클래스 - 구체 빌더
```java
public abstract class Pizza {
    public enum Topping { HAM, MUSHROOM, ONION, PEPPER, SAUSAGE }
    final Set<Topping> toppings;
    
    abstract static class Builder<T extends Builder<T>> {
        EnumSet<Topping> toppings = EnumSet.noneOf(Topping.class);
        public T addTopping(Topping topping) {
            toppings.add(Objects.requireNonNull(topping));
            return self();
        }
        
        abstract Pizza build();
        
        // 하위 클래스는 이 메서드를 재정의(overriding)하여
        // "this"를 반환하도록 해야 한다.
        protected abstract T self();
    }
    
    Pizza(Builder<?> builder) {
        toppings = builder.toppings.clone();
    }
}
```
