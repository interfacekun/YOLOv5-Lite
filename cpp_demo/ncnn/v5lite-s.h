#include "layer.h"
#include "net.h"

#if defined(USE_NCNN_SIMPLEOCV)
#include "simpleocv.h"
#else
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#endif
#include <float.h>
#include <stdio.h>
#include <vector>
#include <sys/time.h>
// 0 : FP16
// 1 : INT8

// #define USE_INT8 0
// #define USE_VULKAN_COMPUTE 1

// 0 : Image
// 1 : Camera
#define USE_CAMERA 0
typedef unsigned char byte;

ncnn::Extractor* initYolov5();
int detectByYolov5(ncnn::Extractor& ex, byte *bytes, int width, int height);
