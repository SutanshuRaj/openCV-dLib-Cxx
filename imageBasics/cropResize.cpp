#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {
  
  Mat source, scaleDown, scaleUp;
  String imgName("sample.jpg");

  source = imread(imgName, IMREAD_COLOR);
  double scaleX = 0.6;
  double scaleY = 0.6;

  if(source.empty()) {
    cout << "Image Not Found." << endl;
    return EXIT_FAILURE; }

  resize(source, scaleDown, Size(), scaleX, scaleY, INTER_LINEAR);
  resize(source, scaleUp, Size(), scaleX * 3, scaleY * 3, INTER_LINEAR);

  namedWindow("Scaled-Up Image", WINDOW_AUTOSIZE);
  namedWindow("Scaled-Down Image", WINDOW_AUTOSIZE);
  imshow("Scaled-Up Image", scaleUp);
  imshow("Scaled-Down Image", scaleDown);
  
  waitKey(0);

  Mat imgCrop = source(Range(15, 250), Range(15, 450));
  namedWindow("Cropped Image", WINDOW_AUTOSIZE);
  imshow("Cropped Image", imgCrop);

  waitKey(0);
  return EXIT_SUCCESS;
}
