#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <stdio.h>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

Mat img = imread("shapes.jpg", 0);
Mat result=img;
typedef struct
 {
	int x;
	int y;
 }point;

int isvalid(int i,int j)
{
	if(i<0||j<0||i>=img.rows||j>=img.cols)
return 0;
else return 1;}

Mat visited(img.rows,img.cols,CV_8UC1,Scalar(255));

void dfs(int i,int j)
{//cout << "indfs"<< endl;
	int k,l;

    

    point start,current,temp;

    start.x=i;
    start.y=j;

    stack<point>q;

    q.push(start);

    //img.at<uchar>(i,j) = 0;
    int ctr=1000;
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
         		if(img.at<uchar>(i,j)==255)
         		{//printf("asdf");
         			temp.x=i;
         			temp.y=j;
         			q.push(temp);
         		    result.at<uchar>(i,j) =0;	
         		}
         	}
        }
    }


    }
    printf("dghj");
}

void callbackfunc(int Event, int y, int x, int flags, void *userdata)
{//printf("asdfg");
	if (Event == EVENT_LBUTTONDOWN)
	{
	  cout << x << " "<< y << endl;
	  dfs(x,y);
	  cout<<"hwllo"<<endl;
	  imshow("result",result);
	  waitKey(1000);	  
	}
}

int main()
{
	
	imshow("FillIn1", img);
//	imshow("FillIn", visited);
	setMouseCallback("FillIn1", callbackfunc, NULL);
	waitKey(0);
	return 0;
}
