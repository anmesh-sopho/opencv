#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;


int main(){
  int i,j;
  Mat img=imread("image.jpg",1);
  Mat img1=imread("image.jpg",1);
  for(int i=0;i<img.rows;i++)
    {
      for(int j=0;j<img.cols;j++){
    if(img.at<Vec3b>(i,j)[0]<215)
img.at<Vec3b>(i,j)[0]+=40;
    else
      img.at<Vec3b>(i,j)[0]=255;
      
    if(img.at<Vec3b>(i,j)[1]<215)
img.at<Vec3b>(i,j)[1]+=40;
     else
      img.at<Vec3b>(i,j)[1]=255;
    if(img.at<Vec3b>(i,j)[2]<215)
img.at<Vec3b>(i,j)[2]+=40;
     else
      img.at<Vec3b>(i,j)[2]=255;
      }}
  namedWindow("new",WINDOW_AUTOSIZE);
  imshow("new",img);
   namedWindow("old",WINDOW_NORMAL);
  imshow("old",img1);
 waitKey(0);
  return 0;}
