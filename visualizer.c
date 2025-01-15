/*
 * Generates a .csv file with data correlating to a waveform 
 * Started on 1/14/25 by Lucas Donovan
 */
    
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159

void error(char *msg);
void generate_sine();
void generate_square_wave();
void generate_triangle_wave();
void generate_sawtooth_wave();
void generate_step_function();
void generate_impulse_wave();
void generate_exponential_decay();
void generate_random_waveform();

int main (int argc, char* argv[]) {
    int wv;
	printf("Choose a waveform: \nSine (0) \nSquare (1)\nTriangle (2)\nSawtooth (3)\nStep (4)\nImpulse (5)\nExponential Decay (6)\nRandom (7)\n:");
	scanf("%d", &wv);
	
	switch(wv) {
		case(0):
			generate_sine();
			break;
		case(1):
			generate_square_wave();
			break;
		case(2):
			generate_triangle_wave();
			break;
		case(3):
			generate_sawtooth_wave();
			break;
		case(4):
			generate_step_function();
			break;
		case(5):
			generate_impulse_wave();
			break;
		case(6):
			generate_exponential_decay();
			break;
		case(7):
			generate_random_waveform();
			break;
		default:
			error("Error chosing waveform.");
			break;
	}
    return 0;
}

/*
 * Generate a sine wave
 */
void generate_sine() {
    char *filename = "outputs/sine.csv";
    FILE *file = fopen(filename, "w");
    if (!file) 
        error("File failed to open.");
 
    double amp, freq, phase, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Phase: ");
    scanf("%lf", &phase);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);
	
	fprintf(file, "time,value\n");
	
    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        fprintf(file, "%lf,%lf\n", t, (amp * sin((2 * PI * freq * t) + phase)));
    }

    fclose(file);
}

/*
 * Generate a square wave
 */
void generate_square_wave() {
	char *filename = "outputs/square.csv";
	FILE *file = fopen(filename, "w");
	if(!file)
		error("File failed to open.");

	double amp, freq, duration, sampling_rate;
	printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);
	
	fprintf(file, "time,value\n");

	for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
		fprintf(file, "%lf,%lf\n", t, sin(2 * PI * freq * t) >= 0 ? amp : -amp);
	}

	fclose(file);
}

/*
 * Generate a triangular wave
 */
void generate_triangle_wave() {
    char *filename = "outputs/triangle.csv";
    FILE *file = fopen(filename, "w");
    if (!file) {
        error("File failed to open");
        return;
    }

    double amp, freq, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    // Nyquist Check
    if (sampling_rate < 2 * freq) {
        printf("Warning: Sampling rate is too low to accurately capture the waveform.\n");
    }

    fprintf(file, "time,value\n");

    double period = 1.0 / freq; 

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double phase = fmod(t, period) / period; // Normalize phase to [0, 1)
        double value;

        if (phase < 0.5) {
            value = 4 * amp * phase - amp; // Rising edge
        } else {
            value = amp - 4 * amp * (phase - 0.5); // Falling edge
        }
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generate a sawtooth wave
 */
void generate_sawtooth_wave() {
    char *filename = "outputs/sawtooth.csv";
    FILE *file = fopen(filename, "w");
    if (!file) {
        error("File failed to open");
        return;
    }

    double amp, freq, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    fprintf(file, "time,value\n");

    double period = 1.0 / freq;

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double phase = fmod(t, period) / period; 
        double value = 2 * amp * phase - amp;    
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generate a step function
 */
void generate_step_function() {
    char *filename = "outputs/step.csv";
    FILE *file = fopen(filename, "w");
    if (!file) {
        error("File failed to open");
        return;
    }

    double amp, freq, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    fprintf(file, "time,value\n");

    double period = 1.0 / freq;

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double phase = fmod(t, period) / period; // Normalize phase to [0, 1)
        double value = phase < 0.5 ? amp : -amp; // High for the first half, low for the second half
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generate an impulse wave
 */
void generate_impulse_wave() {
    char *filename = "outputs/impulse.csv";
    FILE *file = fopen(filename, "w");
    if (!file) {
        error("File failed to open");
        return;
    }

    double amp, freq, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    fprintf(file, "time,value\n");

    double period = 1.0 / freq;

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double phase = fmod(t, period); // Phase within period
        double value = (phase < (1.0 / sampling_rate)) ? amp : 0; // Spike at the beginning of each period
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generate a waveform that decays exponentially
 */
void generate_exponential_decay() {
    char *filename = "outputs/exponential.csv";
    FILE *file = fopen(filename, "w");
    if (!file) {
        error("File failed to open");
        return;
    }

    double amp, decay_rate, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Decay Rate: ");
    scanf("%lf", &decay_rate);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    fprintf(file, "time,value\n");

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double value = amp * exp(-decay_rate * t); // Exponential decay formula
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generate a random waveform
 */
void generate_random_waveform() {
    char *filename = "outputs/random.csv";
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("File failed to open");
        return;
    }

    double amp, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    fprintf(file, "time,value\n");

    srand(time(NULL)); // Seed random number generator

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double value = ((double)rand() / RAND_MAX) * 2 * amp - amp; // Random value in range [-amp, amp]
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Shortcut for printing to stderr
 */
void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
