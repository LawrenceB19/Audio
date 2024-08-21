#include "AMP.h"

AMP::AMP() {
    initialize();
}

void AMP::initialize() {
    setupAMP();
}

void AMP::setupAMP() {
    // Configure amp
    for(int i=0; i<8; i++){
    AMP_base.amplitude(1);//always 1
    eg[i] -> attack(5);
    eg[i] -> decay(0);
    eg[i] -> sustain(1);
    eg[i] -> release(5);
    dc[i] -> amplitude(1);
    }
}

float AMP::read(int voice){
    if(rms_eg[voice] -> available()){
        levels[voice] = rms_eg[voice] -> read();
    }
    return(levels[voice]);
}
void AMP::noteOn(int voice){
    eg[voice] -> noteOn();
}
void AMP::noteOff(int voice){
    eg[voice] -> noteOff();
}
bool AMP::isActive(int voice){
    return(eg[voice] -> isActive());
}
bool AMP::isRelease(int voice){
    return(eg[voice] -> isRelease());
}

void AMP::setLevel(int voice, float level) {
    // Configure each envelope
    dc[voice] -> amplitude(level);
}

void AMP::attack(int voice, float duration) {
    // Configure each envelope
    eg[voice] -> attack(duration);
}

void AMP::decay(int voice, float duration) {
    // Configure each envelope
    eg[voice] -> decay(duration);
}

void AMP::sustain(int voice, float level) {
    // Configure each envelope
    eg[voice] -> sustain(level);
}

void AMP::release(int voice, float duration) {
    // Configure each envelope
    eg[voice] -> release(duration);
}

