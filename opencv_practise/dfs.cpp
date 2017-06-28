#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
Mat a=imread("dfs1.png",0);
Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
void des(int i,int j,int count)
{int k,l;
  b.at<uchar>(i,j)=255/count;
  for(k=i-1;k<=i+1;k++)
    {
      for(l=j-1;l<=j+1;l++)
	{if((b.at<uchar>(k,l)==0)&&a.at<uchar>(k,l)==255)
	    {des(k,l,count);}}}
  return ; }
	  
int main(){
  int count =1;
  int i,j;
  for(i=1;i<a.rows-1;i++)
    {
      for(j=1;j<a.cols-1;j++)
	{
	  if((b.at<uchar>(i,j)==0)&&a.at<uchar>(i,j)==255)
	    {
	      des(i,j,count);
		count++;

	    }}
    }namedWindow("out",WINDOW_AUTOSIZE);
  
    imshow("out",b);
    waitKey(0);
    return 0;
  }
