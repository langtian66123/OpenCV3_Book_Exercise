//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV2���鱾����ʾ������40
//		����������ͼ��ʴ�������ۺ�ʾ��
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	2.4.9
//		2014��06�� Created by @ǳī_ë����
//		2014��11�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------



//---------------------------------��ͷ�ļ��������ռ�������֡�-----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage, g_dstImage;//ԭʼͼ��Ч��ͼ
int g_nTrackbarNumer = 0;//0��ʾ��ʴerode, 1��ʾ����dilate
int g_nStructElementSize = 3; //�ṹԪ��(�ں˾���)�ĳߴ�


//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
void Process();//���ͺ͸�ʴ�Ĵ�������
void on_TrackbarNumChange(int, void *);//�ص�����
void on_ElementSizeChange(int, void *);//�ص�����
void ShowHelpText();

//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main( )
{
	//�ı�console������ɫ
	system("color 2F");  

	//����ԭͼ
	g_srcImage = imread("1.jpg");
	if( !g_srcImage.data ) { printf("��ȡsrcImage����~�� \n"); return false; }

	ShowHelpText();

	//��ʾԭʼͼ
	namedWindow("��ԭʼͼ��");
	imshow("��ԭʼͼ��", g_srcImage);

	//���г��θ�ʴ��������ʾЧ��ͼ
	namedWindow("��Ч��ͼ��");
	//��ȡ�Զ����
	Mat element = getStructuringElement(MORPH_RECT, Size(2*g_nStructElementSize+1, 2*g_nStructElementSize+1),Point( g_nStructElementSize, g_nStructElementSize ));
	erode(g_srcImage, g_dstImage, element);
	imshow("��Ч��ͼ��", g_dstImage);

	//�����켣��
	createTrackbar("��ʴ/����", "��Ч��ͼ��", &g_nTrackbarNumer, 1, on_TrackbarNumChange);
	createTrackbar("�ں˳ߴ�", "��Ч��ͼ��", &g_nStructElementSize, 21, on_ElementSizeChange);

	//���һЩ������Ϣ
	cout<<endl<<"\t���гɹ���������������۲�ͼ��Ч��~\n\n"
		<<"\t���¡�q����ʱ�������˳���\n";

	//��ѯ��ȡ������Ϣ������q���������˳�
	while(char(waitKey(1)) != 'q') {}

	return 0;
}

//-----------------------------��Process( )������------------------------------------
//		�����������Զ���ĸ�ʴ�����Ͳ���
//-----------------------------------------------------------------------------------------
void Process() 
{
	//��ȡ�Զ����
	Mat element = getStructuringElement(MORPH_RECT, Size(2*g_nStructElementSize+1, 2*g_nStructElementSize+1),Point( g_nStructElementSize, g_nStructElementSize ));

	//���и�ʴ�����Ͳ���
	if(g_nTrackbarNumer == 0) {    
		erode(g_srcImage, g_dstImage, element);
	}
	else {
		dilate(g_srcImage, g_dstImage, element);
	}

	//��ʾЧ��ͼ
	imshow("��Ч��ͼ��", g_dstImage);
}


//-----------------------------��on_TrackbarNumChange( )������------------------------------------
//		��������ʴ������֮���л����صĻص�����
//-----------------------------------------------------------------------------------------------------
void on_TrackbarNumChange(int, void *) 
{
	//��ʴ������֮��Ч���Ѿ��л����ص��������������һ��Process������ʹ�ı���Ч��������Ч����ʾ����
	Process();
}


//-----------------------------��on_ElementSizeChange( )������-------------------------------------
//		��������ʴ�����Ͳ����ں˸ı�ʱ�Ļص�����
//-----------------------------------------------------------------------------------------------------
void on_ElementSizeChange(int, void *)
{
	//�ں˳ߴ��Ѹı䣬�ص��������������һ��Process������ʹ�ı���Ч��������Ч����ʾ����
	Process();
}


//-----------------------------------��ShowHelpText( )������-----------------------------
//		 ���������һЩ������Ϣ
//----------------------------------------------------------------------------------------------
void ShowHelpText()
{
	//�����ӭ��Ϣ��OpenCV�汾
	printf("\n\n\t\t\t�ǳ���л����OpenCV3������š�һ�飡\n");
	printf("\n\n\t\t\t��Ϊ����OpenCV2��ĵ�40������ʾ������\n");
	printf("\n\n\t\t\t   ��ǰʹ�õ�OpenCV�汾Ϊ��" CV_VERSION );
	printf("\n\n  ----------------------------------------------------------------------------\n");
}