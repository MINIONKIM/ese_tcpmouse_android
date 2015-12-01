package minion.kim.tcpmouse;

import android.util.Log;

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class TCPClient implements Runnable {

    String value;

    TCPClient(String val) {
        value = val;
    }

    public void run() {
        try {
            //Thread.sleep(100);
            InetAddress serverAddr = InetAddress.getByName(AppController.getInstance().getIP());

            Log.d("TCP", "C: Connecting...");
            Socket socket = new Socket(serverAddr, 9999);
            String message = value;

            try {
                Log.d("TCP", "C: Sending: '" + message + "'");
                PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

                out.println(message);
                Log.d("TCP", "C: Sent.");
                Log.d("TCP", "C: Done.");

            } catch (Exception e) {
                Log.e("TCP", "S: Error", e);
            } finally {
                socket.close();
            }
        } catch (Exception e) {
            Log.e("TCP", "C: Error", e);
        }
    }
}