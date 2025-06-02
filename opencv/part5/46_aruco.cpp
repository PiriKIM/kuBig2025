#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include "/home/piri/kuBig2025/opencv/part2/color.hpp"

using namespace std;
using namespace cv;

String folderPath = "/home/piri/kuBig2025/opencv/data/";

int main()
{
    VideoCapture cap(0);
    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_6X6_250);

    vector<int> markerIds;
    vector<Vec3d> rvecs, tvecs;
    vector<vector<Point2f>> markerCorners;
    Mat cameraMatrix = (Mat_<double>(3, 3) << 1000, 0, 640, 0, 1000, 360, 0, 0, 1);
    Mat distCoeffs = (Mat_<double>(5, 1) << 0, 0, 0, 0, 0);

    Mat frame;
    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;
        
        aruco::detectMarkers(frame, dictionary, markerCorners, markerIds);

        aruco::drawDetectedMarkers(frame, markerCorners, markerIds);

        aruco::estimatePoseSingleMarkers(markerCorners, 0.05, cameraMatrix, distCoeffs, rvecs, tvecs);
        
        for (int i = 0; i < markerIds.size(); ++i)
        {
            cout << rvecs[i][0] << rvecs[i][1] << rvecs[i][2] << endl;
            cout << tvecs[i][0] << tvecs[i][1] << tvecs[i][2] << endl;
            cv::drawFrameAxes(frame, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1);
        }

        imshow("frame", frame);
        if (waitKey(33) == 27)
            break;
    }

    destroyAllWindows();
    return 0;
}