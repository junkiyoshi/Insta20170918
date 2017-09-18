#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");
		
	this->icoSphere.setRadius(300);
	this->icoSphere.setResolution(4);

	ofSetColor(ofColor(255));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	//ofRotateY(ofGetFrameNum() % 360);

	vector<ofMeshFace> triangles = icoSphere.getMesh().getUniqueFaces();

	for (int i = 0; i < triangles.size(); i++) {

		ofVec3f avg = (triangles[i].getVertex(0) + triangles[i].getVertex(1) + triangles[i].getVertex(2)) / 3;
		float noise_value = ofNoise(avg.x * 0.0025, avg.y * 0.0025, avg.z * 0.0025, ofGetFrameNum() * 0.025);

		ofMesh mesh;

		ofVec3f point1 = triangles[i].getVertex(0) - avg;
		ofVec3f point2 = triangles[i].getVertex(1) - avg;
		ofVec3f point3 = triangles[i].getVertex(2) - avg;

		ofPushMatrix();
		ofTranslate(avg);

		if (noise_value < 0.10) {
			point1 *= avg * ofNoise(avg.x * 0.015, avg.y * 0.015, avg.z * 0.015, ofGetFrameNum() * 0.025);
			point2 *= avg * ofNoise(avg.x * 0.015, avg.y * 0.015, avg.z * 0.015, ofGetFrameNum() * 0.025);
			point3 *= avg * ofNoise(avg.x * 0.015, avg.y * 0.015, avg.z * 0.015, ofGetFrameNum() * 0.025);

		}
		else {

		}

		mesh.addVertex(point1);
		mesh.addVertex(point2);
		mesh.addVertex(point3);

		mesh.drawWireframe();

		ofPopMatrix();
	}

	cam.end();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
