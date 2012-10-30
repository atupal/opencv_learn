#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cv.h>
#include <highgui.h>
#include "opencv.h"
#include <assert.h>

IplImage* colorToBlack(IplImage *img)
{
	IplImage *out = cvCreateImage(
			cvGetSize(img),
			IPL_DEPTH_8U,
			1
			);

	int step_img = img->widthStep;
	int step_out = out->widthStep;
	int chanels = img->nChannels;
	int height = img->height;
	int width = img->width;
	unsigned char *data_img = (unsigned char *)img->imageData;
	unsigned char *data_out = (unsigned char *)out->imageData;
	int i,j,k;
	int tmp;
	for (i = 0; i < height; ++ i) {
		for (j = 0; j < width; ++ j) {
			tmp = 0;
			for (k = 0; k < chanels; ++ k) {
				tmp += data_img[i * step_img + j * chanels + k] / chanels;
			}
			data_out[i * step_out + j] = tmp;
		}
	}

	return out;
}

IplImage* reserveColor(IplImage *img)
{
	int step_img = img->widthStep;
	int chanels = img->nChannels;
	int width = img->width;
	int height = img->height;
	unsigned char *data_img = (unsigned char *) img->imageData;
	int i,j,k;
	for (i = 0; i < height; ++ i) {
		for (j = 0; j < width; ++ j) {
			for (k = 0; k < chanels; ++ k) {
				data_img[i * step_img + j * chanels + k] = 255 - data_img[i * step_img + j * chanels + k];
			}
		}
	}
	return img;
}

IplImage* fudiao(IplImage *img)
{
	int step_img = img->widthStep;
	int chanels = img->nChannels;
	int width = img->width;
	int height = img->height;
	IplImage *out = cvCreateImage(
			cvGetSize(img),
			IPL_DEPTH_8U,
			3
			);
	int step_out = out->widthStep;
	unsigned char *data_img = (unsigned char *) img->imageData;
	unsigned char *data_out = (unsigned char *) out->imageData;
	int i,j,k;
	for (i = 1; i < height; ++ i) {
		for (j = 0; j < width; ++ j) {
			for (k = 0; k < chanels; ++ k) {
				data_out[i * step_out + j * chanels + k] = data_img[i * step_img + j * chanels + k] - data_img[(i - 1) * step_img + j * chanels + k] + 128;
			}
		}
	}
	
	return out;
}
