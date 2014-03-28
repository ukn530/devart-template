# Mosaic


## Authors
Tatsuya Uchida

## Description
Mosaic is a movie made up of movies. It is like a trick of [photographic mosaic](http://en.wikipedia.org/wiki/Photographic_mosaic "photographic mosaic"). In this case, the medium is not a photo, but a movie.
I shot actors from above or below because I didn't want to make "up and down" in this screen to express a fractal world. Actors use some clothes to contrast image of cells in this movie. 


## Link to Prototype
I made another version before this work.
[Cell](http://ukn.cc/portfolio/?p=12 "cell")

## Sample code
```
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
```

## Links to External Libraries
[openFrameworks](http://www.openframeworks.cc "openFrameworks")


## Images & Videos
https://www.youtube.com/watch?v=Xo587Gm-Wzo
