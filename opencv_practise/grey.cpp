#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{int i,j,z=127;
  Mat a=imread("read.jpg",1);
  Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
  Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
  Mat d(a.rows,a.cols,CV_8UC1,Scalar(0));
  	namedWindow("bin",WINDOW_AUTOSIZE);
  createTrackbar("track","bin",&z,255);
    while(1){
    for(i=0;i<a.rows;i++)
    {
      for(j=0;j<a.cols;j++)
	{
	  b.at<uchar>(i,j)= (int)(.114*(a.at<Vec3b>(i,j)[0])+ .5879*(a.at<Vec3b>(i,j)[1])+0.114* (a.at<Vec3b>(i,j)[2]));
	  c.at<uchar>(i,j)= (int)(a.at<Vec3b>(i,j)[0]+ a.at<Vec3b>(i,j)[1]+a.at<Vec3b>(i,j)[2])/3;
	  if((a.at<Vec3b>(i,j)[0])>z||(a.at<Vec3b>(i,j)[1])>z||(a.at<Vec3b>(i,j)[2])>z)
	    d.at<uchar>(i,j)=255;
	  else
	    d.at<uchar>(i,j)=0;
	    
	}}
      namedWindow("orig",WINDOW_AUTOSIZE);
		imshow("orig",a);
		namedWindow("avg",WINDOW_AUTOSIZE);
		imshow("avg",c);
		namedWindow("gery",WINDOW_AUTOSIZE);
		imshow("gery",b);

		imshow("bin",d);
	int p=	waitKey(50);
	if(p=='e')
	  break;
	
	       
    }
	return 0;
    }
      		
