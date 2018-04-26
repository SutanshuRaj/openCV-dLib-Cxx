cmake_minimum_required(VERSION 2.8)
PROJECT(imageAlign)
find_package(OpenCV REQUIRED)

# ADD_EXECUTABLE(imageAlignGrad imageAlignGrad.cpp)
ADD_EXECUTABLE(imageAlign imageAlign.cpp)

# TARGET_LINK_LIBRARIES(imageAlignGrad ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(imageAlign ${OpenCV_LIBS})
