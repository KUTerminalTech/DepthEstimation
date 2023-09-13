#include <iostream>

#include <opencv2/opencv.hpp>

#include "Options.h"
#include "Camera.h"

using namespace cv;

int main(int argc, char* argv[]) {

    Options opt(argc, argv);
    if (opt.init()) { return 1; }

    Camera left_cam(CONFING_PATH "camera/left.yaml");
    Camera right_cam(CONFING_PATH "camera/right.yaml");


    return 0;
}
