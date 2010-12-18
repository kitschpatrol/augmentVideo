#include "augment.h"

void augment::setup(){
	ofSetWindowTitle("Augment");
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(60);	
	ofBackground(0, 0, 0);
	
	movieIndex = 0;

	// Load the movies
	uclaVideos = new ofVideoPlayer[2];
	uclaVideos[0].loadMovie("ucla1_small.mov");
	uclaVideos[1].loadMovie("ucla2_new.mov");
	
	augmentVideos = new ofVideoPlayer[2];
	augmentVideos[0].loadMovie("over_the_shoulder_computer_1_new.mov");
	augmentVideos[1].loadMovie("over_the_shoulder_computer_2_new.mov");	
	
	// Start the movies
	uclaVideos[movieIndex].play();
	augmentVideos[movieIndex].play();
	
	// TODO set up serial
}


void augment::update(){
	// "This function idles the movie player, so that the movie can play.
	//  If you don't call it, when the movie is playing then you may encouter
	//  problems, especially on winodws machines." -- OF Docs...
	uclaVideos[movieIndex].idleMovie();
	augmentVideos[movieIndex].idleMovie();	
}


void augment::draw(){
	uclaVideos[movieIndex].draw(1200, 0, 320, 263);
	augmentVideos[movieIndex].draw(0, 500, 320, 263);	
}

void augment::changeMovie() {
	// TODO send serial message
	
	// Stop current movies
	uclaVideos[movieIndex].stop();
	augmentVideos[movieIndex].stop();
	
	// Bump movie index
	movieIndex++;
	
	if(movieIndex >= 2) {
		movieIndex = 0;
	}
	
	// Play the new ones
	uclaVideos[movieIndex].play();
	augmentVideos[movieIndex].play();
	
	ofLog(OF_LOG_NOTICE, "Changed to movie %i", movieIndex);	
}


void augment::keyPressed  (int key){
	if (key == 'c') {
		changeMovie();
	}
}


void augment::keyReleased(int key){

}


void augment::mouseMoved(int x, int y ){

}


void augment::mouseDragged(int x, int y, int button){

}


void augment::mousePressed(int x, int y, int button){

}



void augment::mouseReleased(int x, int y, int button){

}


void augment::resized(int w, int h){

}
