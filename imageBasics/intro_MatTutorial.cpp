
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(void) {

  Mat imgA, imgB, imgGray, imgMaskClone;
  imgA = imread("sample.jpg", IMREAD_COLOR);
  imgB = imread("sample2.png", IMREAD_COLOR);

  if(imgA.empty() || imgB.empty()) {
    cout << "Could not open the Image." << endl;
    return -1;
  }

  // Assignment Operation with Mat Pointers.
  // Mat imgAssign(img);
  // Mat imgCopy(img, Rect(15, 15, 50, 50));
  Mat imgCropCopy = imgA(Range(100, 150), Range(100, 350));

  Mat imgMask(imgB.size(), CV_8U, Scalar(0));
  Mat imgClone = imgB.clone();
  imgClone.copyTo(imgMaskClone, imgMask);

  Size sz = imgClone.size();
  cout << "Number of Rows:" << sz.height << endl;
  cout << "Number of Cols:" << sz.width << endl;

  int size[] = {450, 450};
  Mat imgArray(2, size, CV_8U, Scalar::all(127));
  namedWindow("Image using C++", WINDOW_AUTOSIZE);
  imshow("Image using C++", imgCropCopy);

  Mat imgMat = (Mat_<double>(3, 3) << 0, -1, 0, 2, 1, 2, 0, -1, 0);
  cout << "M = " << endl << imgMat << endl;

  // cout << "Color Channel is: " << imgCropCopy.channels() << endl;
  // namedWindow("Image", WINDOW_AUTOSIZE);
  // imshow("Image", imgClone);
  // namedWindow("Image Cropped", WINDOW_AUTOSIZE);
  // imshow("Image Cropped", imgCropCopy);

  waitKey(0);
  return 0;
}
