#include"opencv2/opencv.hpp"
#include<opencv2/core/core.hpp>
#include"opencv2/imgproc/imgproc.hpp"
#include<opencv2/highgui/highgui.hpp>
using namespace std;

using namespace cv;


int main()
{

	Mat	img1 = imread("veg.jpg", 0);
	int i, j, k, l, th = 0, gx = 0, gy = 0, c = 0;
	double g = 0.0;
	Mat img2(img1.rows, img1.cols, CV_8UC1, Scalar(0));
	int kernel = 3;
	int arr1[9] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
	int arr2[9] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Filter", WINDOW_AUTOSIZE);
	imshow("Original", img1);
	createTrackbar("Edges", "Filter", &th, 250);
	while (1)
	{

		for (i = 1; i < img1.rows - 1; i++)
		{
			for (j = 1; j < img1.cols - 1; j++)
			{
				gx = 0; c = 0, gy = 0;
				for (k = 2 - kernel; k < kernel - 1; k++)
				{
					for (l = 2 - kernel; l < kernel - 1; l++)
					{
						gx += (img1.at<uchar>(i + k, j + l)*arr1[c]);
						gy += (img1.at<uchar>(i + k, j + l)*arr2[c]);

						c++;

					}
					gx = abs(gx);
					gy = abs(gy);
					g = sqrt(gx*gx + gy*gy);

					if (g < th)
						img2.at<uchar>(i, j) = 0;
					else
						img2.at<uchar>(i, j) = 255;

				}
			}
		}
		imshow("Filter", img2);

		char p = waitKey(50);
		if (p == 'e')
			break;
	}
	return 0;
}