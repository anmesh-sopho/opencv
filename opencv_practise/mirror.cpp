#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
  Mat a=imread("image.jpg",1);
  Mat c(a.rows,a.cols,CV_8UC3,Scalar(0,0,0));
  for(int i=0;i<a.rows;i++)
    for(int j=0;j<a.cols;j++)
      {
	for(int k=0;k<3;k++)
	  {c.at<Vec3b>(i,j)[k]=a.at<Vec3b>(      i   ,a.cols-1-j)[k];
	  }	  }
	namedWindow ("new",WINDOW_AUTOSIZE);
	imshow("new",c);
	namedWindow("old",WINDOW_AUTOSIZE);
	imshow("old",a);
	waitKey(0);
	
	return 0;
}
