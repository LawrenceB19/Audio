#include "MixerManager.h"

MixerManager::MixerManager() {
    initializeMixers();
}

void MixerManager::initializeMixers() {
    setupMixers();
}

void MixerManager::setupMixers() {
    // Configure each mixer, you can set default gains and other properties here
    mixer1.gain(0, 0.25);
    mixer1.gain(1, 0.25);
    mixer1.gain(2, 0.25);
    mixer1.gain(3, 0.25);

    mixer2.gain(0, 0.25);
    mixer2.gain(1, 0.25);
    mixer2.gain(2, 0.25);
    mixer2.gain(3, 0.25);

    mixer3.gain(0, 0.5); // Example setup, adjust as necessary
    mixer3.gain(1, 0.5);
}
