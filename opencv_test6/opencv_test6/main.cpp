//
//  main.cpp
//  opencv_test6
//
//  Created by 张行剑 on 2016/10/10.
//  Copyright © 2016年 Lukas_Zhang. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include"opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

#define PATH string("/Users/zhangxingjian/Desktop/Programming/C++/OpenCV/opencv_test6/opencv_test6/opencv_test6/")

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    VideoCapture cap(0);
    if(!cap.isOpened()){
        return -1;
    }
    Mat frame;
    
    while(true){
        cap>>frame;
        imshow("当前视频", frame);
        if(waitKey(30) >= 0) break;
    }
    
    return 0;
}
