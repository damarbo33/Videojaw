/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VideoTranscoder.h
 * Author: dmarcobo
 *
 * Created on 18 de enero de 2018, 17:26
 */

#ifndef VIDEOTRANSCODER_H
#define VIDEOTRANSCODER_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <array>
#include <algorithm>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_mixer.h>

using namespace std;

extern "C"{
    #include <libavutil/avstring.h>
    #include <libavutil/imgutils.h>
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavfilter/buffersink.h>
    #include <libavfilter/buffersrc.h>
    #include <libavutil/opt.h>
    #include <libavutil/pixdesc.h>
    #include <libswscale/swscale.h>
}

// Set up the pixel format color masks for RGB(A) byte arrays.
// Only STBI_rgb (3) and STBI_rgb_alpha (4) are supported here!
/* SDL interprets each pixel as a 32-bit number, so our masks must depend
  on the endianness (byte order) of the machine */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
   static const uint32_t rmask = 0xff000000;
   static const uint32_t gmask = 0x00ff0000;
   static const uint32_t bmask = 0x0000ff00;
   static const uint32_t amask = 0x000000ff;
#else
   static const uint32_t rmask = 0x000000ff;
   static const uint32_t gmask = 0x0000ff00;
   static const uint32_t bmask = 0x00ff0000;
   static const uint32_t amask = 0xff000000;
#endif

class VideoTranscoder {
public:
    VideoTranscoder();
    VideoTranscoder(const VideoTranscoder& orig);
    virtual ~VideoTranscoder();
    int transcode(string inputFile, string outputFile);
    int remux(string inputFile, string outputFile);
    
private:

    //Buffer for errors added to c++ compatibility
    char buffErrors[AV_ERROR_MAX_STRING_SIZE];

    struct SwsContext *sws_ctx;
    struct SwsContext *sws_ctx2;
    int nframe;     //Contador de frames totales

    void (*sdlProcessing)(SDL_Surface *sf);

    AVFormatContext *ifmt_ctx;
    AVFormatContext *ofmt_ctx;

    typedef struct FilteringContext {
        AVFilterContext *buffersink_ctx;
        AVFilterContext *buffersrc_ctx;
        AVFilterGraph *filter_graph;
    } FilteringContext;
    FilteringContext *filter_ctx;

    typedef struct StreamContext {
        AVCodecContext *dec_ctx;
        AVCodecContext *enc_ctx;
    } StreamContext;
    StreamContext *stream_ctx;
    
    int closeResources(AVPacket *packet, AVFrame *frame, int ret);
    int init_filter(FilteringContext* fctx, AVCodecContext *dec_ctx,
        AVCodecContext *enc_ctx, const char *filter_spec);
    int copy_metadata(AVFormatContext *input_format_context, AVFormatContext *output_format_context);
    char * av_cplus_err2str(int errnum);
    char * av_cplus_make_error_string(char *errbuf, size_t errbuf_size, int errnum);
    int flush_encoder(unsigned int stream_index);
    int filter_encode_write_frame(AVFrame *frame, unsigned int stream_index);
    void encodeFrameToRGB(AVFrame *filt_frame, unsigned int stream_index);
    static void processFrameInSDL2(SDL_Surface *sf);
    static void processFrameInSDL(SDL_Surface *sf);
    int encode_write_frame(AVFrame *filt_frame, unsigned int stream_index, int *got_frame);
    int init_filters(void);
    int open_output_file(const char *filename);
    int open_input_file(const char *filename);
    
    
    
//    static void log_packet(const AVFormatContext *fmt_ctx, const AVPacket *pkt, const char *tag)
//    {
//        AVRational *time_base = &fmt_ctx->streams[pkt->stream_index]->time_base;
//        printf("%s: pts:%s pts_time:%s dts:%s dts_time:%s duration:%s duration_time:%s stream_index:%d\n",
//               tag,
//               av_ts2str(pkt->pts), av_ts2timestr(pkt->pts, time_base),
//               av_ts2str(pkt->dts), av_ts2timestr(pkt->dts, time_base),
//               av_ts2str(pkt->duration), av_ts2timestr(pkt->duration, time_base),
//               pkt->stream_index);
//    }
//    int remux(string inputFile, string outputFile);

};

#endif /* VIDEOTRANSCODER_H */

