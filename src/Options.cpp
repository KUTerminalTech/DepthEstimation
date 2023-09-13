#include "Options.h"

#include <iostream>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

Options::Options(int argc, char** argv)
    : argument_length(argc), arguments(argv)
{  }

Options::~Options() {  }

int Options::init() {

    po::options_description desc("Depth estimation argument description.");
    desc.add_options()
        ( "help,h", "produce help message" )
        ( "deviceL,l", po::value<std::string>(), "camera device path for LEFT" )
        ( "deviceR,r", po::value<std::string>(), "camera device path for RIGHT" )
    ;

    po::variables_map vmap;
    po::store(po::parse_command_line(argument_length, arguments, desc), vmap);
    po::notify(vmap);

    if (vmap.count("help")) {
        std::cerr << desc << std::endl;
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

const std::string Options::getLeftCamera() const {
    return left_cam_path;
}

const std::string Options::getRightCamera() const {
    return right_cam_path;
}