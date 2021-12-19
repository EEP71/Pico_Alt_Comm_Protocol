#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "stdlib.h"

enum settings_selector
{
    set_adc_capture_depth = 'a',
    set_adc_sample_rate = 'b',
    set_adc_amplification = 'c',
    set_channel_number = 'd',

    set_awg_wave_type = 'e',
    set_dac_freq = 'f',
    set_dac_channel_number = 'g',
    set_peak_to_peak = 'h',
    set_awg_offset = 'i',

    set_mSeconds_per_dev   = 'j',
    set_trigger            = 'k',
    set_direction          = 'l',
    set_mVolt_per_DIV      = 'm',

    get_adc_capture_depth = 'n',
    get_adc_sample_rate =   'o'

};

void setting_selector(uint16_t input_value);
int convert_to_int();

#endif