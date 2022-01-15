#define VERSION "0.03 - Fast"
#define GET_DEVICE_ID (uint8_t)DataIn_Get()[0]

#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/vreg.h>
#include "Main.h"
#include "Communication.h"
#include "Settings.h"
#include "Error.h"
#include "Globals.h"


#include "DAC.h"
#include "ADC.h"

#include "LIA.h"
#include "AWG.h"
#include "Scope.h"
#include "Analyzer.h"
//Uart throughput is 500k bytes in ~5s so 100kByte/sec
void OC(){
  vreg_set_voltage(0b1111); //1.25v VCore
  set_sys_clock_khz(192000,true); //192.0mhz Core Clock
}

void Init(){
  //if(!stdio_usb_init()){Error_Handler(USB_INIT);}
  OC();
  stdio_usb_init();

  //adc_init();

  //init_dma();
  //init_spectrum_analyser();
  //init_oscilloscope();
  //init_AWG();
}

void Print_Logo(){
  printf("%s\n\r",Logo);
  printf("V%s\n",VERSION);
}

int main() {
  Init();
  sleep_ms(1000);
  Print_Logo();

  while(1){
    Handle_Data_In();
  }
  return 0;
}

void Handle_Data_In(){
  if(!DataIn_IsReady()){Serial_in_Handler_Async(); return;}

  uint8_t Temp = Packet_Decode();

  if(Temp >= 127){
    Serial_Response(GET_DEVICE_ID,Temp);
    DataIn_Clear();
    DataIn_ClearReady();
    return;
    }

  if(Temp <= 127 || !Temp)
    Serial_Response(GET_DEVICE_ID,Temp);
    DataIn_Clear();
    DataIn_ClearReady();
    return;
  }

void Task_Add(void* func){

}

void Task_Remove(void* func){

}

void RunTasks(){

}

