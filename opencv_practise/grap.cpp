#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{int k,i,j;
  Mat img=imread("kk.jpg",1);
  Mat im[3];
  int in[3][256];
  for(i=0;i<3;i++)
    for(j=0;j<256;j++)
      in[i][j]=0;
  for(i=0;i<img.rows;i++)
    for(j=0;j<img.cols;j++)
      {
	in[0][img.at<Vec3b>(i,j)[0]]++;
	in[1][img.at<Vec3b>(i,j)[1]]++;
	in[2][img.at<Vec3b>(i,j)[2]]++;
      }

  Mat a(256,1000,CV_8UC3,Scalar(255,255,255));
  Mat b(256,1000,CV_8UC3,Scalar(255,255,255));
  Mat c(256,1000,Scalar(255,255,255));
  im[0]=a;
  im[1]=b; 
  im[2]=c; 
    for(i=0;i<256;i++)
      {for(k=0;k<3;k++)
	  {for(j=1000-in[k][i];j<1000;j++)
	      {
		im[k].at<Vec3b>(i,j)[k]=255;
	      }
	  }}
    namedWindow("red",WINDOW_AUTOSIZE);
    imshow("red",im[2]);
     namedWindow("green",WINDOW_AUTOSIZE);
    imshow("green",im[1]);
     namedWindow("blue",WINDOW_AUTOSIZE);
    imshow("blue",im[2]);
    waitKey(0);
    return 0;
}
