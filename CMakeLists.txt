cmake_minimum_required(VERSION 3.9)
project(Relaxe)

set(CMAKE_BUILD_TYPE Debug)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

include_directories(include)

link_directories(OpenCV/opencv-3.4.0)

file(GLOB SOURCE_FILES
        src/*.cpp
        include/*.h*)

add_executable( Relaxe ${SOURCE_FILES})

target_link_libraries( Relaxe ${OpenCV_LIBS})