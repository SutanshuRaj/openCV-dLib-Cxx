
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
using namespace cv;

String faceCascadePath;
CascadeClassifier faceCascade;

int main(int argc, char * argv[]) {

  Mat frame, frameGray, frameClone;
  vector <Rect> faces;

  faceCascadePath = "models/haarcascade_frontalface_default.xml";
  int faceNeighboursMax = 5;
  int neighbourStep = 1;

  if (!faceCascade.load(faceCascadePath)) {
    cout << "Error Loading Face Cascade File." << endl;
    return EXIT_FAILURE; }

  frame = imread("hillary_clinton.jpg");
  cvtColor(frame, frameGray, COLOR_BGR2GRAY);

  for (int neigh = 1; neigh <= faceNeighboursMax; ++neigh) {
    frameClone = frame.clone();
    faceCascade.detectMultiScale(frameGray, faces, 1.2, neigh);

    for (size_t i = 0; i < faces.size(); ++i) {
      int x = faces[i].x;
      int y = faces[i].y;
      int w = faces[i].width;
      int h = faces[i].height;

      rectangle(frameClone, Point(x, y), Point(x+w, y+h), Scalar(255,0,0), 2, 4); }

    putText(frameClone, format("# Neighbours = %d", neigh), Point(10, 50),
	    FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 4);
    imshow("Face Detect Demo", frameClone);

    if (waitKey(0) == 27) {
      destroyAllWindows();
      break; } }

  return EXIT_SUCCESS;
}
