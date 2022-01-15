#include <stdio.h>
#include <pico/stdlib.h>
#include "ADC.h"
#include "Scope.h"
#include "Globals.h"

void OSC_Start(){
    //printf("OSC Started!\n");
}

void OSC_Stop(){
    //printf("OSC Stoped!\n");
}

void OSC_Reset(){
    //printf("OSC Settings Reset!\n");
}

void OSC_Init(){
    //printf("OSC Init!\n\r");
}
void OSC_Main(){
    //Where All of the action happens
    //printf("OSC Main Loop!\n\r");
    //sleep_ms(100);
}

void OSC_Configure(){
    //printf("OSC Reconfigure!\n\r");
}

void OSC_Debug_Conf(){
    printf("-- OSC Config Data -- \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r"
        ,OSC_mSecPerDivCh1
        ,OSC_mSecPerDivCh2
        ,OSC_mVoltPerDivCh1
        ,OSC_mVoltPerDivCh2
        ,OSC_TriggerCh1
        ,OSC_TriggerCh2
        ,OSC_DirectionCh1
        ,OSC_DirectionCh2
        ,OSC_AmplificationCh1
        ,OSC_AmplificationCh2
        ,OSC_ActiveChannels);
}