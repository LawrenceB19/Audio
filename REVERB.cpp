#include "REVERB.h"

REVERB::REVERB() {
    initializeMixers();
}

void REVERB::initializeMixers() {
    setupMixers();
}

void REVERB::setupMixers() {
    // Configure each mixer, you can set default gains and other properties here
    mixerL.gain(0, 0.5);
    mixerL.gain(1, 0.5);
    mixerR.gain(0, 0.5);
    mixerR.gain(1, 0.5);
    freeverb.size(1.0);     // max reverb length
    freeverb.lowpass(0.3);  // sets the reverb master lowpass filter
    freeverb.lodamp(0.1);   // amount of low end loss in the reverb tail
    freeverb.hidamp(0.2);   // amount of treble loss in the reverb tail
    freeverb.diffusion(1.0);  // 1.0 is the detault setting, lower it to create more "echoey" reverb
}

void REVERB::wetdry(float wet) {
    mixerL.gain(0, 1-wet);
    mixerL.gain(1, wet);
    mixerR.gain(0, 1-wet);
    mixerR.gain(1, wet);  
}

void REVERB::Size(float size) {
    freeverb.size(size); 
}

void REVERB::Lowpass(float lp) {
    freeverb.lowpass(lp); 
}

void REVERB::Diffusion(float dif) {
    freeverb.diffusion(dif); 
}
