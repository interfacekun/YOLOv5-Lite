typedef unsigned char byte;
typedef struct CNNEx_T CNNEx_T;
CNNEx_T newCNNEx_T();
int runDetect(CNNEx_T& ex, byte *bytes, int width, int height);