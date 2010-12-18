#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

class augment : public ofBaseApp{

	public:

		// OF Stuff
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void resized(int w, int h);

		// Movie Stuff
		void changeMovie();	
		int movieIndex;
		ofVideoPlayer * uclaVideos;
		ofVideoPlayer * augmentVideos;	
	
		// Serial stuff
		ofSerial serial;
		int charIndex;
		char * charsToSend;
};

#endif
