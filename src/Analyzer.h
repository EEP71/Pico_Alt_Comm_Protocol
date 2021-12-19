#ifndef SPECTRUM_ANALYSER_H
#define SPECTRUM_ANALYSER_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "globals.h"
#include "stdlib.h"


#define BASE_CLOCK 48000000

void fft();
void print_fft_values();
void calculate_freq_per_bin();
float calculate_sample_rate();
void init_spectrum_analyser();
void update_fft_alloc();
#endif