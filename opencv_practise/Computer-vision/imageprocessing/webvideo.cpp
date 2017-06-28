#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>
#include "iostream"
#include <math.h>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture vid(0);
	Mat temp,temp1;
	int i;
	while(1)
	{
		vid.read(temp);
				namedWindow("For",WINDOW_AUTOSIZE);

				
				Canny(temp,temp1,40,80);
				imshow("For",temp1);

		i=waitKey(50);
        if(i==27)
        {
        	break;
        }
	}
	return 0;
}