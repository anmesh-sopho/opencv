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
	  {for(int k=y-2;k<y+2;k++)
	      for(int t=x-2;t<x+2;t++)
	  for(int i=0;i<3;i++)
	    img.at<Vec3b>(k,t)[i]=255;
	}
}


int main()
{
  img = Mat(500,500,CV_8UC3,Scalar(0,0,0));
  while(1){
 
	setMouseCallback("deep", callbackfunc, NULL);
	 imshow("deep", img);
int i=	waitKey(50);
 if(i==' ')
   break;}
	return 0;
}
