cmake_minimum_required(VERSION 2.8.12)

PROJECT(objectTrack)

find_package( OpenCV REQUIRED)
ADD_EXECUTABLE(objectTrack objectTrack.cpp)
TARGET_LINK_LIBRARIES(objectTrack ${OpenCV_LIBS}) 
