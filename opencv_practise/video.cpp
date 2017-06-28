#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <math.h>
using namespace cv;
using namespace std;
int main()
{ VideoCapture vidi(0);
  Mat temp;
  namedWindow("video",WINDOW_AUTOSIZE);
  while(1)
    {Mat temp1;
 
  vidi.read(temp);
  cvtColor(temp,temp1, CV_RGB2GRAY);
  imshow("video",temp1);
 int i= waitKey(50);
 if(i==' ')
   break;}
  return(0);
}
