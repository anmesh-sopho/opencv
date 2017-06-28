#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()

{   
  Mat a= imread("a.png",1);
    int i,j,th=0;
    namedWindow( "color2", WINDOW_AUTOSIZE );
    createTrackbar("qwerty","color2",&th,255);
    while(1)
    {
    
    Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
     
    for(i=0;i<a.rows;i++)
       { for(j=0;j<a.cols;j++)
         {
            b.at<uchar>(i,j)=0.114*a.at<Vec3b>(i,j)[0]+0.587*a.at<Vec3b>(i,j)[1]+0.299*a.at<Vec3b>(i,j)[2];
         }
        }

        for(i=0;i<a.rows;i++)
       { for(j=0;j<a.cols;j++)
         {
            if(b.at<uchar>(i,j)>th)
                b.at<uchar>(i,j)=255;

            else
                b.at<uchar>(i,j)=0;
}}

namedWindow("color",WINDOW_AUTOSIZE);
imshow("color",b);

int i=waitKey(50);
if(i==27)
break;                                          // Wait for a keystroke in the window
    }
  return 0;
  }




    
 