#include "FILTER.h"

FILTER::FILTER() {
    initialize();
}

void FILTER::initialize() {
    setupFilters();
}


void FILTER::setupFilters() {
    // Configure output mix defaul settings
    for(int i=0; i<8; i++){
        outMix[i] -> gain(0,1);
        outMix[i] -> gain(1,0);
        mixB[i] -> gain(0,1);
        mixB[i] -> gain(1,0);
        mixB[i] -> gain(2,0);
        mixA[i] -> gain(0,1);
        mixA[i] -> gain(1,0);
        mixA[i] -> gain(2,0);
        mixA[i] -> gain(3,0);
        ladder[i] -> interpolationMethod(LADDER_FILTER_INTERPOLATION_LINEAR);
    }
}

void FILTER::mix(int voice,float amount) {
    outMix[voice] -> gain(0,amount);
    outMix[voice] -> gain(1,1 - amount);
}

void FILTER::inputDrive(float drive, byte filter) {
    for(int i=0; i<8; i++){
        switch(filter){
            case 0:
                ladder[i] -> inputDrive(drive * 4);
                svfA[i] -> inputGain(drive * 4);
                break;
            case 1:
                svfB[i] -> inputGain(drive * 4);
                break;
        }
    }
}

void FILTER::passbandGain(float gain) {
    for(int i=0; i<8; i++){
        ladder[i] -> passbandGain(gain * 0.5);
    }
}


void FILTER::route(byte mode) {
    switch(mode){
        case 0://filter 1 -> filter 2
            for(int i=0; i<8; i++){
                inMixB[i] -> gain(0,0);
                inMixB[i] -> gain(1,1);
                inMixA[i] -> gain(0,1);
                inMixA[i] -> gain(1,0);
            }
            break;
        case 1://filter 2 -> filter 1
            for(int i=0; i<8; i++){
                inMixB[i] -> gain(0,1);
                inMixB[i] -> gain(1,0);
                inMixA[i] -> gain(0,0);
                inMixA[i] -> gain(1,1);
            }
            break;
        case 2://parallel
            for(int i=0; i<8; i++){
                inMixB[i] -> gain(0,1);
                inMixB[i] -> gain(1,0);
                inMixA[i] -> gain(0,1);
                inMixA[i] -> gain(1,0);
            }
            break;
    }
}

void FILTER::mode(byte filter,byte type) {
    //0-lp, 1-bp, 2-hp, 3-ladder
    switch(filter){
        case 0://filter 1
            for(byte i=0; i<8; i++){
                for(byte j=0; j<4; j++){
                    mixA[i] -> gain(j,0);
                }        
                //reset all gains
                mixA[i] -> gain(type,1);
                //activate gain on selected filter
            }
            break;
        case 1:
            for(byte i=0; i<8; i++){
                for(byte j=0; j<4; j++){
                    mixB[i] -> gain(j,0);
                }        
                //reset all gains
                mixB[i] -> gain(type,1);
                //activate gain on selected filter
            }
            break;
    }
}

void FILTER::frequency(byte  voice, byte filter, float freq){
    switch(filter){
        case 0://filter A
            ladder[voice] -> frequency(freq);
            svfA[voice] -> frequency(freq);
            break;
        case 1://filter B
            svfB[voice] -> frequency(freq);
            break;
    }
}

void FILTER::resonance(byte  voice, byte filter, float res){
    switch(filter){
        case 0://filter A
            ladder[voice] -> resonance(res);
            svfA[voice] -> resonance(res * 5);
            break;
        case 1://filter B
            svfB[voice] -> resonance(res * 5);
            break;
    }
}