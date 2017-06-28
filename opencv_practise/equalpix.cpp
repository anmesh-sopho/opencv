#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"


using namespace cv;
using namespace std;
int main()
{int i,j,z;
  int sum=0;
 
  Mat img=imread("read.jpg",0);
  
  int p[256];
  for(i=0;i<256;i++)
      p[i]=0;
  for(i=0;i<img.rows;i++)   
    for(j=0;j<img.cols;j++)
      {
++p[img.at<uchar>(i,j)];
      }
  int avg=(img.rows*img.cols)/2;
  for(i=0;i<256;i++)
    {sum=sum+p[i];
      if(sum>=avg)
	{z=i;
break;}
    }
cout<<p[1]<<" "<<avg<<" "<<img.rows<<" "<<img.cols<<" "<<sum<<" "<<z;
for(i=0;i<img.rows;i++)
    for(j=0;j<img.cols;j++)
      {if(img.at<uchar>(i,j)>z)
	  
	  img.at<uchar>(i,j)=255;  
	 else
	   img.at<uchar>(i,j)=0;
}
namedWindow("equal",WINDOW_AUTOSIZE);
imshow("equal",img);
waitKey(0);
 
 return 0;
}
   
	  
