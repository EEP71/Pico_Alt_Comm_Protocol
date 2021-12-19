#ifndef ERROR_H
#define ERROR_H

/* --Error Types
* INIT - Only ocurs when initializing a peripheral.
* GEN - Generic fault occured during runtime.
* CONF - Invallid or corrupt Configuration.
*/


const typedef enum {USB_INIT, ADC_INIT, DAC_INIT, AWG_INIT, SA_INIT, LOA_INIT, OSC_INIT, DMA_INIT,
              SYS_GEN, USB_GEN, ADC_GEN, DAC_GEN, AWG_GEN, SA_GEN, LOA_GEN, OSC_GEN, DMA_GEN,
              SYS_CONF, USB_CONF, ADC_CONF, DAC_CONF, AWG_CONF, SA_CONF, LOA_CONF, OSC_CONF, DMA_CONF}
Status_Codes;


void Error_Handler(Status_Codes Code);

#endif