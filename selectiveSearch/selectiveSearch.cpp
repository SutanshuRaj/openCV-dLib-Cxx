
#include <opencv2/ximgproc/segmentation.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <ctime>

using namespace cv;
using namespace std;
using namespace cv::ximgproc::segmentation;

static void help() {
  cout << endl << "Usage: " << endl <<
    "/.selectiveSearch inputImage (f | g) " << endl <<
    "f=fast and q=quality" << endl <<
    "Use 'l' to decrease bounding boxes, 'm' to increase, and 'q' to quit." << endl; }

int main (int argc, char * argv[]) {

  if (argc < 3) {
    help();
    return -1; }

  setUseOptimized(true);
  setNumThreads(4);

  Mat img = imread(argv[1]);

  int height = 200;
  int width = img.cols * height / img.rows;
  resize(img, img, Size(width, height));

  Ptr<SelectiveSearchSegmentation> selSearch = createSelectiveSearchSegmentation();

  selSearch -> setBaseImage(img);

  if (argv[2][0] == 'f')
    selSearch -> switchToSelectiveSearchFast();
  else if (argv[2][0] == 'q')
    selSearch -> switchToSelectiveSearchQuality();
  else
    return -1;

  vector<Rect> bbox;
  selSearch -> process(bbox);
  cout << "Total Region Proposals: " << bbox.size() << endl;

  int numBbox = 100;
  int increment = 50;

  while (1) {
    Mat outputImg = img.clone();
    for (int i = 0; i < bbox.size(); ++i) {
      if (i < numBbox)
	rectangle(outputImg, bbox[i], Scalar(0, 255, 0));
      else
	break; }

    imshow("Output Image", outputImg);

    int k = waitKey();
    if (k == 109)
      numBbox += increment;
    else if (k == 108 && numBbox > increment)
      numBbox -= increment;
    else if (k == 113)
      break; }

  return 0; }

