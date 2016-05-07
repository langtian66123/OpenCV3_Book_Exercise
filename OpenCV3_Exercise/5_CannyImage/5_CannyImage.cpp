#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	Mat srcImage = imread("1.jpg");
	imshow("原图-Canny边缘检测",srcImage);

	Mat dstImage,edge,grayImage;

	//创建与src同类型和大小的矩阵 ----------------------------没有看懂有什么用呢？
	//dstImage.create(srcImage.size(),srcImage.type());

	//将图像转换为灰度图
	cvtColor(srcImage,grayImage,CV_BGR2GRAY);
	//使用3*3内核来降噪（图像模糊）
	blur(grayImage,edge,Size(3,3));

	//运行Canny算子
	Canny(edge,edge,3,9,3);

	imshow("效果图-Canny边缘检测",edge);

	waitKey(0);
	return 0;
}