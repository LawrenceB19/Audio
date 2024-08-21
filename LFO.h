#ifndef LFO_H
#define LFO_H

// Define custom waveform types
#define LFO_WAVEFORM_TRIANGLE 0
#define LFO_WAVEFORM_SAWTOOTH 1
#define LFO_WAVEFORM_REVERSE_SAWTOOTH 2
#define LFO_WAVEFORM_SQUARE 3
#define LFO_WAVEFORM_SINE 4
#define LFO_WAVEFORM_VARIABLE_TRIANGLE 5
#define LFO_WAVEFORM_PULSE 6
#define LFO_WAVEFORM_SAMPLE_HOLD 7
#define LFO_WAVEFORM_CUSTOM 8 // You can add more waveform types as needed

class LFO {
public:
    LFO(); // Constructor
    void initialize(); // Method to initialize LFOs
    float read(int voice); // Method to read the current LFO value
    void frequency(int voice, float freq); // Set the frequency for a specific LFO
    void sync(int voice); // Sync the phase of a specific LFO
    void shape(short type); // Set the waveform shape for all LFOs
    void pulseWidth(float pw); // Set the pulse width for PWM LFOs (if applicable)

    float levels[8]; // Array to store the current LFO levels

private:
    void setupLFOs(); // Private helper to set up LFOs
    float generateLfoSample(int voice); // Generate the next LFO sample for a specific voice

    float phase[8]; // Current phase for each LFO voice
    float phaseIncrement[8]; // Phase increment based on frequency for each voice
    float lfoFrequency[8]; // Frequency for each LFO voice
    short waveformType; // The waveform type (e.g., TRIANGLE, SAWTOOTH)
    float pulseWidthValue; // Pulse width value (only relevant for PWM waveforms)
    float lastRandomValue[8]; // Last random value for S&H waveform
};

#endif
