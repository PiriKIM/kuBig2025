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
    Mat frame;

    QRCodeDetector qrDetector;
    vector<Point> points;
    String info;
    
    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;

        // info = qrDetector.detectAndDecode(frame, points);
        qrDetector.detectAndDecode(frame, points);
        polylines(frame, points, true, red, 2);

        // if (!info.empty())
        // {
        //     polylines(frame, points, true, red, 2);
        //     putText(frame, info, Point(10, 30), FONT_HERSHEY_DUPLEX, 1 , black);
        // }

        imshow("frame", frame);
        if (waitKey(33) == 27)
            break;
    }
    
    destroyAllWindows();
    return 0;
}