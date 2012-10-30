#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cv.h>
#include <highgui.h>

#define MAXIMAGE 1025 * 1025

typedef IplImage* (*bianhuanType)(IplImage *);
int readVideo(char *fileName);
int readVideoWithATrackbar(char *fileName);
int readVideoFromDevice();
IplImage* colorToBlack(IplImage*);
int readVideoForBianhuan(bianhuanType);
IplImage* reserveColor(IplImage *img);
IplImage* fudiao(IplImage *img);
