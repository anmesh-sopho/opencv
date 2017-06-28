#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
  Mat a(100,50,CV_8UC3,Scalar(233,23,255));
	namedWindow("anmesh",WINDOW_AUTOSIZE);
	imshow("anmesh",a);
	waitKey(0);
	return 0;	}
