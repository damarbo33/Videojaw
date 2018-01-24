/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dmarcobo
 *
 * Created on 11 de enero de 2018, 10:26
 */
#include "VideoTranscoder.h"

/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char **argv)
{
    int ret = 0;
    SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);			// Initialize SDL
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE|SDL_RESIZABLE);
    
    if (argc != 3) {
        av_log(NULL, AV_LOG_ERROR, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }
    
    VideoTranscoder *trans = new VideoTranscoder();
//    trans->transcode(argv[1], argv[2]);
    //trans->remux(argv[1], argv[2]);
    vector<string> *lista = new vector<string>();
    vector<string> *lista2 = new vector<string>();
    vector<string> *lista3 = new vector<string>();
    
//    lista->push_back("C:\\clips\\SampleVideo_720x480_5mb.mp4"); //Reference of format 640x480
//    lista->push_back("C:\\clips\\SampleVideo_1280x720_5mb.mp4"); //Video to recompress
//    lista->push_back("C:\\clips\\resampled.mp4");
//    trans->transcodeList(lista,0);
//    
//    lista2->push_back("C:\\clips\\SampleVideo_720x480_5mb.mp4"); //Reference of format 640x480
//    lista2->push_back("C:\\clips\\Clip_1080_5sec_MPEG2_HD_15mbps.mpg"); //Video to recompress
//    lista2->push_back("C:\\clips\\resampled2.mp4");
//    trans->transcodeList(lista2,0);
    
    lista3->push_back("C:\\clips\\resampled.mp4"); //Video resampled to join
    lista3->push_back("C:\\clips\\resampled2.mp4"); //Video resampled to join
    trans->remux(lista3, "C:\\clips\\outjoined.mp4");
    
    delete lista;
    delete lista2;
    delete lista3;
    delete trans;
    
    return ret ? 1 : 0;
}
