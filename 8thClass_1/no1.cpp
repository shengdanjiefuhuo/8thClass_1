#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat practise1;
	cv::Mat srcMat = cv::imread("C:/Users/hp/Desktop/5.jpg", 1);

	cv::Point2f center(srcMat.cols / 2.0, srcMat.rows / 2.0);
	cv::Mat rot = cv::getRotationMatrix2D(center, -10.0, 1);

	//获取外界四边形
	cv::Rect bbox = cv::RotatedRect(center, srcMat.size(), -10.0).boundingRect();
	//调整仿射矩阵参数
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	//仿射变换
	cv::warpAffine(srcMat, practise1, rot, bbox.size());
	
	cv::imshow("crc", srcMat);
	cv::imshow("practise1", practise1);
	
	waitKey(0);

}