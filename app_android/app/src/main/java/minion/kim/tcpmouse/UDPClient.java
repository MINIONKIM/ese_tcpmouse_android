package minion.kim.tcpmouse;

import android.util.Log;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPClient
{
    public class client_UDP implements Runnable{

        final ByteArrayOutputStream arrStream = new ByteArrayOutputStream();
        final DataOutputStream outStream = new DataOutputStream(arrStream);

        float[] value;
        byte[] buf;

        float yaw, pitch, roll;
        String servAddr;

        client_UDP(float _yaw, float _pitch, float _roll, String _servAddr)
        {
            yaw = _yaw;
            pitch = _pitch;
            roll = _roll;
            servAddr = _servAddr;
        }

        public void makeStream() throws Exception{
            outStream.writeFloat(yaw);
            outStream.writeFloat(pitch);
            outStream.writeFloat(roll);

            outStream.close();

            buf = arrStream.toByteArray();
        }

        public void run(){

            try {

                makeStream();

                InetAddress serverAddr = InetAddress.getByName(servAddr);

                DatagramSocket socket = new DatagramSocket();
                DatagramPacket pkt = new DatagramPacket(buf, buf.length, serverAddr, 9999);

                socket.send(pkt);
                socket.close();
            } catch (Exception e) {
                Log.d("UDP", "err");
            }
        }
    }
}
