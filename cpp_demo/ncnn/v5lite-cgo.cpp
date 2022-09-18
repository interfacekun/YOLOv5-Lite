
#include "v5lite-s.h"

extern "C" {
   #include "v5lite-cgo.h"
}

int test() {
    printf("hello v5lite-cgo");
}
struct cnnex: ncnn::Extractor {
};

cnnex* newCnnex() {
    cnnex* n = (cnnex*)initYolov5();
    return n;
}

int runDetect(cnnex *ex, byte *bytes, int width, int height) {
    return detectByYolov5(*ex, bytes, width, height);
}