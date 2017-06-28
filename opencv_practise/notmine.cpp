#include <bits/stdc++.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main(int argv,char *argc[])
{
	Mat a=imread(argc[1],0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	int arr[9],i,j,k,l,c=0;
	int sumgx=0,sumgy=0,sum;
	int gx[9]={-1,0,1,-2,0,2,-1,0,1};
	int gy[9]={-1,-2,-1,0,0,0,1,2,1};
	int tr=0;
        namedWindow("Terminal",WINDOW_NORMAL);
	createTrackbar("TrackEdge","Terminal",&tr,255);
	while(1)
	{
	for(i=1;i<a.rows-1;i++)
	{
		for(j=1;j<a.cols-1;j++)
		{
			c=0;sumgx=0;sumgy=0;
			for(k=i-1;k<=i+1;k++)
			{
				for(l=j-1;l<=j+1;l++)
				{
					sumgx=sumgx+(gx[c]*a.at<uchar>(k,l));
					sumgy=sumgy+(gy[c]*a.at<uchar>(k,l));
					c++;
				}
			}
			sumgx=sumgx/4;
			sumgy=sumgy/4;
			sum=(int)(sqrt(sumgx*sumgx)+(sumgy*sumgy));
			sum=(int)(sum/1.414);
			if(sum>=tr)
				b.at<uchar>(i,j)=255;
			else
				b.at<uchar>(i,j)=0;
		}
	}
	imshow("Terminal",b);
	imshow("Original",a);
	char c=waitKey(50);
	if(c=='e')
		break;
	}
	return 0;
}
