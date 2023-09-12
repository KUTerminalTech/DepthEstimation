cmake_minimum_required(VERSION 2.7.0...3.27.0)
project(depth_estimation VERSION 0.1.0 LANGUAGES C CXX)

# include(CTest)
# enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
# set(Boost_USE_STATIC_RUNTIME OFF)

# Libary package lists
find_package(OpenCV REQUIRED)
find_package(Boost 1.70 REQUIRED COMPONENTS program_options)

add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
)

# libraries' include directories
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${OpenCV_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIR}
)

# link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
    ${OpenCV_LIBS}
    ${Boost_LIBRARIES}
)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
