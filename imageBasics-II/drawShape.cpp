#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(void) {

  Mat imageLine, imageCircle, imageText;

  Mat image = imread("mark.jpg");

  if (image.empty()) {
    std::cout << "Image Not Found" << std::endl;
    return EXIT_FAILURE; }

  imageLine = image.clone();
  line(imageLine, Point(300, 180), Point(400, 180), Scalar(0, 255, 0), 1, CV_AA);
  String str1 = "Image with Line";

  imageCircle = image.clone();
  circle(imageCircle, Point(350, 200), 150, Scalar(0, 255, 0), 1, CV_AA);
  String str2 = "Image with Circle";

  imageText = image.clone();
  putText(imageText, "Mark Zuckerberg", Point(200, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 1);
  String str3 = "Image with Text";

  namedWindow(str1, WINDOW_AUTOSIZE);
  imshow(str1,	imageLine);

  namedWindow(str2, WINDOW_AUTOSIZE);
  imshow(str2,	imageCircle);

  namedWindow(str3, WINDOW_AUTOSIZE);
  imshow(str3,	imageText);
  
  waitKey(0);
  return EXIT_SUCCESS;

}
