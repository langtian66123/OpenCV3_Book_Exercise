#include<opencv2/opencv.hpp>
using namespace cv;

int main(){
	Mat srcImage = imread("1.jpg");
	imshow("图像显示",srcImage);
	//等待任意按键按下
	waitKey(0);
	return 0;
}