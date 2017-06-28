#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace cv;
using namespace std;
 Mat a=imread("pentagon.png",0);

Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));

int main()
{
  int i,j,n,th=30,m,k,count;
   namedWindow("line",WINDOW_AUTOSIZE);
  createTrackbar("threshold","line",&th,255);
  while(1)
    {count=0;
      Mat b(sqrt(a.rows*a.rows+a.cols*a.cols)/2,180,CV_8UC1,Scalar(0));
  for(i=0;i<a.rows;i++)
    for(j=0;j<a.cols;j++)
      if(a.at<uchar>(i,j)==255)
	{
	  for(n=0;n<180;n++)
	    {   float p=CV_PI*n/180;
	  float d=i*cos(p)+j*sin(p);
	  if(d>0)
	  if(b.at<uchar>((int)d/2,n)<255)
	    b.at<uchar>((int)d/2,n)+=3;}
	}
  namedWindow("grap",WINDOW_AUTOSIZE);
    imshow("grap",b);
    for(i=2;i<a.rows-2;i++)
      {  for(j=2;j<a.cols-2;j++)
	  if(b.at<uchar>(i,j)>th)
	  for(m=i-2;m<=i+2;m++)
	    for(n=j-2;n<=j+2;n++)
	      {
		if(b.at<uchar>(i,j)>=b.at<uchar>(m,n))
		    count++;
		     if(count==25)
		       {
			  count=0;
		            for(k=0;k<a.rows;k++)
			      {double d=(i-k*cos(CV_PI*j/180))/sin(CV_PI*j/180);
			        c.at<uchar>(d,k)=255;
				}
			}
		   
	      }
      }
      
		  
		        
    imshow("line",c);
    
 i= waitKey(50);
	       if(i==' ')
		 break;}
    
return 0;
}
	       	
    
