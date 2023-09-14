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

    float scale = 1.f;
    Mat Q = Mat::zeros(4, 4, CV_64F);
    Mat map11, map12, map21, map22;

    Mat left_cam_mx = left_cam.cameraMatrix();
    Mat right_cam_mx = right_cam.cameraMatrix();

    Mat left_cam_coef = left_cam.cameraCoefficient();
    Mat right_cam_coef = right_cam.cameraCoefficient();

    left_cam_mx *= scale;
    right_cam_mx *= scale;

    // Mat left_recti = left_cam.rectificationMatrix();
    // Mat right_recti = right_cam.rectificationMatrix();

    // ? we need another 'PROJECTION MATRIX?'

    // * example 
    // cv::initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_32FC1, map11, map12);
    // cv::initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_32FC1, map21, map22);

    // ! implement below code based on above example
    // initUndistortRectifyMap(left_cam_mx, left_cam_coef, left_recti, left_pj, img_size, CV_32FC1, );
    // initUndistortRectifyMap(right_cam_mx, right_cam_coef, right_recti, right_pj, img_size, CV_32FC1, );

    /**************************************************************************************************************/
    /* initialization complete */
    /**************************************************************************************************************/

    double Tx = 0.12 // baseline
    // double focal =  // right porjection matrix < at(0, 0) as double >





    return 0;
}
