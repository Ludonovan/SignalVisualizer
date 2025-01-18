/*
 * Generates a .csv file with data correlating to a waveform 
 * Started on 1/14/25 by Lucas Donovan
 */

#include "visualizer.h"

int main (int argc, char* argv[]) {
    int wv;
	printf("Choose a waveform: \nSine (0)\nSquare (1)\nTriangle (2)\nSawtooth (3)\nStep (4)\nImpulse (5)\nExponential Decay (6)\nSinc(7)\nRectangle (8)\nStaircase (9)\nDamped Sine (10)\nRandom (11)\n:");
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
			generate_sinc_wave();
			break;
		case(8):
			generate_rect_wave();
			break;
		case(9):
			generate_stair_wave();
			break;
		case(10):
			generate_damped_sine();
			break;
		case(11):
			generate_random_waveform();
			break;
        case(-1):
            test_wave();
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
    FILE *file = open_file("outputs/sine.csv");
    
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

	nyquist_check(freq, sampling_rate);

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        fprintf(file, "%lf,%lf\n", t, (amp * sin((2 * PI * freq * t) + phase)));
    }

    fclose(file);
}

/*
 * Generate a square wave
 */
void generate_square_wave() {

    FILE *file = open_file("outputs/square.csv");

	double amp, freq, duration, sampling_rate, phase;
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

	nyquist_check(freq, sampling_rate);

	for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
		fprintf(file, "%lf,%lf\n", t, sin((2 * PI * freq * t) + phase) >= 0 ? amp : -amp);
	}

	fclose(file);
}

/*
 * Generate a triangular wave
 */
void generate_triangle_wave() {

    FILE *file = open_file("outputs/triangle.csv");

    double amp, freq, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);
	
	nyquist_check(freq, sampling_rate);

    double period = 1.0 / freq; 

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double phase = fmod(t, period) / period;
        double value;

        if (phase < 0.5) {
            value = 4 * amp * phase - amp; 
        } else {
            value = amp - 4 * amp * (phase - 0.5); 
        }
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generate a sawtooth wave
 */
void generate_sawtooth_wave() {
   
    FILE *file = open_file("outputs/sawtooth.csv");

    double amp, freq, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

	nyquist_check(freq, sampling_rate);
    
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

    FILE *file = open_file("outputs/step.csv");

    double start, amp, sampling_rate; 
    printf("Start time: ");
    scanf("%lf", &start);
    printf("Amplitude: ");
    scanf("%lf", &amp);
	printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    for (double t = start - 5; t <= start + 5; t += (1.0 / sampling_rate)) {
        fprintf(file, "%lf,%lf\n", t, (t >= start) ? amp : 0);
    }
    fclose(file);
}

/*
 * Generate an impulse wave
 */
void generate_impulse_wave() {
   
    FILE *file = open_file("outputs/impulse.csv");

    double amp, freq, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Frequency: ");
    scanf("%lf", &freq);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

	nyquist_check(freq, sampling_rate);
    
	double period = 1.0 / freq;

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double phase = fmod(t, period); 
        double value = (phase < (1.0 / sampling_rate)) ? amp : 0; 
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generate a waveform that decays exponentially
 */
void generate_exponential_decay() {

    FILE *file = open_file("outputs/exp_decay.csv");

    double amp, decay_rate, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Decay Rate: ");
    scanf("%lf", &decay_rate);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double value = amp * exp(-decay_rate * t); 
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generate a random waveform
 */
void generate_random_waveform() {

    FILE *file = open_file("outputs/random.csv");

    double amp, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    srand(time(NULL)); 

    for (double t = 0; t <= duration; t += (1.0 / sampling_rate)) {
        double value = ((double)rand() / RAND_MAX) * 2 * amp - amp; 
        fprintf(file, "%lf,%lf\n", t, value);
    }
    fclose(file);
}

/*
 * Generates a sinc wave
 */
void generate_sinc_wave() {
    FILE *file = open_file("outputs/sinc.csv");
	
	double amp, duration, sampling_rate;
    printf("Amplitude: ");
    scanf("%lf", &amp);
    printf("Duration: ");
    scanf("%lf", &duration);
    printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);
	
	double half_duration = duration / 2;

    for (double t = -half_duration; t <= half_duration; t += 1.0 / sampling_rate) {
        fprintf(file, "%lf,%lf\n", t, ((sin(PI*t)) / (PI*t) ));
    }

    fclose(file);
}    

/*
 * Generates a rectangle wave 
 */
void generate_rect_wave() {
    FILE *file = open_file("outputs/rect.csv");
	
	double amp, start, stop, sampling_rate;
	
	printf("Amplitude: ");
	scanf("%lf", &amp);
	printf("Start time: ");
	scanf("%lf", &start);
	printf("Stop time: ");
	scanf("%lf", &stop);
	printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);

    for (double t = start - 1; t <= stop + 1; t += (1.0 / sampling_rate)) {
        fprintf(file, "%lf,%lf\n", t, (t >= start && t <= stop) ? amp : 0);
    }

    fclose(file);
}

/*
 * Generates a staircase wave 
 */
void generate_stair_wave() {
    FILE *file = open_file("outputs/stair.csv");
	
	double start, stop, sampling_rate;
	
	printf("Start time: ");
	scanf("%lf", &start);
	printf("Stop time: ");
	scanf("%lf", &stop);
	printf("Sampling Rate: ");
    scanf("%lf", &sampling_rate);
	
    for (double t = start; t <= stop; t += (1.0 / sampling_rate)) {
        fprintf(file, "%lf,%lf\n", t, floor(t));
    }

    fclose(file);
}


/*
 * Generates a damped sine wave 
 */
void generate_damped_sine() {
    FILE *file = open_file("outputs/damped_sine.csv");
	
	double amp, freq, start, stop, damp, sampling_rate;
	
	printf("Amplitude: ");
	scanf("%lf", &amp);
	printf("Frequency: ");
	scanf("%lf", &freq);
	printf("Start time: ");
	scanf("%lf", &start);
	printf("Stop time: ");
	scanf("%lf", &stop);
	printf("Dampening constant: ");
	scanf("%lf", &damp);
	printf("Sampling rate: ");
	scanf("%lf", &sampling_rate);

	nyquist_check(freq, sampling_rate);
    
	for (double t = start; t <= stop; t += (1.0 / sampling_rate)) {
        fprintf(file, "%lf,%lf\n", t, (pow(2.71828, -damp * t) * (amp * sin(2 * PI * freq * t))));
    }

    fclose(file);
} 


/*
 * TODO
 * Generates a waveform based on an input function
 */
void generate_wave_from_input() {
    FILE *file = open_file("outputs/function.csv");

    char *func;
    printf("Input the function. (ex: 2sin(2*pi*30*t+(pi/2)))\n: ");
    scanf("%s", func);
    parse_input_function(func); 
}

/*
 * TODO
 * Parse an input function
 */
void parse_input_function(char *func) {

}

/*
 * For testing
 */
void test_wave() {
    FILE *test_file = open_file("outputs/test.csv");
	
	double amp, freq, phase, start, stop, damp, sampling_rate;
	
	printf("Amplitude: ");
	scanf("%lf", &amp);
	printf("Frequency: ");
	scanf("%lf", &freq);
	printf("Phase: ");
	scanf("%lf", &phase);
	printf("Start time: ");
	scanf("%lf", &start);
	printf("Stop time: ");
	scanf("%lf", &stop);
	printf("Dampening constant: ");
	scanf("%lf", &damp);
	printf("Sampling rate: ");
	scanf("%lf", &sampling_rate);

	nyquist_check(freq, sampling_rate);
    
	for (double t = start; t <= stop; t += (1.0 / sampling_rate)) {
		//if (/* t is an integer */)	
			freq = 2 * freq + 1;
        fprintf(test_file, "%lf,%lf\n", t, amp * sin((2 * PI * freq * t) + phase));
    }

    fclose(test_file);
}    

/*
 * Perform a Nyquist check to ensure accurate plotting 
 */
void nyquist_check(double freq, double sampling_rate) {
    if (sampling_rate < 2 * freq) {
        error("Sampling rate is too low to accurately capture the waveform.\n");
    }
}

/*
 * Open a file with input name
 */
FILE *open_file(char *filename) {
    FILE *file = fopen(filename, "w");
	if (!file) {
        error("File failed to open");
    }
    fprintf(file, "time,value\n");
    return file;
}

/*
 * Shortcut for printing to stderr
 */
void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

