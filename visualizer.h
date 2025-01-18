#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159

void generate_sine();
void generate_square_wave();
void generate_triangle_wave();
void generate_sawtooth_wave();
void generate_step_function();
void generate_impulse_wave();
void generate_exponential_decay();
void generate_random_waveform();
void generate_sinc_wave();
void generate_rect_wave();
void generate_stair_wave();
void generate_damped_sine();
void test_wave();
void generate_wave_from_input();
void parse_input_function(char *func);
void nyquist_check(double freq, double sampling_rate);
FILE *open_file(char *filename);
void error(char *msg);
 
