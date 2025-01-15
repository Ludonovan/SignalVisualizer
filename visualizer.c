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

int main (int argc, char* argv[]) {
    generate_sine();
    return 0;
}

/*
 * Generate a .csv file containing a sine wave
 */
void generate_sine() {
    char *filename = "sine.csv";
    FILE *file = fopen(filename, "w");
    if (!file) {
        error("File failed to open.");
    }
 
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
 * Shortcut for printing to stderr
 */
void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
