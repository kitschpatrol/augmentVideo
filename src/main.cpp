#include "ofMain.h"
#include "augment.h"
#include "ofAppGlutWindow.h"

int main( ){
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 2040, 800, OF_WINDOW); // or OF_FULLSCREEN
	ofRunApp( new augment());
}
