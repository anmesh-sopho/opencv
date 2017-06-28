#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()

{   
    int i,j;
    Mat a(400,400,CV_8UC3,Scalar(0,0,0));
    for(i=0;i<400;i++)
       { if((i/20)%2==0)
       	              {for(j=0;j<401;j++)
                           {   if((j/20)%2==0)

                                   {a.at<Vec3b>(i,j)[0]=255;
                                    a.at<Vec3b>(i,j)[1]=255;
                                    a.at<Vec3b>(i,j)[2]=255;}
                                                             }
                                                         }
                    
                    else{ for(j=0;j<401;j++)
        {   if((j/20)%2==1)
            {a.at<Vec3b>(i,j)[0]=255;
            a.at<Vec3b>(i,j)[1]=255;
            a.at<Vec3b>(i,j)[2]=255;}
        }




                          }
       	


    }
    namedWindow("String",WINDOW_AUTOSIZE);
    imshow("String",a);
    waitKey(0);
    return  0;
}