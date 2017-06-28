#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<stdio.h>

using namespace cv;
using namespace std;
Mat img;
void callbackfunc(int Event, int x, int y, int flags, void *userdata)
{
	if (Event == EVENT_LBUTTONDOWN)
	{
		printf("B=%d G=%d R=%d \n", img.at<Vec3b>(x, y)[0], img.at<Vec3b>(x, y)[1], img.at<Vec3b>(x, y)[2]);
	}
}


int main()
{
	img = imread("C:\\Users\\deepa\\Downloads\\praneet\\ta.jpg", 1);
	imshow("deep", img);
	setMouseCallback("deep", callbackfunc, NULL);
	waitKey(0);
	return 0;
}
