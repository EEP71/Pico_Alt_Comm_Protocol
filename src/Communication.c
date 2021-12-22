#include <pico/stdlib.h>
#include <stdio.h>
#include "Communication.h"
#include "Globals.h"
#include "Scope.h"
#include "Analyzer.h"
#include "AWG.h"
#include "LIA.h"


#define SERIAL_IN_PACKET_SIZE_BYTES (uint8_t)32
#define PACKET_VALID_MAGIC_NUM (uint16_t)0x7FFF



uint8_t TestArray[4096];


uint8_t Data_In[SERIAL_IN_PACKET_SIZE_BYTES];
uint8_t Dev_Target;
uint8_t Dev_Option;
bool Data_In_Ready;

//!We need stdio_get_until(); But that func. is not exposed to us. getchar_timeout_us(); Wraps this function with a useles timeout feature.
//!This can be fixed by adding the function to a header but that requires modifying the SDK, For compatibility reasons its best to avoid doing that.

/* Serial Data Spec.
 * [0] Peripheral ID - Can Refer to Specific HW or SW Components
 * [1] Data Type - Config Data 0x00, Start 0x01, Stop 0x02, Reset Config 0x03
 * [2-29] Encoded Data [Data format will be descripted in the relevant Section]
 * [30-31] - Padding, Signifies End Of transaction Must be 0x7FFF. (Also used as a cheap way to verity packet validity)
 */ 

/*
 * Reads 1 byte from the serial buffer on each call.
 * If enough bytes have been read (As defined by SERIAL_IN_PACKET_SIZE_BYTES)
 * the ready flag will be set and the data can be read with DataIn_Get();
 * If the data is not ready or the packet verification has failed a nullptr is returned.
*/
void  Serial_in_Handler_Async(){

  static uint8_t Bytes_Read;  
  int16_t Temp = getchar_timeout_us(0);

  if (Temp == PICO_ERROR_TIMEOUT) {return;}

  Data_In[Bytes_Read++] = Temp;
  
  if (Bytes_Read == SERIAL_IN_PACKET_SIZE_BYTES){
    
    Bytes_Read = 0;

    //Check last 2 bytes for Required Value
    if (Packet_Check()){
     Data_In_Ready = true;
     return;
    }
    Data_In_Ready = false;
  }
}

//Will Read 24 Bytes From Serial Buffer Each Time its called. If during any point in reading said buffer an invallid character is read, we exit.
//Else we proceed With the packet Check.
void Serial_in_Handler(){

  for(uint8_t Bytes_recieved = 0; Bytes_recieved < (SERIAL_IN_PACKET_SIZE_BYTES); Bytes_recieved++){
    int16_t Temp = getchar_timeout_us(0);
    if (Temp == PICO_ERROR_TIMEOUT) {return;}
    Data_In[Bytes_recieved] = (uint8_t)Temp;
}
  if (Packet_Check()){
    Data_In_Ready = true;
    return;
  }
  Data_In_Ready = false;
}

//Checks the last 2 bytes of our buffer for the magic number 0x7FFF
bool Packet_Check(){
 
  if (PACKET_VALID_MAGIC_NUM == ((Data_In[SERIAL_IN_PACKET_SIZE_BYTES-2] << 8) | Data_In[SERIAL_IN_PACKET_SIZE_BYTES-1])){
    return true;
  }
  printf("Packet Error\n");
  return false;
}

//Returns The Pointer To Our Data array. If the data is not ready a nullptr is returned.
//If the data is ready
char* DataIn_Get(){
  if(!Data_In_Ready){return NULL;}
  Data_In_Ready = false;
  return Data_In;
}

//Clear Data and set the ready flag to false
void DataIn_Clear(){
  for(uint8_t i = 0; i <= SERIAL_IN_PACKET_SIZE_BYTES-1; i++){
    Data_In[i] = (uint8_t)0;
  }
  Data_In_Ready = false;
}

bool DataIn_IsReady(){
  return Data_In_Ready;
}

void DataIn_ClearReady(){
  Data_In_Ready = false;
}


/* 
 * Decodes an incoming data packet.
 * Based on the contents of said packet an action is taken.
 * The only checks that take place are for a valid device ID
 * and option byte, no integrity check for the data itself is done.
 * This will have to be done by the peripheral itself.
 * Returns false if the 1st two bytes are invallid otherwise a true is returned.
 */ 
uint8_t Packet_Decode(){

  if(Data_In[DEV_ID_BYTE] > NUM_OF_DEVICES){
    return false;
    }
  if(Data_In[DEV_OPTION_BYTE] > NUM_OF_OPTIONS){
    return false;
    }

  switch (Data_In[DEV_OPTION_BYTE]){
    //Check Option First
    case DEV_CONF:{

      switch (Data_In[DEV_ID_BYTE]){
        case SYS_ID:{break;}
        case DAC_ID:{break;}
        case ADC_ID:{break;}

        case AWG_ID:{
          AWG_FrequencyCh1 =    (Data_In[2] << 24) | (Data_In[3] << 16) | (Data_In[4] << 8) | Data_In[5];
          AWG_FrequencyCh2 =    (Data_In[6] << 24) | (Data_In[7] << 16) | (Data_In[8] << 8) | Data_In[9];
          AWG_PeakToPeakCh1 =   (Data_In[10] << 8) | Data_In[11];
          AWG_PeakToPeakCh2 =   (Data_In[12] << 8) | Data_In[13];
          AWG_WaveTypeCh1 =      Data_In[14];
          AWG_WaveTypeCh2 =      Data_In[15];
          AWG_AmplificationCh1 = Data_In[16];
          AWG_AmplificationCh2 = Data_In[17];
          AWG_ActiveChannels =   Data_In[18];
          AWG_Configure();
          return RESPONSE_CONFIG_OK;
          break;
        }

        case OSC_ID:{
          OSC_mSecPerDivCh1 =   (Data_In[2] << 8)  | Data_In[3];
          OSC_mSecPerDivCh2 =   (Data_In[4] << 8)  | Data_In[5];
          OSC_mVoltPerDivCh1 =  (Data_In[6] << 8)  | Data_In[7];
          OSC_mVoltPerDivCh2 =  (Data_In[8] << 8)  | Data_In[9];
          OSC_TriggerCh1 =      (Data_In[10] << 8) | Data_In[11];
          OSC_TriggerCh2 =      (Data_In[12] << 8) | Data_In[13];
          OSC_DirectionCh1 =     Data_In[14];
          OSC_DirectionCh2 =     Data_In[15];
          OSC_AmplificationCh1 = Data_In[16];
          OSC_AmplificationCh2 = Data_In[17];
          OSC_Configure();

          break;
        }
        
        case SA_ID:{
          SA_SampleRateCh1 =   (Data_In[2] << 24) | (Data_In[3] << 16) | (Data_In[4] << 8) | Data_In[5];
          SA_SampleRateCh2 =   (Data_In[6] << 24) | (Data_In[7] << 16) | (Data_In[8] << 8) | Data_In[9];
          SA_CaptureDepthCh1 = (Data_In[10] << 8) | Data_In[11];
          SA_CaptureDepthCh2 = (Data_In[12] << 8) | Data_In[13];
          SA_AmplificationCh1 = Data_In[14];
          SA_AmplificationCh2 = Data_In[15];
          SA_ActiveChannels =   Data_In[16];
          SA_Configure();

          break;
        }
        
        case LIA_ID:{
          LOI_Stub1 = (Data_In[2] << 24)  | (Data_In[3] << 16)  | (Data_In[4] << 8)  | Data_In[5];
          LOI_Stub2 = (Data_In[6] << 24)  | (Data_In[7] << 16)  | (Data_In[8] << 8)  | Data_In[9];
          LOI_Stub3 = (Data_In[10] << 24) | (Data_In[11] << 16) | (Data_In[12] << 8) | Data_In[13];
          LOI_Stub4 = (Data_In[14] << 24) | (Data_In[15] << 16) | (Data_In[16] << 8) | Data_In[17];
          LOI_Stub5 = (Data_In[18] << 24) | (Data_In[19] << 16) | (Data_In[20] << 8) | Data_In[21];
          LIA_Configure();

          break;
        }
        default:{return RESPONSE_CONFIG_FAIL;}
        return RESPONSE_CONFIG_OK;
      }
      break;
    }

    case DEV_START:{
      switch (Data_In[DEV_ID_BYTE]){
        case AWG_ID:{AWG_Start(); break;}
        case OSC_ID:{OSC_Start(); break;}
        case SA_ID: {SA_Start();  break;}
        case LIA_ID:{LIA_Start(); break;}
      }
      return RESPONSE_START_OK;
      break;
    }

    case DEV_STOP:{
       switch (Data_In[DEV_ID_BYTE]){
        case AWG_ID:{AWG_Stop(); break;}
        case OSC_ID:{OSC_Stop(); break;}
        case SA_ID: {SA_Stop();  break;}
        case LIA_ID:{LIA_Stop(); break;}
      }
      return RESPONSE_STOP_OK;
      break;
    }

    case DEV_RESET:{
      switch (Data_In[DEV_ID_BYTE]){
        case AWG_ID:{AWG_Reset(); break;}
        case OSC_ID:{OSC_Reset(); break;}
        case SA_ID: {SA_Reset();  break;}
        case LIA_ID:{LIA_Reset(); break;} 
      }
      return RESPONSE_RESET_OK;
      break;
    }
    default:{return RESPONSE_OPTION_FAIL;}
  }
 return true;
}

/*
* -- Serial Out -- 
* Consists of 4 functions:
* * Data Packets of 4 to 1 Bytes
* * Status Code
* Every transfer comes with a single byte denoting its type.
* The 2 MSB Bits define one of the 4 possible functions with:
* * 00/000000 - Response
* * 01/000000 - 1 Byte
* * 10/000000 - 2 Bytes
* * 11/000000 - 4 Bytes
* The 1st 3 LSB Bits define the source of the data which 
* folows the same structure as the Device ID's Defined in Globals.h
* Namely:
* * 00000/000 - System
* * 00000/001 - DAC HW
* * 00000/010 - ADC HW
* * 00000/011 - AWG SW
* * 00000/100 - OSC SW
* * 00000/101 - SA SW
* * 00000/110 - LIA
* * 00000/111 - (Unused)
* The 4th Bit defines the channel source of the 4 DSP components
* With:
* * 0000/0/000 - Channel 1
* * 0000/1/000 - Channel 2
* The 5th and 6th bits are unused.
* Example: 11001100 = 32bit data from the Osciloscope on channel 2
*/
void Serial_Out_32(uint8_t Device,uint8_t Channel, uint32_t Data){
  uint8_t Temp = (0b11 << 6) + (Channel << 3) + Device;
  putchar_raw(Temp);
  putchar_raw((uint8_t)(Data >> 24) & 0xFF);
  putchar_raw((uint8_t)(Data >> 16) & 0xFF);
  putchar_raw((uint8_t)(Data >> 8) & 0xFF);
  putchar_raw((uint8_t) Data & 0xFF);
}

void Serial_Out_16(uint8_t Device, uint8_t Channel, uint16_t Data){
  uint8_t Temp = (0b10 << 6) + (Channel << 3) + Device;
  putchar_raw(Temp);
  putchar_raw((uint8_t)(Data >> 8) & 0xFF);
  putchar_raw((uint8_t) Data & 0xFF);
}

void Serial_Out_8(uint8_t Device, uint8_t Channel, uint8_t Data){
  uint8_t Temp = (0b01 << 6) + (Channel << 3) + Device;
  putchar_raw(Temp);
  putchar_raw((uint8_t) Data & 0xFF);
}

void Serial_Response(uint8_t Device, uint8_t Code){
  uint8_t Temp = (0b00 << 6) + Device;
  putchar_raw(Temp);
  putchar_raw(Code);
}