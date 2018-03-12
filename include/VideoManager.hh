//
// Created by sam on 09/03/18.
//

#ifndef RELAXE_VIDEOMANAGER_HH
# define RELAXE_VIDEOMANAGER_HH

# include <string>
 #include <vector>

class VideoManager
{
 public:
  explicit VideoManager() = default;
  explicit VideoManager(std::vector<std::string>);
  ~VideoManager() = default;
  VideoManager(const VideoManager&) = delete;
  const VideoManager&	operator=(const VideoManager&) = delete;

  std::vector<std::string> 	getVideoPaths() const;
  bool				loadVideosInDirectory(const std::string &
  directoryPath);
  void				displayVideoPaths() const;
 private:
  std::vector<std::string>	videoPaths;
};


#endif //RELAXE_VIDEOMANAGER_HH
