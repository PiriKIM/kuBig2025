#include <iostream>
#include <opencv2/opencv.hpp>
#include "/home/piri/kuBig2025/opencv/part2/color.hpp"

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp");

    namedWindow("img");
    
    auto i = getTickCount();
    int keycode;
    while (true)
    {
        imshow("img", img);
        keycode = waitKey();
        cout << "keycode : " << keycode << endl;
        cout << "i : " << i << endl;
        cout << "fps : " << getTickFrequency() / (getTickCount() - i) << endl;

        if (keycode == 'v' || keycode == 'V')
        {
            img = ~img;
        }
        if (keycode == 'a' || keycode == 'A')
        {
            img = img + Scalar(1, 1, 1);    // 3채널 bgr 모두 연산
        }
        if (keycode == 'd' || keycode == 'D')
        {
            img = img - Scalar(1, 1, 1);
        }
        if (keycode == 82)
        {
            img = img + 1;                  // blue 채널에만 연산됨
            cout << "key up-arrow!" << endl;
        }
        if (keycode == 84)
        {
            img = img - 1;
            cout << "key down-arrow!" << endl;
        }
        
        if (keycode == 27)
            break;

        i = getTickCount();
    }

    destroyAllWindows();

    return 0;
}