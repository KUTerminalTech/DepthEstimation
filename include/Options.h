#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include <string>

class Options {
private:
    int argument_length;
    char** arguments;

    std::string left_cam_path;
    std::string right_cam_path;

public:
    Options() = delete;
    Options(int argc, char** argv);
    ~Options();

    int init();

    const std::string getLeftCamera() const;
    const std::string getRightCamera() const;
};

#endif