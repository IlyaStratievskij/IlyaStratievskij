#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

float w = 250, h = 350;
Mat matrix, imgWarp;

int main()
{
    ////////////////// Warp Images ////////////////

    String path = "Resource/cards.png";
    Mat img = imread(path);

    Point2f src[4] = { {637, 139}, {883, 85}, {716, 493}, {975, 437} };
    Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    for (int i = 0; i < 4; i++) {
        circle(img, src[i], 10, Scalar(0, 69, 255), FILLED);
    }

    imshow("img", img);
    imshow("imgWarp", imgWarp);
    waitKey(0);
}