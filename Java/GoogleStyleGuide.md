> 구글의 자바 코딩 스타일처럼 코딩하자.

# 소스파일 기본사항
## 파일 이름
- 소스파일 이름은 해당 이름에 포함된 최상위 클래스의 대/소문자를 구분한다
## 파일 인코딩은 UTF-8
- 공백문자
    - 아스키코드 수평 공간 문자는 소스 파일의 모든 위치에 나타나는 유일한 공백 문자.
    - 탭 문자는 들여쓰기에 사용X
- 이스케이프 시퀀스
    - \b, \t, \n, \f, \r, \", \' 사용을 지향하고 \012, \u000a(8진수나 12진수 이스케이프)사용을 지양한다.
- 아스키 문자가 아닌 문자만 유니코드를 사용한다.

## 원본 파일 구조
- 다음과 같은 순서로 소스파일을 작성.
    ```
    1. 라이센스 및 저작권 정보
    
    2. package statement
    
    3. import statements
    
    4. 하나의 최상위 클래스
    
    한줄 씩 띄워서 작성한다.
    ```
- 라이센스 및 저작권 정보
    - 있으면 작성
- package statements
    - not line-wrapped
- import statements
    - wildcard statements 사용X
    - not line-wrapped
    - 모든 static import는 한 블럭에
    - 모든 non-static import도 한 블럭에
- 클래스 선언
    - 하나의 최상위 클래스 선언
    - 각각의 클래스의 Content는 논리적인 순서가 같아야 한다.
        - 생성자, 메소드가 오버로드 되었을 때, 사이에 다른 코드를 넣지 않는다.
## Format
- 괄호
    - if, else, for, do, while의 다음 내용이 비어있거나, 하나의 statement만 가져도 괄호를 사용한다.
    - 괄호를 열때 앞에 개행 X
    - 괄호를 열고 개행
    - 괄호를 닫기 전에 개행
    - else나 comma가 있을 시, 괄호를 닫고 개행 X
    - if/else나 try/catch/finally가 아니면 {}같이 사용 x
    - 블록 사용시 2 space 만큼 들여쓰기
    - 한줄에 한 statement
    - column limit은 100 characters로 제한
        - package, import statement 제외
        - 긴 URL이나 메소드 참조 제외
        - 주석 내의 명령어 라인 제외
- 변수 선언
    - 변수 선언은 한번에 한개만
        for loop 내에서는 여러개 가능
    - 변수 선언은 필요한 곳에서 가능하다.
- 배열
    - c스타일로 String args[] 와 같이 선언 X
- switch
    - 스위치문 들여쓰기는 2space
- 접근 제어자
     - 다음과 같은 순으로 작성
     - public protected private abstract default static final transient volatile synchronized native strictfp
- long 리터럴
    - 뒤에 L suffix를 꼭 붙이자
    - l 안됨
## Naming
- 모든 identifiers에 special prefix나 suffix 사용 X
- 패키지명은 전부 소문자
- 클래스명은 UpperCamelCase
- 메소드명은 lowerCamelCase
- 상수명은 전부 대문자
- 필드명은 lowerCamelCase
- 인자도 lowerCamelCase
- 지역변수도 lowerCamelCase

## Programming Practices
- @Override는 항상사용
    - Deprecated일 때 제외
- 예외처리는 항상 해주자.
- static member에 접근할 때는, 클래스명으로 접근
- finalize 사용X
