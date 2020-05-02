/*
 *  ofxFFTLive.cpp
 *  Created by lukasz karluk on 29/08/09.
 *
 */

#include "ofxFFTLive.h"

ofxFFTLive::ofxFFTLive() : ofxFFTBase() {
    soundStream = NULL;
}

ofxFFTLive::~ofxFFTLive() {
    if(soundStream == NULL) {
        return;
    }
    soundStream->stop();
    soundStream->close();
    delete soundStream;
    soundStream = NULL;
}

void ofxFFTLive::setup(int deviceID, int inputChannel) 
{
		_inputChannel = inputChannel;
    ofSoundStream * soundStream = new ofSoundStream();

		if (deviceID != -1)
		{
			soundStream->setDeviceID(deviceID);
		}

		/*
		auto devices = soundStream->getDeviceList();
		
		for (auto &d : devices)
		{
			ofLog() << d.deviceID << " / " << d.name << " num input channels: " << d.inputChannels;
		}
		*/

    soundStream->setup(this,                   // callback obj.
                       0,                      // out channels.
                       inputChannel+1,                      // in channels.
                       44100,                  // sample rate.
                       getBufferSize(),        // buffer size.
                       4);                     // number of buffers.
    this->soundStream = soundStream;
}

void ofxFFTLive::audioIn(float * input, int bufferSize, int nChannels) {
    ofxFFTBase::audioIn(input);
}

void ofxFFTLive::audioIn(ofSoundBuffer & buffer)
{
	ofSoundBuffer b;
	buffer.getChannel(b, _inputChannel);
	ofxFFTBase::audioIn(&b.getBuffer()[0]);
	//ofLog() << "audio input " << buffer.getDeviceID() << " / " << buffer.getNumChannels();
}
