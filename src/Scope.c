#include "Scope.h"

#include <stdio.h>
#include <pico/stdlib.h>


#define AMOUNT_OF_BYTES 100
#define ACTIVE_CHANNELS 5
#define RAND_MAX 0x7fffffff


float data[AMOUNT_OF_BYTES * ACTIVE_CHANNELS];

void init_oscilloscope(){
    sleep_ms(10);

}

void do_oscilloscope(){
    sleep_ms(10);

}
void set_mSeconds_per_div(){
    printf("set_mSeconds_per_div");
    sleep_ms(10);
}

void trigger(){
    printf("trigger");
    sleep_ms(10);
}
void direction(){
    printf("direction");
    sleep_ms(10);
}
void print_voltage_array(){
    float a = 5000.0;
    for (int i = 0; i < (AMOUNT_OF_BYTES * ACTIVE_CHANNELS); ++i) {
        //data[i] = ((float)rand()/(float)(RAND_MAX)) * a;

    }
    for (int i = 0; i < (AMOUNT_OF_BYTES * ACTIVE_CHANNELS); ++i) {
        printf("%f,", data[i]);
    }
}