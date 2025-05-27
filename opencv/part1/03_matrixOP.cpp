#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

int main()
{
    Mat img;
    Mat img2(100, 200, CV_8UC1);
    Mat img3(100, 200, CV_8UC3, Scalar(0, 0, 255)); // 빨간색  rgb가 아니고 bgr 순이다.
    Mat img4(Size(600, 800), CV_8UC3);
    img4.setTo(Scalar(0, 255, 0));

    Mat mat1 = Mat::zeros(3, 3, CV_32SC1);
    Mat mat2 = Mat::ones(3, 3, CV_32FC1);
    Mat mat3 = Mat::eye(3, 3, CV_32FC1);

    cout << "< mat1 >" << endl << mat1 << endl;
    cout << "< mat2 >" << endl << mat2 << endl;
    cout << "< mat3 >" << endl << mat3 << endl;

    // 외부 메모리 사용하기
    float data[] = {1, 2, 3, 4, 5, 6 ,7 , 8, 9, 10};
    Mat mat4(2, 4, CV_32FC1, data);     // data가 더 많으면 되는만큼 채움, data가 더 적으면 뒤에 남은건 쓰레기값...?

    cout << "< mat4 >" << endl << mat4 << endl;

    // imshow("img", img);
    imshow("img2", img2);
    imshow("img3", img3);
    waitKey();
    
    return 0;
}