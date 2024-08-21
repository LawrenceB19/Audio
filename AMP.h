#ifndef AMP_H
#define AMP_H

#include <Audio.h>


class AMP{
public:
    AMP(); // Constructor
    void initialize(); // Method to initialize LFOs
    float read(int voice);
    float levels[8];
    void noteOn(int voice);
    void noteOff(int voice);
    bool isActive(int voice);
    bool isRelease(int voice);
    void setLevel(int voice, float level);//Method to set the amp level for a voice
    void attack(int voice, float duration); //set envelope attack
    void decay(int voice, float duration); //set envelope decay
    void sustain(int voice, float level); //set envelope sustain
    void release(int voice, float duration); //set envelope release
    //Public DC objects
    AudioSynthWaveformDc AMP_base; //always set to 1
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
    //Public audio multipliers for amp modulation signal (multiplies eg with level)
    AudioEffectMultiply eg_mult1;
    AudioEffectMultiply eg_mult2;
    AudioEffectMultiply eg_mult3;
    AudioEffectMultiply eg_mult4;
    AudioEffectMultiply eg_mult5;
    AudioEffectMultiply eg_mult6;
    AudioEffectMultiply eg_mult7;
    AudioEffectMultiply eg_mult8;
    //Public audio multipliers for signal and modulation
    AudioEffectMultiply signal_mult1;
    AudioEffectMultiply signal_mult2;
    AudioEffectMultiply signal_mult3;
    AudioEffectMultiply signal_mult4;
    AudioEffectMultiply signal_mult5;
    AudioEffectMultiply signal_mult6;
    AudioEffectMultiply signal_mult7;
    AudioEffectMultiply signal_mult8;



    AudioSynthWaveformDc *dc[8] = {&DC1, &DC2, &DC3, &DC4, &DC5, &DC6, &DC7, &DC8};
    AudioEffectEnvelope *eg[8] ={&eg1,&eg2,&eg3,&eg4,&eg5,&eg6,&eg7,&eg8};
    AudioEffectMultiply *eg_mult[8] ={&eg_mult1,&eg_mult2,&eg_mult3,&eg_mult4,&eg_mult5,&eg_mult6,&eg_mult7,&eg_mult8};
    AudioEffectMultiply *signal_mult[8] ={&signal_mult1,&signal_mult2,&signal_mult3,&signal_mult4,&signal_mult5,&signal_mult6,&signal_mult7,&signal_mult8};
    AudioAnalyzeRMS *rms_eg[8] = {&RMS1, &RMS2, &RMS3, &RMS4, &RMS5, &RMS6, &RMS7, &RMS8};

private:
    void setupAMP(); // Private helper to set up EGs
};

#endif