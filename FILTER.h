#ifndef FILTER_H
#define FILTER_H

#include <Audio.h>


class FILTER {
public:
    FILTER(); // Constructor
    void initialize(); // Method to initialize filters
    void mix(int voice, float amount); //mix between filter 1 and filter 2 for parallel mode
    void mode(byte filter, byte type); //switch between filter modes
    void route(byte mode); //0:1->2,  1:2->1,  2:parallel
    void frequency(byte voice,byte filter, float freq);
    void resonance(byte voice,byte filter, float res);
    void passbandGain(float gain);
    void inputDrive(float drive, byte filter);

    AudioMixer4 outMix1;
    AudioMixer4 outMix2;
    AudioMixer4 outMix3;
    AudioMixer4 outMix4;
    AudioMixer4 outMix5;
    AudioMixer4 outMix6;
    AudioMixer4 outMix7;
    AudioMixer4 outMix8;

    AudioMixer4 mixA1;
    AudioMixer4 mixA2;
    AudioMixer4 mixA3;
    AudioMixer4 mixA4;
    AudioMixer4 mixA5;
    AudioMixer4 mixA6;
    AudioMixer4 mixA7;
    AudioMixer4 mixA8;

    AudioMixer4 mixB1;
    AudioMixer4 mixB2;
    AudioMixer4 mixB3;
    AudioMixer4 mixB4;
    AudioMixer4 mixB5;
    AudioMixer4 mixB6;
    AudioMixer4 mixB7;
    AudioMixer4 mixB8;

    AudioMixer4 inMixB1;
    AudioMixer4 inMixB2;
    AudioMixer4 inMixB3;
    AudioMixer4 inMixB4;
    AudioMixer4 inMixB5;
    AudioMixer4 inMixB6;
    AudioMixer4 inMixB7;
    AudioMixer4 inMixB8;

    AudioMixer4 inMixA1;
    AudioMixer4 inMixA2;
    AudioMixer4 inMixA3;
    AudioMixer4 inMixA4;
    AudioMixer4 inMixA5;
    AudioMixer4 inMixA6;
    AudioMixer4 inMixA7;
    AudioMixer4 inMixA8;

    AudioFilterLadder ladder1;
    AudioFilterLadder ladder2;
    AudioFilterLadder ladder3;
    AudioFilterLadder ladder4;
    AudioFilterLadder ladder5;
    AudioFilterLadder ladder6;
    AudioFilterLadder ladder7;
    AudioFilterLadder ladder8;

    AudioFilterStateVariable svfA1;
    AudioFilterStateVariable svfA2;
    AudioFilterStateVariable svfA3;
    AudioFilterStateVariable svfA4;
    AudioFilterStateVariable svfA5;
    AudioFilterStateVariable svfA6;
    AudioFilterStateVariable svfA7;
    AudioFilterStateVariable svfA8;

    AudioFilterStateVariable svfB1;
    AudioFilterStateVariable svfB2;
    AudioFilterStateVariable svfB3;
    AudioFilterStateVariable svfB4;
    AudioFilterStateVariable svfB5;
    AudioFilterStateVariable svfB6;
    AudioFilterStateVariable svfB7;
    AudioFilterStateVariable svfB8;

    AudioMixer4 *outMix[8] ={&outMix1, &outMix2, &outMix3, &outMix4, &outMix5, &outMix6, &outMix7, &outMix8};
    AudioMixer4 *mixA[8] ={&mixA1,&mixA2,&mixA3,&mixA4,&mixA5,&mixA6,&mixA7,&mixA8};
    AudioMixer4 *mixB[8] ={&mixB1,&mixB2,&mixB3,&mixB4,&mixB5,&mixB6,&mixB7,&mixB8};
    AudioMixer4 *inMixA[8] ={&inMixA1,&inMixA2,&inMixA3,&inMixA4,&inMixA5,&inMixA6,&inMixA7,&inMixA8};
    AudioMixer4 *inMixB[8] ={&inMixB1,&inMixB2,&inMixB3,&inMixB4,&inMixB5,&inMixB6,&inMixB7,&inMixB8};
    AudioFilterLadder *ladder[8] ={&ladder1, &ladder2, &ladder3, &ladder4, &ladder5, &ladder6, &ladder7, &ladder8};
    AudioFilterStateVariable *svfA[8] = {&svfA1,&svfA2,&svfA3,&svfA4,&svfA5,&svfA6,&svfA7,&svfA8};
    AudioFilterStateVariable *svfB[8] = {&svfB1,&svfB2,&svfB3,&svfB4,&svfB5,&svfB6,&svfB7,&svfB8};
private:
    void setupFilters(); // Private helper to set up filters
};

#endif