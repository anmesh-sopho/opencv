#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<math.h>
#include <bits/stdc++.h>
using namespace cv;
using namespace std;


int main()
{
	Mat img = imread("pentagon.png", 0);
	int row = img.rows, col = img.cols, j, i, d, q, a, b, k, n, o, temp, p, s, x, y;
	d = 2 * (sqrt(row*row + col*col) + 1);
	Mat ayuy(d, 181, CV_8UC1, Scalar(0));

	Mat ayuf(row, col, CV_8UC1, Scalar(0));
	for (i = 0; i < (row); i++)
	{
		for (j = 0; j < (col); j++)
		{
			if (img.at<uchar>(i, j) == 255)
			{
				for (a = 0; a < 180; a++)
				{
					b = j*cos(CV_PI*a / 180) + i*sin(CV_PI*a / 180);
					k = b + sqrt(row*row + col*col);
					if (k>0){
						if (ayuy.at<uchar>(k, a) < 245)
							ayuy.at<uchar>(k, a) += 1;
						else
							ayuy.at<uchar>(k, a) = 255;
					}
				}
			}

		}
	}
	printf("%d", row);
	
	for (i = 0; i < d; i++)
	{
		for (j = 0; j < 181; j++)
		{
			temp = ayuy.at<uchar>(i, j);
			for (n = (i - 8); n <= (i + 8); n++)
			{
				for (o = (j - 8); o <= (j + 8); o++)
				{
					if ((n >= 0) && (o >= 0) && (n < d) && (o<180))
					{
						if (ayuy.at<uchar>(n, o)>temp)
						{
							temp = ayuy.at<uchar>(n, o);


						}
					}
				}
			}


			if ((temp >75) && (ayuy.at<uchar>(i, j) >= temp))
			{

				for (p = 0; p < col; p++)
				{
					s = ((i -sqrt(row*row+col*col)- p*cos(CV_PI*j / 180.0)) / sin(CV_PI*j / 180.0));
					if ((s < row) && (s >= 0))

						ayuf.at<uchar>(s, p) = 255;
					//printf("%d,%d\n", s, p);

				}
			}
		}
	}

	namedWindow("im", WINDOW_AUTOSIZE);
	imshow("im", img);

	namedWindow("imy", WINDOW_AUTOSIZE);
	imshow("imy", ayuy);
	namedWindow("imx", WINDOW_AUTOSIZE);
	imshow("imx", ayuf);
	waitKey(0);
	return 0;
}