#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include "pico/stdlib.h"

#define HIGHEST_CAPTURE_DEPTH 3000
#define DEFAULT_CAPTURE_DEPTH 1000
#define DEFAULT_CLOCK_DEVIDE  960
extern int capture_depth;
extern int clock_divide;

extern uint16_t capture_buf[HIGHEST_CAPTURE_DEPTH];
#endif