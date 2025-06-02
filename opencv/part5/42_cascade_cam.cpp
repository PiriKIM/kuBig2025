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

    CascadeClassifier classifier(folderPath + "haarcascade_frontalface_default.xml");

    vector<Rect> faces;
    
    while (true)
    {
        cap >> frame;

        if (frame.empty())
            break;

        classifier.detectMultiScale(frame, faces);

        for (auto &rect : faces)
        {
            rectangle(frame, rect, red, 2);
        }

        imshow("frame", frame);
        if (waitKey(33) == 27)
            break;
    }

    destroyAllWindows();
    return 0;
}