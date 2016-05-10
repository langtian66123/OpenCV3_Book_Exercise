#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void on_ContrastAndBright(int, void*);

int g_nContrastValue; //�Աȶ�ֵ
int g_nBrightValue;	//����ֵ
Mat g_srcImage,g_dstImage;

int main(){
	
	g_srcImage = imread("1.jpg");
	if(!g_srcImage.data){
		printf("��ȡͼƬ����");
		return false;
	}

	g_dstImage = Mat::zeros(g_srcImage.size(),g_srcImage.type());

	g_nContrastValue=80;
	g_nBrightValue=80;

	namedWindow("��Ч��ͼ���ڡ�",0);
	createTrackbar("�Աȶȣ�","��Ч��ͼ���ڡ�",&g_nContrastValue,300,on_ContrastAndBright);
	createTrackbar("���ȣ�","��Ч��ͼ���ڡ�",&g_nBrightValue,200,on_ContrastAndBright);

	on_ContrastAndBright(g_nContrastValue,0);
	on_ContrastAndBright(g_nBrightValue,0);

	while(char(waitKey(1))!='q'){}
	return 0;
}

//�ı�ͼ��ԱȶȺ�����ֵ�Ļص�����
void on_ContrastAndBright(int,void*){
	namedWindow("��ԭʼͼ���ڡ�",0);

	//����forѭ����ִ������g_dstImage(i,j) = a*g_srcImage(i,j) + b
	for(int r=0;r<g_srcImage.rows;r++){
		for(int c=0;c<g_srcImage.cols;c++){
			for(int i=0;i<3;i++){
				//saturate_cast�������ڽ����������
				g_dstImage.at<Vec3b>(r,c)[i] = (saturate_cast<uchar>)((g_nContrastValue * 0.01)*(g_srcImage.at<Vec3b>(r,c)[i]) + g_nBrightValue);
			}
		}
	}

	imshow("��ԭʼͼ���ڡ�",g_srcImage);
	imshow("��Ч��ͼ���ڡ�",g_dstImage);
}