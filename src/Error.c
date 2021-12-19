#include "Error.h"

//TODO Add SB_Main Error Handler From STM32

void Error_Handler(Status_Codes Code){
  while(1){
    switch (Code){
        //TODO Blink Led In pattern Or Print Error;
      case USB_INIT:{
        
      }
      break;
      case ADC_INIT:{
        
      }
      break;
      case DAC_INIT:{
        
      }
      break;
      case OSC_INIT:{
        
      }
      break;
      case AWG_INIT:{
        
      }
      break;
      case SA_INIT:{
        
      }
      break;
    }
  }
}