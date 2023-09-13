#include "Camera.h"

#include <yaml-cpp/yaml.h>

Camera::Camera(std::string config_path) {
    camera_config = YAML::LoadFile(config_path);
}

Camera::~Camera() {  }

void Camera::init() {

    /* video width */
    video_width = camera_config["video_width"].as<uint32_t>();  
    /* video height */
    video_height = camera_config["video_height"].as<uint32_t>();

    /* camera name */
    camera_name = camera_config["camera_name"].as<std::string>();

    uint8_t cam_mx_row = camera_config["camera_matrix"]["row"].as<uint8_t>();
    uint8_t cam_mx_col = camera_config["camera_matrix"]["col"].as<uint8_t>();

    /* camera matrix */
    camera_matrix = cv::Mat(
        cv::Size(cam_mx_row, cam_mx_col),
        CV_32FC1,
        camera_config["camera_matrix"]["data"].as<double*>()
    );

    uint8_t coef_row = camera_config["camera_coefficient"]["row"].as<uint8_t>();
    uint8_t coef_col = camera_config["camera_coefficient"]["col"].as<uint8_t>();

    /* coefficient */
    distortion_camera_coefficient = cv::Mat(
        cv::Size(coef_row, coef_col),
        CV_32FC1,
        camera_config["camera_coefficient"]["data"].as<double*>()
    );

    uint8_t recti_row = camera_config["rectification"]["row"].as<uint8_t>();
    uint8_t recti_col = camera_config["rectification"]["col"].as<uint8_t>();

    /* rectificiation*/
    rectification_matrix = cv::Mat(
        cv::Size(recti_row, recti_col),
        CV_32FC1,
        camera_config["camerma_coefficient"]["data"].as<double*>()
    );

    // ? need projection ? 

}

const uint32_t Camera::videoWidth() const {
    return video_width;
}

const uint32_t Camera::videoHeight() const {
    return video_height;
}

const cv::Mat Camera::cameraMatrix() const {
    return camera_matrix;
}

const cv::Mat Camera::cameraCoefficient() const {
    return distortion_camera_coefficient;
}

const cv::Mat Camera::rectificationMatrix() const {
    return rectification_matrix;
}