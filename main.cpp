#include <iostream>

#include <opencv2/opencv.hpp>

#include "Options.h"
#include "Camera.h"

using namespace cv;

int main(int argc, char* argv[]) {

    Options opt(argc, argv);
    if (opt.init()) { return 1; }



    return 0;
}
