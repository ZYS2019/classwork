#include<opencv.hpp>

using namespace cv;

int main()
{
	Mat src = imread("C:/Users/SZJ/Desktop/1.jpg");
	//Mat dst(src.rows, src.cols, CV_8UC3);
	//Mat srcgray = imread("C:/Users/SZJ/Desktop/1.jpg", 0);
	Mat deepMat;
	Mat shallowMat;

	src.copyTo(deepMat);
	shallowMat = src;
	
	int height = src.rows;
	int weight = src.cols;
	uchar threshold = 200;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			
			uchar average = (src.at<Vec3b>(i, j)[0] + src.at<Vec3b>(i, j)[1] + src.at<Vec3b>(i, j)[2]) / 3;
			if (average > threshold) {
				average = 255;
			}
			else {
				average = 0;
			}
			src.at<Vec3b>(i, j)[0] = average;
			src.at<Vec3b>(i, j)[1] = average;
			src.at<Vec3b>(i, j)[2] = average;
		}
	}

	imshow("src", src);
	imshow("deepMat", deepMat);
	imshow("shallowMat", shallowMat);
	//imshow("dst", dst);
	//imshow("∂¡»Îª“∂»Õº", srcgray);
	waitKey(0);
	return 0;
}


