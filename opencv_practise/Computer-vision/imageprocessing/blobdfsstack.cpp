#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include <bits/stdc++.h>
#include"iostream"

using namespace cv;
using namespace std;

 Mat img=imread("try.png",0);
 Mat visited(img.rows,img.cols,CV_8UC1,Scalar(0));
 int cnt=1;
 typedef struct
 {
	int x;
	int y;
 }point;

int isvalid(int i,int j)
{if(i<0||j<0||i>=img.rows||j>=img.cols)
return 0;
else return 1;}
void bfs(int i,int j)
{
	int k,l;

    

    point start,current,temp;

    start.x=i;
    start.y=j;

    stack<point>q;

    q.push(start);

    visited.at<uchar>(i,j) = 255/cnt;
    while(!q.empty())
    {
    	current=q.top();
    	q.pop();
    	for(i=current.x-1;i<=current.x+1;i++)
        {
         for(j=current.y-1;j<=current.y+1;j++)
        {
         	if(isvalid(i,j))
         	{
         		if(visited.at<uchar>(i,j) ==0 &&img.at<uchar>(i,j)==255)
         		{
         			temp.x=i;
         			temp.y=j;
         			q.push(temp);
         		    visited.at<uchar>(i,j) =255/cnt;	
         		}
         	}
        }
    }


    }
}



int main ()
{
  int i,j;
  cnt=1;

for (i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
	{
		if((visited.at<uchar>(i,j)==0)&&(img.at<uchar>(i,j)==255))
		{
			bfs(i,j);
			cnt++;
		}
	}
namedWindow("color",WINDOW_AUTOSIZE);
imshow("color",visited);
imshow("color2",img);
waitKey(0);
return 0;
}
