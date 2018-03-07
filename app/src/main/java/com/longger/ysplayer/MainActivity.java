package com.longger.ysplayer;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.longger.lame.Mp3Encoder;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("audioencoder");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = findViewById(R.id.sample_text);

        Mp3Encoder lameEncoder = new Mp3Encoder();

        tv.setText("Lame Version：" + lameEncoder.Version());

    }

}
