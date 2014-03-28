#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxQtVideoSaver.h"
#include "ofCell.h"
#include "cellMovie.h"

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
// video saver-----------------------
	int 				camWidth;
	int 				camHeight;
	ofxQtVideoSaver		saver;

// mosaic----------------------------
	float cellNumber;
	float cellWidth;
	float cellHeight;
	int cellnum;
	ofPoint fracmat[3600];
	int cellPointx;
	int cellPointy;
	
	ofCell cells[3600];
	cellMovie cellmovie;
	ofVideoPlayer	backgroundMovie;
	ofImage			capture;
	bool save;
	bool fractal;
	bool extend;
	bool mono;
};

#endif