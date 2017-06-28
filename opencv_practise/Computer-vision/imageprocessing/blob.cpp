#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include<bits/stdc++.h>
#include"iostream"

using namespace cv;
using namespace std;

 Mat img=imread("binary.png",0);
 Mat visited(img.rows,img.cols,CV_8UC1,Scalar(0));

int cnt;

void DFS_VISIT(int i,int j)
{
	int k,l;

    visited.at<uchar>(i,j) = 255/cnt;

	for(k=i-1;k<=i+1;k++)
		for(l=j-1;l<=j+1;l++)
			if((visited.at<uchar>(k,l)==0)&&(img.at<uchar>(k,l)==255))
				DFS_VISIT(k,l);

}

int main ()
{
  int i,j;
  cnt=1;

for (i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
	{
		if((visited.at<uchar>(i,j)==0)&&(img.at<uchar>(i,j)==255))
		{
			DFS_VISIT(i,j);
			cnt++;
		}
	}
namedWindow("color",WINDOW_AUTOSIZE);
imshow("color",visited);
imshow("color2",img);
waitKey(0);
return 0;
}
