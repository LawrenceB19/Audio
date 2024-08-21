#include "LFO.h"
#include <cmath>  // Include for sinf() and other math functions
#include <cstdlib>  // Include for rand() function

#ifndef PI
#define PI 3.14159265358979323846  // Define PI if not already defined
#endif

LFO::LFO() {
    initialize();
}

void LFO::initialize() {
    setupLFOs();
}

float LFO::read(int voice) {
    levels[voice] = generateLfoSample(voice);
    return levels[voice];
}

void LFO::setupLFOs() {
    for (int i = 0; i < 8; i++) {
        phase[i] = 0.0f; // Initialize phase to 0
        phaseIncrement[i] = 0.0f; // Initialize phase increment to 0
        lfoFrequency[i] = 1.0f; // Default frequency
        lastRandomValue[i] = 0.0f; // Initialize the last random value for S&H
    }
    waveformType = LFO_WAVEFORM_TRIANGLE; // Default waveform type
    pulseWidthValue = 0.5f; // Default pulse width
}

void LFO::frequency(int voice, float freq) {
    lfoFrequency[voice] = freq;
    phaseIncrement[voice] = freq / 500.0f; // Assuming 44.1 kHz sample rate
}

void LFO::sync(int voice) {
    phase[voice] = 0.0f; // Reset phase to sync
}

void LFO::shape(short type) {
    waveformType = type; // Set the waveform type for all LFOs
}

void LFO::pulseWidth(float pw) {
    pulseWidthValue = pw; // Set the pulse width for all LFOs
}

float LFO::generateLfoSample(int voice) {
    phase[voice] += phaseIncrement[voice];
    if (phase[voice] >= 1.0f) {
        phase[voice] -= 1.0f; // Wrap the phase back to 0

        if (waveformType == LFO_WAVEFORM_SAMPLE_HOLD) {
            // Generate a new random value for Sample & Hold
            lastRandomValue[voice] = (float)rand() / RAND_MAX * 2.0f - 1.0f;
        }
    }

    switch (waveformType) {
        case LFO_WAVEFORM_TRIANGLE:
            return 2.0f * (phase[voice] < 0.5f ? phase[voice] : 1.0f - phase[voice]) - 1.0f;

        case LFO_WAVEFORM_SAWTOOTH:
            return 2.0f * phase[voice] - 1.0f;

        case LFO_WAVEFORM_REVERSE_SAWTOOTH:
            return 1.0f - 2.0f * phase[voice];

        case LFO_WAVEFORM_SINE:
            return sinf(2.0f * PI * phase[voice]);

        case LFO_WAVEFORM_SQUARE:
            // Fixed 50% duty cycle for square wave
            return (phase[voice] < 0.5f) ? 1.0f : -1.0f;

        case LFO_WAVEFORM_PULSE:
            // Variable pulse width for pulse wave
            return (phase[voice] < pulseWidthValue) ? 1.0f : -1.0f;

        case LFO_WAVEFORM_VARIABLE_TRIANGLE: {
            float variableSlope = 1.0f - 2.0f * pulseWidthValue;
            if (phase[voice] < pulseWidthValue) {
                return 2.0f * phase[voice] / pulseWidthValue - 1.0f;
            } else {
                return (2.0f * (1.0f - phase[voice]) / variableSlope - 1.0f);
            }
        }

        case LFO_WAVEFORM_SAMPLE_HOLD:
            return lastRandomValue[voice];

        default:
            return 0.0f; // Default case for unknown waveform type
    }
}
