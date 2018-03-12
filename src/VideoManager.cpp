//
// Created by sam on 09/03/18.
//

#include <dirent.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "VideoManager.hh"

VideoManager::VideoManager(std::vector<std::string> _videoPaths)
 : videoPaths{_videoPaths} { }

std::vector<std::string> VideoManager::getVideoPaths() const
{
  return (this->videoPaths);
}

bool 	VideoManager::loadVideosInDirectory(const std::string &directoryPath)
{
  struct dirent	*dirent;
  DIR		*dir;
  std::string	filePath;
  struct stat	fileStat;
  std::ifstream	fin;
  int 		num;

  if (( dir = opendir(directoryPath.c_str())) == nullptr)
    {
      std::cerr << "Can't open directory : " + directoryPath << std::endl;
      return (false);
    }
  while ((dirent = readdir(dir)))
    {
      filePath = directoryPath + "/" + dirent->d_name;
      if (filePath.substr(filePath.find_last_of('.')) == ".mp4")
	this->videoPaths.push_back(filePath);
    }
  closedir(dir);
  return (true);
}

void	VideoManager::displayVideoPaths() const
{
  for (auto it = this->videoPaths.begin(); it != this->videoPaths.end(); ++it)
    {
      std::cout << *it << std::endl;
    }
}

