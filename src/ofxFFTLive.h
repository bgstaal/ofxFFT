/*
 *  ofxFFTLive.h
 *  Created by lukasz karluk on 29/08/09.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxFFTBase.h"

class ofxFFTLive : public ofxFFTBase {

	int _inputChannel;
  
public:

    ofxFFTLive();
    ~ofxFFTLive();
    
    void setup(int deviceID = -1, int inputChannel = 0);
    void audioIn(float * input, int bufferSize, int nChannels);
		void audioIn(ofSoundBuffer& buffer);
    
    ofSoundStream * soundStream;
};