#include <cstdlib>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "VideoPlayer.hh"

using namespace cv;

int main(int argc, char **argv)
{
  std::vector<std::string>		videoPaths;
  VideoManager				videoManager;

  if (argc == 1)
    {
      std::cerr << "Please enter a video folder to load up!" << std::endl;
      return (1);
    }
  try
    {
      VideoPlayer videoPlayer(argv[1]);
      videoPlayer.videoLoop();
    }
  catch (std::runtime_error(&e))
    {
      std::cerr << e.what() << std::endl;
    }
}
