#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    ////////////////// Chapter 2 ////////////////
    string path = "Resource/in_smile.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDia, imgErode;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
    Canny(img, imgCanny, 50, 150);
    

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDia, kernel);
    erode(imgDia, imgErode, kernel);

    imshow("img", img);
    imshow("img_Canny", imgCanny);
    imshow("img_Gray", imgGray);
    imshow("img_Blur", imgBlur);
    imshow("img_imgDia", imgDia);
    imshow("img_imgErode", imgErode);

    waitKey(0);
}