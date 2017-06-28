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
                  printf("B=%d\n" ,a.at<Vec3b>(x,y)[0]);
                  printf("G=%d\n" ,a.at<Vec3b>(x,y)[0]);
                  printf("R=%d\n" ,a.at<Vec3b>(x,y)[0]);
      }
}



  int main()
{
     a=imread("a.png",1);
imshow("Win",a);
setMouseCallback("Win",Callbackfunc,NULL);
waitKey(0);
}




