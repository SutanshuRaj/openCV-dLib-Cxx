cmake_minimum_required(VERSION 2.8)

PROJECT(imageClassify)

# MAC Users Uncomment the line below
# SET(OpenCV_DIR /usr/local/Cellar/opencv3/3.2.0/share/OpenCV/)

find_package( OpenCV REQUIRED )

# MacOS Users Uncomment the Lines Below #
ADD_EXECUTABLE(train_digits train_digits.cpp)
TARGET_LINK_LIBRARIES(train_digits ${OpenCV_LIBS})

# add_example(train_digits)
