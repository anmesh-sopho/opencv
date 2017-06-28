#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
  Mat a[3];
   Mat c(200,200,CV_8UC3,Scalar(255,0,0));
   a[0]=c;
  namedWindow("blue",WINDOW_AUTOSIZE);
  imshow("blue",a[0]);
  waitKey(0);
  return 0;
}
