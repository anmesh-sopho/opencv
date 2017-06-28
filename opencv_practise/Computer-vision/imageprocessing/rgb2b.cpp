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
    
    Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));

    for(i=0;i<a.rows;i++)
       { for(j=0;j<a.cols;j++)
         {
            b.at<uchar>(i,j)=0.114*a.at<Vec3b>(i,j)[0]+0.587*a.at<Vec3b>(i,j)[1]+0.299*a.at<Vec3b>(i,j)[2];
         }
        }

        
    namedWindow( "color", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "color", b );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;




}