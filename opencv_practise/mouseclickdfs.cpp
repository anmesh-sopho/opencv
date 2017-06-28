#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<stack>
using namespace cv;
using namespace std;
Mat a=imread("fill.jpg", 0);
Mat b=a.clone();
void des(int i,int j)
{int k,l;cout<<i<<j;
  Point start ,current;
  start.y=i;
  start.x=j;
  stack <Point> s;
  s.push(start);
  b.at<uchar>(i,j)=0;
  while(!s.empty())
    {current=s.top();
      s.pop();
      for(k=current.y-1;k<current.y+1;k++)
	for(l=current.x-1;l<current.x+1;l++)
	  if(k>0&&l>0)
	    if(b.at<uchar>(k,l)==255&&(a.at<uchar>(k,l)==255))
	      { s.push({k,l});
		cout<<"Fg";
		b.at<uchar>(k,l)=0;
	      }
   }
    }
    /*void des(int i,int j)
{int k,l;
  b.at<uchar>(i,j)=0;
  for(k=i-1;k<=i+1;k++)
    {
      for(l=j-1;l<=j+1;l++)
	{if(l>0&&k>0&&k<a.rows&&l<a.cols)
	  if((b.at<uchar>(k,l)==255)&&a.at<uchar>(k,l)==255)
	    {des(k,l);}}}
	    return ; }*/
void callbackfunc(int Event, int x, int y, int flags, void *userdata)
{
	if (Event == EVENT_LBUTTONDOWN)
	  {	  des(x,y);}
	
}

int main(){
 
   while(1){
  
  	setMouseCallback("paint", callbackfunc, NULL);
	imshow("paint",b);
	int i=	waitKey(50);
 if(i==' ')
   break;}
	return 0;
}

  
