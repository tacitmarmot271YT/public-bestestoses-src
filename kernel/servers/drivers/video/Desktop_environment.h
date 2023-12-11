#pragma once
#include "vesamode.h"

typedef struct{
uint8 XResolution, YResolution;
uint16_t BitsPerPixel;
}VideoModeDriver;
int ScreenBufferSize;
VideoModeDriver videoDriver;

void InitScreen(){
     ScreenBufferSize = videoDriver.XResolution * videoDriver.YResolution
                                                     * (videoDriver.BitsPerPixel/8);
     //ScreenBackBuffer = alloc(ScreenBufferSize);
 }
