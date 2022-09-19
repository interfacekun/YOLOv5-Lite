typedef unsigned char byte;
typedef struct cnnex cnnex;
int test();
cnnex* newCnnex();
int runDetect(cnnex *c, byte *bytes, int width, int height);