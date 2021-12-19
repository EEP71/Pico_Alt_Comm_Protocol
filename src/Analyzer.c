
#include "Globals.h"
#include "Analyzer.h"
#include "kiss_fft/kiss_fftr.h"
#include <inttypes.h>

kiss_fft_scalar fft_in[HIGHEST_CAPTURE_DEPTH]; // kiss_fft_scalar is a float
kiss_fft_cpx fft_out[HIGHEST_CAPTURE_DEPTH];
float freqs[HIGHEST_CAPTURE_DEPTH];
float freq_power[HIGHEST_CAPTURE_DEPTH];

kiss_fftr_cfg kiss_cfg;

void init_spectrum_analyser(){
    kiss_cfg = kiss_fftr_alloc(capture_depth, false, 0, 0);
}

void fft(){
    uint64_t sum = 0;
    for (int i = 0; i < capture_depth; i++)
    {
        sum+=capture_buf[i];
    }
    float avg = sum / capture_depth;

    for (int i=0;i<capture_depth;i++)
    {
        fft_in[i]= capture_buf[i] - avg;
    }
    kiss_fftr(kiss_cfg , fft_in, fft_out);
    for (int i = 0; i < capture_depth/2; i++) {
      freq_power[i] = fft_out[i].r*fft_out[i].r+fft_out[i].i*fft_out[i].i;
    }
  }

void calculate_freq_per_bin(){
    float f_max = calculate_sample_rate();
    float f_res = f_max / capture_depth;
    for (int i = 0; i < capture_depth; i++) {
        freqs[i] = f_res*i;
    }
}

float calculate_sample_rate()
{
    float sample_rate = 0;
    sample_rate = BASE_CLOCK / clock_divide;
    return sample_rate;
}
void print_fft_values(){
    for (int i = 0; i < capture_depth/2; ++i) {
        printf("%f,", freq_power[i]);
    }
}

void update_fft_alloc(){
    kiss_fft_free(kiss_cfg);
    kiss_cfg = kiss_fftr_alloc(capture_depth, false, 0, 0);
}
