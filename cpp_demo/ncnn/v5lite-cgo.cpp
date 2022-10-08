
#include "v5lite-s.h"
#include <iostream>
using namespace std;
extern "C"
{
#include "v5lite-cgo.h"
}

int test()
{
    printf("hello v5lite-cgo");
    return 0;
}
typedef struct cnnex
{
    ncnn::Net* yolov5;
    uint8_t data;
} cnnex;

cnnex *newCnnex()
{
    cnnex *c = (cnnex *)malloc(sizeof(cnnex)); //创建一个结构体含有N个数据
    c->yolov5 = initYolov5();
    c->data = 8;
    return c;
}

int runDetect(cnnex *c, unsigned char *bytes, int width, int height)
{
    printf(
        "runDetect c->ex:%p c->data:%d bytes:%s width:%d height:%d\n",
        c->yolov5, c->data, ((char *)bytes), width, height);
    try
    {
      
        detectByYolov5(*(c->yolov5), bytes, width, height);
        // testBytes(bytes, width, height);
        // throw exception();
        // c->ex->set_num_threads(2);
        return 0;
    }
    // catch (std::exception &e)
    // {
    //     std::cout << "runDetect caught" << std::endl;
    //     std::cout << e.what() << std::endl;
    //     return -1;
    // }
     catch (...)
    {
        std::cout << "runDetect caught" << std::endl;
        return -1;
    }
}