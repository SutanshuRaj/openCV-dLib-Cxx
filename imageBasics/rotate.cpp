
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {

  Mat img, rotateMat, imgRotate;
  img = imread("sample.jpg", cv::IMREAD_COLOR);

  if (img.empty()) {
    cout << "Image Not Found." << endl;
    return EXIT_FAILURE; }

  Point2f center(img.rows/2, img.cols/2);
  double rotationAngle = 30;
  double scale = 1;

  rotateMat = cv::getRotationMatrix2D(center, rotationAngle, scale);
  cout << "Rotation Matrix is: " << endl << rotateMat << endl;
  warpAffine(img, imgRotate, rotateMat, Size(img.rows, img.cols));

  namedWindow("Original Image", WINDOW_AUTOSIZE);
  namedWindow("Rotated Image", WINDOW_AUTOSIZE);
  imshow("Original Image", img);
  imshow("Rotated Image", imgRotate);

  waitKey(0);
  return EXIT_SUCCESS;

}
