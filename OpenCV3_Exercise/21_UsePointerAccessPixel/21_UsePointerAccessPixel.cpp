#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void colorReduce(Mat& inputImage, Mat& outputImage, int div);

int main(){
	Mat srcImage = imread("1.jpg");
	imshow("ԭʼͼ��",srcImage);

	Mat dstImage;
	dstImage.create(srcImage.rows,srcImage.cols,srcImage.type());

	//��¼��ʼʱ��
	double time0 = static_cast<double>(getTickCount());

	colorReduce(srcImage,dstImage,32);

	time0 = ((double)getTickCount() - time0)/getTickFrequency();

	cout<<"�˷�������ʱ��Ϊ�� "<<time0<<"��"<<endl;

	imshow("Ч��ͼ",dstImage);

	waitKey(0);
	return 0;
}

//��ָ���������
void colorReduce(Mat& inputImage,Mat& outputImage,int div){
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols * outputImage.channels();

	for(int i = 0;i<rowNumber;i++){
		uchar* data = outputImage.ptr<uchar>(i);  //��ȡ��i�е��׵�ַ

		for(int j = 0;j<colNumber;j++){
			data[j] = data[j]/div * div + div/2;
		}
	}
}