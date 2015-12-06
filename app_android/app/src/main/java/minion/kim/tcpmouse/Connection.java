package minion.kim.tcpmouse;


import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

/**
 * Created by minion on 2015-12-01.
 */
public class Connection extends Activity {

    private EditText txt;
    Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.connection);
        txt = (EditText)findViewById(R.id.txtIP);
        findViewById(R.id.button).setOnClickListener(mClickListener);

    }

    Button.OnClickListener mClickListener = new View.OnClickListener() {
        public void onClick(View v) {
            AppController.getInstance().setIP(txt.getText().toString());
            intent = new Intent(Connection.this, MainActivity.class);
            startActivity(intent);
        }
    };

}
