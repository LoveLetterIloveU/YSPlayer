package com.longger.lame;

/**
 * Created by cjl on 2018/3/7.
 */

public class LameEncoder {

    public native String version();
    public native int init(String pcmPath, String mp3Path, int sampleRate, int audioChannels, int bitRate);
    public native void encoder();
    public native void destroy();
}
