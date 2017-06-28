#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>
#include <math.h>


using namespace cv;
using namespace std;

int main()

{   
  int i,j,f=0,val,k,l,u=0,th,jk,sx=0,sy=0;
  float g[9];


  for(i=0;i<25;i++)
  {
  	g[i]=0;
  }



  Mat a= imread("a.png",0);
  Mat b(a.rows,a.cols,CV_8UC1,Scalar(255));
  

  for(i=1;i<a.rows-1;i++)
       { for(j=1;j<a.cols-1;j++)
         {
          f=0;
          sx=0;
          for(k=i-1;k<=i+1;k++)
          {
            for(l=j-1;l<=j+1;l++)
            {     if(l-j==-1&&k-i==-1)
                   {jk=-1;}
                   if(l-j==0&&k-i==-1)
                   {jk=0;}
                 if(l-j==1&&k-i==-1)
                   {jk=1;}
                 if(l-j==-1&&k-i==0)
                   {jk=-2;}
                 if(l-j==0&&k-i==0)
                   {jk=0;}
                 if(l-j==1&&k-i==0)
                   {jk=2;}
                 if(l-j==-1&&k-i==1)
                   {jk=-1;}
                 if(l-j==0&&k-i==1)
                   {jk=0;}
                 if(l-j==1&&k-i==1)
                   {jk=1;}
                g[f]=a.at<uchar>(k,l)*jk;
                sx+=g[f];

                  
            }

          }
          sy=abs(sx)/4;
         	if(sy>20)
          b.at<uchar>(i,j)=0;
         	
         }
     }


namedWindow( "color", WINDOW_AUTOSIZE );
    imshow( "color", b );  
    waitKey(0);



return 0;


}