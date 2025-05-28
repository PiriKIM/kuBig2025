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
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    cout << "Frame width : " << w << endl;
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    cout << "Frame height : " << h << endl;
    double fps = cap.get(CAP_PROP_FPS);
    cout << "fps : " << cvRound(fps) << endl;
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');

    VideoWriter outputVideo(folderPath + "inverse_vtest.avi", fourcc, fps, Size(w, h));
    if(!outputVideo.isOpened())
    {
        cerr << "파일 생성 실패!" << endl;
        return -1;
    }

    Mat frame;
    while (true)
    {
        cap >> frame;
        if (frame.empty())      // 마지막 프레임 처리
            break;
        frame = ~frame;
        outputVideo << frame;
        imshow("frame", frame);
        if (waitKey(1000 / fps) == 27)  // fps 조절 숫자. waitKey : 일정시간동안 키입력을 기다림 (ms 단위)
            break;
    }

    cap.release();
    outputVideo.release();
    destroyAllWindows();

    return 0;
}