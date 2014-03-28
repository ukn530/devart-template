#include "cellMovie.h"

void cellMovie::setup(){
	width = 64;
	height = 36;
	
	for(int i = 0; i < 100; i++){
		cellMovie[i].loadMovie("movie/body36.mov");
		cellMovie[i].setPosition(i*0.01);
		cellMovie[i].play();
		cellMovie[i].setPaused(true);
		tex[i].allocate(width, height,GL_RGB);
		pixelss = new unsigned char[width * height * 3];	
	}
}

void cellMovie::update(){
	for (int i=0; i < 100; i++) {
		cellMovie[i].idleMovie();
		unsigned char * pixels = cellMovie[i].getPixels();
		
		for (int k = 0; k < width; k += width/64) {
			for (int j = 0; j < height; j += height/36) {
				int r = pixels[(j * width + k)*3];
				int g = pixels[(j * width + k)*3+1];
				int b = pixels[(j * width + k)*3+2];
				
				ar += r;
				ag += g;
				ab += b;
			}
		}
		
		rcell[i] = ar/2304;
		gcell[i] = ag/2304;
		bcell[i] = ab/2304;
		
		ar = 0;
		ag = 0;
		ab = 0;
		
		
		if (cellMovie[i].bLoaded){
			memcpy(pixelss, pixels, width * height * 3);
			tex[i].loadData(pixelss, width, height, GL_RGB);
		}
		cellMovie[i].nextFrame();
	}
}