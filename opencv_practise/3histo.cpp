#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{int i,j,k;
  Mat a=imread("kk.jpg",1);
 
  int in[3][256];
  for(i=0;i<3;i++)
    for(j=0;j<256;j++)
      in[i][j]=0;
  for(i=0;i<a.rows;i++)
    for(j=0;j<a.cols;j++)
      for(k=0;k<3;k++)
	in[k][a.at<Vec3b>(i,j)[k]]++;
  int max[3];
  max[0]=max[1]=max[2]=0;
  for(i=0;i<256;i++)
      for(k=0;k<3;k++)
	if(max[k]<in[k][i])
	  max[k]=in[k][i];
  Mat o[3];
  Mat b(max[0]+10,256,CV_8UC3,Scalar(255,255,255));
  Mat g(max[1]+10,256,CV_8UC3,Scalar(255,255,255));
   Mat r(max[2]+10,256,CV_8UC3,Scalar(255,255,255));
   o[0]=b;
   o[1]=g;
   o[2]=r;
   for(i=0;i<256;i++)
     for(k=0;k<3;k++)
       {
	 for(j=(max[k]-in[k][i]);j<max[k];j++)
	   o[k].at<Vec3b>(i,j)[k]=255;
       }
    namedWindow("blue",WINDOW_AUTOSIZE);
   imshow("blue",o[0]);
    namedWindow("green",WINDOW_AUTOSIZE);
   imshow("green",o[1]);
    namedWindow("red",WINDOW_AUTOSIZE);

   imshow("red",o[2]);
   waitKey(0);
   return 0;
}
	   
	   
    
  
