#ifndef AWG_H
#define AWG_H

#include <stdio.h>
#include <pico/stdlib.h>


void init_AWG();
void do_AWG();
void set_wave_type();
void set_frequency();
void set_channel();
void set_peak_2_peak();
void set_offset();
void set_amplification();


#endif