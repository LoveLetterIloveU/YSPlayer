package com.longger.ysplayer;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

import com.longger.lame.LameEncoder;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("audioencoder");
    }

    public LameEncoder lameEncoder;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = findViewById(R.id.sample_text);

        lameEncoder = new LameEncoder();

        tv.setText("Lame Version：" + lameEncoder.version());

        int ret = lameEncoder.init("/sdcard/pcm/langhua.pcm", "/sdcard/pcm/langhua.mp3", 44100, 2, 128000);//采样率为44.1kHz，码率为128kBps

        if(ret == 0)
            lameEncoder.encoder();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        lameEncoder.destroy();
    }
}
