#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>
 
using namespace cv;
using namespace std;
Mat vis;
void DES_visit(int i, int j, int cnt, Mat img, Mat vis)
{
          int k, l;
          vis.at<uchar>(i, j) = 255/cnt;
          for (k = i - 1; k <= i + 1; k++)
          {
                   for (l = j - 1; l <= j + 1; l++)
                   {
                             if (k>0 && k<img.rows && l>0 && l<img.cols)
                             if (vis.at<uchar>(k, l) == 0 && img.at<uchar>(k, l) == 255)
                                      DES_visit(k, l, cnt, img, vis);
                   }
          }
}
int main(int, char**)
{
          Mat img = imread("binary.png", 0);
          int i, j,cnt = 1;
          vis = img.clone();
          for (i = 0; i < img.rows; i++)
          {
                   for (j = 0; j < img.cols; j++)
                   {
                             vis.at<uchar>(i,j) = 0;
                   }
          }
 
          for (i = 0; i < img.rows; i++)
          {
                   for (j = 0; j < img.cols; j++)
                   {
                             if (vis.at<uchar>(i,j)==0 && img.at<uchar>(i, j) == 255)
                             {
                                      DES_visit(i, j, cnt,img,vis);
                                      cnt++;
                             }
                   }
          }
          int c, sumx = 0, sumy = 0, count = 0;
          for (c = 1; c < cnt; c++)
          {
                   sumx = 0;
                   sumy = 0;
                   count = 0;
                   for (i = 0; i < img.rows; i++)
                   {
                             for (j = 0; j < img.cols; j++)
                             {
                                      if (vis.at<uchar>(i, j) == (255/c))
                                      {
                                                sumx += i;
                                                sumy += j;
                                                count++;
                                      }
                             }
                   }
                   printf("Centre of mass of object-%d is (%d,%d)\n",c, sumx / count, sumy / count);
          }
          namedWindow("Hello", WINDOW_AUTOSIZE);
          imshow("Hello", vis);
          waitKey(0);
          return 0;
}
 