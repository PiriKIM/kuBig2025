#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>
#include "/home/piri/kuBig2025/opencv/part2/color.hpp"

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

Ptr<cv::freetype::FreeType2> rapperFreeTypeCenterSetup(const String &fontpath)
{
    Ptr<cv::freetype::FreeType2> ft2 = freetype::createFreeType2();
    ft2->loadFontData(fontpath, 0);
    return ft2;
}

void rapperFreeTypeCenter(Mat &img, Ptr<cv::freetype::FreeType2> ft2, const String &text, const int &textHeight, const int &thickness, const int &line_type, const Scalar &color, const Point &textOrg)
{
    Size textSize = ft2->getTextSize(text, textHeight, -1, 0);
    Point org((textOrg.x - textSize.width) / 2, (textOrg.y - textSize.height) / 2);
    ft2->putText(img, text, org, textHeight, color, thickness, line_type, true);
}

int main()
{
    Mat img(1000, 1200, CV_8UC3, white);

    int a = 0, b = 0, c = 0;
    auto ft2 = rapperFreeTypeCenterSetup(folderPath + "NanumPenScript-Regular.ttf");

    String text = "안녕하세요, 세상이여!";

    while (true)
    {
        img.setTo(white);   // 배경 그리기

        rapperFreeTypeCenter(img, ft2, text, 50, -10, LINE_AA, blue, Point(600, 200));
        rapperFreeTypeCenter(img, ft2, text, 50, -1, LINE_AA, green, Point(600, 300));
        rapperFreeTypeCenter(img, ft2, text, 50, 0, LINE_AA, red, Point(600, 400));
        rapperFreeTypeCenter(img, ft2, text, 50, 1, LINE_AA, black, Point(600, 500));
        rapperFreeTypeCenter(img, ft2, text, 50, 2, LINE_AA, purple, Point(600, 600));
        rapperFreeTypeCenter(img, ft2, text, 50, 3, LINE_AA, cyan, Point(600, 700));

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