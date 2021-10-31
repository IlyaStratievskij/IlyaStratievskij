#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    ////////////////// Resize, Crop ////////////////
    string path = "Resource/in_smile.png";
    Mat img = imread(path);
    Mat imgResize, imgCrop;
    
    cout << img.size() << endl;
    resize(img, imgResize, Size(), 0.5, 0.5);
    cout << imgResize.size() << endl;

    Rect roi(100, 100, 500, 250);
    imgCrop = img(roi);

    imshow("img", img);
    imshow("imgResize", imgResize);
    imshow("imgCrop", imgCrop);
    

    waitKey(0);
}