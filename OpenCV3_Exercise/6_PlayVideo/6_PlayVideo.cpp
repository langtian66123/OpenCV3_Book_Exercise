#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	//读入视频
	VideoCapture capture("1.avi");

	//循环显示每一帧
	while(1){
		Mat frame;
		capture>>frame;//读取当前帧
		imshow("读取视频每一帧",frame);
		waitKey(30);

	}
	
	return 0;
}