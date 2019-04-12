# IO 패키지
> 단일 방향으로 연속적으로 흘러가는 것.
자바에서 데이터는 스트림(Stream)을 통해 입출력되므로 스트림의 특징을 잘 이해해야 한다.

## InputStream OutputStream
- 자바는 기본적인 데이터 입출력 API를 java.io 패키지로 제공하고 있다.
- InputStream
    - 프로그램이 데이터를 입력받을 때 ( 프로그램을 기준으로 데이터가 들어올 때)
    - 키보드, 파일, 네트워크상의 프로그램
- OutputStream
    - 프로그램이 데이터를 보낼 때 ( 프로그램을 기준으로 데이터가 나갈 때)
    - 모니터, 파일, 네트워크상의 프로그램

## 바이트 기반 스트림, 문자 기반 스트림
> 스트림 클래스는 크게 두 종류로 구분된다.

1. 바이트 기반 스트림
    - 그림, 멀티미디어, 문자 등 모든 종류의 데이터를 받고 보낼 수 있다.
2. 문자 기반 스트림
    - 오로지 문자만 받고 보낼 수 있도록 특화되어 있다.

|구분|바이트 기반 스트림||문자 기반 스트림||
|---|---|---|---|---|
||입력 스트림|출력 스트림|입력 스트림|출력 스트림|
|최상위 클래스|InputStream|OutputStream|Reader|Writer|
|하위 클래스|XXXInputStream(FileInputStream)|XXXOutputStream(FileOutputStream)|XXXReaderFileReader)|XXXWriter(FileWriter)|

## InputStream
- 바이트 기반 입력 스트림의 최상위 클래스
- 추상 클래스
- InputStream 클래스의 주요 메소드
    1. int read()
        - 1바이트를 읽고 4바이트 int 타입으로 리턴
        - 입력 스트림으로부터 바이트를 읽을 수 없다면 -1을 리턴
        ```java
        InputStream is = new FileInputStream("C:/test.jpg");
        int readByte;
        while((readByte=is.read()) != -1) { ... }
        ```
    2. int read(byte[] b)
        - 매개값으로 주어진 바이트 배열의 길이만큼 바이트를 읽고 배열에 저장
        - 읽은 바이트 수 리턴
        - 입력 스트림으로부터 바이트를 읽을 수 없다면 -1을 리턴
        ```java
        InputStream is = new FileInputStream("C:/test.jpg");
        int readByteNo;
        byte[] readBytes = new byte[100];
        while((readByteNo = is.read(readBytes)) != -1) { ... }
        ```
    3. int read(byte[] b, int off, int len)
        - 입력 스트림으로부터 len개의 바이트만큼 읽고 b[off]부터 len개까지 저장
        - 읽은 바이트 수를 리턴
        - 입력 스트림으로부터 바이트를 읽을 수 없다면 -1을 리턴
        ```java
        InputStream is = new FileInputStream("C:/test.jpg");
        byte[] readBytes = new byte[100];
        int readBytesNo = is.read(readBytes, 0, 100);
        ```
    4. void close()
        - 사용한 시스템 자원을 반납하고 입력 스트림을 닫는다.
        ```java
        is.close();
        ```
## OutputStream
- 바이트 기반 출력 스트림의 최상위 클래스
- 추상 클래스
- OutputStream 클래스의 주요 메소드
    1. void write(int b)
        - 출력스트림으로 int 값에서 끝에 있는 1바이트를 보낸다
        ```java
        OutputStream os = new FileOutputStream("C:/test.txt");
        byte[] data = "ABC".getBytes();
        for(int i=0; i<data.length; i++) {
            os.write(data[i]);  //"A", "B", "C"를 하나씩 출력
        }
        ```
    2. void write(byte[] b)
        - 바이트 배열 b의 모든 바이트를 보낸다
        ```java
        OutputStream os = new FileOutputStream("C:/test.txt");
        byte[] data = "ABC".getBytes();
        os.write(data);  //"ABC" 모두 출력
        ```
    3. void write(byte[] b, int off, int len)
        - b[off]부터 len개까지의 바이트를 보낸다
        ```java
        OutputStream os = new FileOutputStream("C:/test.txt");
        byte[] data = "ABC".getBytes();
        os.write(data, 1, 2);   // "BC"만 출력
        ```
    4. void flush()
        - 출력 스트림은 내부에 작은 버퍼가 있어서 데이터가 출력되기 전에 버퍼에 쌓여있다가 순서대로 출력
        - flush()는 잔류하고 있는 데이터를 모두 출력시키고 버퍼를 비운다.
    5. void close()
        - 사용한 시스템 자원을 반납하고 출력 스트림을 닫는다.
        ```java
        OutputStream os = new FileOutputStream("C:/test.txt");
        byte[] data = "ABC".getBytes();
        os.write(data);
        os.flush();
        os.close();
        ```
## Reader
- 문자 기반 입력 스트림의 최상위 클래스
- 추상 클래스
- Reader 클래스의 주요 메소드
    1. int read()
        - 입력 스트림으로부터 한 개의 문자(2바이트)를 읽고 4바이트 int 타입으로 리턴
        - 4바이트 중 끝에 있는 2바이트에 문자 데이터가 들어있다.
        ```java
        char charData = (char) read();
        // 리턴한 int 값을 char 타입으로 변환하면 읽은 문자를 얻을 수 있다.
        ```
    2. int read(char[] buf)
        - 주어진 문자 배열의 길이만큼 문자를 읽고 배열에 저장
        - 읽은 문자 수를 리턴한다.
    3. int read(char[] cbuf, int off, int len)
        - 주어진 문자 배열 cbuf[off]부터 eln개까지 저장
        - 읽은 문자 수를 리턴한다.
    4. void close
        - 사용한 시스템 자원을 반납한다.
## Writer
- 문자 기반 출력 스트림의 최상위 클래스
- 추상 클래스
- Writer 클래스의 주요 메소드
    1. void write(int c)
        - int 갑셍서 끝에 있는 2바이트만 출력 스트림으로 보낸다.
    2. void write(char[] cbuf)
        - cbuf의 모든 문자를 출력 스트림으로 보낸다.
    3. void write(char[] cbuf, int off, int len)
        - cbuf[off]부터 len개의 문자를 출력스트림으로 보낸다.
    4. void write(String str)
        - 문자열 전체를 출력 스트림으로 보낸다.
    5. void write(String str, int off, int len)
        - 문자열 off 순번부터 len개까지의 문자를 보낸다.
    6. flush()
        - 버퍼에 잔류하고 있는 데이터를 모두 출력시키고 버퍼를 비우는 역할
    7. close()
        - 사용한 시스템 자원을 반납한다

# 콘솔 입출력
> 콘솔은 시스템을 사용하기 위해 키보드로 입력을 받고 화면으로 출력하는 소프트웨어

## System.in 필드
> 자바는 프로그램이 콘솔로부터 데이터를 입력받을 수 있도록 System 클래스의 in 정적 필드를 제공
InputStream 타입의 필드이므로 InputStream 변수로 참조가 가능하다.

- 키보드로 부터 어떤 키가 입력되었는지 확인할 때, InputStream의 read() 메소드로 한 바이트를 읽는다.
- 리턴된 int 값에는 십진수 아스키 코드가 들어있다.
- 한글과 같이 2바이트를 필요로하는 유니코드는 read() 메소드로 읽을 수 없다.
    - read(byte[] b, int off, int len) 메소드로 전체 입력내용을 배열로 받고, String 객체를 생성한다.
```java
mport java.io.InputStream;

public class SystemInExample2 {
    public static void main(String[] args) throws Exception {
        InputStream is = System.in;

        byte[] datas = new byte[100];

        System.out.println("이름: ");
        int nameBytes = is.read(datas);
        String name = new String(datas, 0, nameBytes-1);

        System.out.println("하고 싶은말: ");
        int commentBytes = is.read(datas);
        String comment = new String(datas, 0, commentBytes-1);

        System.out.println("입력한 이름: " + name);
        System.out.println("입력한 하고 싶은말: " + comment);
    }
}
```
## System.out 필드
> System.in으로 콘솔에서 입력된 데이터를 읽었다면, 반대로 콘솔로 데이터를 출력하기 위해서
System.out 정적 필드를 사용한다.

- 콘솔로 1개의 바이트를 출력할 때, OutputStream의 write(int b) 메소드를 이용.
- 한글 출력은 한글을 바이트 배열로 얻은 다음, write(byte[] b)나 write(byte[] b, int off, int len)
메소드로 콘솔에 출력한다.
```java
import java.io.OutputStream;

public class SystemOutExample {
    public static void main(String[] args) throws Exception{
        OutputStream os = System.out;

        for(byte b = 48; b < 58; b++) {
            os.write(b);
        }
        os.write(10);

        for(byte b = 97; b < 123; b++) {
            os.write(b);
        }
        os.write(10);

        String hangul = "가나다라마바사아자차카타파하";
        byte[] hangulBytes = hangul.getBytes();
        os.write(hangulBytes);

        os.flush();
    }
}
```

## Console 클래스
> 자바 6부터는 콘솔에서 입력받은 문자열을 쉽게 읽을 수 있도록 java.io.Console 클래스를 제공한다.
Console 객체를 얻기 위해서는 System의 정적 메소드인 console()을 호출한다.

    Console console = System.console();
- 명령 프롬프트에서 실행하지 않으면 System.console() 메소드는 null을 리턴한다.
- Console 클래스의 읽기 메소드는 다음과 같다

|리턴 타입|메소드|설명|
|---|---|---|
|String|readLine()|Enter키를 입력하기 전의 모든 문자열을 읽음|
|char[]|readPassword()|키보드 입력 문자를 콘솔에 보여주지 않고 문자열을 읽음|

## Scanner 클래스
> Console 클래스는 콘솔로부터 문자열은 읽을 수 있지만 기본 타입 값을 바로 읽을 수는 없다.
java.util 패키지의 Scanner 클래스를 이용하면 콘솔로부터 기본 타입의 값을 바로 읽을 수 있다.

