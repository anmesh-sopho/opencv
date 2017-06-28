#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;

int main()

{   
  int i,j,g[256],val,k,u=0,th;


  for(i=0;i<256;i++)
  {
  	g[i]=0;
  }



  Mat a= imread("abcd.jpg",0);
  Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
  

  for(i=0;i<a.rows;i++)
       { for(j=0;j<a.cols;j++)
         {
         	val=a.at<uchar>(i,j);
         	g[val]++;
         }
     }

     k=(a.rows)*(a.cols);

  for(i=0;i<256;i++)
  {
      u+=g[i];
      if(u>=k/2)
      	{break;}
  }

       th=i;
       for(i=0;i<a.rows;i++)
       { for(j=0;j<a.cols;j++)
         {
            if(a.at<uchar>(i,j)>th)
                b.at<uchar>(i,j)=255;

            else
                b.at<uchar>(i,j)=0;
}}

namedWindow( "color", WINDOW_AUTOSIZE );
    imshow( "color", b );  
    waitKey(0);



return 0;


}