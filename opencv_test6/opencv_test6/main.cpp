//
//  main.cpp
//  opencv_test6
//
//  Created by ZHHJemotion on 2016/10/10.
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


// =============================== global varibales declaration section =================
//    Describe: global variables declaration
// ========================================================================================
Mat srcImage, dstImage1, dstImage2, dstImage3; // the types of storied images
int boxFilterValue = 3; // Box Fliter 参数值
int meanBlurValue = 3; // Mean Blur Filter 参数值
int gaussianBlurValue = 3; // Gaussian Fliter 参数值


// =============================== global function declaration section ====================
//    Describe: global function declaration
// ========================================================================================
// the callback function of the Trackbar 轨迹条的回调函数
static void onBoxFilter(int, void *);  // Box Fliter
static void onMeanBlur(int, void *);  // Mean Filter
static void onGaussianBlur(int,void *);  // Gaussian Filter


// =============================== onBoxFilter() Function ===============================
//    Describe: the callback function of Box Filter
// =======================================================================================
static void onBoxFilter(int, void *)
{
    // Box Filter operation
    boxFilter(srcImage, dstImage1, -1, Size(boxFilterValue+1, boxFilterValue+1));
    // show the dstImage1
    imshow("the image of Box Filter", dstImage1);
}

// =============================== onMeanBlur() Function ================================
//    Describe: the callback function of Mean Filter
// =======================================================================================
static void onMeanBlur(int, void *)
{
    // Mean Filter operation
    blur(srcImage, dstImage2, Size(meanBlurValue+1, meanBlurValue+1));
    // show the dstImage2
    imshow("the image of Mean Blur", dstImage2);
}


// =============================== onGaussianBlur() Function ===============================
//    Deacribe: the callback function of Gaussian Fliter
// =======================================================================================
static void onGaussianBlur(int, void *)
{
    // Gaussian Filter operation
    GaussianBlur(srcImage, dstImage3, Size(gaussianBlurValue*2+1, gaussianBlurValue*2+1), 0, 0);
    // show the dstImage3
    imshow("the image of Gaussian Filter", dstImage3);
}


// =============================== main() function ==================================

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //VideoCapture cap(0);
    //if(!cap.isOpened()){
    //    return -1;
    //}
    //Mat frame;
    //
    //while(true){
    //    cap>>frame;
    //    imshow("当前视频", frame);
    //    if(waitKey(30) >= 0) break;
    //}
    
    // change the console's color
    system("color 5E");
    
    // read the original image
    srcImage = imread(PATH+string("1.jpg"),1);
    
    // Exception Handling
    if(!srcImage.data) {printf("Error: we can't read this 1.jpg!"); return false;}
    
    // clone these original images to three Mat types 克隆原图到三个Mat类型中
    dstImage1 = srcImage.clone();
    dstImage2 = srcImage.clone();
    dstImage3 = srcImage.clone();
    
    // show the original image
    namedWindow("The original Image");
    imshow("The original Image", srcImage);
    
    // ============================= Box Filter ========================================
    // create a new window
    namedWindow("the image of Box Filter");
    // create a TrackBar
    createTrackbar("内核值", "the image of Box Filter", &boxFilterValue, 40, onBoxFilter);
    onBoxFilter(boxFilterValue, 0);
    //imshow("the image of Box Filter", dstImage1);
    // ==================================================================================
    
    // ============================= Mean Blur =========================================
    // create a new window
    namedWindow("the image of Mean Blur");
    // create a TrackBar
    createTrackbar("内核值", "the image of Mean Blur", &meanBlurValue, 40, onMeanBlur);
    onMeanBlur(meanBlurValue, 0);
    //imshow("the image of Mean Blur", dstImage2);
    // ====================================================================================
    
    // ============================= Gaussian Filter =======================================
    // create a new window
    namedWindow("the image of Gaussian Filter");
    // create a TrackBar
    createTrackbar("内核值", "the image of Gaussian Filter", &gaussianBlurValue, 40, onGaussianBlur);
    onGaussianBlur(gaussianBlurValue, 0);
    //imshow("the iamge of Gaussian Filter", dstImage3);
    // ====================================================================================
    
    // output some helpful information
    cout<<endl<<"\t ok! please adjust the track bar to observe the result! \n\n"
            <<"\t when you type 'q', the program quit! \n"
            <<"\n\n\t\t\t by ZHHJemotion ";
    
    // when you type the "q", the program quit
    while (char(waitKey(1)) != 'q') {}
    
    // ====================================================================================
    // e.g the Gaussian Blur without TrackBar
    Mat image = imread(PATH+string("1.jpg"),1);
    if(!image.data){printf("Error! we can't read the image 1.jpg"); return false;}
    
    namedWindow("the original image");
    namedWindow("the output image after gaussian blur");
    
    imshow("the original image", image);
    
    Mat output;
    GaussianBlur(image, output, Size(9,9), 0, 0);
    imshow("the output image after gaussian blur", output);
    
    waitKey(0);
    

    
    return 0;
}
