import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        Socket socket = null;

        try {
            socket = new Socket();
            socket.connect(new InetSocketAddress(5000));

            Scanner sc = new Scanner(System.in);
            OutputStream os = socket.getOutputStream();
            byte[] buf = new byte[128];
            String message = null;

            while(true) {
                message = sc.nextLine();
                buf = message.getBytes("UTF-8");
                os.write(buf);
                os.flush();
                System.out.println(message);
            }
        } catch (Exception e) {}
    }
}

