#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void colorReduce(Mat& inputImage,Mat& outputImage,int div);

int main(){
	Mat srcImage,dstImage;
	srcImage = imread("1.jpg");
	imshow("原图",srcImage);

	colorReduce(srcImage,dstImage,32);

	imshow("效果图",dstImage);
	
	waitKey(0);
	return 0;
}

//用动态地址计算缩减颜色空间 At
void colorReduce(Mat& inputImage,Mat& outputImage,int div){
	
	outputImage = inputImage.clone();
	
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols;

	for(int i = 0;i<rowNumber;i++){
		for(int j= 0;j<colNumber;j++){
			outputImage.at<Vec3b>(i,j)[0]=outputImage.at<Vec3b>(i,j)[0]/div * div + div/2;
			outputImage.at<Vec3b>(i,j)[1]=outputImage.at<Vec3b>(i,j)[1]/div * div + div/2;
			outputImage.at<Vec3b>(i,j)[2]=outputImage.at<Vec3b>(i,j)[2]/div * div + div/2;
		}
	}
}