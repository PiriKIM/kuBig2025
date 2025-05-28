#include <iostream>
// #include <array.h>
#include <opencv2/opencv.hpp>
#include "/home/piri/kuBig2025/opencv/part2/color.hpp"

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

int main()
{
    // data
    String name = "Kimdongpil";
    int age = 10;
    Point pt1(100, 200);
    vector<int> scores = {80, 90, 50};
    Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);
    // Array arr(10);

    String filename = folderPath + "maydata.json";
    FileStorage fs;
    fs.open(filename, FileStorage::WRITE);
    fs << "name" << name;
    fs << "age" << age;
    fs << "point" << pt1;
    fs << "data" << mat1;
    // fs << "array" << arr; // 빌드 통과 못함!

    fs.release();

    return 0;
}