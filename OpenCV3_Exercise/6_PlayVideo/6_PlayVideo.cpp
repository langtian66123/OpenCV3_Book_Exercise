#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	//������Ƶ
	VideoCapture capture("1.avi");

	//ѭ����ʾÿһ֡
	while(1){
		Mat frame;
		capture>>frame;//��ȡ��ǰ֡
		imshow("��ȡ��Ƶÿһ֡",frame);
		waitKey(30);

	}
	
	return 0;
}