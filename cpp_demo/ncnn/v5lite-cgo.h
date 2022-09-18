typedef unsigned char byte;
struct cnnex;
cnnex* newCnnex();
int runDetect(cnnex& ex, byte *bytes, int width, int height);