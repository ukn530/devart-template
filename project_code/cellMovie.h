#ifndef _CELL_MOVIE
#define _CELL_MOVIE

#include "ofMain.h"
class cellMovie {
private:
	char fileName[30];
	ofVideoPlayer cellMovie[100];
	unsigned char* pixelss;
	int ar;
	int ag;
	int ab;	
public:
	void setup();
	void draw();
	void update();
	ofTexture	tex[100];
	int rcell[100];
	int gcell[100];
	int bcell[100];
	int width;
	int height;
	
};
#endif