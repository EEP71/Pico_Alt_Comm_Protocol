#ifndef ADC_H
#define ADC_H

#include <hardware/dma.h>

#define LED_PIN 25
#define CAPTURE_CHANNEL 0

void init_dma();
void init_adc();
uint16_t *adc_capture();
void print_samples();
void print_sample_rate();
void change_capture_depth(int depth);
void change_clock_divide(int devide);

#endif