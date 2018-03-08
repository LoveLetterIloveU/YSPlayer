//
// Created by 曹江龙 on 2018/3/7.
//

#include <stdio.h>
#include "source/lame.h"

class Mp3Encoder{
private:
    FILE* pcmFile;
    FILE* mp3File;
    lame_t lameClient;

public:
    int Init(const char* pcmFilepath, const char* mp3Filepath, int sampleRate, int channels, int biteRate);
    void Encode();
    void Destroy();
};