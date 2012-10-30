# $@  表示目标文件
# $^  表示所有的依赖文件
# $<  表示第一个依赖文件
# $?  表示比目标还要新的依赖文件列表

require=src/opencv.h bin/video.o
opencv_arg=-I /usr/include/opencv -L /usr/lib -lm -lopencv_core -lopencv_highgui #-lopencv_imgproc

bin/opencv:src/opencv.cpp $(require)
	g++ -g $^ -o $@ $(opencv_arg)

bin/ts:src/ts.cpp $(require)
	g++ -g $^ -o $@ $(opencv_arg)

bin/video.o:src/opencv_video.cpp src/opencv.h
	g++ -c $< -g $(opencv_arg) -o bin/video.o

clean:
	rm *.o
