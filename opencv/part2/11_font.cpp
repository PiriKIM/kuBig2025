#include <iostream>
#include <opencv2/opencv.hpp>
#include "/home/piri/kuBig2025/opencv/part2/color.hpp"

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

int main()
{
    Mat img(400, 600, CV_8UC3, white);

    int a = 0, b = 0, c = 0;

    while (true)
    {
        img.setTo(white);   // 배경 그리기
        
        putText(img, "This is kuBig2025 test TEXT", Point(20 + a, 50), FONT_ITALIC, 1, red);
        putText(img, "This is kuBig2025 test TEXT", Point(20 + a, 100), FONT_HERSHEY_SIMPLEX, 1, green);
        putText(img, "This is kuBig2025 test TEXT", Point(20 + a, 150), FONT_HERSHEY_DUPLEX, 1, blue);
        putText(img, "This is kuBig2025 test TEXT", Point(20 + a, 200), FONT_HERSHEY_TRIPLEX, 1, yellow);
        putText(img, "This is kuBig2025 test TEXT", Point(20 + a, 250), FONT_HERSHEY_COMPLEX, 1, purple);
        putText(img, "This is kuBig2025 test TEXT", Point(20 + a, 300), FONT_HERSHEY_PLAIN, 1, cyan);

        imshow("img", img);
        if (waitKey(33) == 27)
            break;
        a += 1;
        b -= 1;
        c += 3;
    }
    
    destroyAllWindows();

    return 0;
}