package minion.kim.tcpmouse;

import android.app.Activity;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity implements SensorEventListener {

    int gyroX, gyroY, gyroZ;
    private SensorManager mSensorManager;
    private Sensor mGyroscope;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mSensorManager = (SensorManager)getSystemService(Context.SENSOR_SERVICE);
        mGyroscope = mSensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE);
    }

    public void onSensorChanged(SensorEvent event){
        Sensor sensor = event.sensor;
        String acc;
        float[] orient = {};

        String gdata;

        /*
        if(sensor.getType() == Sensor.TYPE_ORIENTATION){

            yaw = event.values[0];
            pitch = event.values[1];
            roll = event.values[2];

            //new Thread(new client_UDP(yaw, pitch, roll)).start();

           // list_orientation.setText("yaw : " + yaw + "\n" + "pitch : " + pitch + "\n" + "roll : " + roll);
        }*/

        if(sensor.getType() == Sensor.TYPE_GYROSCOPE){
            gyroX = Math.round(event.values[0] * 1000);
            gyroY = Math.round(event.values[1] * 1000);
            gyroZ = Math.round(event.values[2] * 1000);

            gdata = String.valueOf(gyroX) + " " + String.valueOf(gyroY) + " " + String.valueOf(gyroZ) + " ";
            // Log.d("gyro : ", gdata);

            //AppController.getInstance().setValue(gdata);

            Thread cThread = new Thread(new TCPClient(gdata));
            cThread.start();
        }

        /*if(sensor.getType() == Sensor.TYPE_ACCELEROMETER){
            accelX = Math.round(event.values[0] * 1000);
            accelY = Math.round(event.values[1] * 1000);
            accelZ = Math.round(event.values[2] * 1000);

            //list_g.setText("ACC_X-Axis : " + accelX + "\n" +"ACC_Y-Axis : " + accelY + "\n" +"ACC_Z-Axis : " + accelZ);
        }*/
    }

    public void onAccuracyChanged(Sensor sensor, int accuracy){}

    protected void onResume(){
        super.onResume();
        mSensorManager.registerListener(this, mGyroscope, SensorManager.SENSOR_DELAY_NORMAL);
        //mSensorManager.registerListener(this, accSensor, SensorManager.SENSOR_DELAY_FASTEST);
        //mSensorManager.registerListener(this, orientation,SensorManager.SENSOR_DELAY_FASTEST);
    }

    protected void onPause(){
        super.onPause();
        mSensorManager.unregisterListener(this);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
