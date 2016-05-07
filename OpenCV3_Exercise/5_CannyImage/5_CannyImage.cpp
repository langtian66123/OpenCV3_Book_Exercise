#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
	Mat srcImage = imread("1.jpg");
	imshow("ԭͼ-Canny��Ե���",srcImage);

	Mat dstImage,edge,grayImage;

	//������srcͬ���ͺʹ�С�ľ��� ----------------------------û�п�����ʲô���أ�
	//dstImage.create(srcImage.size(),srcImage.type());

	//��ͼ��ת��Ϊ�Ҷ�ͼ
	cvtColor(srcImage,grayImage,CV_BGR2GRAY);
	//ʹ��3*3�ں������루ͼ��ģ����
	blur(grayImage,edge,Size(3,3));

	//����Canny����
	Canny(edge,edge,3,9,3);

	imshow("Ч��ͼ-Canny��Ե���",edge);

	waitKey(0);
	return 0;
}