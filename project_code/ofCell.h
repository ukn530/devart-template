#ifndef _OF_CELL
#define _OF_CELL

#include "ofMain.h"
#include "cellMovie.h"

class ofCell {
private:
	ofPoint cellPos;
	float cellHeight;
	int cellMovieNum;
	ofPoint speed;
	float phase;
	float phaseSpeed;
	float movedHeight;
	
	float mag;
public:
	ofCell();
	void randomMove();
	void fractal();
	void extend();

	void setHeight(float cellHeight);
	float getHeight();
	void setPos(ofPoint cellPos);
	ofPoint getPos();
	void setCmn(int cellMovieNum);
	int getCmn();
	void setSpeed(ofPoint speed);
	ofPoint getSpeed();
	void setMag(float mag);
	float getMag();
};
#endif