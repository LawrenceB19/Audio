#ifndef REVERB_H
#define REVERB_H

#include <Audio.h>
#include "effect_platervbstereo.h"

class REVERB {
public:
    REVERB(); // Constructor
    void initializeMixers(); // Method to initialize mixers
    void wetdry(float wet);//sets wet/dry mix from 0-dry to 1-wet
    void Size(float size); //sets the size of the reverb
    void Lowpass(float lp); //sets the lowpass filter of the reverb
    void Diffusion(float dif); //sets the echoiness
    
    // Public mixer objects
    AudioEffectPlateReverb   freeverb;
    AudioMixer4 mixerL;
    AudioMixer4 mixerR;

private:
    void setupMixers(); // Private helper to set up mixers
};

#endif