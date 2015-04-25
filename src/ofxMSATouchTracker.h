/*
 *  TouchInfo.h
 *  MSA Labs Vol. 1
 *
 *  Created by Mehmet Akten on 03/08/2009.
 *  Copyright 2009 MSA Visuals Ltd.. All rights reserved.
 *
 */

#pragma once

//#include "ofxiPhone.h"
#include "ofMain.h"
#include "ofxMultiTouch.h"

class TouchInfo {
public:
	ofPoint normPos;
	ofPoint normOldPos;
	ofPoint normVel;
	
	ofPoint pos;
	ofPoint oldPos;
	ofPoint vel;
	
	bool isDown;
};


class ofxMSATouchTracker : public ofxMultiTouchListener {
public:	
	vector<TouchInfo*> activeTouches;
	TouchInfo touches[5];
	
	ofxMSATouchTracker();
	void setup();
	void update();
	
	void touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	void touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	void touchUp(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	void touchDoubleTap(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL) {}
};

extern ofxMSATouchTracker touchTracker;