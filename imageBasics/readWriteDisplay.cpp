
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(void) {
  
  Mat image, imgGray;
  String imageName("sample.jpg");
  image = imread(imageName, IMREAD_COLOR);

  if(image.empty()) {
    cout << "Image Not Found!" << endl;
    return EXIT_FAILURE; }

  cvtColor(image, imgGray, COLOR_BGR2GRAY);
  
  namedWindow("Image", WINDOW_AUTOSIZE);
  imshow("Image", image);

  namedWindow("GrayImage", WINDOW_AUTOSIZE);
  imshow("GrayImage", imgGray);

  waitKey(0);
  return EXIT_SUCCESS;
}
