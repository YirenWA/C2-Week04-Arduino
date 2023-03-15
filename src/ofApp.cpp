#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   
    // 串行通信開始
    serial.setup("COM8 Arduino Uno", 9600);
   
    ofBackground(4,5,9);
    speedx.resize(AMOUNT);
    speedy.resize(AMOUNT);
    for (int i = 0; i < AMOUNT; i++) {
        speedx[i] = ofRandom(0.001, 0.4);
        speedy[i] = ofRandom(0.001, 0.2);
    }

    font.load("NewYork PERSONAL USE.otf", 15);//字体
}

//--------------------------------------------------------------
void ofApp::update(){
    // Check if there is any serial data available
    if (serial.available() > 0) {  
        byteData = serial.readByte();// Read the byte data from the serial connection

        cout << "Received byte data: " << byteData << endl;
    }
    else {
        byteData = 0;// Set the `byteData` to a default value (for example, 0)
    }

    // Check if the Button1 is pressed
    if (!Screen || byteData == 49 || byteData == 10 || byteData == 13) {
        // Set the `Screen` variable to `true`
        Screen = true;

        cout << "Button1 pressed, Screen set to true" << endl;
    }

    // Check if the Button2 is pressed
    if (!Screen || byteData1 == 50 || byteData1 == 10 || byteData1 == 13) {
        // Set the `Screen1` variable to `true`
        Screen = true;

        cout << "Button2 pressed, Screen set to true" << endl;
    }

    // Check if the `byteData` is equal to 10,13,49
    if (byteData == 49|| byteData == 10|| byteData == 13) {
        // Set the `Screen` variable to `false`
        Screen = false;
 
        cout << "byteData is 10,13,49, Screen set to false" << endl;
    } 

    // Check if the `byteData` is equal to 10,13,50
    if (byteData1 == 50 || byteData1 == 10 || byteData1 == 13) {
        // Set the `Screen1` variable to `false`
        Screen1 = false;

        cout << "byteData is 10,13,50, Screen1 set to false" << endl;
    }
}
//--------------------------------------------------------------
void ofApp::draw() {
    float time = ofGetElapsedTimef();
    for (int i = 0; i < AMOUNT; i++) {

        //文本
        msg = "Planting Flowers\n";
        ofSetColor(90, 130, 40, 255);
        font.drawString(msg, ofGetWidth() / 2 - font.stringWidth(msg) / 2, ofGetHeight() - 15);
        //----------------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------------

        ofSetLineWidth(1.2);
        //草1
        float x = ofGetWidth() * ofNoise(time * speedx[i] / 1);
        float y = ofGetHeight() * ofNoise(time * speedy[i] / 2);
        ofSetColor(ofRandom(160, 190), ofRandom(200, 240), 140, ofRandom(25, 90));
        ofDrawLine(x + 110, ofRandom(135, 150), 310, y + 190);

        //草2
        float x11 = ofGetWidth() * ofNoise(time * speedx[i] / 1.5);
        float y11 = ofGetHeight() * ofNoise(time * speedy[i] / 2);
        ofSetColor(ofRandom(190, 200), ofRandom(200, 240), 140, ofRandom(20, 100));
        ofDrawLine(x11 + 40, ofRandom(80, 105), 250, y11 + 150);

        //草3,最后的
        float x12 = ofGetWidth() * ofNoise(time * speedx[i] / 1);
        float y12 = ofGetHeight() * ofNoise(time * speedy[i] / 2.0);
        ofSetColor(ofRandom(190, 200), ofRandom(200, 240), 130, ofRandom(20, 50));
        ofDrawLine(x12 - 50, ofRandom(285, 290), 150, y12 + 90);

        //草4，最前面的
        float x13 = ofGetWidth() * ofNoise(time * speedx[i] / 1);
        float y13 = ofGetHeight() * ofNoise(time * speedy[i] / 2);
        ofSetColor(ofRandom(140, 170), ofRandom(200, 220), 110, ofRandom(20, 160));
        ofDrawLine(x13 - 150, ofRandom(360, 375), 60, y13 + 210);

        //草5
        float x14 = ofGetWidth() * ofNoise(time * speedx[i] / 1);
        float y14 = ofGetHeight() * ofNoise(time * speedy[i] / 2);
        ofSetColor(ofRandom(140, 170), ofRandom(200, 240), 110, ofRandom(20, 100));
        ofDrawLine(x14 - 105, ofRandom(250, 260), 90, y13 + 125);

        //草6
        float x15 = ofGetWidth() * ofNoise(time * speedx[i] / 2);
        float y15 = ofGetHeight() * ofNoise(time * speedy[i] / 2);
        ofSetColor(ofRandom(150, 175), ofRandom(200, 240), 100, ofRandom(10, 80));
        ofDrawLine(x15 - 130, ofRandom(40, 46), 60, y15 + 110);

        //yinghuochong
        float x7 = ofGetWidth() * ofNoise(time * speedx[i] * 2.5);
        float y7 = ofGetHeight() * ofNoise(time * speedy[i] * 1.2);
        ofSetColor(165, 180, ofRandom(70, 105), ofRandom(20, 250));
        ofDrawCircle(x7 + 80, y7 - 360, 3);
        ofDrawCircle(x7 - 160, y7 - 200, 3);
        ofDrawCircle(x7 + 150, y7 - 300, 3);

        //----------------------------------------------------------------------------------------
        // 红色花
        //----------------------------------------------------------------------------------------
        if (!Screen || byteData == 49 || byteData == 10 || byteData == 13) {

            Screen = true;

            //flower1
            float x2 = ofGetWidth() * ofNoise(time * speedx[i] * 1.2);
            float y2 = ofGetHeight() * ofNoise(time * speedy[i] * 0.3);
            ofSetColor(155, 20, ofRandom(20, 45), ofRandom(90, 220));
            ofDrawCircle(x2 + 30, y2 - 260, 8.5);

            //flower2
            float x3 = ofGetWidth() * ofNoise(time * speedx[i] * 1.1);
            float y3 = ofGetHeight() * ofNoise(time * speedy[i] * 0.4);
            ofSetColor(155, 50, 35, ofRandom(70, 160));
            ofDrawCircle(x3 + 140, y3 - 200, 6);

            //flower3
            float x4 = ofGetWidth() * ofNoise(time * speedx[i] * 1.1);
            float y4 = ofGetHeight() * ofNoise(time * speedy[i] * 0.6);
            ofSetColor(ofRandom(120, 155), 50, 20, ofRandom(150, 240));
            ofDrawCircle(x4 - 120, y4 - 90, 6);

            //flower4
            float x5 = ofGetWidth() * ofNoise(time * speedx[i] * 1.0);
            float y5 = ofGetHeight() * ofNoise(time * speedy[i] * 0.2);
            ofSetColor(155, 50, ofRandom(40, 55), ofRandom(100, 150));
            ofDrawCircle(x5 - 150, y5 + 20, 5);

            //flower5
            float x6 = ofGetWidth() * ofNoise(time * speedx[i] * 1.1);
            float y6 = ofGetHeight() * ofNoise(time * speedy[i] * 0.3);
            ofSetColor(150, 50, ofRandom(60, 75), ofRandom(80, 110));
            ofDrawCircle(x6 - 50, y6 - 90, 3.8);

            //flower6
            float x7 = ofGetWidth() * ofNoise(time * speedx[i] * 1);
            float y7 = ofGetHeight() * ofNoise(time * speedy[i] / 6);
            ofSetColor(155, 50, ofRandom(40, 55), ofRandom(120, 150));
            ofDrawCircle(x7 - 140, y7 - 340, 6);

            //-----------------------------------------------------------------------------------
            //-----------------------------------------------------------------------------------
            //草1
            float x = ofGetWidth() * ofNoise(time * speedx[i] * 3);
            float y = ofGetHeight() * ofNoise(time * speedy[i] * 3);
            ofSetColor(ofRandom(160, 190), ofRandom(200, 240), 140, ofRandom(25, 120));
            ofDrawLine(x + 110, ofRandom(135, 150), 310, y + 190);

            //草2
            float x11 = ofGetWidth() * ofNoise(time * speedx[i] * 2);
            float y11 = ofGetHeight() * ofNoise(time * speedy[i] * 1);
            ofSetColor(ofRandom(190, 200), ofRandom(200, 240), 140, ofRandom(20, 180));
            ofDrawLine(x11 + 40, ofRandom(80, 105), 250, y11 + 150);

            //草3
            float x12 = ofGetWidth() * ofNoise(time * speedx[i] * 3);
            float y12 = ofGetHeight() * ofNoise(time * speedy[i] * 3);
            ofSetColor(ofRandom(190, 200), ofRandom(200, 240), 130, ofRandom(20, 100));
            ofDrawLine(x12 - 50, 290, 150, y12 + 90);

            //草4
            float x13 = ofGetWidth() * ofNoise(time * speedx[i] * 3);
            float y13 = ofGetHeight() * ofNoise(time * speedy[i] * 3);
            ofSetColor(ofRandom(140, 170), ofRandom(200, 220), 110, ofRandom(20, 130));
            ofDrawLine(x13 - 150, ofRandom(360, 375), 60, y13 + 210);

            //草5
            float x14 = ofGetWidth() * ofNoise(time * speedx[i] * 2);
            float y14 = ofGetHeight() * ofNoise(time * speedy[i] * 1);
            ofSetColor(ofRandom(140, 170), ofRandom(200, 240), 110, ofRandom(20, 165));
            ofDrawLine(x14 - 105, ofRandom(250, 260), 90, y13 + 125);

            //草6
            float x15 = ofGetWidth() * ofNoise(time * speedx[i] * 3);
            float y15 = ofGetHeight() * ofNoise(time * speedy[i] * 3);
            ofSetColor(ofRandom(150, 175), ofRandom(200, 240), 100, ofRandom(10, 80));
            ofDrawLine(x15 - 130, ofRandom(40, 46), 60, y15 + 110);

            // msg = "turn the light off\n";
            // font.drawString(msg, 50, 60);
        }

        //----------------------------------------------------------------------------------------
        // 紫色花
        //----------------------------------------------------------------------------------------
        if (!Screen1 || byteData == 50 ) {

        Screen1 = true;

        //flower1
        float x2 = ofGetWidth() * ofNoise(time * speedx[i] * 1.2);
        float y2 = ofGetHeight() * ofNoise(time * speedy[i] * 0.3);
        ofSetColor(45, 120, ofRandom(140, 175),255);
        ofDrawCircle(x2 + 30, y2 - 260, 10.5);

        //flower2
        float x3 = ofGetWidth() * ofNoise(time * speedx[i] * 1.1);
        float y3 = ofGetHeight() * ofNoise(time * speedy[i] * 0.4);
        ofSetColor(25, 150, 195, ofRandom(70, 160));
        ofDrawCircle(x3 + 140, y3 - 200, 6.5);

        //flower3
        float x4 = ofGetWidth() * ofNoise(time * speedx[i] * 1.1);
        float y4 = ofGetHeight() * ofNoise(time * speedy[i] * 0.6);
        ofSetColor(ofRandom(120, 15), 150, 250, ofRandom(190, 240));
        ofDrawCircle(x4 - 120, y4 - 90, 6.5);

        //flower4
        float x5 = ofGetWidth() * ofNoise(time * speedx[i] * 1.0);
        float y5 = ofGetHeight() * ofNoise(time * speedy[i] * 0.2);
        ofSetColor(115, 200, ofRandom(240, 255), ofRandom(140, 190));
        ofDrawCircle(x5 - 150, y5 + 20, 7);

        //flower5
        float x6 = ofGetWidth() * ofNoise(time * speedx[i] * 1.1);
        float y6 = ofGetHeight() * ofNoise(time * speedy[i] * 0.3);
        ofSetColor(10, 150, ofRandom(60, 155), ofRandom(180, 210));
        ofDrawCircle(x6 - 50, y6 - 90, 3.8);

        //flower6
        float x7 = ofGetWidth() * ofNoise(time * speedx[i] * 1);
        float y7 = ofGetHeight() * ofNoise(time * speedy[i] / 6);
        ofSetColor(10, 150, ofRandom(80, 195), ofRandom(120, 220));
        ofDrawCircle(x7 - 140, y7 - 340, 7.5);

        //-----------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------
        //草1
        float x = ofGetWidth() * ofNoise(time * speedx[i] * 3);
        float y = ofGetHeight() * ofNoise(time * speedy[i] * 3);
        ofSetColor(255, ofRandom(100, 140), 90, ofRandom(25, 205));
        ofDrawLine(x + 110, ofRandom(135, 150), 310, y + 190);

        //草2
        float x11 = ofGetWidth() * ofNoise(time * speedx[i] * 2);
        float y11 = ofGetHeight() * ofNoise(time * speedy[i] * 1);
        ofSetColor(255, ofRandom(100, 140), 90, ofRandom(20, 205));
        ofDrawLine(x11 + 40, ofRandom(80, 105), 250, y11 + 150);

        //草3
        float x12 = ofGetWidth() * ofNoise(time * speedx[i] * 3);
        float y12 = ofGetHeight() * ofNoise(time * speedy[i] * 3);
        ofSetColor(255, ofRandom(100, 140),80, ofRandom(20, 195));
        ofDrawLine(x12 - 50, 290, 150, y12 + 90);

        //草4
        float x13 = ofGetWidth() * ofNoise(time * speedx[i] * 3);
        float y13 = ofGetHeight() * ofNoise(time * speedy[i] * 3);
        ofSetColor(255, ofRandom(100, 120), 70, ofRandom(20, 255));
        ofDrawLine(x13 - 150, ofRandom(360, 375), 60, y13 + 210);

        //草5
        float x14 = ofGetWidth() * ofNoise(time * speedx[i] * 2);
        float y14 = ofGetHeight() * ofNoise(time * speedy[i] * 1);
        ofSetColor(255, ofRandom(100, 140), 70, ofRandom(20, 205));
        ofDrawLine(x14 - 105, ofRandom(250, 260), 90, y13 + 125);

        //草6
        float x15 = ofGetWidth() * ofNoise(time * speedx[i] * 3);
        float y15 = ofGetHeight() * ofNoise(time * speedy[i] * 3);
        ofSetColor(255, ofRandom(100, 140), 90, ofRandom(10, 205));
        ofDrawLine(x15 - 130, ofRandom(40, 46), 60, y15 + 110);

        // msg = "turn the light off\n";
        // font.drawString(msg, 50, 60);
    }
    }
 }


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
   // serial.writeByte(sendData); // sending the data to arduino
    //    cout << "Mouse pressed, sending data: " << sendData << endl;
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

//-----------------------------

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
