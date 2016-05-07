#include <opencv2\opencv.hpp>
using namespace cv;

int main(){
	Mat img = imread("1.jpg");
	imshow("载入的图片",img);
	//等待6000 ms后窗口自动关闭
	waitKey(6000);
}