/*
����ͼ���ϲ���
��1��ͼ��ROI���ӣ�ͼ����Ĥ
��2��ͼ�����Ի�ϲ���
��3��ͼ��ROI���Ի�ϲ���
*/

#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;

bool ROI_AddImage();
bool LinearBlending();
bool ROI_LinearBlending();

int main(){
	system("color 5E");

	if(ROI_AddImage() && LinearBlending() && ROI_LinearBlending()){
		cout<<endl<<"���гɹ����ó���������Ҫ��ͼ��~����"<<endl;
	}

	waitKey(0);
	return 0;
}

bool ROI_AddImage(){
	Mat srcImage1 = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");

	if(!srcImage1.data){
		printf("��ȡsrcImage1����\n");
		return false;
	}
	if(!logoImage.data){
		printf("��ȡlogoImage����\n");
		return false;
	}

	//����ROI����ʹ��Rect
	Mat imageROI = srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));
	//����ROI����ʹ���С��з�Χ
	//Mat imageROI = srcImage1(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

	//������Ĥ������Ϊ�Ҷ�ͼ��
	Mat mask = imread("dota_logo.jpg",0); //0����Ҷ�ͼ��

	//����Ĥ���Ƶ�ROI
	logoImage.copyTo(imageROI,mask);

	namedWindow("<1>����ROIʵ��ͼ�����ʾ������");
	imshow("<1>����ROIʵ��ͼ�����ʾ������",srcImage1);

	return true;
}

//ͼ�����Ի�ϲ���
bool LinearBlending(){

	double alphaValue = 0.7;
	double betaValue;

	Mat srcImage2 = imread("mogu.jpg");
	Mat srcImage3 = imread("rain.jpg");
	Mat dstImage;
	
	//����ͼ���ϼ�Ȩ����
	betaValue = 1.0 - alphaValue;
	addWeighted(srcImage2,alphaValue,srcImage3,betaValue,0.0,dstImage);

	imshow("<2>���Ի��ʾ�����ڡ�ԭͼ1��",srcImage2);
	imshow("<2>���Ի��ʾ�����ڡ�ԭͼ2��",srcImage3);
	imshow("<2>���Ի��ʾ�����ڡ�Ч��ͼ��",dstImage);

	return true;
}

bool ROI_LinearBlending(){
	Mat srcImage4 = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");

	if(!srcImage4.data){
		printf("��ȡsrcImage1����\n");
		return false;
	}
	if(!logoImage.data){
		printf("��ȡlogoImage����\n");
		return false;
	}

	//����ROI����ʹ��Rect
	Mat imageROI = srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));
	//����ROI����ʹ���С��з�Χ
	//Mat imageROI = srcImage1(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

	addWeighted(imageROI,0.5,logoImage,0.3,0.0,imageROI);

	imshow("<3>ROI_���Ի��ʾ�����ڡ�Ч��ͼ��",srcImage4);

	return true;
}