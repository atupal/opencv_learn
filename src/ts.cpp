#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opencv.h"
#include <cv.h>
#include <highgui.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	if (argc > 1) {
		if (memcmp(argv[1], "opencv_capture", sizeof(argv[1])) == 0) {
			readVideo("/home/atupal/Downloads/东之伊甸.mp4");
		}
		if (strcmp(argv[1], "videoT") == 0) {
			printf("sf");
			readVideoWithATrackbar("/home/atupal/Downloads/东之伊甸.mp4");
		}
	}

	return 0;
}