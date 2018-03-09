
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/objdetect.hpp"
#include <opencv2/ml.hpp>

using namespace cv::ml;
using namespace cv;
using namespace std;

int main(int argc, char * argv[]) {

  HOGDescriptor hog(Size(64, 128), Size(16, 16), Size(8, 8), Size(8, 8), 9, 0, -1, 0, 0.2, 1, 64, 0);

  vector<float> svmDetectorDefault = hog.getDefaultPeopleDetector();
  hog.setSVMDetector(svmDetectorDefault);

  float finalHeight = 800.0;
  String imagePath = "pedestrians/race.jpg";

  Mat img = imread(imagePath, IMREAD_COLOR);
  if (img.empty()) {
    cout << "Image cannot Load!" << endl;
    return EXIT_FAILURE; }

  float finalWidth = (finalHeight * img.cols) / img.rows;
  resize(img, img, Size(finalWidth, finalHeight));

  vector<Rect> bboxes;
  vector<double> weights;

  float hitThreshold = 1.0;
  Size winStride = Size(8, 8);
  Size padding = Size(32, 32);
  float scale = 1.05;
  float finalThreshold = 2;
  bool useMeanShiftGrouping = 0;

  hog.detectMultiScale(img, bboxes, weights, 0, winStride, padding, scale, finalThreshold, useMeanShiftGrouping);

  if (!bboxes.empty()) {
    cout << "Default Detector :: Pedestrians Detected: " << bboxes.size() << endl;
    vector<Rect>::const_iterator loc = bboxes.begin();
    vector<Rect>::const_iterator end = bboxes.end();
    for ( ; loc != end; ++loc) {
      rectangle(img, *loc, Scalar(0, 255, 0), 2); } }

  imshow("Pedestrians", img);
  waitKey(0);
  return EXIT_SUCCESS;
}
