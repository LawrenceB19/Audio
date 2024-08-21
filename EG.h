#ifndef EG_H
#define EG_H

#include <Audio.h>


class EG {
public:
    EG(); // Constructor
    void initialize(); // Method to initialize LFOs
    float read(int voice);
    float levels[8];
    void noteOn(int voice);
    void noteOff(int voice);
    bool isActive(int voice);
    bool isSustain(int voice);
    void setLevel(int voice, float level);//Method to set the level of a specific envelope
    void attack(int voice, float duration); //set envelope attack
    void decay(int voice, float duration); //set envelope decay
    void sustain(int voice, float level); //set envelope sustain
    void release(int voice, float duration); //set envelope release
    //Public DC objects
    AudioSynthWaveformDc DC1;
    AudioSynthWaveformDc DC2;
    AudioSynthWaveformDc DC3;
    AudioSynthWaveformDc DC4;
    AudioSynthWaveformDc DC5;
    AudioSynthWaveformDc DC6;
    AudioSynthWaveformDc DC7;
    AudioSynthWaveformDc DC8;
    // Public envelope objects
    AudioEffectEnvelope eg1;
    AudioEffectEnvelope eg2;
    AudioEffectEnvelope eg3;
    AudioEffectEnvelope eg4;
    AudioEffectEnvelope eg5;
    AudioEffectEnvelope eg6;
    AudioEffectEnvelope eg7;
    AudioEffectEnvelope eg8;
    // Public RMS objects
    AudioAnalyzeRMS  RMS1;
    AudioAnalyzeRMS  RMS2;
    AudioAnalyzeRMS  RMS3;
    AudioAnalyzeRMS  RMS4;
    AudioAnalyzeRMS  RMS5;
    AudioAnalyzeRMS  RMS6;
    AudioAnalyzeRMS  RMS7;
    AudioAnalyzeRMS  RMS8;


    AudioSynthWaveformDc *dc[8] = {&DC1, &DC2, &DC3, &DC4, &DC5, &DC6, &DC7, &DC8};
    AudioEffectEnvelope *eg[8] ={&eg1,&eg2,&eg3,&eg4,&eg5,&eg6,&eg7,&eg8};
    AudioAnalyzeRMS *rms_eg[8] = {&RMS1, &RMS2, &RMS3, &RMS4, &RMS5, &RMS6, &RMS7, &RMS8};

private:
    void setupEGs(); // Private helper to set up EGs
};

#endif