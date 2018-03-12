#include <cstdlib>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include "VideoPlayer.hh"
#include "VideoManager.hh"

using namespace cv;

int main(int argc, char **argv)
{
  std::vector<std::string>		videoPaths;
  VideoManager				videoManager;
  VideoPlayer				videoPlayer(argv[1]);

  videoPlayer.videoLoop();
//  if (system("../spotify_scripts/spotify_controller.sh play") == -1)
//    std::cerr << "Could not use Spotify controller" << std::endl;
//  if (!(videoManager.loadVideosInDirectory("../Videos")))
//    {
//      std::cerr << "Error in loading directory!" << std::endl;
//      return (1);
//    }
//  videoPaths = videoManager.getVideoPaths();
//  auto it = videoPaths.begin();
//
//  VideoCapture cap(argv[1]);
//
//  if (!cap.isOpened())
//    {
//      std::cerr << "Error opening video stream or file" << std::endl;
//      return -1;
//    }
//  cvNamedWindow("Relaxe", CV_WINDOW_NORMAL);
//  cvSetWindowProperty("Relaxe", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
//  while (1)
//    {
//      Mat frame;
//
//      cap >> frame;
//      if (frame.empty())
//	break;
//      imshow("Relaxe", frame);
//      char c = (char) cv::waitKey(25);
//      if (c == 27)
//	{
//	  if (it == videoPaths.end())
//	    it = videoPaths.begin();
//	  cap.open(*it);
//	  if (!cap.isOpened())
//	    {
//	      std::cerr << "Error opening video stream or file" << std::endl;
//	      return -1;
//	    }
//	  ++it;
//	}
//    }
//  cap.release();
//  destroyAllWindows();
//  return 0;
}
