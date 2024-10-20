#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

class Waveform {
public:
    virtual ~Waveform() {}
    virtual float generate(float time) = 0;
    virtual void setFrequency(float frequency) = 0;
    virtual void setAmplitude(float amplitude) = 0;
    virtual void setPhase(float phase) = 0;
};

class SineWave : public Waveform {
private:
    float frequency;
    float amplitude;
    float phase;   

public:
    SineWave() : frequency(1.0f), amplitude(1.0f), phase(0.0f) {}

    float generate(float time) override {
        return amplitude * std::sin(2 * M_PI * frequency * time + phase);
    }

    void setFrequency(float freq) override {
        frequency = freq;
    }

    void setAmplitude(float amp) override {
        amplitude = amp;
    }

    void setPhase(float ph) override {
        phase = ph;
    }
};

void generateWaveform(Waveform& waveform, float duration, int sampleRate) {
    std::vector<float> samples;
    int totalSamples = static_cast<int>(duration * sampleRate);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Time (s)\tValue\n";

    for (int i = 0; i < totalSamples; ++i) {
        float time = static_cast<float>(i) / sampleRate;
        float value = waveform.generate(time);
        std::cout << time << "\t\t" << value << std::endl;
    }
}

int main() {
    SineWave sineWave;

    float frequency, amplitude, phase;

    std::cout << "Enter the frequency (Hz): ";
    std::cin >> frequency;
    std::cout << "Enter the amplitude: ";
    std::cin >> amplitude;
    std::cout << "Enter the phase shift (radians, optional, default is 0): ";
    std::cin >> phase;

    sineWave.setFrequency(frequency);
    sineWave.setAmplitude(amplitude);
    sineWave.setPhase(phase);

    float duration = 1.0;
    int sampleRate = 1000; 

    std::cout << "Generated Sine Wave Samples:\n";
    generateWaveform(sineWave, duration, sampleRate);

    return 0;
}
