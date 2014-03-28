#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	save = true; //save?, true or false
	fractal = false;
	extend = false;
	mono = false;
	
	ofSetFrameRate(30);
	if (save) {
		saver.setCodecQualityLevel(OF_QT_SAVER_CODEC_QUALITY_HIGH);
		saver.setup(ofGetWidth(), ofGetHeight(), "mosaic5959_19.mov");
	}	
	backgroundMovie.loadMovie("movie/three720.mov");
//	backgroundMovie.setFrame(450);
//	backgroundMovie.setFrame(9720);
//	backgroundMovie.setFrame(13930);
//	backgroundMovie.setFrame(660);
//	backgroundMovie.setFrame(570);
	backgroundMovie.setFrame(300);

	backgroundMovie.play();
	backgroundMovie.setPaused(true);
		
	cellNumber = 59;//number of row & line
	
	cellWidth = ofGetWidth()/cellNumber;
	cellHeight = ofGetHeight()/cellNumber;
	cout << cellWidth << endl;
	
	cellnum = 0;
	if(fractal){
		for (float j=-ofGetHeight()/2; j<ofGetHeight()/2; j += cellHeight){
			for (float i=-ofGetWidth()/2; i<ofGetWidth()/2; i += cellWidth) {
				cells[cellnum].setPos(ofPoint(i*cellNumber, j*cellNumber));
				cells[cellnum].setHeight(cellHeight*cellNumber);
				cells[cellnum].setSpeed(ofPoint(ofRandom(-5, 5), ofRandom(-5, 5)));
				fracmat[cellnum] = ofPoint(i,j);
				cellnum++;
			}
		}
	} else {
		for (float j=-ofGetHeight()/2; j<ofGetHeight()/2; j += cellHeight){
			for (float i=-ofGetWidth()/2; i<ofGetWidth()/2; i += cellWidth) {
				cells[cellnum].setPos(ofPoint(i, j));
				cells[cellnum].setHeight(cellHeight);
				cells[cellnum].setSpeed(ofPoint(ofRandom(-5, 5), ofRandom(-5, 5)));
				fracmat[cellnum] = ofPoint(i,j);
				cellnum++;
			}
		}
	}
	
	cellmovie.setup();
}

//--------------------------------------------------------------
void testApp::update(){
	
	backgroundMovie.idleMovie();
	cellmovie.update();
	
	unsigned char * pixels = backgroundMovie.getPixels();
	
	for (int i=0; i < cellnum; i++) {
		if (fractal) {
			cells[i].fractal();
			cellPointx = fracmat[i].x + ofGetWidth()/2;
			cellPointy = fracmat[i].y + ofGetHeight()/2;
			cellWidth = cells[i].getHeight()*16/9;
			cellHeight = cells[i].getHeight();
		} else if (extend) {
			cells[i].extend();
			cellPointx = fracmat[i].x + ofGetWidth()/2;
			cellPointy = fracmat[i].y + ofGetHeight()/2;
			cellHeight = cells[i].getHeight();
		} else{
			cellPointx = cells[i].getPos().x + ofGetWidth()/2;
			cellPointy = cells[i].getPos().y + ofGetHeight()/2;
			cellWidth = cells[i].getHeight()*16/9;
			cellHeight = cells[i].getHeight();
		}
		
//		cells[i].randomMove();
		
		
		int r = pixels[(cellPointy * ofGetWidth() + cellPointx) * 3];
		int g = pixels[(cellPointy * ofGetWidth() + cellPointx) * 3+1];
		int b = pixels[(cellPointy * ofGetWidth() + cellPointx) * 3+2];
		
		int sub[100];
		int useful = 768;
		for (int k = 0; k < 100; k++) {
			if(mono){
				sub[k] = abs(r + g + b - cellmovie.rcell[k] - cellmovie.gcell[k] - cellmovie.bcell[k]);
			} else {
				sub[k] = abs(r - cellmovie.rcell[k]) + abs(g - cellmovie.gcell[k]) + abs(b - cellmovie.bcell[k]);
			}

			if(useful >= sub[k]){
				useful = sub[k];
				cells[i].setCmn(k);
			}
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for (int i=0; i < cellnum; i++) {
		cellmovie.tex[cells[i].getCmn()].draw(cells[i].getPos().x + ofGetWidth()/2, cells[i].getPos().y + ofGetHeight()/2, cellWidth, cellHeight);
	}
	
	if (save) {
		capture.grabScreen(0,0,ofGetWidth(),ofGetHeight());
		saver.addFrame(capture.getPixels(), 1.0f / 30.0f); 
	}
	
	backgroundMovie.nextFrame();
	float magg;
	magg = cells[0].getMag();

	cout << ofGetFrameNum() << endl;
	cout << magg << endl;
	cout << cells[0].getHeight() << endl;

 }

//--------------------------------------------------------------
void testApp::exit(){
	saver.finishMovie();
}
