//
// Created by sam on 10/03/18.
//

#ifndef RELAXE_VIDEOPLAYER_HH
# define RELAXE_VIDEOPLAYER_HH

# include <string>
# include <opencv2/highgui/highgui.hpp>
# include <opencv2/core/core.hpp>
# include <opencv2/imgproc.hpp>

# include "VideoManager.hh"

class VideoPlayer
{
 public:
  explicit VideoPlayer(const std::string& startingVideo);
  VideoPlayer();
  ~VideoPlayer() = default;
  VideoPlayer(const VideoPlayer&) = delete;
  const VideoPlayer&	operator=(const VideoPlayer&) = delete;
  void	videoLoop();

 private:
  VideoManager				videoManager;
  std::vector<std::string>		videoPaths;
  cv::VideoCapture			videoCapture;
  std::vector<std::string>::iterator	it;
};


#endif //RELAXE_VIDEOPLAYER_HH
