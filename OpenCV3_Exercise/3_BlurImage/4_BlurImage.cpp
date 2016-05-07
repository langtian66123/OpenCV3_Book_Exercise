#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(){
	Mat srcImage = imread("1.jpg");
	imshow("原图-图像模糊-均值滤波",srcImage);

	//进行均值滤波操作
	Mat dstImage;
	blur(srcImage,dstImage,Size(7,7));

	imshow("效果图-均值滤波",dstImage);

	waitKey(0);

	return 0;
}