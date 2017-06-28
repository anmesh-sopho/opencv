#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()

{   
  Mat a= imread("a.png",1);
  Mat b= imread("a.png",1);
    int i,j,k=0,l=0,m=0;
    namedWindow( "color2", WINDOW_AUTOSIZE );
    createTrackbar("qwerty","color2",&k,255);
    createTrackbar("qwerty1","color2",&l,255);
    createTrackbar("qwerty2","color2",&m,255);
    while(1)
    {
    
    for(i=0;i<a.rows;i++)
    {
      for(j=0;j<a.cols;j++)
      {
        if((50-k<(a.at<Vec3b>(i,j)[0]))&&((a.at<Vec3b>(i,j)[0])<100+k))
          a.at<Vec3b>(i,j)[0]=255;
        else {(a.at<Vec3b>(i,j)[0])=(a.at<Vec3b>(i,j)[0]);}
        if((50-k<(a.at<Vec3b>(i,j)[1]))&&((a.at<Vec3b>(i,j)[1])<100+k))
          a.at<Vec3b>(i,j)[1]=0;
        else {(a.at<Vec3b>(i,j)[1])=(a.at<Vec3b>(i,j)[1]);}
        if((50-k<(a.at<Vec3b>(i,j)[2]))&&((a.at<Vec3b>(i,j)[2])<100+k))
          a.at<Vec3b>(i,j)[2]=0;
        else {(a.at<Vec3b>(i,j)[2])=(a.at<Vec3b>(i,j)[2]);}
        }
    }

     
    

        
//namedWindow("color",WINDOW_AUTOSIZE);
imshow("color2",a);

imshow("color1",b);

int i=waitKey(50);
if(i==27)
break;                                          // Wait for a keystroke in the window
    }
  return 0;
  }




    
 