#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
#include<stdio.h>
using namespace cv;
using namespace std;
Mat a=imread("dfs1.png",0);
Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
void des(int i,int j,int *count)
{int k,l;
  b.at<uchar>(i,j)=255/(*count);
  for(k=i-1;k<=i+1;k++)
    {
      for(l=j-1;l<=j+1;l++)
	{if((b.at<uchar>(k,l)==0)&&a.at<uchar>(k,l)==255)
	    {des(k,l,&count);}}}
  return ; }
	  
void centroid(Mat *a,int*z,int *k)
{int sumi=0,sumj=0;int count =0;
  int i,j;
  for(i=0;i<(*a).rows;i++)
    for(j=0;j<(*a).cols;j++)
      {if((*a).at<uchar>(i,j)==255)
	      {sumi+=i;
		sumj+=j;
		count++;
		
	      }}
	 *z=sumi/count;
 *k=sumj/count;
}	  
int main(int argv,char **argc)
{int count =1;
  for(i=1;i<a.rows-1;i++)
    for(j=1;j<a.cols-1;j++)
      {
	desi(i,j,&count);
	count++;
      }
  Mat a=imread(argc[1],0);
  int i,j;
  centroid(&a,&i,&j);
  printf("%d    %d",i,j);// using dfs we can count the number of object by using count from that we can get centroid of individual centroid...
  return 0;
}
  
