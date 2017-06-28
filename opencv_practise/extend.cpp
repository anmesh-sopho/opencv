#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{int i,j,k,l,n,m;
 int  z=0;
  Mat img=imread("apple.png",1);
  Mat a(img.rows*2,img.cols*2,CV_8UC3,Scalar(0,0,0));
   for(n=0;n<img.rows;n++)
     for(m=0;m<img.cols;m++){
  for(i=m;i<=m+2;i++){
    for(j=n;j<=n+2;j++)
      {for(k=0;k<3;k++)
	  a.at<Vec3b>(i,j)[k]=img.at<Vec3b>(n,m)[k];
      }}}
  namedWindow("orig",WINDOW_AUTOSIZE);
  imshow("orig",img);
   namedWindow("mag",WINDOW_AUTOSIZE);
  imshow("mag",a);
  waitKey(0);
  return 0;
}
    
