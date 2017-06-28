#include <bits/stdc++.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{Mat img=imread("read.jpg",0);
  int sumx=0,sumy=0;
int gx[9]={-1,0,1,-2,0,2,-1,0,1};
	int gy[9]={-1,-2,-1,0,0,0,1,2,1};
	float g;
	int  i,j,n,m,k=0,x=0;
  int r=img.rows,c=img.cols;
  Mat a(r,c,CV_8UC1,Scalar(255));
  for(i=0;i<r;i+=1)
    for(j=0;j<c;j+=1)
      {
	for(n=i;n<i+3;n++)
	  for(m=j;m<j+3;m++)
	    {
	      gx[x]=img.at<uchar>(n,m)*gx[x];
	      gy[x]=img.at<uchar>(n,m)*gy[x];
	      x++;
	    }x=0;
	for(k=0;k<9;k++)
	       
	       {	 sumx+=gx[k];
		   sumy+=gy[k];}
	g=sqrt(sumx*sumx+sumy*sumy);
	sumx=0,sumy=0;	a.at<uchar>(i+1,j+1)=g;
      }
  namedWindow("out",WINDOW_AUTOSIZE);
  imshow("out",a);
  waitKey(0);
  return 0;
}
