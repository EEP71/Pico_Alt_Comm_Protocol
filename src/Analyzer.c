#include <pico/stdlib.h>
#include <stdio.h>
#include "ADC.h"
#include "Globals.h"
#include "Analyzer.h"
#include "Communication.h"

void SA_TestDataOutput();
void SA_Start(){
    //printf("SA Started!\n");
    SA_TestDataOutput();
}

void SA_Stop(){
    //printf("SA Stoped!\n");
}
 
void SA_Reset(){
    //printf("SA Settings Reset!\n");
}

void SA_Init(){
    //printf("SA Init!\n\r");
}

void SA_Main(){
    //Where All of the action happens
    //printf("SA Main Loop!\n\r");
    //sleep_ms(100);
}

void SA_Configure(){
    //printf("SA Reconfigure!\n\r");
}

void SA_Debug_Conf(){
  printf("-- SA Config Data -- \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r %d \n\r"
    ,SA_SampleRateCh1
    ,SA_SampleRateCh2
    ,SA_CaptureDepthCh1
    ,SA_CaptureDepthCh2
    ,SA_AmplificationCh1
    ,SA_AmplificationCh2
    ,SA_ActiveChannels);
}
// Test Me By Sending the hex String 
// 05 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 7F FF
void SA_TestDataOutput(){
    while(1){
    static uint32_t Test;
    static uint32_t Test2 = 10000;
    Serial_Out_32(SA_ID,0, Test++);
    Serial_Out_32(SA_ID,1, Test2+= 16);
    //sleep_ms(50);
    }
}