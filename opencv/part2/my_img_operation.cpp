// #include <opencv2/opencv.hpp>
// using namespace cv;
// using namespace std;

// int main() {
//     Mat img = imread("/home/piri/kuBig2025/opencv/data/lenna.bmp");
//     if (img.empty()) {
//         cout << "이미지를 불러올 수 없습니다." << endl;
//         return -1;
//     }

//     Mat modified;
//     int value = 0;
//     int direction = 1; // 1: 밝게, -1: 어둡게

//     while (true) {
//         img.convertTo(modified, -1, 1, value); // 알파=1, 베타=value (밝기만 조절)

//         imshow("Bright/Dark Animation", modified);
//         int key = waitKey(30);
//         if (key == 27) break;  // ESC 키로 종료

//         value += direction;

//         if (value >= 100) direction = -1;  // 최대 밝기 도달 → 어둡게
//         if (value <= -100) direction = 1;  // 최소 밝기 도달 → 밝게
//     }

//     destroyAllWindows();
//     return 0;
// }


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// saturate_cast 없이 수동으로 범위 제한
uchar clamp(int val) {
    return val < 0 ? 0 : (val > 255 ? 255 : val);
}

int main() {
    Mat img = imread("/home/piri/kuBig2025/opencv/data/lenna.bmp");
    if (img.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return -1;
    }

    Mat modified = img.clone();

    int delta = 1;   // 밝기 변화량
    int value = 0;   // 현재 밝기 보정값
    int direction = 1;  // 1이면 밝게, -1이면 어둡게

    while (true) {
        // 원본 이미지 기준으로 수정본 생성
        modified = img.clone();

        for (int y = 0; y < modified.rows; ++y) {
            for (int x = 0; x < modified.cols; ++x) {
                Vec3b& pixel = modified.at<Vec3b>(y, x);
                for (int c = 0; c < 3; ++c) {
                    pixel[c] = clamp(pixel[c] + value);
                }
            }
        }

        imshow("3-Channel Add/Subtract", modified);

        int key = waitKey(30);
        if (key == 27) break;  // ESC로 종료

        value += delta * direction;

        if (value >= 100) direction = -1;
        if (value <= -100) direction = 1;
    }

    destroyAllWindows();
    return 0;
}
