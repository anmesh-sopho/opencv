#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>


using namespace cv;
using namespace std;

int main()

{   
  int i,j,g[25],f=0,val,k,l,u=0,th;


  for(i=0;i<25;i++)
  {
  	g[i]=0;
  }



  Mat a= imread("lena_n.png",0);
  Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
  

  for(i=2;i<a.rows-2;i++)
       { for(j=2;j<a.cols-2;j++)
         {
          f=0;
          for(k=i-2;k<=i+2;k++)
          {
            for(l=j-2;l<=j+2;l++)
            {
                g[f]=a.at<uchar>(k,l);
                f++;
            }

          }
         	sort(g,g+25);
          b.at<uchar>(i,j)=g[12];
         	
         }
     }


namedWindow( "color", WINDOW_AUTOSIZE );
    imshow( "color", b );  
    waitKey(0);



return 0;


}