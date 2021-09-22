#include <iostream>
#include "opencv2/core.hpp"

#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
using namespace cv;
using namespace cv::xfeatures2d;
using std::cout;
using std::endl;



int main(int argc, char* argv[]){
    
    Mat img = imread("C:/Users/Silho/OneDrive/Desktop/adv_robot_programming/open_cv_cpp_challenge/open_cv_cpp_challenge/BookScene.png",IMREAD_GRAYSCALE);
    
      if ( img.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        return -1;
    }
    // imshow("Book Scene",img);
    // waitKey(20);
    VideoCapture cap("C:/Users/Silho/OneDrive/Desktop/adv_robot_programming/open_cv_cpp_challenge/open_cv_cpp_challenge/BookScene.MOV");

    // cap is the object of class video capture that tries to capture Bumpy.mp4
    if ( !cap.isOpened() )  // isOpened() returns true if capturing has been initialized.
    {
        cout << "Cannot open the video file. \n";
        return -1;
    }

    
    namedWindow("Book Scene", 1);

     //-- Step 1: Detect the keypoints using SURF Detector, compute the descriptors
    int minHessian = 400;
    Ptr<SIFT> detector = SIFT::create();
    std::vector<KeyPoint> keypoints_object, keypoints_scene;
    Mat descriptors_object, descriptors_scene;

    detector->detectAndCompute( img, noArray(), keypoints_object, descriptors_object );
    while(1)
    {
        Mat grayFrame;
        Mat frame;
        // Mat object is a basic image container. frame is an object of Mat.
        cap >> frame; //get a new frame from video
        //convert color frame to gray frame
        cvtColor(frame, grayFrame,COLOR_BGR2GRAY);
        if (!cap.read(frame)) // if not success, break loop
        // read() decodes and captures the next frame.
        {
            cout<<"\n Cannot read the video file. \n";
            break;
        }
        // detector->detectAndCompute( grayFrame, noArray(), keypoints_scene, descriptors_scene );
        imshow("Book Scene", grayFrame);
        // first argument: name of the window.
        // second argument: image to be shown(Mat object).

        if(waitKey(30) == 27) // Wait for 'esc' key press to exit
        { 
            break; 
        }
    }
    
    return 0;
}