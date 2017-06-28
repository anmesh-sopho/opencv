#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()

{   
    int i,j;
    Mat a(400,400,CV_8UC3,Scalar(0,255,0));
    for(i=0;i<401;i++)
       { for(j=0;j<401;j++)
        {   if(j>=i)
           { a.at<Vec3b>(i,j)[0]=255;}
        }}
    namedWindow("String",WINDOW_AUTOSIZE);
    imshow("String",a);
    waitKey(0);
    return  0;






}