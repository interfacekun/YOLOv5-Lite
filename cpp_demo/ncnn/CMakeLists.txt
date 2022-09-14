project(YOLOv5s)

cmake_minimum_required(VERSION 3.10.2)

#set(ncnn_DIR "/root/git/ncnn-tensorflow/build/src/CMakeFiles/ncnn.dir")

#INCLUDE_DIRECTORIES(/root/git/ncnn-tensorflow/build/install/include)
#find_library(NCNN_LIB libncnn.a /root/git/ncnn-tensorflow/build/install/lib)

find_package(ncnn REQUIRED 
            PATHS /root/git/ncnn/build/install/lib/cmake/ncnn 
            NO_DEFAULT_PATH)
find_package(OpenCV REQUIRED)

add_executable(ncnnv5lite v5lite-s.cpp)

target_link_libraries(ncnnv5lite ncnn ${OpenCV_LIBS})
#target_link_libraries(ncnnv5lite ${libncnn.a} ${OpenCV_LIBS})