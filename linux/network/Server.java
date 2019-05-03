import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket();
            serverSocket.bind(new InetSocketAddress(5000));

            Socket socket = serverSocket.accept();
            System.out.println(socket.getRemoteSocketAddress());

            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            byte[] buf = new byte[128];
            String message = null;
            while (true) {
                int ret = is.read(buf);
                message = new String(buf, 0, ret, "UTF-8");
                if(ret <= 0) {
                    break;
                }
                buf = message.getBytes("UTF-8");
                os.write(buf);
                os.flush();
            }
            is.close();
            os.close();
            socket.close();
            serverSocket.close();
        } catch (Exception e) {}


    }
}

