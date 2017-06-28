#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;
Mat a;


void Callbackfunc(int Event,int y,int x,int flags,void *userdata)
{
     if (Event==EVENT_LBUTTONDOWN)
     {
                  printf("x=%d\n" ,x);
                  
                  printf("y=%d\n" ,y);
      }
}



  int main()
{
     VideoCapture cap("new.mp4");
     Mat a;
     cap.read(a);
imshow("Win",a);
setMouseCallback("Win",Callbackfunc,NULL);
waitKey(0);
}




