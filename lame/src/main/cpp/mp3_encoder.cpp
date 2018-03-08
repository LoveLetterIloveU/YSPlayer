//
// Created by 曹江龙 on 2018/3/7.
//

#include "mp3_encoder.h"
#include "Log.h"

int Mp3Encoder::Init(const char *pcmFilepath, const char *mp3Filepath, int sampleRate, int channels, int biteRate) {
    int ret = -1;
    pcmFile = fopen(pcmFilepath, "rb");//二进制形式只读
    if(pcmFile){
        mp3File = fopen(mp3Filepath, "wb");//二进制形式只写
        if(mp3File){
            lameClient = lame_init();
            lame_set_in_samplerate(lameClient, sampleRate);
            lame_set_out_samplerate(lameClient, sampleRate);//编码时输入、输出采样率保持统一
            lame_set_num_channels(lameClient, channels);
            lame_set_brate(lameClient, biteRate / 1000);//输入参数单位是kBps
            lame_init_params(lameClient);
            ret = 0;
            LOGE("lame初始化成功");
        }
    } else{
        LOGE("PCM文件'%s'不存在", pcmFilepath);
    }
    return ret;
}

void Mp3Encoder::Encode() {
    if(!pcmFile|| !mp3File || !lameClient)
        return;

    int bufferSize = 1024 * 256;
    short* buffer = new short[bufferSize / 2];//lame编码函数需要short类型数据（short占两个字节）
    short* leftBuffer = new short[bufferSize / 4];
    short* rightBuffer = new short[bufferSize / 4];

    unsigned char* mp3_buffer = new unsigned char[bufferSize];

    size_t readBufferSize = 0; //size_t与unsigned int类似，但其表示范围因平台而易，可移植性更高
    while ((readBufferSize = fread(buffer, 2, bufferSize / 2, pcmFile)) > 0){
        for(int i=0; i<readBufferSize; i++){
            if(i%2 == 0) {
                leftBuffer[i/2] = buffer[i];
            } else{
                rightBuffer[i/2] = buffer[i];
            }
        }

        size_t wroteSize = lame_encode_buffer(lameClient, leftBuffer, rightBuffer, (int)(readBufferSize/2), mp3_buffer, bufferSize);
        fwrite(mp3_buffer, 1, wroteSize, mp3File);
    }

    //清除临时new的内存
    delete [] buffer;
    delete [] leftBuffer;
    delete [] rightBuffer;
    delete [] mp3_buffer;

    LOGE("编码完毕");
}

void Mp3Encoder::Destroy() {
    if(pcmFile)
        fclose(pcmFile);

    if(mp3File)
        fclose(mp3File);

    if(lameClient)
        lame_close(lameClient);
}
