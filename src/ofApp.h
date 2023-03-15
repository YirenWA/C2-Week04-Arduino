#pragma once

#include "ofMain.h"
#define AMOUNT 13

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		int nBytesRead = 0;
		ofSerial serial;
		char bytesReadString1[2];
		char bytesReadString2[10];

		ofTrueTypeFont font;
		string sensorValue;
		int byteData;
		int byteData1;
		string msg;
		char sendData = 1;

		bool byteDataReceived = false;
		bool Screen = false;
		bool Screen1 = false;

		vector<float> speedx;//ÃûÎªspeedxµÄ
		vector<float> speedy;

		
};
