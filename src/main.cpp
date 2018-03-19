#include <cstdlib>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "VideoPlayer.hh"

using namespace cv;

int main(int argc, char **argv)
{
  std::vector<std::string>		videoPaths;
  VideoManager				videoManager;
  std::string				spotify;

  if (argc != 2)
    {
      std::cerr << "USAGE: ./relaxe [video path]"
		<< std::endl;
      return (1);
    }
  try
    {
      if ((system("./spotify_scripts/spotify_controller.sh play") == -1))
	std::cerr << "Could not execute spotify script!" << std::endl;
      VideoPlayer videoPlayer(argv[1]);
      videoPlayer.videoLoop();
    }
  catch (std::runtime_error(&e))
    {
      std::cerr << e.what() << std::endl;
    }
}
