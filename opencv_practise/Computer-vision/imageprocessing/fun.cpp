#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()

{   
  Mat a= imread("ext5.png",1);
  Mat b= imread("ext5.png",1);
    int i,j,k,l,m;
    k=0,l=0,m=0;
    namedWindow( "color2", WINDOW_AUTOSIZE );
    createTrackbar("qwerty","color2",&k,255);
    createTrackbar("qwerty1","color2",&l,255);
    createTrackbar("qwerty2","color2",&m,255);
    while(1)
    {
    
    
     
    for(i=0;i<a.rows;i++)
       { for(j=0;j<a.cols;j++)
         {

            a.at<Vec3b>(i,j)[0]+=k;
            a.at<Vec3b>(i,j)[1]+=l;
            a.at<Vec3b>(i,j)[2]+=m;

        }
      }
        
//namedWindow("color",WINDOW_AUTOSIZE);
imshow("color2",a);

imshow("color1",b);

                                         // Wait for a keystroke in the window
    
  
  }

   i=waitKey(5);
if(i==27)
    break; 
  return 0;

}


    
 