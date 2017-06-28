#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;


int main(){
  int i,j;
  Mat a(400,400,CV_8UC3,Scalar(100,100,100));
  for(i=0;i<400;i++){
    for(j=0;j<400;j++){
      if (((i-200)*(i-200)+(j-200)*(j-200))<=10000){
	a.at<Vec3b>(i,j)[2]=sqrt((i-200)*(i-200)+(j-200)*(j-200))/100*255;
	a.at<Vec3b>(i,j)[1]=(100-sqrt((i-200)*(i-200)+(j-200)*(j-200)))/100*255;
	a.at<Vec3b>(i,j)[0]=255/2;
	
      }}}
  namedWindow("box",WINDOW_AUTOSIZE);
  imshow("box",a);
  waitKey(0);
  return 0;}
