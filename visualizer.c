/*
 * A signal visualizer tool
 * Started on 1/14/25 by Lucas Donovan
*/
    
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

void error(char *msg);
void generate_sine();
void generate_square_wave();

int main (int argc, char* argv[]) {
    int wv;
	printf("Choose a waveform: \nSine (0) \nSquare (1)");
	scanf("%d", &wv);
	
	switch(wv) {
		case(0):
			generate_sine();
			break;
		case(1):
			generate_square_wave();
			break;
		default:
			error("Error chosing waveform.");
			break;
	}
    return 0;
}

/*
 * Generate a .csv file containing a sine wave
 */
void generate_sine() {
    char *filename = "sine.csv";
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
 * Generate a .csv file conaining a square wave
 */
void generate_square_wave() {
	char *filename = "square.csv";
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
 * Shortcut for printing to stderr
 */
void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
