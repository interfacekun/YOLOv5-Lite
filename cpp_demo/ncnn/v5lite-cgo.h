// typedef unsigned char byte;
typedef struct cnnex cnnex;
int test();
cnnex* newCnnex();
int runDetect(cnnex *c, unsigned char *bytes, int width, int height, int size_of_buffer);