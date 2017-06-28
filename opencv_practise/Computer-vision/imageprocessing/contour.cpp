#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<vector>
#include<bits/stdc++.h>

using namespace cv;
using namespace std;

int main(int ,char**)
{ Mat img=imread("binary.png",0),output;
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
Canny(img,output,46,168);
findContours( output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
for( size_t k = 0; k < contours.size(); k++ )
approxPolyDP(Mat(contours[k]), contours[k], 3, true);
int idx = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
        Scalar color( rand()&255, rand()&255, rand()&255 );
        drawContours( output, contours, idx, color, CV_FILLED, 8, hierarchy );
    }

    namedWindow( "Components", 1 );
    imshow( "Components", output);
    waitKey(0);
}
