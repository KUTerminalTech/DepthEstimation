#include <iostream>

#include <opencv2/opencv.hpp>
#include <boost/program_options.hpp>

using namespace cv;

namespace po = boost::program_options;

int main(int argc, char* argv[]) {

    std::string left_cam_path;
    std::string right_cam_path;

    // po::option_description argDesc("Allowed options", NULL);
    po::options_description argDesc("Argument description");
    argDesc.add_options()
        ( "help,h", "produce help message" )
        ( "deviceL,l", po::value<std::string>(), "camera device path for LEFT" )
        ( "deviceR,r", po::value<std::string>(), "camera device path for RIGHT" )
    ;

    po::variables_map vmap;
    po::store(po::parse_command_line(argc, argv, argDesc), vmap);
    po::notify(vmap);

    if (vmap.count("help")) {
        std::cerr << argDesc << std::endl;
        return 1;
    }

    if (vmap.count("deviceL")) {
        left_cam_path = vmap["deviceL"].as<std::string>();
    }

    if (vmap.count("deviceR")) {
        right_cam_path = vmap["deviceR"].as<std::string>();
    }

    return 0;
}
