#include "opencv.h"
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <stdlib.h>


int readVideo(char *fileName)
{
	printf("%s\n", fileName);
	CvCapture *video_capture = cvCreateFileCapture(fileName);
	IplImage *img;
	cvNamedWindow("win_1", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("win_1", 100, 100);

	int flag = 1;

	while (flag != 27) {
		img = cvQueryFrame(video_capture);
		if (img) {
			cvShowImage("win_1", img);
			flag = cvWaitKey(30);
		}
	}
	
	cvReleaseCapture(&video_capture);
	cvDestroyWindow("win_1");

	return 0;
}

int g_slider_position = 0;
CvCapture* g_capture = NULL;

void onTrackbarSlide(int pos)
{
	cvSetCaptureProperty(
			g_capture,
			CV_CAP_PROP_POS_FRAMES,
			pos
			);
}

int readVideoWithATrackbar(char *fileName)
{
	cvNamedWindow( "win_1", CV_WINDOW_AUTOSIZE );
	g_capture = cvCreateFileCapture( fileName );
	int frames = (int) cvGetCaptureProperty(
			g_capture,
			CV_CAP_PROP_FRAME_COUNT
			);
	if( frames != 0 ) {
		cvCreateTrackbar(
				"Position",
				"win_1",
				&g_slider_position,
				frames,
				onTrackbarSlide
				);
	}
	IplImage* frame;
	while (1) {
		frame = cvQueryFrame( g_capture );
		if ( !frame ) {
			break;
		}
		cvShowImage( "win_1", frame );
		char c = cvWaitKey(33);

	}
	return (0);
}
