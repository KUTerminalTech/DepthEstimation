#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <string>

#include <opencv2/core/mat.hpp>

class Camera {
private:
    YAML::Node camera_config;

    uint32_t video_width;
    uint32_t video_height;

    std::string camera_name;

    cv::Mat camera_matrix;
    cv::Mat distortion_camera_coefficient;
    cv::Mat rectification_matrix;

public:
    Camera() = delete;
    Camera(std::string config_path);
    ~Camera();

    void init();

    const uint32_t videoWidth() const;
    const uint32_t videoHeight() const;
    const cv::Mat cameraMatrix() const;
    const cv::Mat cameraCoefficient() const;
    const cv::Mat rectificationMatrix() const;

};

#endif