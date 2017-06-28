#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <math.h>
using namespace cv;
using namespace std;
int main()
{
	Mat img1 = imread("ext5.png", 1);
	Mat img(img1.rows, img1.cols, CV_8UC1, Scalar(0));
	Canny(img1,img,255,255);
   namedWindow("Out",CV_WINDOW_NORMAL);
   int i, j, m, n, k, r, s, t, max=0,th=80,f,ke=2,anh=45,anl=29;
    double d;
    
    k=(int)sqrt(img.rows*img.rows+img.cols*img.cols)+1;
    Mat hg(k,180,CV_8UC1,Scalar(0));
    Mat out(img.rows,img.cols,CV_8UC1,Scalar(0));
    	        for(i=0;i<k;i++)
	  for(j=0;j<180;j++)
	    hg.at<uchar>(i,j)=0;
	for(i=0;i<img.rows;i++)
	  for(j=0;j<img.cols;j++)
	    if(img.at<uchar>(i,j)==255)
	      {
		for(n=0;n<180;n++)
		  {
		    d=i*cos(CV_PI*(n+1)/180.0)+j*sin(CV_PI*(n+1)/180.0);
		    d=(d>0)?d:(k+d);
	             if(hg.at<uchar>((int)d,n)<255)
		       hg.at<uchar>((int)d,n)++;
		     else
		         hg.at<uchar>((int)d,n)=255;
		  }
	      }
	imshow("Hough",hg);
	createTrackbar("Threshhold","Out",&th,255);
	createTrackbar("Kernels","Out",&ke,10);
	createTrackbar("Angle High","Out",&anh,90);
		createTrackbar("Angle Low","Out",&anl,90);
	while(1)
	{
	  for(i=0;i<img.rows;i++)
	    for(j=0;j<img.cols;j++)
	      out.at<uchar>(i,j)=0;
	  for(i=ke;i<k-ke;i++)
	    for(j=ke;j<180-ke;j++)
	      {
		for(m=-ke;m<ke+1;m++)
		  for(n=-ke;n<ke+1;n++)
		    {
		      r=hg.at<uchar>(i+m,j+n);
		      if(r>th&&r>max)
			{
			  max=r;
			  s=i+m;
			  t=j+n;
			}
		    }
		if(max!=0&&((t<anh&&t>anl)||(t>180-anh&&t<180-anl)))
		  for(m=0;m<img.rows;m++)
		    {
		      f = (int)((s-m*cos(CV_PI*t/180.0))/sin(CV_PI*t/180.0));
		      if(f>=0&&f<img.cols)
			out.at<uchar>(m,f)=255;
		    }
		 max=0;
	        }
	  imshow("in",img);
	  imshow("Out",out);
	  int p = waitKey(50);
	  if(p==27)
	  break; 
	}
	return 0;
}
	
