#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()

{   
    int i,j;
 /*   Mat a(400,400,CV_8UC3,Scalar(0,255,0));
    for(i=0;i<401;i++)
       { for(j=0;j<401;j++)
        {   if(j>=i)
           { a.at<Vec3b>(i,j)[0]=255;}
        }}
    namedWindow("String",WINDOW_AUTOSIZE);
    imshow("String",a);
    waitKey(0);
    return  0;

*/
    Mat a= imread("abcd.jpg",1);
    Mat b= imread("abcd.jpg",1);
   // Mat img2(a.rows,a.cols,CV_8UC3,Scalar(0,0,0));

    for(i=0;i<a.rows;i++)
       { for(j=0;j<a.cols/2;j++)
         {
            b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,j)[0];
            b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,j)[0];
            b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,j)[0];
            a.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,a.cols-j)[0];
            a.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i,a.cols-j)[1];
            a.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i,a.cols-j)[2];
         }
        }

        for(i=0;i<a.rows;i++)
       { for(j=a.cols/2;j<a.cols;j++)
         {
            
            a.at<Vec3b>(i,j)[0]=b.at<Vec3b>(i,a.cols-j)[0];
            a.at<Vec3b>(i,j)[1]=b.at<Vec3b>(i,a.cols-j)[1];
            a.at<Vec3b>(i,j)[2]=b.at<Vec3b>(i,a.cols-j)[2];
         }
        }
    namedWindow( "color", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "color", a );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;




}