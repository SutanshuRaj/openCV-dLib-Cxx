#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void) {

  Mat im_src, im_dst, im_out;

  im_src = imread("book2.jpg");

  vector <Point2f> pts_src;
  pts_src.push_back(Point2f(141, 131));
  pts_src.push_back(Point2f(480, 159));
  pts_src.push_back(Point2f(493, 630));
  pts_src.push_back(Point2f(64, 601));

  im_dst = imread("book1.jpg");

  vector <Point2f> pts_dst;
  pts_dst.push_back(Point2f(318, 256));
  pts_dst.push_back(Point2f(534, 372));
  pts_dst.push_back(Point2f(316, 670));
  pts_dst.push_back(Point2f(73, 473));

  if (im_src.empty() || im_dst.empty()) {
    cout << "Image Not Found." << endl;
    return EXIT_FAILURE; }

  Mat h = findHomography(pts_src, pts_dst);
  warpPerspective(im_src, im_out, h, Size(im_dst.cols, im_dst.rows));

  imshow("Original Image", im_src);
  imshow("Destination Image", im_dst);
  imshow("Warped Image", im_out);

  waitKey(0);
  destroyAllWindows();
  return EXIT_SUCCESS;
}
