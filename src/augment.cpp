#include "augment.h"

void augment::setup(){
	// Set up OF
	ofSetWindowTitle("Augment");
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(60);	
	ofBackground(0, 0, 0);

	// Set up serial, replace with device name / baud to suit your config
	serial.enumerateDevices();
	serial.setup("/dev/tty.usbserial-A900aeQz", 115200);		
	
	charIndex = 0;
	charsToSend = "LOGA";
	
	// Load the movies
	movieIndex = 0;	
	
	uclaVideos = new ofVideoPlayer[2];
	uclaVideos[0].loadMovie("ucla1_small.mov");
	uclaVideos[1].loadMovie("ucla2_new.mov");
	
	augmentVideos = new ofVideoPlayer[2];
	augmentVideos[0].loadMovie("over_the_shoulder_computer_1_new.mov");
	augmentVideos[1].loadMovie("over_the_shoulder_computer_2_new.mov");	
	
	// Start the movies
	uclaVideos[movieIndex].play();
	augmentVideos[movieIndex].play();
	

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
	// TODO send serial message?
	
	// Bumb the character index
	charIndex++;
	
	if (charIndex >= 4) {
		charIndex = 0;
	}
	
	// Stop current movies
	uclaVideos[movieIndex].stop();
	augmentVideos[movieIndex].stop();
	
	// Bump movie index
	movieIndex++;
	
	if (movieIndex >= 2) {
		movieIndex = 0;
	}
	
	// Play the new ones
	uclaVideos[movieIndex].play();
	augmentVideos[movieIndex].play();
	
	ofLog(OF_LOG_NOTICE, "Changed to movie %i and sending char %c", movieIndex, charsToSend[charIndex]);	
}


void augment::keyPressed  (int key){
	if (key == 'c') {
		changeMovie();
	}
	else if (key == 'f') {
		ofToggleFullscreen();
	}
  else if (key == 'l') {
   serial.writeByte('L');
	}
	else if (key == 'o') {
   serial.writeByte('O');
	}
	else if (key == 'g') {
   serial.writeByte('G');
	}
	else if (key == 'a') {
		serial.writeByte('A');
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
