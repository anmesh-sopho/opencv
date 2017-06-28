#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>
#include "iostream"
#include <math.h>

using namespace cv;
using namespace std;

 typedef struct
{
	int x;
	int y;
}point;

Mat img=imread("binary.png",0);
 Mat visited(img.rows,img.cols,CV_8UC1,Scalar(0));
int cnt=1;

int isvalid(int i,int j)

{if((i<0||j<0)||i>=img.rows||j>=img.cols)
return 0;
else return 1;}

void bfs(int i,int j)
{
	int k,l;

    

    point start,current,temp;

    start.x=i;
    start.y=j;

    queue<point>q;

    q.push(start);

    visited.at<uchar>(i,j) = 255/cnt;
    while(!q.empty())
    { printf("yes");
    	current=q.front();
    	q.pop();
    	for(i=current.x-1;i<=current.x+1;i++)
        {
         for(j=current.y-1;j<=current.y+1;j++)
        {
         	if(isvalid(i,j))
         	{
         		if((visited.at<uchar>(i,j) ==0) &&(img.at<uchar>(i,j)==255))
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
  

for (i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
	{
		if((visited.at<uchar>(i,j)==0)&&(img.at<uchar>(i,j)==255))
		{   printf("no");
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
