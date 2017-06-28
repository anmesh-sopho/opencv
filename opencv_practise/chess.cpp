#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{int i,j,k;
  Mat a(800,800,CV_8UC3,Scalar(0,0,0));
  
    for(i=0;i<800;i++)
    {for(j=0;j<800;j++)
	{
	  for(k=0;k<3;k++)
	    {
	      a.at<Vec3b>(i,j)[k]=255*(((i/100)%2+(j/100)%2)%2);
	   
	    }
	}
	   
	}
  namedWindow("anmesh",WINDOW_AUTOSIZE);
  imshow("anmesh",a);
  waitKey(0);
  return 0;
}
