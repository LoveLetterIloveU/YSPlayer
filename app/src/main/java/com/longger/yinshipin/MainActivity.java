package com.longger.yinshipin;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.longger.lame.LameEncoder;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("libmp3lame");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = findViewById(R.id.sample_text);

        LameEncoder lameEncoder = new LameEncoder();

        tv.setText(lameEncoder.getLameVersion());

    }

}
