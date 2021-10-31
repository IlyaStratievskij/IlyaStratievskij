#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    ////////////////// Draw Shapes and Text ////////////////
    Mat img(512, 512, CV_8UC3, Scalar(255, 0, 255));

    circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
    rectangle(img, Point(100, 100), Point(410, 410), Scalar(255, 0, 0), 3);
    line(img, Point(100, 100), Point(410, 410), Scalar(0, 120, 355), 5);

    putText(img, "Hello, world", Point(150, 250), FONT_HERSHEY_DUPLEX, 1, Scalar(0 ,0 ,0), 2);

    imshow("img", img);

    waitKey(0);
}