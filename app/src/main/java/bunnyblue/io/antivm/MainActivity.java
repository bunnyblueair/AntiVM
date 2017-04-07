package bunnyblue.io.antivm;

import android.app.Activity;
import android.os.Bundle;

import io.github.AntiVMV1;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        AntiVMV1 mAntiVMV1=new AntiVMV1();
        mAntiVMV1.antiVM(getBaseContext());
    }
}
