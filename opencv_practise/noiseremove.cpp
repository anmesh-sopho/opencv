#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
Mat erosion(Mat a,Mat b)
{int r=a.rows,c=a.cols;
  int i,j,k,l;
  for(i=1;i<r-1;i++)
    for(j=1;j<c-1;j++)
      {
	if(a.at<uchar>(i,j)==255)
	 for(k=i-1;k<=i+1;k++)
	    for(l=j-1;l<=j+1;l++)
	      { 
		    if(a.at<uchar>(k,l)==0)
                     b.at<uchar>(i,j)=0;
	 
	      }}
	return b;
}
Mat dilation(Mat a,Mat b)
{int r=a.rows,c=a.cols;
  int i,j,k,l;
  for(i=1;i<r-1;i++)
    for(j=1;j<c-1;j++)
      {
	if(a.at<uchar>(i,j)==0)
	 for(k=i-1;k<=i+1;k++)
	    for(l=j-1;l<=j+1;l++)
	      { 
		    if(a.at<uchar>(k,l)==255)
                     b.at<uchar>(i,j)=255;
	 
	      }}
	return b;
}

      	
int main()
{
  
  Mat a=imread("filter4.png",0);
  Mat b=a.clone();
  b=erosion(a,a.clone());//one type
    b=dilation(b,b.clone());
    b=dilation(b,b.clone());//another type
     b=erosion(b,b.clone());
     
    
  namedWindow("erosion",WINDOW_AUTOSIZE);
  imshow("erosion",b);
  waitKey(0);
  return 0;
}
