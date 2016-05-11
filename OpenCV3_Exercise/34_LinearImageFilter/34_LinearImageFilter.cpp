//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV2���鱾����ʾ������34
//		��������������ͼ���˲��ۺ�ʾ��
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	2.4.9
//		2014��06�� Created by @ǳī_ë����
//		2014��11�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------


//---------------------------------��ͷ�ļ��������ռ�������֡�-------------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//	������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage,g_dstImage1,g_dstImage2,g_dstImage3;//�洢ͼƬ��Mat����
int g_nBoxFilterValue=3;  //�����˲�����ֵ
int g_nMeanBlurValue=3;  //��ֵ�˲�����ֵ
int g_nGaussianBlurValue=3;  //��˹�˲�����ֵ


//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//	������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
//�ĸ��켣���Ļص�����
static void on_BoxFilter(int, void *);		//��ֵ�˲�
static void on_MeanBlur(int, void *);		//��ֵ�˲�
static void on_GaussianBlur(int, void *);			//��˹�˲�
void ShowHelpText();


//-----------------------------------��main( )������--------------------------------------------
//	����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main(   )
{
	//�ı�console������ɫ
	system("color 5F");  

	//�����������
	ShowHelpText();

	// ����ԭͼ
	g_srcImage = imread( "1.jpg", 1 );
	if( !g_srcImage.data ) { printf("Oh��no����ȡsrcImage����~�� \n"); return false; }

	//��¡ԭͼ������Mat������
	g_dstImage1 = g_srcImage.clone( );
	g_dstImage2 = g_srcImage.clone( );
	g_dstImage3 = g_srcImage.clone( );

	//��ʾԭͼ
	namedWindow("��<0>ԭͼ���ڡ�", 1);
	imshow("��<0>ԭͼ���ڡ�",g_srcImage);


	//=================��<1>�����˲���==================
	//��������
	namedWindow("��<1>�����˲���", 1);
	//�����켣��
	createTrackbar("�ں�ֵ��", "��<1>�����˲���", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);
	//================================================

	//=================��<2>��ֵ�˲���==================
	//��������
	namedWindow("��<2>��ֵ�˲���", 1);
	//�����켣��
	createTrackbar("�ں�ֵ��", "��<2>��ֵ�˲���",&g_nMeanBlurValue, 40,on_MeanBlur );
	on_MeanBlur(g_nMeanBlurValue,0);
	//================================================

	//=================��<3>��˹�˲���=====================
	//��������
	namedWindow("��<3>��˹�˲���", 1);
	//�����켣��
	createTrackbar("�ں�ֵ��", "��<3>��˹�˲���",&g_nGaussianBlurValue, 40,on_GaussianBlur );
	on_GaussianBlur(g_nGaussianBlurValue,0);
	//================================================


	//���һЩ������Ϣ
	cout<<endl<<"\t���гɹ���������������۲�ͼ��Ч��~\n\n"
		<<"\t���¡�q����ʱ�������˳���\n";

	//���¡�q����ʱ�������˳�
	while(char(waitKey(1)) != 'q') {}

	return 0;
}


//-----------------------------��on_BoxFilter( )������------------------------------------
//	�����������˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_BoxFilter(int, void *)
{
	//�����˲�����
	boxFilter( g_srcImage, g_dstImage1, -1,Size( g_nBoxFilterValue+1, g_nBoxFilterValue+1));
	//��ʾ����
	imshow("��<1>�����˲���", g_dstImage1);
}


//-----------------------------��on_MeanBlur( )������------------------------------------
//	��������ֵ�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_MeanBlur(int, void *)
{
	//��ֵ�˲�����
	blur( g_srcImage, g_dstImage2, Size( g_nMeanBlurValue+1, g_nMeanBlurValue+1), Point(-1,-1));
	//��ʾ����
	imshow("��<2>��ֵ�˲���", g_dstImage2);
}


//-----------------------------��ContrastAndBright( )������------------------------------------
//	��������˹�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_GaussianBlur(int, void *)
{
	//��˹�˲�����
	GaussianBlur( g_srcImage, g_dstImage3, Size( g_nGaussianBlurValue*2+1, g_nGaussianBlurValue*2+1 ), 0, 0);
	//��ʾ����
	imshow("��<3>��˹�˲���", g_dstImage3);
}


//-----------------------------------��ShowHelpText( )������----------------------------------
//		 ���������һЩ������Ϣ
//----------------------------------------------------------------------------------------------
void ShowHelpText()
{
	//�����ӭ��Ϣ��OpenCV�汾
	printf("\n\n\t\t\t�ǳ���л����OpenCV3������š�һ�飡\n");
	printf("\n\n\t\t\t��Ϊ����OpenCV2��ĵ�34������ʾ������\n");
	printf("\n\n\t\t\t   ��ǰʹ�õ�OpenCV�汾Ϊ��" CV_VERSION );
	printf("\n\n  ----------------------------------------------------------------------------\n");
}