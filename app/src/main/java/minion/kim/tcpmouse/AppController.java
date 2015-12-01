package minion.kim.tcpmouse;


import android.app.Application;

public class AppController extends Application {

    private static AppController mInstance;
    private String IPAddr;
    private String gyrovalue;

    @Override
    public void onCreate() {
        super.onCreate();
        mInstance = this;
    }

    public static synchronized AppController getInstance() {
        return mInstance;
    }

    public void setIP(String _addr)
    {
        IPAddr = _addr;
    }

    public String getIP()
    {
        return IPAddr;
    }

    public void setValue(String _val)
    {
        gyrovalue = _val;
    }

    public String getValue()
    {
        return gyrovalue;
    }

}
