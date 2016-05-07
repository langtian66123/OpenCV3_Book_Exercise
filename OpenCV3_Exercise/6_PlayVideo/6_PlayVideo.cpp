#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	//读入视频
	VideoCapture capture("1.avi");
	Mat edge;
	//循环显示每一帧
	while(1){
		Mat frame;
		capture>>frame;//读取当前帧

		////边缘检测处理
		//cvtColor(frame,edge,CV_BGR2GRAY);//灰度
		//blur(edge,edge,Size(7,7));//降噪
		//Canny(edge,edge,0,30,3);//Canny边缘检测

		imshow("读取视频每一帧",frame);
		if(waitKey(30)>=0) 
			break;

	}
	
	return 0;
}