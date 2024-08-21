#ifndef MIXER_MANAGER_H
#define MIXER_MANAGER_H

#include <Audio.h>

class MixerManager {
public:
    MixerManager(); // Constructor
    void initializeMixers(); // Method to initialize mixers
    
    // Public mixer objects
    AudioMixer4 mixer1;
    AudioMixer4 mixer2;
    AudioMixer4 mixer3;

private:
    void setupMixers(); // Private helper to set up mixers
};

#endif