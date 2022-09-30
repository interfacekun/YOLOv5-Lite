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
    set(CMAKE_INSTALL_PREFIX /Volumes/outDisk/git/IoT/go/vision)
    # add_definitions(-DUSE_VULKAN_COMPUTE)
    # set(NCNN_PATH ${NCNN_PROJ}/build/install/lib/cmake/ncnn)
    set(YOLO_PROJ /Volumes/outDisk/git/IoT/YOLOv5-Lite/cpp_demo/ncnn)
    set(NCNN_PATH ${NCNN_PROJ}/build-aarch64/install/lib/cmake/ncnn)
    # 指定include 和动态库路径
    # include_directories(${YOLO_PROJ}/include)
    # link_directories(${YOLO_PROJ}/lib)
    set(OCV_PATH ${YOLO_PROJ}/opencv-4.5.4/aarch64-install)
elseif(${HOST} STREQUAL "xmk")
    set(NCNN_PROJ /Users/xmk/git/IoT/ncnn)
    set(CMAKE_INSTALL_PREFIX /Users/xmk/git/IoT/go/vision)
    add_definitions(-DUSE_VULKAN_COMPUTE)
    set(NCNN_PATH ${NCNN_PROJ}/build/install/lib/cmake/ncnn)
else()
    set(NCNN_PROJ /root/git/IoT/ncnn)
    set(CMAKE_INSTALL_PREFIX /root/git/IoT/go/vision)
    set(NCNN_PATH ${NCNN_PROJ}/build/install/lib/cmake/ncnn)
endif()


find_package(ncnn REQUIRED 
            PATHS ${NCNN_PATH}
            NO_DEFAULT_PATH)
find_package(OpenCV REQUIRED 
            PATHS ${OCV_PATH}
            NO_DEFAULT_PATH)
# find_package(OpenCV REQUIRED)

message("OpenCV" ${OpenCV_LIBS})

add_executable(ncnnv5lite v5lite-s.cpp)
target_link_libraries(ncnnv5lite ncnn ${OpenCV_LIBS})


add_library(v5lite SHARED v5lite-s.cpp)
target_link_libraries(v5lite ncnn ${OpenCV_LIBS})

# add_executable(ncnnv5litecgo v5lite-cgo.cpp)
# target_link_libraries(ncnnv5litecgo ncnn ${OpenCV_LIBS})

add_library(v5litecgo SHARED v5lite-cgo.cpp v5lite-s.cpp)
target_link_libraries(v5litecgo ncnn ${OpenCV_LIBS})


# target_link_libraries(ncnnv5lite ${libncnn.a} ${OpenCV_LIBS})
# install(TARGETS v5litecgo
#         LIBRARY DESTINATION lib/${HOST}
# )
set(INSTALL_HEAD_FILES v5lite-cgo.h)
# install(FILES ${INSTALL_HEAD_FILES} DESTINATION  ${CMAKE_INSTALL_PREFIX}/src)
