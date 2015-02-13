#include "ofApp.h"
#define GRID_INTERVAL 30

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // まず、円の半径を求めるので、中心点とマウス座標の間の距離を求める。
    double distX = mouseX - ofGetWidth()/2;
    double distY = mouseY - ofGetHeight()/2;
    radius = hypot(distX, distY);
    
    // 三平方の定理で斜辺を求める関数hypot(x,y)で求めているが、
    // ofDist(x1, y1, x2, y2)でも2点間の距離が取れるので
    // radius = ofDist(ofGetWidth()/2, ofGetHeight()/2, mouseX, mouseY); でもOK。
    // ただ、どうせ後ろでdistX / distY を使うので、今回は使用しなかった。
    
    // マウスが中心点に対して何度のところにあるかを求める。
    ofVec3f vec1(distX, distY);
    ofVec3f vec2(1, 0);
    
    degree = (distY < 0)? vec1.angle(vec2): 360-vec1.angle(vec2);
    /*  This Means
        if (distY < 0) degree = vec1.angle(vec2);
        else degree = 360-vec1.angle(vec2);  */
    
    //　上は、「三項演算子」と呼ばれ、数値代入においてifを使いたい場合に?と:で表記を簡略化できるもの。
    // 使いすぎると読みづらくなるので用法用量には気をつけて。
    
    circle_color = ofColor::fromHsb(degree*255/360, 255, 255);
    // degreeは0から360だが、HSBは0から255で指定する必要があるため、変換している。
    // なお、このような"線形写像"にはofMapという便利な関数があるので調べてみると良い。
    // 今回はどちらの0からなので簡単だが、例えば100〜600の値を341から1862の間に変換する場合は、ofMapが楽。
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(circle_color); //updateで更新された色で描画する。マウスの動きに合わせて毎コマ色が変わる。
    ofSetLineWidth(1.0);
    
    drawGrid(GRID_INTERVAL); //グリッド描画は、将来的に使えるように関数化した。講義で説明する。
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, radius); //円を描画
    
    ofSetColor(255);
    
    ofLine(mouseX, 0, mouseX, ofGetHeight());
    ofLine(0, mouseY, ofGetWidth(), mouseY);
    //マウスを中心に上下左右に出る線を描画した。
    
    ofSetLineWidth(2.0);
    ofLine(ofGetWidth()/2, ofGetHeight()/2, mouseX, mouseY);
    //中心とマウスを結ぶ、円の半径を示す線を描画した。
    
    ofDrawBitmapString(ofToString(degree), mouseX+10, mouseY-10);
    // ofDrawBitmapString(s,x,y) は最も簡単に文字を表示する方法。
    // しかし日本語は使用不可だし、文字サイズも小さくて読みづらい。
    // 解決策として ofTrueTypeFont / ofxTrueTypeFontUC があるが、これは講義で説明する。
}

void ofApp::drawGrid(int interval){
    // グリッド線を描画する関数。変更する恐れのない特定の機能は、
    // このように関数という形で分離すると、コーディングの精神衛生上非常に楽だ。講義で説明する。
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
