/*
 *  TouchInfo.cpp
 *  MSA Labs Collection
 *
 *  Created by Mehmet Akten on 24/10/2009.
 *  Copyright 2009 MSA Visuals Ltd.. All rights reserved.
 *
 */

#include "ofxMSATouchTracker.h"

ofxMSATouchTracker touchTracker;

ofxMSATouchTracker::ofxMSATouchTracker() {
	bzero(touches, sizeof(touches));
}

void ofxMSATouchTracker::setup() {
	ofxMultiTouch.addListener(&touchTracker);
}

void ofxMSATouchTracker::update() {
	activeTouches.clear();
	for(int i=0; i<5; i++) {
		TouchInfo &touch = touches[i];
		touch.normOldPos = touch.normPos;
		touch.oldPos = touch.pos;
		if(touch.isDown) activeTouches.push_back(&touch);
	}	
}



void ofxMSATouchTracker::touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data) {
	TouchInfo &touch = touches[touchId];
	touch.pos.set(x, y);
	touch.normPos.set(x / ofGetWidth(), y / ofGetHeight());
	
	touch.oldPos = touch.pos;
	touch.normOldPos = touch.normPos;
	
	touch.vel.set(0, 0, 0);
	touch.normVel.set(0, 0, 0);
	
	touch.isDown = true;	
	
	update();
}

void ofxMSATouchTracker::touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data) {
	TouchInfo &touch = touches[touchId];
	touch.pos.set(x, y);
	touch.normPos.set(x / ofGetWidth(), y / ofGetHeight());
	
	touch.vel = touch.pos - touch.oldPos;
	touch.normVel = touch.normPos - touch.normOldPos;
	touch.vel.z = touch.normVel.z = 1;
	
	touch.isDown = true;	
}

void ofxMSATouchTracker::touchUp(float x, float y, int touchId, ofxMultiTouchCustomData *data) {
	TouchInfo &touch = touches[touchId];
	touch.pos.set(x, y);
	touch.normPos.set(x / ofGetWidth(), y / ofGetHeight());
	
	touch.oldPos = touch.pos;
	touch.normOldPos = touch.normPos;
	
	touch.vel = touch.pos - touch.oldPos;
	touch.normVel = touch.normPos - touch.normOldPos;
	touch.vel.z = touch.normVel.z = 0;
	
	touch.isDown = false;	
	
	update();
}
