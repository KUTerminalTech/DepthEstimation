#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <string>

#include <yaml-cpp/yaml.h>
#include <opencv2/core/mat.hpp>

class Camera {
private:
    // YAML::Node camera_config;
    int video_width;
    int video_height;

    std::string camera_name;

    cv::Mat camera_matrix;
    cv::Mat distortion_camera_coefficient;
    cv::Mat rectification_matrix;

public:
    Camera() = delete;
    Camera(std::string config_path);
    ~Camera();



};

#endif