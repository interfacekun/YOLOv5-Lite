project(YOLOv5s)

cmake_minimum_required(VERSION 3.10.2)

#set(ncnn_DIR "/root/git/ncnn-tensorflow/build/src/CMakeFiles/ncnn.dir")

#INCLUDE_DIRECTORIES(/root/git/ncnn-tensorflow/build/install/include)
#find_library(NCNN_LIB libncnn.a /root/git/ncnn-tensorflow/build/install/lib)

EXECUTE_PROCESS(
    COMMAND whoami
    TIMEOUT 5
    OUTPUT_VARIABLE HOST
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
MESSAGE(STATUS "BUILD FROM HOST ${HOST}")

if(${HOST} STREQUAL "interface")
    set(NCNN_PROJ /Volumes/outDisk/git/IoT/ncnn)
    add_definitions(-DUSE_VULKAN_COMPUTE)
elseif(${HOST} STREQUAL "xmk")
    set(NCNN_PROJ /Users/xmk/git/IoT/ncnn)
    add_definitions(-DUSE_VULKAN_COMPUTE)
else()
    set(NCNN_PROJ /root/git/IoT/ncnn)
endif()

set(NCNN_PATH ${NCNN_PROJ}/build/install/lib/cmake/ncnn)
find_package(ncnn REQUIRED 
            PATHS ${NCNN_PATH}
            NO_DEFAULT_PATH)
find_package(OpenCV REQUIRED)

add_executable(ncnnv5lite v5lite-s.cpp)
target_link_libraries(ncnnv5lite ncnn ${OpenCV_LIBS})

add_library(v5lite SHARED v5lite-s.cpp)
target_link_libraries(v5lite ncnn ${OpenCV_LIBS})

# add_executable(ncnnv5litecgo v5lite-cgo.cpp)
# target_link_libraries(ncnnv5litecgo ncnn ${OpenCV_LIBS})

add_library(v5litecgo SHARED v5lite-cgo.cpp v5lite-s.cpp)
target_link_libraries(v5litecgo ncnn ${OpenCV_LIBS})
#target_link_libraries(ncnnv5lite ${libncnn.a} ${OpenCV_LIBS})