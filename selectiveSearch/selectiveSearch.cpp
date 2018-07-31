
#include <opencv2/ximgproc/segmentation.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <ctime>

using namespace cv;
using namespace std;
using namespace cv::ximgproc::segmentation;

int main (int argc, char * argv[]) {

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
  
  
