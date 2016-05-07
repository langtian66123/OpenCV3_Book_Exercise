#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	VideoCapture capture(0); //����Ϊ0������ȡ����ͷ
	Mat frame,edges;
	
	while(1){
		capture>>frame;

		//��Ե���
		cvtColor(frame,edges,CV_BayerRG2GRAY);
		blur(edges,edges,Size(7,7));
		Canny(edges,edges,0,30,3);

		imshow("��ȡ��Ƶ",edges);
		if(waitKey(30)>=0)
			break;
	}
	return 0;
}