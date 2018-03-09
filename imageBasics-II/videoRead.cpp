#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(void){

  VideoCapture cap("chaplin.mp4");

  if (!cap.isOpened()) {
    cout << "Error Opening Video Stream / File." << endl;
    return EXIT_FAILURE; }

  namedWindow("Video", WINDOW_AUTOSIZE);

  while (cap.isOpened()) {
    Mat frame;
    cap >> frame;
    if (frame.empty()) {
      cout << "Can't Read File." << endl;
      return EXIT_FAILURE; }

    imshow("Video", frame);

    char c = (char)waitKey(25);
    if (c == 27)
      break; }

  cap.release();
  destroyAllWindows();
  waitKey(0);
  return EXIT_SUCCESS;
}