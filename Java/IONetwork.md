# 네트워크
>여러 대의 컴퓨터를 통신 회선으로 연결한 것.

## 서버와 클라이언트
- 서버
    - 서비스를 제공하는 프로그램
    - 클라이언트의 연결을 수락하여 서비스를 제공
- 클라이언트
    - 서비스를 받는 프로그램
    - 서비스를 받기 위해 서버에 연결을 요청
- 클라이언트/서버 모델
    - 한 개의 서버와, 다수의 클라이언트로 구성되는 것
- P2P
    - 두 개의 프로그램이 서버인 동시에 클라이언트 역할을 하는것.

## IP 주소와 포트(Port)
- IP 주소
    - 네트워크 어댑터마다 할당되는 컴퓨터의 고유 주소
    - 명령 프롬프트에서 확인할 수 있다.
- Port
    - 다양한 서버 프로그램들이 실행되었을 때, 어떤 서버와 통신해야 할지 결정해 준다.
    - 서버는 시작할 때 고정적인 포트 번호를 가지고 실행한다.(Port binding)
    - 클라이언트는 서버에서 보낸 정보를 받기 위해 포트 번호가 필요한데, 이는 운영체제가
    자동으로 부여하는 동적 포트 번호를 사용한다.
        - 동적 포트 번호는 클라이언트가 서버로 연결 요청을 할 때 전송되어 서버가 클라이언트로
        데이터를 보낼 때 사용된다.
            
        |구분명|범위|설명|
        |---|---|---|
        |Well Know Port Numbers|0 ~ 1023|국제인터넷주소관리기구가 특정 애플리케이션 용으로 미리 예약한 포트|
        |Registered Port Numbers|1024 ~ 49151|회사에서 등록해서 사용할 수 있는 포트|
        |Dynamic Or Private Port Numbers|49152 ~ 65535|운영체제가 부여하는 동적 포트 또는 개인적인 목적으로 사용할 수 있는 포트|
    
## InetAddress로 IP 주소 얻기
- 자바는 IP주소를 java.net.InetAddress 객체로 표현한다.
```java
//로컬 컴퓨터의 InetAddress를 얻고 싶을 때
InetAddress ia = InetAddress.getLocalHost();
//외부 컴퓨터의 도메인 이름을 알고 있을 때
InetAddress ia2 = InetAddress.getByName(String host);
InetAddress[] ia2Arr = InetAddress.getAllByName(String host);
```

## TCP 네트워킹
> Transmission Control Protocol은 연결지향적 프로토콜이다. 클라이언트와 서버가 연결된 상태에서
데이터를 주고받는 프로토콜을 말한다.
- 장점 : 데이터를 정확하고 안정적으로 전달
- 단점 : 데이터를 보내기 전에 반드시 연결이 형성되어야 한다.
- 고정된 통신 선로가 최단선이 아닐 경우 상대적으로 UDP(User Datagram Protocol)보다 데이터 전송 속도가 느리다.

## ServerSocket, Socket
- ServerSocket
    - 클라이언트의 연결 요청을 기다리면서 연결 수락을 담당하는 역할
- Socket
    - 연결된 클라이언트와 통신을 담당하는 역할
![소켓,서버소켓](https://postfiles.pstatic.net/MjAxNzExMjBfMTAy/MDAxNTExMTA1MjEwNDYw.XxgiEMSgGFqTIBT3EvhzdkjsfCtxW9aVsbU1v5ylMXUg.BC3jROQnSheVDvkFQ6X6K69yOnLD_9ubhGJZrgvXIeEg.PNG.qbxlvnf11/20171120_002629.png?type=w773)
- 서버는 클라이언트가 접속할 포트를 가지고 있어야 한다.
    - 바인딩 포트

## ServerSocekt 생성과 연결 수락
- 서버를 개발하려면 우선 ServerSocket 객체를 얻어야 한다.
- 다음은 ServerSocket을 얻는 방법들이다.
```java
ServerSocket serverSocket = new ServerSocket(5001);

ServerSocket serverSocket = new ServerSocket();
serverSocket.bind(new InetSocketAddress(5001));

ServerSocket serverSocket = new ServerSocket();
serverSocket.bind(new InetSocketAddress("localhost", 5001));
// 만약 서버 PC에 멀티 IP가 할당되어 있을 경우, 특정 IP로 접속할 때만
// 연결 수락을 하고 싶다면 "localhost" 대신 정확한 IP를 주면 된다.
```
- ServerSocket 생성시, 해당 포트가 이미 다른 프로그램에서 사용 중이라면 BindException 발생.
    - 다른 포트로 바인딩하거나, 다른 프로그램을 종료하고 다시 실행
- 바인딩 후에 클라이언트 연결 수락을 위해 accept() 메소드를 실행
    - 클라이언트가 연결 요청하기 전까지 accept()은 블로킹된다. -> UI를 생성하는 스레드나 이벤트를
    처리하는 스레드에서 accept() 메소드를 호출하지 않도록 한다.
    - 클라이언트와 통신할 Socket을 만들고 리턴 -> 연결 수락
- accept()에서 블로킹 되어 있을 때, ServerSocket을 close() 하려하면, SocketException이 발생.
- 연결된 클라이언트의 IP와 포트 정보를 알고 싶을 때, Socket의 getRemoteSocketAddress() 호출.
```java
InetSocketAddress socketAddress = (InetSocketAddress) socket.getRemoteSocketAddress();
```

|리턴 타입|메소드명(매개변수)|설명|
|---|---|---|
|String|getHostName()|클라이언트 IP리턴|
|int|getPort()|클라이언트 포트 번호|
|String|toString()|"IP:포트번호" 형태의 문자열 리턴|

- 더 이상 클라이언트 연결 수락이 필요 없으면 ServerSocket의 close() 메소드를 호출해서
포트를 언바인딩 시켜야 한다.

## Socket 생성과 연결 요청
- 클라이언트가 서버에 연결 요청을 하려면 Socket을 이용해야 한다.
```JAVA
try {
    Socket socket = new Socket("localhost", 5001);
    Socket socket = new Socket( new InetSocketAddress("localhost", 5001) );
} catch (UnknownHostException e) {
    //IP 표기 방법이 잘못되었을 경우
} catch (IOException e) {
    //해당 포트의 서버에 연결할 수 없는 경우
}

socket = new Socket();
socket.connect( new InetSocketAddress("localhost", 5001) );
```
- 외부 서버에 접속하려면 localhost 대신 정확한 IP를 입력한다.
- Socket 생성자 및 connect() 메소드는 서버와 연결이 될 때까지 블로킹된다.

## Socket 데이터 통신
- 클라이언트가 연결 요청(connect())하고 서버가 연결 수락(accept()) 했다면, 양쪽 Socket 객체로부터
각각 입력 스트림과 출력 스트림을 얻을 수 있다.
```java
InputStream is = socket.getInputStream();
OutputStream os = socket.getOutputStream();
```
- 상대방에게 데이터를 보내기 위해서는 보낼 데이터를 byte[] 배열로 생성하고,
이것을 매개값으로 해서 OutputStream write() 메소드를 호출하면 된다.
```java
String data = "보낼 데이터";
byte[] byteArr = data.getBytes("UTF-8");
OutputStream outputStream = socket.getOutputStream();
outputStream.write(byteArr);
outputStream.flush();
```
- 상대방이 보낸 데이터를 받기 위해서는 byte[] 배열을 생성하고, 이것을 매개값으로 해서
InputStream의 read() 메소드를 호출하면 된다.
```java
byte[] byteArr = new byte[100];
InputStream inputStream = socket.getInputStream();
int readByteCount = inputStream.read(byteArr);
String data = new String(byteArr, 0, readByteCount, "UTF-8");
```

## 스레드 병렬 처리
- ServerSocket과 Socket은 동기(블로킹) 방식으로 구동된다.
- 서버를 실행시키는 main 스레드가 직접 입출력을 담당하게 되면 입출력이 완료될 때까지 다른 작업을
할 수 없는 상태가 된다.
    - accept(), connect(), read(), write()는 별도의 작업 스레드를 생성해서 병렬적으로 처리하는 것이 좋다.
![다중 클라이언트와 병렬적으로 통신1](http://postfiles5.naver.net/MjAxODA2MDZfNjMg/MDAxNTI4MjYyMzQ5OTA1.SpsV8ZwBSwe_YevEU5I8Wysz83cBZ8O63KdNQYu-u24g.QZS-qSoknGPkLb2JEg9hClyPXZHMVKN5YIDPDtX8I9gg.PNG.qbxlvnf11/20180603_193501.png?type=w773)
- 위와 같이 스레드로 병렬 처리를 할 경우, 클라이언트의 폭증으로 인해 서버의 과도한 스레드 생성을 초래한다.
- 스레드풀을 이용해서 서버를 구현한다.
![다중 클라이언트와 병렬적으로 통신2](https://t1.daumcdn.net/cfile/tistory/275E084155E92C102A)
- 스레드풀은 스레드 수를 제한해서 사용하기 때문에 갑작스런 클라이언트의 폭증은 작업 큐의 작업
량만 증가시킬 뿐, 스레드 수는 변함이 없어서 서버 성능은 완만히 저하된다.

## UDP 네트워킹
>User Datagram Protocol
- 비연결 지향적 프로토콜
- 데이터를 주고받을 때 연결 절차를 거치지 않고 발신자가 일방적으로 데이터를 발신하는 방식
- 연결 과정이 없기 때문에 TCP보다 빠른 전송을 할 수 있지만 데이터 전달의 신뢰성은 떨어진다.

