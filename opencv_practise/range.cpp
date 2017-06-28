#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{int i,j,k;int r=100,b=55,g=55,e=0;
  Mat img=imread("kk.jpg",1);
  namedWindow("out",WINDOW_AUTOSIZE);
  createTrackbar("blue","out",&b,255);
  createTrackbar("green","out",&g,255);
  createTrackbar("red","out",&r,255);
  createTrackbar("error","out",&e,255);
  
  while(1){
    Mat d(img.rows,img.cols,CV_8UC1,Scalar(0));
    for(i=0;i<img.rows;i++)
      { for(j=0;j<img.cols;j++)
	{
	 
	  if(((img.at<Vec3b>(i,j)[0]>=b+e||img.at<Vec3b>(i,j)[0]<=b-e))&&((img.at<Vec3b>(i,j)[1]>=g+e||img.at<Vec3b>(i,j)[1]<=g-e))&&((img.at<Vec3b>(i,j)[2]>=r+e||img.at<Vec3b>(i,j)[2]<=r-e)))
	    { 
	      d.at<uchar>(i,j)=255;
		
		 }
	  else
	    d.at<uchar>(i,j)=0;
	  
	    
      
	    
	}}
  
  imshow("out",d);
 int i= waitKey(50);
 if(i=='g')
   break;}
  return 0;
}
