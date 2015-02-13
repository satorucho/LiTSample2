#include "ofApp.h"
#define GRID_INTERVAL 30

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
    double distX = mouseX - ofGetWidth()/2;
    double distY = mouseY - ofGetHeight()/2;
    radius = hypot(distX, distY);
    
    ofVec3f vec1(distX, distY);
    ofVec3f vec2(1, 0);
    degree = (distY < 0)? vec1.angle(vec2): 360-vec1.angle(vec2);
    /*  This Means
        if (distY < 0) degree = vec1.angle(vec2);
        else degree = 360-vec1.angle(vec2);  */
    
    circle_color = ofColor::fromHsb(degree*255/360, 255, 255);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(circle_color);
    ofSetLineWidth(1.0);
    
    drawGrid(GRID_INTERVAL);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
    
    ofSetColor(255);
    ofLine(mouseX, 0, mouseX, ofGetHeight());
    ofLine(0, mouseY, ofGetWidth(), mouseY);
    ofSetLineWidth(2.0);
    ofLine(ofGetWidth()/2, ofGetHeight()/2, mouseX, mouseY);
    
    ofDrawBitmapString(ofToString(degree), mouseX+10, mouseY-10);
}

void ofApp::drawGrid(int interval){
    int x_position = 0, y_position = 0;
    while (x_position <= ofGetWidth()) {
        ofLine(x_position, 0, x_position, ofGetHeight());
        x_position += interval;
    }
    while (y_position <= ofGetHeight()) {
        ofLine(0, y_position, ofGetWidth(), y_position);
        y_position += interval;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
