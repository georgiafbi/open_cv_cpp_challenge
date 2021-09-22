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

    // Mat img = imread("C:/Users/Silho/OneDrive/Desktop/adv_robot_programming/open_cv_cpp_challenge/open_cv_cpp_challenge/BookScene.png");
    // imshow("Book Scene",img);

    VideoCapture cap("C:/Users/Silho/OneDrive/Desktop/adv_robot_programming/open_cv_cpp_challenge/open_cv_cpp_challenge/BookScene.MOV");

    // cap is the object of class video capture that tries to capture Bumpy.mp4
    if ( !cap.isOpened() )  // isOpened() returns true if capturing has been initialized.
    {
        cout << "Cannot open the video file. \n";
        return -1;
    }

    // double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video
    // The function get is used to derive a property from the element.
    // Example:
    // CV_CAP_PROP_POS_MSEC :  Current Video capture timestamp.
    // CV_CAP_PROP_POS_FRAMES : Index of the next frame.

    //namedWindow("A_good_name",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
    // first argument: name of the window.
    // second argument: flag- types: 
    // WINDOW_NORMAL : The user can resize the window.
    // WINDOW_AUTOSIZE : The window size is automatically adjusted to fitvthe displayed image() ), and you cannot change the window size manually.
    // WINDOW_OPENGL : The window will be created with OpenGL support.
    namedWindow("Book Scene", 1);
    while(1)
    {
        Mat frame;
        // Mat object is a basic image container. frame is an object of Mat.
        cap >> frame; //get a new frame from video
        if (!cap.read(frame)) // if not success, break loop
        // read() decodes and captures the next frame.
        {
            cout<<"\n Cannot read the video file. \n";
            break;
        }

        imshow("Book Scene", frame);
        // first argument: name of the window.
        // second argument: image to be shown(Mat object).

        if(waitKey(30) == 27) // Wait for 'esc' key press to exit
        { 
            break; 
        }
    }
    
    return 0;
}