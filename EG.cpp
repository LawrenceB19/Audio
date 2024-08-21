#include "EG.h"

EG::EG() {
    initialize();
}

void EG::initialize() {
    setupEGs();
}

void EG::setupEGs() {
    // Configure each envelope
    for(int i=0; i<8; i++){
    eg[i] -> attack(5);
    eg[i] -> decay(0);
    eg[i] -> sustain(1);
    eg[i] -> release(5);
    dc[i] -> amplitude(1);
    }
}

float EG::read(int voice){
    if(rms_eg[voice] -> available()){
        levels[voice] = rms_eg[voice] -> read();
    }
    return(levels[voice]);
}
void EG::noteOn(int voice){
    eg[voice] -> noteOn();
}
void EG::noteOff(int voice){
    eg[voice] -> noteOff();
}
bool EG::isActive(int voice){
    return(eg[voice] -> isActive());
}
bool EG::isSustain(int voice){
    return(eg[voice] -> isSustain());
}

void EG::setLevel(int voice, float level) {
    // Configure each envelope
    dc[voice] -> amplitude(level);
}

void EG::attack(int voice, float duration) {
    // Configure each envelope
    eg[voice] -> attack(duration);
}

void EG::decay(int voice, float duration) {
    // Configure each envelope
    eg[voice] -> decay(duration);
}

void EG::sustain(int voice, float level) {
    // Configure each envelope
    eg[voice] -> sustain(level);
}

void EG::release(int voice, float duration) {
    // Configure each envelope
    eg[voice] -> release(duration);
}

