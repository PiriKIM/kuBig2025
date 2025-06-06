#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");
    if (!cap.isOpened())
    {
        cerr << "동영상 파일이 없습니다!" << endl;
    }
    // cvRound : 반올림
    cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    auto fps = cap.get(CAP_PROP_FPS);
    cout << "fps : " << cvRound(fps) << endl;

    Mat frame;
    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;
        imshow("frame", frame);
        if (waitKey(1000 / fps) == 27)  // fps 조절 숫자. waitKey : 일정시간동안 키입력을 기다림 (ms 단위)
            break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}