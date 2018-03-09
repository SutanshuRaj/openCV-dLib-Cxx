
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
using namespace cv;

String faceCascadePath, smileCascadePath;
CascadeClassifier faceCascade, smileCascade;

int main(int argc, char * argv[]) {

  faceCascadePath = "models/haarcascade_frontalface_default.xml";
  smileCascadePath = "models/haarcascade_smile.xml";

  if (!faceCascade.load(faceCascadePath) || !smileCascade.load(smileCascadePath)) {
    cout << "Unable to Load XML Files." << endl;
    return EXIT_FAILURE; }

  int smileNeighboursMax = 25;
  int neighbourStep = 2;

  Mat frame, frameGray;
  vector <Rect> faces, smiles;
  
  frame = imread("hillary_clinton.jpg");
  cvtColor(frame, frameGray, COLOR_BGR2GRAY);

  faceCascade.detectMultiScale(frameGray, faces, 1.3, 3);

  for (size_t i = 0; i < faces.size(); ++i) {
    int x = faces[i].x;
    int y = faces[i].y;
    int w = faces[i].width;
    int h = faces[i].height;

    rectangle(frame, Point(x, y), Point(x+w, y+h), Scalar(255, 0, 0), 2);

    Mat faceROI = frameGray(faces[i]);

    for (int neigh = 0; neigh <= smileNeighboursMax; neigh += neighbourStep) {
      Mat frameClone = frame.clone();
      Mat faceCloneROI = frameClone(faces[i]);

      smileCascade.detectMultiScale(faceROI, smiles, 1.3, neigh);

      for (size_t j = 0; j < smiles.size(); ++j) {
	int xx = smiles[j].x;
	int yy = smiles[j].y;
	int ww = smiles[j].width;
	int hh = smiles[j].height;

	rectangle(faceCloneROI, Point(xx, yy), Point(xx + ww, yy + hh),
		  Scalar(0, 255, 0), 2); }

      putText(frameClone, format("# Neighbours: %d", neigh), Point(10, 50),
	      FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 4);
      imshow("Face Smile Demo", frameClone);

      if (waitKey(0) == 27) {
	destroyAllWindows();
	break; }
    }
  }
}
