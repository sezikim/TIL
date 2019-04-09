# 스트림
> 스트림은 자바 8부터 추가된 컬렉션의 저장 요소를 하나씩 참조해서 람다식(함수적 스타일)으로
처리할 수 있도록 해주는 반복자이다.

## 스트림의 특징
>Stream은 Iterator와 비슷한 역할을 하는 반복자이지만, **람다식으로 요소 처리 코드**를 제공하는
점과 **내부 반복자를 사용하므로 병렬 처리가 쉽다**는 점 그리고 중간 처리와 최종 처리 작업을
수행하는 점에서 많은 차이를 가지고 있다.
- 스트림 생성 -> 중간 처리 -> 최종 처리
-   객체 집합( 대표적으로 Collection).스트림생성.중간 처리.최종 처리;
    이와 같이 계속해서 "." 로 연계할 수 있어 파이프라인 이라고 한다.

|종류||리턴타입|메소드|소속된 인터페이스|
|---|---|---|---|---|
|중간처리|필터링|Stream IntStream LongStream DoubleStream|distinct()|공통|
|중간처리|필터링|Stream IntStream LongStream DoubleStream|filter(...)|공통|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|flatMap(...)|공통|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|flatMapToDouble(...)|Stream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|flatMapToInt(...)|Stream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|flatMapToLong(...)|Stream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|map(...)|공통|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|mapToDouble(...)|Stream, IntStream, LongStream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|mapToInt(...)|Stream, LongStream, DoubleStream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|mapToLong(...)|Stream, IntStream, DoubleStream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|mapToObj(...)|IntStream, LongStream, DoubleStream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|asDoubleStream()|IntStream, LongStream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|asLongStream|IntStream|
|중간처리|매핑|Stream IntStream LongStream DoubleStream|boxed()|IntStream, LongStream, DoubleStream|
|중간처리|정렬|Stream IntStream LongStream DoubleStream|sorted(...)|공통|
|중간처리|루핑|Stream IntStream LongStream DoubleStream|peek(...)|공통|
|최종처리|매칭|boolean|allMatch(...)|공통|
|최종처리|매칭|boolean|anyMatch(...)|공통|
|최종처리|매칭|boolean|noneMatch(...)|공통|
|최종처리|집계|long|count()|공통|
|최종처리|집계|OptionalXXX|findFirst()|공통|
|최종처리|집계|OptionalXXX|max(...)|공통|
|최종처리|집계|OptionalXXX|min(...)|공통|
|최종처리|집계|OptionalDouble|average()|IntStream, LongStream, DoubleStream|
|최종처리|집계|OptionalXXX|reduce(...)|공통|
|최종처리|집계|int, long, double|sum()|IntStream, LongStream, DoubleStream|
|최종처리|루핑|void|forEach(...)|공통|
|최종처리|수집|R|collect(...)|공통|

## 중간 처리
- 필터링
    - 요소를 걸러내는 역할
    - distinct(), filter()
- 매핑
    - 요소를 다른 요소로 대체하는 작업
    - flatXXX(), mapXXX(), asDoubleStream(), asLongStream(), boxed()
- 정렬
    - 최종 처리 전에 중간 단게에서 요소를 정령해서 최종 처리 순서를 변경할 수 있다.
    - sorted()
- 루핑
    - 중간 처리 단계에서 전체 요소를 루핑하면서 추가적인 작업을 하기 위해 사용
    - 최종 처리 메소드가 실행되지 않으면 지연된다. ( 반드시 최종 처리 메소드가 호출되어야 동작 )
    - peek()

## 최종 처리
- 루핑
    - 파이프라인 마지막에 루핑하면서 요소를 하나씩 처리
    - 요소를 소비하는 최종 처리 메소드이므로 이후에 sum()과 같은 다른 최종 메소드를 호출하면 안된다.
    - forEach()
- 매칭
    - 최종 처리 단계에서 요소들이 특정 조건에 만족하는지 조사
    - allMatch(), anyMatch(), noneMatch()
- 집계
    - 요소들을 처리해서 카운팅, 합계, 평균값, 최대, 최소 등과 같이 하나의 값으로 산출
    - 대량의 데이터를 가공해서 축소하는 리덕션(Reduction)
    - count(), findFirst(), max(), min(), average(), sum()
    - Optional 클래스
        - 집계 값이 존재하지 않을 경우 디폴트 값을 설정, 집계 값을 처리하는 Consumer도 등록가능
        - isPresent(), orElse(), ifPresent()
- 수집
    - 스트림은 요소들을 필터링 또는 매핑한 후 수집하는 최종 처리 메소드인 collect()를 제공한다.
    - 요소들을 그룹핑한 후 집계
    - collect()
```java
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class ToListExample {
    public static void main(String[] args) {
        List<Student> totalList = Arrays.asList(
                new Student("홍길동", 10, Student.Sex.MALE),
                new Student("김수애", 6, Student.Sex.FEMALE),
                new Student("신용권", 10, Student.Sex.MALE),
                new Student("박수미", 6, Student.Sex.FEMALE)
        );
        
        //남학생들만 묶어 List 생성
        List<Student> maleList = totalList.stream()
                .filter(s->s.getSex()==Student.Sex.MALE)
                .collect(Collectors.toList());
        maleList.stream()
                .forEach(s -> System.out.println(s.getName()));

        System.out.println();
        
        //여학생들만 묶어 HashSet 생성
        Set<Student> femaleSet = totalList.stream()
                .filter(s->s.getSex() == Student.Sex.FEMALE)
                .collect(Collectors.toCollection(HashSet::new));
        femaleSet.stream()
                .forEach(s -> System.out.println(s.getName()));
    }
}
```
```java
public class Student {
    public enum Sex {MALE, FEMALE}
    public enum City {Seoul, Pusan}

    private String name;
    private int score;
    private Sex sex;
    private City city;

    public Student(String name, int score, Sex sex) {
        this.name = name;
        this.score = score;
        this.sex = sex;
    }

    public Student(String name, int score, Sex sex, City city) {
        this.name = name;
        this.score = score;
        this.sex = sex;
        this.city = city;
    }

    public String getName() { return name; }
    public int getScore() { return score; }
    public Sex getSex() { return sex; }
    public City getCity() { return city; }
}
```

## 사용자 정의 컨테이너에 수집하기
    collect(Supplier<R>, XXXConsumer<R>, BiConsumer<R, R>)
- 첫 번째 Supplier는 요소들이 수집될 컨테이너 객체R을 생성.
- 두 번째 XXXConsumer는 컨테이너 객체R에 요소T를 수집하는 역할 ( 수집할 때마다 XXXConsumer 실행 )
- 세 번째 BiConsumer는 컨테이너 객체R을 결합하는 역할 ( 병렬 처리 스트림에서만 호출 )
```java
//남학생이 저장되는 컨테이너
MaleStudent maleStudent = totalList.stream()
        .filter(s->s.getSex == Student.Sex.MALE)
        .collect(MaleStudent :: new, MaleStudent :: accumulate, MaleStudent :: combine);
```

## 요소를 그룹핑해서 수집
    groupingByXXX(Function<T, K> classifier)
    - T를 K로 매핑하고 K키에 저장된 List에 T를 지정한 Map 생성
    groupingByXXX(Function<T, K> classifier, Collector<T, A, D> collector)
    - T를 K로 매핑하고 K키에 저장된 D객체에 T를 누적한 Map 생성
    groupingByXXX(Function<T, K> classifier, Supplier<XXXMap<K, D>> mapFactory, Collector<T, A, D> collector)
    - T를 K로 매핑하고 Supplier가 제공하는 Map에서 K키에 저장된 D객체에 T를 누적
    ```java
    Map<Student.City, List<String>> mapByCity = totalList.stream()
        .collect(
            Collectors.groupingBy(
                Student::getCity,
                Collectors.mapping(Student::getName, Collectors.toList())
        );
    ```

## 그룹핑 후 매핑 및 집계
- Collectors.groupingBy() 메소드는 그룹핑 후, 매핑이나 집계를 할 수 있도록 
두 번째 매개값으로 Collector를 가질 수 있다.
```java
Map<Student.Sex, Double> mapBySex = totalList.stream()
    .collect(
        Student::getSex,
        Collectors.averageDouble(Student::getScore)
    );
```

## 스트림과 병렬처리
> 병렬 처리란 멀티 코어 CPU 환경에서 하나의 작업을 분할해서 각각의 코어가 병렬적으로
처리하는 것을 말하는데, 병렬 처리의 목적은 작업 처리 시간을 줄이기 위한 것이다.
자바 8부터 요소를 병렬 처리할 수 있도록 하기 위해 병렬 스트림을 제공하기 때문에 컬렉션의
전체 요소 처리 시간을 줄여 준다.

- 동시성과 병렬성
    - 동시성 : 멀티 작업을 위해 싱글 스레드가 번갈아가며 실행하는 성질
    - 병렬성 : 멀티 작업을 위해 멀티 코어를 이용해 동시에 실행하는 성질
        - 데이터 병렬성
            - 전체 데이터를 쪼개어 서브 데이터로 만들고, 서브 데이터들을 병렬 처리해서 작업을 빨리 끝내는 것
            - 자바 8에서 지원하는 병렬 스트림은 데이터 병렬성을 구현한 것
            - 멀티 코어의 수만큼 대용량 요소를 서브 요소들로 나누고, 분리된 스레드에서 병렬 처리
        - 작업 병렬성
            - 서로 다른 작업을 병렬 처리하는 것
            - 대표적으로 웹 서버의 각각 브라우저에서 요청한 내용을 개별 스레드에서 병렬로 처리
```java
MaleStudent maleStudent = totalList.parallelStream()
    .filter(s->s.getSex == Student.Sex.MALE)
    .collect(MaleStudent::new, MaleStudent::accumulate, MaleStudent::combine);
```

