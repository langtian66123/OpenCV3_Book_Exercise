#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	VideoCapture capture(0); //参数为0，即获取摄像头
	Mat frame,edges;
	
	while(1){
		capture>>frame;

		//边缘检测
		cvtColor(frame,edges,CV_BayerRG2GRAY);
		blur(edges,edges,Size(7,7));
		Canny(edges,edges,0,30,3);

		imshow("读取视频",edges);
		if(waitKey(30)>=0)
			break;
	}
	return 0;
}