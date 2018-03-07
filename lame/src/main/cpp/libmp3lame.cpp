//
// Created by 曹江龙 on 2018/3/7.
//
#include <jni.h>
#include "source/lame.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_longger_lame_LameEncoder_getLameVersion(JNIEnv *env, jobject instance) {

    // TODO
    return env->NewStringUTF(get_lame_version());
}