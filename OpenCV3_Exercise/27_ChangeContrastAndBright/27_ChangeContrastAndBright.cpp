#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void on_ContrastAndBright(int, void*);

int g_nContrastValue; //对比度值
int g_nBrightValue;	//亮度值
Mat g_srcImage,g_dstImage;

int main(){
	
	g_srcImage = imread("1.jpg");
	if(!g_srcImage.data){
		printf("读取图片错误");
		return false;
	}

	g_dstImage = Mat::zeros(g_srcImage.size(),g_srcImage.type());

	g_nContrastValue=80;
	g_nBrightValue=80;

	namedWindow("【效果图窗口】",0);
	createTrackbar("对比度：","【效果图窗口】",&g_nContrastValue,300,on_ContrastAndBright);
	createTrackbar("亮度：","【效果图窗口】",&g_nBrightValue,200,on_ContrastAndBright);

	on_ContrastAndBright(g_nContrastValue,0);
	on_ContrastAndBright(g_nBrightValue,0);

	while(char(waitKey(1))!='q'){}
	return 0;
}

//改变图像对比度和亮度值的回调函数
void on_ContrastAndBright(int,void*){
	namedWindow("【原始图窗口】",0);

	//三个for循环，执行运算g_dstImage(i,j) = a*g_srcImage(i,j) + b
	for(int r=0;r<g_srcImage.rows;r++){
		for(int c=0;c<g_srcImage.cols;c++){
			for(int i=0;i<3;i++){
				//saturate_cast函数用于进行溢出保护
				g_dstImage.at<Vec3b>(r,c)[i] = (saturate_cast<uchar>)((g_nContrastValue * 0.01)*(g_srcImage.at<Vec3b>(r,c)[i]) + g_nBrightValue);
			}
		}
	}

	imshow("【原始图窗口】",g_srcImage);
	imshow("【效果图窗口】",g_dstImage);
}