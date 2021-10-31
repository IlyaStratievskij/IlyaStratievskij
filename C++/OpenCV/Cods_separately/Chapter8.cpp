#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main()
{
    ////////////////// Face Detection ////////////////
   // VideoCapture cap(0);
    string path = "Resource/Photo.jpg";
    Mat img = imread(path);

    CascadeClassifier faceCascade;
    faceCascade.load("Resource/haarcascade_frontalface_default.xml");

    if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }
    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for (int i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);
    }
    imshow("Image", img);

    waitKey(0);
}