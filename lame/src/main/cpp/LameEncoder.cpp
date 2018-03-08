//
// Created by 曹江龙 on 2018/3/7.
//
#include <jni.h>
#include "source/lame.h"
#include "mp3_encoder.h"
#include "Log.h"

static Mp3Encoder* encoder;//static内部变量

extern "C"
JNIEXPORT jstring JNICALL
Java_com_longger_lame_LameEncoder_version(JNIEnv *env, jobject instance) {

    return env->NewStringUTF(get_lame_version());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_longger_lame_LameEncoder_init(JNIEnv *env, jobject instance, jstring pcmPath_,
                                       jstring mp3Path_, jint sampleRate, jint audioChannels,
                                       jint bitRate) {
    const char *pcmPath = env->GetStringUTFChars(pcmPath_, 0);
    const char *mp3Path = env->GetStringUTFChars(mp3Path_, 0);

    encoder = new Mp3Encoder();
    int ret = encoder->Init(pcmPath, mp3Path, sampleRate, audioChannels, bitRate);

    env->ReleaseStringUTFChars(pcmPath_, pcmPath);
    env->ReleaseStringUTFChars(mp3Path_, mp3Path);
    return ret;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_longger_lame_LameEncoder_encoder(JNIEnv *env, jobject instance) {

    encoder->Encode();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_longger_lame_LameEncoder_destroy(JNIEnv *env, jobject instance) {

    encoder->Destroy();
    delete encoder;
}