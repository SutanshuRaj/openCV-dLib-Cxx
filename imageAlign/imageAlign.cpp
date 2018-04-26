
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main (int argc, char * argv[]) {

  Mat img1 = imread("images/image1.jpg");
  Mat img2 = imread("images/image2.jpg");

  Mat imgGray1, imgGray2;
  cvtColor(img1, imgGray1, CV_BGR2GRAY);
  cvtColor(img2, imgGray2, CV_BGR2GRAY);

  const int warpMode = MOTION_EUCLIDEAN;

  Mat warpMatrix;

  if (warpMode == MOTION_HOMOGRAPHY)
    warpMatrix = Mat::eye(3, 3, CV_32F);
  else
    warpMatrix = Mat::eye(2, 3, CV_32F);

  int numberIter = 5000;
  double terminationEps = 1e-10;

  TermCriteria criteria(TermCriteria::COUNT+TermCriteria::EPS, numberIter, terminationEps);

  findTransformECC(imgGray1, imgGray2, warpMatrix, warpMode, criteria);

  Mat imgAligned;

  if (warpMode != MOTION_HOMOGRAPHY)
    warpAffine(img2, imgAligned, warpMatrix, img1.size(), INTER_LINEAR | WARP_INVERSE_MAP);
  else
    warpPerspective(img2, imgAligned, warpMatrix, img1.size(), INTER_LINEAR | WARP_INVERSE_MAP);

  imshow("Image-1", img1);
  imshow("Image-2", img2);
  imshow("Image Aligned", imgAligned);
  waitKey(0);
  return EXIT_SUCCESS;

}
