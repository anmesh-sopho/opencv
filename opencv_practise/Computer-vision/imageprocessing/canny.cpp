#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include <bits/stdc++.h>
#include"iostream"

using namespace cv;
using namespace std;

int main ()
{int x=0,y=0;
	namedWindow("color1",WINDOW_AUTOSIZE);
createTrackbar("track1","color1",&x,255);
createTrackbar("track2","color1",&y,255);
   Mat img=imread("a.png",1);
Mat img3;
while(1)
{
Canny(img,img3,x,y);
imshow("color",img);
imshow("color2",img3);


int i= waitKey(50);
if(i==27)
break;
  //waitKey(0);
}
  return 0;
}