#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <vector>

using namespace cv;
using namespace std;

int main(void) {

  Mat image, result, result2;

  image = imread("sample.jpg", IMREAD_COLOR);

  if(image.empty()) {
    cout <<  "Image Not Found." << endl;
    return EXIT_FAILURE; }

  Mat warpMat = (Mat_<double>(2, 3) << 1.2, 0.2, 2, -0.3, 1.3, 1);
  Mat warpMat2 = (Mat_<double>(2, 3) << 1.2, 0.3, 2, 0.2, 1.3, 1);

  warpAffine(image, result, warpMat, Size(1.5 * image.rows, 1.4 * image.cols),  INTER_LINEAR, BORDER_REFLECT_101);
  warpAffine(image, result2, warpMat2, Size(1.5 * image.rows, 1.4 * image.cols), INTER_LINEAR, BORDER_REFLECT_101);

  imshow("Original Image", image);
  imshow("Warped Image", result);
  imshow("Warped Image - 2", result2);
  waitKey(0);
  return EXIT_SUCCESS;
}
