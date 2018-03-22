#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdlib.h>

using namespace cv;
using namespace std;

void warpTriangle(Mat& imgInput, Mat& imgOutput, vector<Point2f> trigIn, vector<Point2f> trigOut) {

  Rect rIn = boundingRect(trigIn);
  Rect rOut = boundingRect(trigOut);

  vector<Point2f> trigInCrop, trigOutCrop;
  vector<Point> trigOutCropInt;

  for (int i = 0; i < 3; ++i) {
    trigInCrop.push_back(Point2f(trigIn[i].x - rIn.x, trigIn[i].y - rIn.y));
    trigOutCrop.push_back(Point2f(trigOut[i].x - rOut.x, trigOut[i].y - rOut.y));

    trigOutCropInt.push_back(Point((int)(trigOut[i].x - rOut.x), (int)(trigOut[i].y - rOut.y))); }

  Mat imgInCrop, imgOutCrop;
  imgInput(rIn).copyTo(imgInCrop);

  Mat warpMat = getAffineTransform(trigInCrop, trigOutCrop);

  imgOutCrop = Mat::zeros(rOut.height, rOut.width, imgInCrop.type());
  warpAffine(imgInCrop, imgOutCrop, warpMat, imgOutCrop.size(), INTER_LINEAR, BORDER_REFLECT_101);

  Mat mask = Mat::zeros(rOut.height, rOut.width, CV_32FC3);
  fillConvexPoly(mask, trigOutCropInt, Scalar(1.0, 1.0, 1.0), 16, 0);

  multiply(imgOutCrop, mask, imgOutCrop);
  multiply(imgOutput(rOut), Scalar(1.0, 1.0, 1.0) - mask, imgOutput(rOut));
  imgOutput(rOut) += imgOutCrop; }


int main(int argc, char * argv[]) {

  Mat imgInput = imread("robot.jpg");
  imgInput.convertTo(imgInput, CV_32FC3, 1/255.0);

  Mat imgOutput = Mat::ones(imgInput.size(), imgInput.type());
  imgOutput = Scalar(1.0, 1.0, 1.0);

  vector<Point2f> trigIn;
  trigIn.push_back(Point2f(360, 200));
  trigIn.push_back(Point2f(60, 250));
  trigIn.push_back(Point2f(450, 400));

  vector<Point2f> trigOut;
  trigOut.push_back(Point2f(400, 200));
  trigOut.push_back(Point2f(160, 270));
  trigOut.push_back(Point2f(400, 400));

  warpTriangle(imgInput, imgOutput, trigIn, trigOut);

  imgInput.convertTo(imgInput, CV_8UC3, 255.0);
  imgOutput.convertTo(imgOutput,CV_8UC3, 255.0);

  Scalar color = Scalar(255, 150, 0);

  vector<Point> trigInInt, trigOutInt;
  for (int i = 0; i < 3; ++i) {
    trigInInt.push_back(Point(trigIn[i].x, trigIn[i].y));
    trigOutInt.push_back(Point(trigOut[i].x, trigOut[i].y)); }

  polylines(imgInput, trigInInt, true, color, 2, 16);
  polylines(imgOutput, trigOutInt, true, color, 2, 16);

  imshow("Input", imgInput);
  imshow("Output", imgOutput);
  waitKey(0);
  
  return EXIT_SUCCESS;

}
