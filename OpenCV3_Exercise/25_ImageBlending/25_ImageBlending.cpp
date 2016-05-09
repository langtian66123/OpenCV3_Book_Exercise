/*
初级图像混合操作
（1）图像ROI叠加，图像掩膜
（2）图像线性混合操作
（3）图像ROI线性混合操作
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
		cout<<endl<<"运行成功，得出了你所需要的图像~！："<<endl;
	}

	waitKey(0);
	return 0;
}

bool ROI_AddImage(){
	Mat srcImage1 = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");

	if(!srcImage1.data){
		printf("读取srcImage1错误\n");
		return false;
	}
	if(!logoImage.data){
		printf("读取logoImage错误\n");
		return false;
	}

	//定义ROI区域，使用Rect
	Mat imageROI = srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));
	//定义ROI区域，使用行、列范围
	//Mat imageROI = srcImage1(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

	//加载掩膜（必须为灰度图）
	Mat mask = imread("dota_logo.jpg",0); //0代表灰度图像

	//将掩膜复制到ROI
	logoImage.copyTo(imageROI,mask);

	namedWindow("<1>利用ROI实现图像叠加示例窗口");
	imshow("<1>利用ROI实现图像叠加示例窗口",srcImage1);

	return true;
}

//图像线性混合操作
bool LinearBlending(){

	double alphaValue = 0.7;
	double betaValue;

	Mat srcImage2 = imread("mogu.jpg");
	Mat srcImage3 = imread("rain.jpg");
	Mat dstImage;
	
	//进行图像混合加权操作
	betaValue = 1.0 - alphaValue;
	addWeighted(srcImage2,alphaValue,srcImage3,betaValue,0.0,dstImage);

	imshow("<2>线性混合示例窗口【原图1】",srcImage2);
	imshow("<2>线性混合示例窗口【原图2】",srcImage3);
	imshow("<2>线性混合示例窗口【效果图】",dstImage);

	return true;
}

bool ROI_LinearBlending(){
	Mat srcImage4 = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");

	if(!srcImage4.data){
		printf("读取srcImage1错误\n");
		return false;
	}
	if(!logoImage.data){
		printf("读取logoImage错误\n");
		return false;
	}

	//定义ROI区域，使用Rect
	Mat imageROI = srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));
	//定义ROI区域，使用行、列范围
	//Mat imageROI = srcImage1(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

	addWeighted(imageROI,0.5,logoImage,0.3,0.0,imageROI);

	imshow("<3>ROI_线性混合示例窗口【效果图】",srcImage4);

	return true;
}