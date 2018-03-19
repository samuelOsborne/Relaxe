//
// Created by sam on 10/03/18.
//

#include <iostream>
#include "VideoPlayer.hh"

VideoPlayer::VideoPlayer(const std::string &videoDirectoryPath)
{
  if (!(this->videoManager.loadVideosInDirectory(videoDirectoryPath)))
    throw std::runtime_error("Can't load video directory!");
  this->videoPaths = this->videoManager.getVideoPaths();
  if (this->videoPaths.empty())
    throw std::runtime_error("No videos loaded!");
  this->it = this->videoPaths.begin();
  this->videoCapture.open(*this->it);
  if (!this->videoCapture.isOpened())
    std::runtime_error("Can't load videos!");
  cvNamedWindow("Relaxe", CV_WINDOW_NORMAL);
  cvSetWindowProperty("Relaxe", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
}

void VideoPlayer::videoLoop()
{
  char			c;

  while (1)
    {
      cv::Mat frame;

      this->videoCapture >> frame;
      if (frame.empty())
	{
	  this->videoCapture.set(CV_CAP_PROP_POS_FRAMES, 0);
	  this->videoCapture >> frame;
	}
      imshow("Relaxe", frame);
      c = (char) cv::waitKey(25);
      if (c == '1')
	{
	  it++;
	  if (it == this->videoPaths.end())
	    it = this->videoPaths.begin();
	  this->videoCapture.open(*it);
	  if (!this->videoCapture.isOpened())
	    std::runtime_error("Error opening video stream or file");
	}
      else
      if (c == 27)
	break;
    }
  cv::destroyAllWindows();
}