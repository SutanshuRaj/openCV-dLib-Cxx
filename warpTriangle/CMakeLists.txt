cmake_minimum_required(VERSION 1.8)
PROJECT(warpTriangle)
find_package(OpenCV REQUIRED)
ADD_EXECUTABLE(warpTriangle warpTriangle.cpp)
TARGET_LINK_LIBRARIES(warpTriangle ${OpenCV_LIBS})

