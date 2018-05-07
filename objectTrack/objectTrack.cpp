
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>

using namespace std;
using namespace cv;

int main (int argc, char * argv[]) {

  string trackerTypes[6] = {"BOOSTING", "MIL", "KCF", "TLD", "MEDIANFLOW", "GOTURN"};
  string trackerType = trackerTypes[2];
  Ptr<Tracker> tracker;

  if (trackerType == "BOOSTING")
    tracker = TrackerBoosting::create();

  if (trackerType == "MIL")
    tracker = TrackerMIL::create();

  if (trackerType == "KCF")
    tracker = TrackerKCF::create();

  if (trackerType == "TLD")
    tracker = TrackerTLD::create();

  if (trackerType == "MEDIANFLOW")
    tracker = TrackerMedianFlow::create();

  if (trackerType == "GOTURN")
    tracker = TrackerGOTURN::create();

  VideoCapture vid("videos/chaplin.mp4");

  if ( !vid.isOpened()) {
    cout << "Could not Read Video File." << endl;
    return EXIT_FAILURE; }

  Mat frame;
  bool positive = vid.read(frame);

  // Rect2d bbox (287, 23, 86, 320);
  
  Rect2d bbox = selectROI(frame, false);
  rectangle(frame, bbox, Scalar(255, 0, 0), 2, 1);
  imshow("Tracking", frame);

  tracker -> init(frame, bbox);

  while (vid.read(frame)) {

    double timer = (double)getTickCount();
    bool positive = tracker -> update(frame, bbox);
    float fps = getTickFrequency() / ((double)getTickCount() - timer);

    if (positive)
      rectangle(frame, bbox, Scalar(255, 0, 0), 2, 1);
    else
      putText(frame, "Tracking Failure Detected", Point(100, 80), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2);

    putText(frame, trackerType + " Tracker", Point(100, 20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50, 170, 50), 2);
    putText(frame, "FPS: " + to_string(fps), Point(100, 50), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50, 170, 50), 2);
    imshow ("Tracking", frame);

    int k = waitKey(1);
    if (k == 27)
      break;

  }
}

    
  
  
