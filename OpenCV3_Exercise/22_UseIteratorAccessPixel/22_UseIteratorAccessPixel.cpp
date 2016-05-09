#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void colorReduce(Mat& inputImage,Mat& outputImage,int div);

int main(){
	
	Mat srcImage = imread("1.jpg");
	imshow("原图",srcImage);

	Mat dstImage;
	//dstImage.create(srcImage.rows,srcImage.cols,srcImage.type());

	double time0 = static_cast<double>(getTickCount());
	colorReduce(srcImage,dstImage,32);
	time0 = ((double)getTickCount() - time0)/getTickFrequency();

	imshow("效果图",dstImage);
	waitKey(0);

	return 0;
}

//用迭代器缩减颜色空间
void colorReduce(Mat& inputImage,Mat& outputImage,int div){
	outputImage = inputImage.clone();
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();
	//存取彩色图像像素
	for(;it!=itend;++it){
		//处理每个像素
		(*it)[0] = (*it)[0]/div * div + div/2;
		(*it)[1] = (*it)[1]/div * div + div/2;
		(*it)[2] = (*it)[2]/div * div + div/2;
	}
}