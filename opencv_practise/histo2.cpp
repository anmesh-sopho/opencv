#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main(int argv, char **argc){
  Mat a=imread(argc[1],1);
  Mat b[3];
  int max[3][256];
    for(int  i=0;i<256;i++)
      for(int k=0;k<3;k++)
	{
	  max[k][i]=0;}
  for(int  i=0;i<a.rows;i++)
      for(int j=0;j<a.cols;j++)
	{for(int k=0;k<3;k++)
	  max[k][a.at<Vec3b>(i,j)[k]]++;
	}
   for(int  i=0;i<256;i++)
      for(int k=0;k<3;k++)
	{
	  max[k][i]/=100;}
   int max1[3]={0,0,0};
   for(int k=0;k<3;k++)
   for(int i=0;i<256;i++)
  	   {
	     if(max1[k]<max[k][i])
	       max1[k]=max[k][i];
	 
	   }
 
  
       
  for(int k=0;k<3;k++)
    {b[k]=Mat(max1[k]+10,256,CV_8UC3,Scalar(255,255,255));
    }
  for(int k=0;k<3;k++)
  for(int i=0;i<256;i++)
      for(int j=max1[k]+10-max[k][i];j<max1[k]+10;j++)
	{for(int z=0;z<3;z++)
	    {if(z!=k)
		b[k].at<Vec3b>(j,i)[z]=0;}
	}
  
  namedWindow("blue",WINDOW_AUTOSIZE);
  imshow("blue",b[0]);
  namedWindow("red",WINDOW_AUTOSIZE);
  imshow("red",b[2]);
  namedWindow("green",WINDOW_AUTOSIZE);
  imshow("green",b[1]);
  waitKey(0);
  return 0;
}
    
