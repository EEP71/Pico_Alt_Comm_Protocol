#include <pico/stdlib.h>
#include <stdio.h>
#include "ADC.h"
#include "LIA.h"
#include "Globals.h"

//TODO Hassan Lock-In-Amplifier Code

void LIA_Start(){
    //printf("LIA Started!\n");
}

void LIA_Stop(){
    //printf("LIA Stoped!\n");
}

void LIA_Reset(){
    //printf("LIA Settings Reset!\n");
}

void LIA_Init(){
    //printf("LIA Init!\n\r");
}
void LIA_Main(){
    //Where All of the action happens
    //printf("LIA Main Loop!\n\r");
    //sleep_ms(100);
}

void LIA_Configure(){
    //printf("LIA Reconfigure!\n\r");
}

void LIA_Debug_Conf(){
    printf("-- LIA Config Data -- \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r"
        ,LOI_Stub1
        ,LOI_Stub2
        ,LOI_Stub3
        ,LOI_Stub4
        ,LOI_Stub5);
}