typedef unsigned char byte;
typedef struct cnnex cnnex;
int test();
cnnex* newCnnex();
int runDetect(cnnex *ex, byte *bytes, int width, int height);