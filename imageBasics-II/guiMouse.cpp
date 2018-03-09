
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Point center, circumference;
Mat source;
float radius;

void drawCircle(int action, int x, int y, int flags, void *userdata) {
  if (action == EVENT_LBUTTONDOWN) {
    center = Point(x, y);
    circle(source, center, 1, Scalar(255, 255, 0), 2, CV_AA); }

  else if (action == EVENT_LBUTTONUP) {
    circumference = Point(x, y);
    radius = sqrt(pow(center.x - circumference.x, 2) + pow(center.y - circumference.y, 2));
    circle(source, center, radius, Scalar(0, 255, 0), 2, CV_AA);
    imshow("Image with GUI", source); }
}

int main(void) {
  source = imread("sample.jpg", IMREAD_COLOR);

  if (source.empty()) {
    cout <<  "Image Not Found" << endl;
    return EXIT_FAILURE; }

  Mat image = source.clone();
  namedWindow("Image with GUI", WINDOW_AUTOSIZE);

  setMouseCallback("Image with GUI", drawCircle);
  int k = 0;

  while (k != 27) {
    imshow("Image with GUI", source);
    putText(source, "Choose Center and Drag. Press ESC to Exit", Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 255), 2);
    k = waitKey(23) & 0xFF;
    if (k == 99)
      image.copyTo(source); }

  return EXIT_SUCCESS;
}

