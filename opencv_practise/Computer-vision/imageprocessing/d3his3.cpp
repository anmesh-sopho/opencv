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
	img1 = imread("a.png", 1);
	Mat his(400, 256, CV_8UC1, Scalar(255));
	Mat his1(400, 256, CV_8UC1, Scalar(255));
	Mat his2(400, 256, CV_8UC1, Scalar(255));
	int arr[256],arr1[256],arr2[256], i, j, max = img1.at<uchar>(0,0)[0],max1 = img1.at<uchar>(0,0)[1],max2 = img1.at<uchar>(0,0)[2];
	double sc = 0.0,sc1 = 0.0,sc2 = 0.0;

	for (i = 0; i < 256; i++) 
		{arr[i] = 0;}
	for (i = 0; i < img1.rows; i++)
	{

		for (j = 0; j < img1.cols; j++)
		{
			arr[img1.at<uchar>(i, j)]++;
			arr1[img1.at<uchar>(i, j)]++;
			arr2[img1.at<uchar>(i, j)]++;
		}
	}
	for (i = 0; i < 256; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (max1 < arr1[i])
			max1 = arr1[i];
		if (max2 < arr2[i])
			max2 = arr2[i];

	}
		sc = 1000.0/max;
		printf("%f", sc);


	for (i = 0; i < 256; i++)
	{
		for (j = 0; j<arr[i] * sc; j++)
		{
			his.at<uchar>(399 - j, i) = 0;

		}

		for (j = 0; j<arr1[i] * sc; j++)
		{
			his1.at<uchar>(399 - j, i) = 0;
			
		}

		for (j = 0; j<arr2[i] * sc; j++)
		{
			his2.at<uchar>(399 - j, i) = 0;
			
		}
	}

	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("Original", img1);
	namedWindow("Histogram", WINDOW_AUTOSIZE);
	imshow("Histogram", his);
	namedWindow("Histogram1", WINDOW_AUTOSIZE);
	imshow("Histogram1", his1);
	namedWindow("Histogram2", WINDOW_AUTOSIZE);
	imshow("Histogram2", his2);
	waitKey(0);
	return 0;
}