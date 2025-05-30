#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "/home/piri/kuBig2025/opencv/part2/color.hpp"

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

int main()
{
    VideoCapture cap(0);
    // Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    // vector<Mat> images;
    Mat img, edge;
    int low_v, high_v;
    namedWindow("img1");
    createTrackbar("lowedge", "img1", &low_v, 255);
    createTrackbar("highedge", "img1", &high_v, 255);
    // Canny(img, edge, 50, 100);
    // images.push_back(edge);

    // vector img show code
    while (true)
    {
        cap >> img;
        Canny(img, edge, low_v, high_v);
        imshow("img1", edge);
        // waitKey(33);

        if (waitKey(33) == 27)
            break;
    }

    destroyAllWindows();
    return 0;
}