#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	VideoCapture capture(0); //参数为0，即获取摄像头
	Mat edges;
	
	while(1){
		Mat frame;
		capture >> frame;

		//边缘检测
		if(!frame.empty()){ //注意一定要加上if判断，不然会抛出异常
			cvtColor(frame,edges,CV_BGR2GRAY);
			blur(edges,edges,Size(7,7));
			Canny(edges,edges,0,30,3);
			imshow("读取视频",edges);
			if(waitKey(30)>=0)
				break;
		}

		//if(!frame.empty()){
		//	imshow("读取视频",frame);
		//}

		//waitKey(30);
	}
	return 0;
}