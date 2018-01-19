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
    //trans->transcode(argv[1], argv[2]);
    trans->remux(argv[1], argv[2]);
    delete trans;
    
    return ret ? 1 : 0;
}
