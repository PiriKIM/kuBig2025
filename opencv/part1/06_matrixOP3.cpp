#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp");
    float data[] = {1, 1, 2, 3};
    Mat mat1(2, 2, CV_32FC1, data);
    cout << "mat1: " << endl << mat1 << endl;
    Mat mat2 = mat1.inv();
    cout << "mat2: " << endl << mat2 << endl;
    cout << "mat1 dot mat2: " << endl << mat1.dot(mat2) << endl;

    cout << "mat1.t(): " << endl << mat1.t() << endl;
    cout << "mat1*mat2: " << endl << mat1 * mat2 << endl;
    cout << "reshape 4,1: " << endl << mat1.reshape(4) << endl;
    
    Mat mat3;
    mat1.convertTo(mat3, CV_8UC1);
    // img.resize(100); // crop size
    Mat img2;
    resize(img, img2, Size(2000, 2000));
    Mat img3;
    resize(img, img3, Size(100, 100));
    imshow("img", img);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("mat3", mat3);

    waitKey();
    return 0;
}