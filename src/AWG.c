#include <pico/stdlib.h>
#include <stdio.h>
#include "AWG.h"
#include "Globals.h"

void AWG_Start(){
    printf("AWG Started!\n");
}

void AWG_Stop(){
    printf("AWG Stoped!\n");
}

void AWG_Reset(){
    printf("AWG Settings Reset!\n");
}

void AWG_Init(){
    printf("AWG Init!\n\r");
}
void AWG_Main(){
    //Where All of the action happens
    printf("AWG Main Loop!\n\r");
    sleep_ms(100);
}

void AWG_Configure(){
    printf("AWG Reconfigure!\n\r");
}

void AWG_Debug_Conf(){
  printf("-- AWG Config Data -- \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r"
  ,AWG_FrequencyCh1
  ,AWG_FrequencyCh2
  ,AWG_PeakToPeakCh1
  ,AWG_PeakToPeakCh2
  ,AWG_WaveTypeCh1
  ,AWG_WaveTypeCh2
  ,AWG_AmplificationCh1
  ,AWG_AmplificationCh1
  ,AWG_ActiveChannels);
}

