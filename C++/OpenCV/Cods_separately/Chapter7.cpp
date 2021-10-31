#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat imgGray, imgBlur, imgCanny, imgDil;

void getContours(Mat imgDil, Mat img) {

    vector <vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    // поиск контура, его видимый край
    // RETR_EXTERNAL - выдаёт крайние внешние контуры
    // CHAIN_APPROX_SIMPLE - склеивает все контуры и они хранятся в виде отрезков

    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        cout << area << endl;

        vector <vector<Point>> conPoly(contours.size());
        vector <Rect> boundRect(contours.size());
        string objectType;

        if (area > 1000) {
            float peri = arcLength(contours[i], true); // длина дуги контура
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true); // набор точек, состоящий из точек контура изображения
            cout << conPoly[i].size() << endl;
            boundRect[i] = boundingRect(conPoly[i]); // функция определяет прямоугольник внутри которого находится наша фигура

            int objCor = (int)conPoly[i].size();

            if (objCor == 3) { objectType = "Tri"; }
            else if (objCor == 4) {
                float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
                cout << aspRatio << endl;
                if (aspRatio > 0.90 && aspRatio < 1.10)
                {
                    objectType = "Square";
                }
                else {
                    objectType = "Rect";
                }
            }
            else if (objCor > 4) { objectType = "Circle"; }

            drawContours(img, conPoly, i, Scalar(255, 0, 255), 5);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 3);
            putText(img, objectType, { boundRect[i].x, boundRect[i].y-5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 1);
        }
    }
}

int main()
{
    ////////////////// Shapes Detection ////////////////

    String path = "Resource/figures.png";
    Mat img = imread(path);
    
    // Препроцесс
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 50, 50);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDil, kernel);

    getContours(imgDil, img);

    imshow("img", img);
    /*imshow("img Gray", imgGray);
    imshow("img Blur", imgBlur);
    imshow("img Canny", imgCanny);*/
    imshow("img Dil", imgDil);
    waitKey(0);
    return 0;
}