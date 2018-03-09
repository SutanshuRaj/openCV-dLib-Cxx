#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <vector>

using namespace cv;
using namespace std;

int main(void) {

  vector <Point2f> input;
  input.push_back(Point2f(50, 50));
  input.push_back(Point2f(100, 100));
  input.push_back(Point2f(200, 150));

  vector <Point2f> output;
  output.push_back(Point2f(72, 51));
  output.push_back(Point2f(142, 101));
  output.push_back(Point2f(272, 136));

  vector <Point2f> output2;
  output2.push_back(Point2f(77, 76));
  output2.push_back(Point2f(152, 151));
  output2.push_back(Point2f(287, 236));

  // Mat input = (Mat_<int>(3, 2) << 50, 50, 100, 100, 200, 150);
  // Mat output = (Mat_<int>(3, 2) << 72, 51, 142, 101, 272, 136);
  // Mat output2 = (Mat_<int>(3, 2) << 77, 76, 152, 151, 287, 236);

  Mat warpMat = cv::getAffineTransform(input, output);
  Mat warpMat2 = cv:: getAffineTransform(input, output2);

  cout << "Warp Matrix - 1: " << endl << warpMat << endl;
  cout << "Warp Matrix - 2: " << endl << warpMat2 << endl;

  return EXIT_SUCCESS;
}

