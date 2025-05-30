// 카메라 켜서 frame 확보
// 색 공간 -> hsv 로 변경 clone() 해서 따로 처리.
// 양방향 필터 처리
// inrange -> 색종이를 인식
// morph 함수 -> 이진화 Mat 정리
// labeling
// 화면에 rectangle 로 표시
// putText, ft2 로 색종이 or color-paper
// 사각형과 폰트는 색종이를 따라다녀야 함!
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

    while (true)
    {
        cap >> frame;

        imshow("frame", frame);
        if (waitKey(33) == 27)
            break;
    }
    
    destroyAllWindows();
    return 0;
}