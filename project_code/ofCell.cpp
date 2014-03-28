#include "ofCell.h"

ofCell::ofCell(){
	cellPos = ofPoint(0, 0);
	cellHeight = 0;
	cellMovieNum = 0;
	speed = ofPoint(0,0);
	phaseSpeed = ofRandom(0.1, 0.5);
	phase = 0;
	mag =1;
}

void ofCell::randomMove(){
	cellHeight = cellHeight + sin(phase)*4;
    phase += phaseSpeed;
    if(phase > TWO_PI){
        phase -= TWO_PI;
    }
	cellPos += speed;
	if(cellPos.x < cellHeight*8/9 || cellPos.x > ofGetWidth()-cellHeight*8/9){
        speed.x *= -1;
    }
    if(cellPos.y < cellHeight/2 || cellPos.y > ofGetHeight()-cellHeight/2){
        speed.y *= -1;
    }
}

void ofCell::fractal(){
//	mag = 1 - ofGetFrameNum()*0.0001;
	mag = 0.9012 - ofGetFrameNum()*0.01;
	
	cellHeight = cellHeight * mag;
	
	cellPos.x = cellPos.x * mag;
	cellPos.y = cellPos.y * mag;
	
} 

void ofCell::extend(){
	float mag = 1.02;
	cellHeight = cellHeight * mag;
	
	cellPos.y = cellPos.y * mag;
} 

void ofCell::setPos(ofPoint _pos)
{
	cellPos = _pos;
}
ofPoint ofCell::getPos()
{
	return cellPos;
}

void ofCell::setHeight(float _height)
{
	cellHeight = _height;
}
float ofCell::getHeight()
{
	return cellHeight;
}

void ofCell::setCmn(int _cellMovieNum)
{
	cellMovieNum = _cellMovieNum;
}
int ofCell::getCmn()
{
	return cellMovieNum;
}

void ofCell::setSpeed(ofPoint _speed)
{
	speed = _speed;
}
ofPoint ofCell::getSpeed()
{
	return speed;
}

float ofCell::getMag()
{
	return mag;
}