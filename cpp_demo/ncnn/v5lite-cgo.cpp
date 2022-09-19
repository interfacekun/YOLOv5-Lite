
#include "v5lite-s.h"

extern "C" {
   #include "v5lite-cgo.h"
}

int test() {
    printf("hello v5lite-cgo");
    return 0;
}
typedef struct cnnex {
    ncnn::Extractor *ex;
    uint8_t data;
} cnnex;

cnnex* newCnnex() {
    cnnex *c = (cnnex*)malloc(sizeof(cnnex)); //创建一个结构体含有N个数据
    c->ex = initYolov5();
    c->data = 8;
    return c;
}

int runDetect(cnnex *c, byte *bytes, int width, int height) {
    printf(
        "runDetect c->ex:%p c->data:%d bytes:%s width:%d height:%d", 
        c->ex, c->data, ((char *)bytes), width, height
    );
    // return detectByYolov5(*(c->ex), bytes, width, height);
    c->ex->set_num_threads(2);
    return 0;
}