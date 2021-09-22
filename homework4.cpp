#include <iostream>
#include "opencv2/core.hpp"

#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
// #include "opencv2/xfeatures2d.hpp"
using namespace cv;
// using namespace cv::xfeatures2d;
using std::cout;
using std::endl;

int main(int argc, char* argv[]){

    Mat img = imread("C:/Users/Silho/OneDrive/Desktop/adv_robot_programming/open_cv_cpp_challenge/open_cv_cpp_challenge/BookScene.png");
    imshow("Book Scene",img);
    waitKey(0);
    return 0;
}