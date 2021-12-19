
// #include "spectrum_analyser.h"
// #include "adc.h"
// #include "oscilloscope.h"
// #include "AWG.h"
// #include "settings.h"
#define VERSION "0.01"
#include <stdio.h>
#include <pico/stdlib.h>
#include "Communication.h"
#include "Main.h"

void Init(){
  //if(!stdio_usb_init()){Error_Handler(USB_INIT);}

  stdio_usb_init();
  //init_dma();
  //init_adc();
  //init_spectrum_analyser();
  //init_oscilloscope();
  //init_AWG();
}

void Print_Logo(){
  printf("%s\n\r",Logo);
  printf("V%s\n\r",VERSION);
}

int main() {
    Init();
    sleep_ms(1000);
    Print_Logo();

    while(true) {

      Serial_in_Handler_Async();
      if(Ready_DataIn()){
      char* a = Get_DataIn();
      printf("%s\n",a);
      }
      }
    return 0;
}





