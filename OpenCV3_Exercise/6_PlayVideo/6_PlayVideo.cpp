#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	//������Ƶ
	VideoCapture capture("1.avi");
	Mat edge;
	//ѭ����ʾÿһ֡
	while(1){
		Mat frame;
		capture>>frame;//��ȡ��ǰ֡

		////��Ե��⴦��
		//cvtColor(frame,edge,CV_BGR2GRAY);//�Ҷ�
		//blur(edge,edge,Size(7,7));//����
		//Canny(edge,edge,0,30,3);//Canny��Ե���

		imshow("��ȡ��Ƶÿһ֡",frame);
		if(waitKey(30)>=0) 
			break;

	}
	
	return 0;
}