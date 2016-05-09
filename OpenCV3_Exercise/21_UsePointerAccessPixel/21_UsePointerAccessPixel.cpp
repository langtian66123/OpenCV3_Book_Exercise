#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void colorReduce(Mat& inputImage, Mat& outputImage, int div);

int main(){
	Mat srcImage = imread("1.jpg");
	imshow("原始图像",srcImage);

	Mat dstImage;
	dstImage.create(srcImage.rows,srcImage.cols,srcImage.type());

	//记录起始时间
	double time0 = static_cast<double>(getTickCount());

	colorReduce(srcImage,dstImage,32);

	time0 = ((double)getTickCount() - time0)/getTickFrequency();

	cout<<"此方法运行时间为： "<<time0<<"秒"<<endl;

	imshow("效果图",dstImage);

	waitKey(0);
	return 0;
}

//用指针访问像素
void colorReduce(Mat& inputImage,Mat& outputImage,int div){
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols * outputImage.channels();

	for(int i = 0;i<rowNumber;i++){
		uchar* data = outputImage.ptr<uchar>(i);  //获取第i行的首地址

		for(int j = 0;j<colNumber;j++){
			data[j] = data[j]/div * div + div/2;
		}
	}
}