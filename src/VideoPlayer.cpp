//
// Created by sam on 10/03/18.
//

#include <iostream>
#include "VideoPlayer.hh"

VideoPlayer::VideoPlayer(const std::string &videoDirectoryPath)
{
  if (!(this->videoManager.loadVideosInDirectory(videoDirectoryPath)))
    throw std::runtime_error("Can't load video directory");
  this->videoPaths = this->videoManager.getVideoPaths();
  this->it = this->videoPaths.begin();
  this->videoCapture.open(*this->it);
  if (!this->videoCapture.isOpened())
    std::runtime_error("Can't load video directory");
  cvNamedWindow("Relaxe", CV_WINDOW_NORMAL);
  cvSetWindowProperty("Relaxe", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
}

void VideoPlayer::videoLoop()
{
  while (1)
    {
      cv::Mat frame;

      this->videoCapture >> frame;
      if (frame.empty())
	break;
      imshow("Relaxe", frame);
      char c = (char) cv::waitKey(25);
      //change to the enter key
      if (c == 10)
	{
	  if (it == videoPaths.end())
	    it = videoPaths.begin();
	  this->videoCapture.open(*it);
	  if (!this->videoCapture.isOpened())
	    std::runtime_error("Error opening video stream or file");
	  ++it;
	}
      else if (c == 27)
	break;
    }
  cv::destroyAllWindows();
}