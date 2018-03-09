cmake_minimum_required(VERSION 2.8.12)

PROJECT(objectDetect)

find_package( OpenCV REQUIRED )
ADD_EXECUTABLE(detectPedestrian detectPedestrian.cpp)
TARGET_LINK_LIBRARIES(detectPedestrian ${OpenCV_LIBS})
