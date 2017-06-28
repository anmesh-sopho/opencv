#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	Mat var;
	var=imread("read.jpg",1);
	Mat var2,img;
	cvtColor(var,var2,CV_BGR2GRAY);
	int arr[256];
	int count,max=0;
	for(int k=0;k<256;k++){
		count=0;
		arr[k]=0;
		for(int i=0;i<var.rows;i++){
			for(int j=0;j<var.cols;j++){
				if(var2.at<uchar>(i,j)==k)
					count++;
			}
		}
		if(count>max)
			max=count;
		arr[k]=count;
	}
	cout << max<<" " << var2.rows<<" "<<var2.cols<<endl;
	max=max/2.5;
	img=Mat(max+2,256,CV_8UC1,Scalar(255));
	/*imshow("Display Test",img);
	waitKey(0);*/
	count=0;
	cout<< max;
	/*for(int i=0;i<256;i++){
		arr[i]=arr[i]/3;
	}*/
	while(count<256){
		for(int k=0;k<arr[count];k++){
			img.at<uchar>(max+1-(k/2.5),count)=0;
		}
		count++;
	}
	imshow("Display",img);
	waitKey(0);
	return 0;
}
