# 파일 입출력
> IO 패키지에서 제공하는 File 클래스는 파일 크기, 파일 속성, 파일 이름 등의 정보를
얻어내는 기능과 파일 생성 및 삭제 기능을 제공 그러나 파일의 데이터를 읽고 쓰는 기능은 없다.
**파일의 입출력은 스트림을 사용**해야 한다.
```java
File file = new File("C:/Temp/file.txt");
```
- 파일 객체를 생성했다고 해서 파일이나 디렉토리가 생성되는 것은 아니다.
- exists() 메소드로 실제로 있는지 확인한다.
    - exists() 메소드의 리턴값이 false라면 createNewFile(), mkdir(), mkdirs() 메소드로 
    파일 또는 디렉토리를 생성할 수 있다.
    - 파일 또는 디렉토리가 존재할 경우에는 다음 메소드를 통해 정보를 얻어낼 수 있다.
    
    |리턴 타입|메소드|설명|
    |------|------|------------------------------------------------------|
    |boolean|canExeucute()|실행할 수 있는 파일인지 여부|
    |boolean|canRead()|읽을 수 있는 파일인지 여부|
    |boolean|canWrite()|수정 및 저장할 수 있는 파일인지 여부|
    |String|getName()|파일의 이름을 리턴|
    |String|getParent()|부모 디렉토리를 리턴|
    |File|getParentFile()|부모 디렉토리를 File 객체로 생성후 리턴|
    |String|getPath()|전체 경로를 리턴|
    |boolean|isDirectory()|디렉토리인지 여부|
    |boolean|isFile()|파일인지 여부|
    |boolean|isHidden()|숨김 파일인지 여부|
    |long|lastModified()|마지막 수정 날짜 및 시간을 리턴|
    |long|length()|파일의 크기를 리턴|
    |String[]|list()|디렉토리에 포함된 파일 및 서브디렉토리 목록 전부를 String 배열로 리턴|
    |String[]|list(FilenameFilter filter)|디렉톨에 포함된 파일 및 서브디렉토리 목록 중에 FilenameFilter에 맞는 것만 String 배열로 리턴|
    |File[]|listFiles()|디렉토리에 포함된 파일 및 서브 디렉토리 목록 전부를 File 배열로 리턴|
    |File[]|listFiles(FilenameFilter filter)|디렉토리에 포함된 파일 및 서브디렉토리 목록 중에 FilenameFilter에 맞는 것만 File 배열로 리턴|

## FileInputStream
- 파일로부터 바이트 단위로 읽어들일 때 사용하는 바이트 기반 입력 스트림
- InputStream의 하위 클래스이기 때문에 사용 방법이 InputStream과 동일하다.
```java
FileInputStream fis = new FileInputStream("C:/Temp/image.gif");
int readByteNo;
byte[] readBytes = new byte[100];
while( (readByteNo = fis.read(readBytes) ) != -1) {
    //읽은 바이트 배열(readBytes)을 처리
}
fis.close();
```

## FileOutputStream
- 바이트 단위로 데이터를 파일에 저장할 때 사용하는 바이트 기반 출력 스트림
- 파일이 이미 존재할 경우, 데이터를 출력하면 기존의 파일 내용이 사라지게된다.
    - 기존의 파일 내용 끝에 데이터를 추가할 경우에는 FileOutputStream 생성자에 두 번째 매개값으로 true로 준다.
    ```java
    FileOutputStream fos = new FileOutputStream("C:/Temp/data.txt", true);
    FileOutputStream fos = new FileOutputStream(file, true);
    ```
- OutputStream의 하위 클래스이기 때문에 사용 방법이 OutputStream과 동일하다.
```java
FileOutputStream fos = new FileOutputStream("C:/Temp/image.gif");
byte[] data = ...;
fos.flush();
fos.close();
```

## FileReader
- 텍스트 파일을 프로그램으로 읽어들일 때 사용하는 문자 기반 스트림
- Reader의 하위 클래스이기 때문에 사용 방법이 Reader와 동일하다.
```java
FileReader fr = new FileReader("C:/Temp/file.txt");

File file = new File("C:/Temp/file.txt");
FileReader fr = new FileReader(file);
```

## FileWriter
- 텍스트 데이터를 파일에 저장할 때 사용하는 문자 기반 스트림
- 파일이 이미 존재할 경우 그 파일을 덮어쓰게 되므로, 기존의 파일 내용이 사라지게 된다.
    - 기존의 파일 내용 끝에 데이터를 추가할 경우 FileWriter 생성자에 두 번째 매개값으로 true를 주면 된다.
    ```java
    FileWriter fw = new FileWriter("C:/Temp/file.txt", true);
    FileWriter fw = new FileWriter(file, true);
    ```
- FileWriter는 Writer의 하위 클래이기 때문에 사용 방법이 Writer와 동일하다.
```java
FileWriter fw = new FileWriter("C:/Temp/file.txt");
String data = "저장할 문자열";
fw.write(data);
fw.flush();
fw.close();
```

## 보조 스트림
- 보조 스트림이란 다른 스트림과 연결되어 여러가지 편리한 기능을 제공해주는 스트림
    - 보조 스트림의 일부가 FilterInputStream, FilterOutputStream의 하위 클래스이기 때문에
    필터 스트림이라고도 한다.
- 문자 변환, 입출력 성능 향상, 기본 데이터 타입 입출력, 객체 입출력 등의 기능을 제공.
```java
보조스트림 변수 = new 보조스트림(연결스트림)
```
- 보조 스트림은 또 다른 보조 스트림에도 연결되어 스트림 체인을 구성할 수 있다.
```java
InputStream is = System.in;
InputStreamReader reader = new InputStreamReader(is);
BufferedReader br = new BufferedReader(reader);
```

## 문자 변환 보조 스트림
- 소스 스트림이 바이트 기반 스트림 이면서 입출력 데이터가 문자라면 Reader와 Writer로 변환해서
사용하는 것을 고려해야 한다. 그 이유는 Reader와 Writer는 문자 단위로 입출력하기 때문에 바이트
기반 스트림보다는 편리하고, 문자셋의 종류를 지정할 수 있기 때문에 다양한 문자를 입출력할 수 있다.

## InputStreamReader
- 바이트 입력 스트림에 연결되어 문자 입력 스트림인 Reader로 변환시키는 보조 스트림
```java
Reader reader = new InputStreamReader(바이트입력스트림);
```
- 파일 입력을 위한 FileInputStream도 Reader 타입으로 변환시킬 수 있다.
```java
FileInputStream fis = new FileInputStream("C:/Temp/file.txt");
Reader reader = new InputStreamReader(fis);
```

## OutputStreamWriter
- 바이트 출력 스트림에 연결되어 문자 출력 스트림인 Writer로 변환시키는 보조 스트림
```java
Writer writer = new OutputStreamWriter(바이트출력스트림);
```
- 파일 출력을 위한 FileOutputStream을 Writer 타입으로 변환할 수 있다.
```java
FileOutputStream fos = new FileOutputStream("C:/Temp/file.txt");
Writer writer = new OutputStreamWriter(fos);
```

## 성능 향상 보조 스트림
- 프로그램이 입출력 소스와 직접 작업하지 않고 중간에 메모리 버퍼와 작업함으로써
실행 성능을 향상시킬 수 있다.

## BufferedInputStream, BufferedReader
- BufferedInputStream은 바이트 입력 스트림에 연결되어 버퍼를 제공해주는 보조 스트림이다.
- BufferedReader는 문자 입력 스트림에 연결되어 버퍼를 제공해주는 보조 스트림이다.
- 프로그램은 외부의 입력 소스로부터 직접 읽는 대신 버퍼로부터 읽음으로써 읽기 성능이 향상된다.
- 8192 내부 버퍼 사이즈를 가진다.

## BufferedOutputStream, BufferedWriter
- BufferedOutputStream은 바이트 출력 스트림에 연결되어 버퍼를 제공해주는 보조 스트림
- BufferedWriter는 문자 출력 스트림에 연결되어 버퍼를 제공해주는 보조 스트림
- 프로그램 입장에서 직접 데이터를 보내는 것이 아니라, 메모리 버퍼로 데이터를 고속 전송하기
때문에 실행 성능이 향상.
- 8192 내부 버퍼 사이즈를 갖는다.
- 출력하는 방법이 OutputStream이나 Writer와 동일하다. 다만, 버퍼가 가득 찼을 때만 출력을 하기 때문에
마지막 자투리 데이터 부분이 목적지로 가지 못하고 버퍼에 남아있을 수 있다.
    - flush() 메소드를 호출하여 버퍼에서 잔류하고 있는 데이터를 모두 보내야 한다.

## 기본 타입 입출력 보조 스트림
> 바이트 스트림은 바이트 단위로 입출력하기 때문에 자바의 기본 데이터 타입인 boolean, char, short, int, long
,float, double 단위로 입출력할 수 없다.
- DataInputStream과 DataOutputStream 보조 스트림을 연결해 기본 데이터 타입으로 입출력이 가능하다.
- 다음 메소드들을 사용해 기본 데이터 타입을 입출력한다.
- **타입의 크기가 모두 다르므로, 출력한 순서와 동일한 순서로 읽어야 한다.**
```java
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class DataInputOutputStreamExample {
    public static void main(String[] args) throws Exception{
        FileOutputStream fos = new FileOutputStream("C:/Temp/primitive.dat");
        DataOutputStream dos = new DataOutputStream(fos);

        dos.writeUTF("홍길동");
        dos.writeDouble(95.5);
        dos.writeInt(1);

        dos.writeUTF("감자바");
        dos.writeDouble(90.3);
        dos.writeInt(2);

        dos.flush(); dos.close(); fos.close();

        FileInputStream fis = new FileInputStream("C:/Temp/primitive.dat");
        DataInputStream dis = new DataInputStream(fis);

        for(int i = 0; i < 2; i++) {
            String name = dis.readUTF();
            double score = dis.readDouble();
            int order = dis.readInt();
            System.out.println(name + " : " + score + " : " +  order);
        }
        dis.close(); fis.close();
    }
}
```

## 프린터 보조 스트림
- PrintStream과 PrintWriter는 프린터와 유사하게 출력하는 print(), println() 메소드를 가지고 있는 보조 스트림
    - System.out이 대표적인 PrintStream 타입이다.

## 객체 입출력 보조 스트림
> 자바는 메모리에 생성된 객체를 파일 또는 네트워크로 출력할 수가 있다. 객체는 문자가 아니기 때문에
바이트 기반 스트림으로 출력해야 한다.
- 직렬화
    - 객체를 출력하기 위해 객체의 데이터를 일렬로 늘어선 연속적인 바이트로 변경 
- 역질렬화
    - 입력 스트림으로부터 읽어드린 연속적인 바이트를 객체로 복원

- ObjectInputStream, ObjectOutputStream
    - 객체를 입출력할 수 있는 두 개의 보조 스트림
    - ObjectOutputStream은 바이트 출력 스트림과 연결되어 객체를 직렬화 하는 역할
        -     ObjectOutputStream oos = new ObjectOutputStream(바이트출력스트림);
              oos.writeObject(객체);
    - ObjectInputStream은 바이트 입력 스트림과 연결되어 객체를 역직렬화 하는 역할
        -     ObjectInputStream ois = new ObjectInputStream(바이트출력스트림);
              객체타입 변수 = (객체타입) ois.readObject();
    - 복수의 객체를 저장할 경우, 출력된 객체 순서와 동일한 순서로 객체를 읽어야 한다.
    ```java
    import java.io.FileInputStream;
    import java.io.FileOutputStream;
    import java.io.ObjectInputStream;
    import java.io.ObjectOutputStream;

    public class ObjectInputOutputStreamExample {
       public static void main(String[] args) throws Exception{
            FileOutputStream fos = new FileOutputStream("C:/Temp/Object.dat");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
    
            oos.writeObject(new Integer(10));
            oos.writeObject(new Double(3.14));
            oos.writeObject(new int[] { 1, 2, 3 });
            oos.writeObject(new String("홍길동"));
    
            oos.flush(); oos.close(); fos.close();
    
            FileInputStream fis = new FileInputStream("C:/Temp/Object.dat");
            ObjectInputStream ois = new ObjectInputStream(fis);
    
            Integer obj1 = (Integer) ois.readObject();
            Double obj2 = (Double) ois.readObject();
            int[] obj3 = (int[]) ois.readObject();
            String obj4 = (String) ois.readObject();
    
            ois.close(); fis.close();
    
            System.out.println(obj1);
            System.out.println(obj2);
            System.out.println(obj3[0] + "," + obj3[1] + "," + obj3[2]);
            System.out.println(obj4);
        }
    }
    ```
## 직렬화가 가능한 클래스(Serializable)
>자바는 Serializable 인터페이스를 구현한 클래스만 직렬화할 수 있도록 제한하고 있다.
Serializable 인터페이스는 필드나 메소드가 없는 빈 인터페이스이지만, 객체를 직렬화할 때 
private 필드를 포함한 모든 필드를 바이트로 변환해도 좋다는 표시 역할을 한다.
```java
public class XXX implements Serializable { }
```
- 객체를 직렬화하면 바이트로 변환되는 것은 필드들, 생성자 및 메소드는 직렬화에 포함되지 않는다.
- 역직렬화할 때에는 필드의 값만 복원된다.
- static 또는 transient가 붙어 있을 경우에는 직렬화가 되지 않는다.

## serialVersionUID 필드
- 같은 클래스 임을 알려주는 식별자 역할
- 클래스를 변경해서 재컴파일하면 다른 serialVersionUID를 갖게 된다.
    - 역직렬화 실패로 이어진다.
- 불가피하게 클래스의 수정이 필요하면, 클래스 작성시 serialVersionUID를 명시적으로 선언하면 된다.

## writeObject()와 readObject()
- 부모 클래스가 Serializable 인터페이스를 구현하고 있으면 자식 클래스는 Serializable 인터페이스를
구현하지 않아도 자식 객체를 직렬화하면 부모 필드 및 자식 필드 모두 직렬화.
- 부모 클래스가 Serializable 인터페이스를 구현하고 있지 않고, 자식 클래스만 Serializable 인터페이스를
구현하고 있다면 자식 객체를 직렬화할 때 부모의 필드는 직렬화에서 제외된다.

