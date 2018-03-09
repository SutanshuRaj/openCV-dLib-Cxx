#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {

  VideoCapture cap(0);

  if (!cap.isOpened()) {
    cout << "Unable to Open Video Feed." << endl;
    return EXIT_FAILURE; }

  int frameWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
  int frameHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

  namedWindow("Video", WINDOW_AUTOSIZE);

  VideoWriter out("outVideo.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frameWidth, frameHeight));

  while (cap.isOpened()) {

    Mat frame;
    cap >> frame;

    if (frame.empty()) {
      cout << "Could not Read the Frame." << endl;
      cout << EXIT_FAILURE; }

    out.write(frame);
    imshow("Video", frame);

    char c = (char)waitKey(25);
    if (c == 27)
      break;

  }

  cap.release();
  out.release();
  destroyAllWindows();

  waitKey(1);
  return EXIT_SUCCESS;
}

    
    
