#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    // загрузка картинки
    /*string path = "Resource/in_smile.png";
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);
    cout << "Hello World!\n";*/

    // Загрузка видео
    /*string path = "Resource/cyborg.mp4";
    VideoCapture cap(path);
    Mat img;

    while (true) {
        cap.read(img);

        imshow("Video", img);
        waitKey(20);
    }
    */

    ////////////////// Webcam ////////////////
    VideoCapture cap(0); // 0 - встроенная камера, а 1 - подключенная 
    Mat img;

    while (true) {
        cap.read(img);

        imshow("Webcam", img);
        waitKey(1);
    }
}

