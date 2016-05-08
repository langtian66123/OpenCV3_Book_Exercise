#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	VideoCapture capture(0); //����Ϊ0������ȡ����ͷ
	Mat edges;
	
	while(1){
		Mat frame;
		capture >> frame;

		//��Ե���
		if(!frame.empty()){ //ע��һ��Ҫ����if�жϣ���Ȼ���׳��쳣
			cvtColor(frame,edges,CV_BGR2GRAY);
			blur(edges,edges,Size(7,7));
			Canny(edges,edges,0,30,3);
			imshow("��ȡ��Ƶ",edges);
			if(waitKey(30)>=0)
				break;
		}

		//if(!frame.empty()){
		//	imshow("��ȡ��Ƶ",frame);
		//}

		//waitKey(30);
	}
	return 0;
}