#include"opencv2/opencv.hpp"
#include<opencv2/core/core.hpp>
#include"opencv2/imgproc/imgproc.hpp"
#include<opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>


using namespace std;

using namespace cv;



int main()
{

	Mat img1;
	img1 = imread("a.png", 0);
	Mat his(400, 256, CV_8UC1, Scalar(255));
	int arr[256], i, j, max = img1.at<uchar>(0,0);
	double sc = 0.0;

	for (i = 0; i < 256; i++) 
		{arr[i] = 0;}
	for (i = 0; i < img1.rows; i++)
	{

		for (j = 0; j < img1.cols; j++)
		{
			arr[img1.at<uchar>(i, j)]++;
			
		}
	}
	for (i = 0; i < 256; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
		sc = 1000.0/max;
		printf("%f", sc);


	for (i = 0; i < 256; i++)
	{
		for (j = 0; j<arr[i] * sc; j++)
		{
			his.at<uchar>(399 - j, i) = 0;
		}
	}

	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("Original", img1);
	namedWindow("Histogram", WINDOW_AUTOSIZE);
	imshow("Histogram", his);
	waitKey(0);
	return 0;
}