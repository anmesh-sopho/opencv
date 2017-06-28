#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{int t=0;
  double  gx[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
  double  gy[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
  double  x=0, y=0;
  int i,j,n,m;
  namedWindow("out",WINDOW_NORMAL);
  createTrackbar("edge","out",&t,255);
 
  while(1){
     Mat img=imread("dance.jpg",0);
  Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));
  for(i=0;i<img.rows;i++)//binary conversion
      for(j=0;j<img.cols;j++)
	{
	  if(img.at<uchar>(i,j)>t)
	    img.at<uchar>(i,j)=255;
	  else
	    img.at<uchar>(i,j)=0;
	}


  
  
  
  for(i=1;i<img.rows-1;i++)//finding edge 
    for(j=1;j<img.cols-1;j++)
      {
	for(n=i-1;n<i+2;n++)
	  for(m=j-1;m<j+2;m++)
	    {
	      x+=(img.at<uchar>(n,m)*gx[n+1-i][m+1-j]);
	      y+=(img.at<uchar>(n,m)*gy[n+1-i][m+1-j]);
	    }
	x/=4;
	y/=4;
	a.at<uchar>(i,j)=sqrt(x*x+y*y);
	x=y=0;
      }
  imshow("out",a);
 i= waitKey(50);
 if(i==' ')
 break;}
  return(0);
}
