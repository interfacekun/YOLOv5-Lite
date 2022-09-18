
#include "v5lite-cgo.h"

extern "C" {
    #include "v5lite-s.h"
}

struct CNNEx_T: ncnn::Extractor {
    CNNEx_T(): ncnn::Extractor {}
    ~CNNEx_T() {}
}

CNNEx_T newCNNEx_T() {
    auto p = initYolov5();
    return p;
}

int runDetect(CNNEx_T& ex, byte *bytes, int width, int height) {
    return detectByYolov5(ex, bytes, width, height);
}