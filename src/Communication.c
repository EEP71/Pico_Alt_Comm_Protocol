#include <pico/stdlib.h>
#include <stdio.h>
#include "Communication.h"

#define SERIAL_IN_PACKET_SIZE_BYTES (uint8_t)32
#define PACKET_VALID_MAGIC_NUM (uint16_t)0x7FFF

#define DEV_ID_BYTE 0
#define DEV_OPTION_BYTE 1

//Expected Values's For Data[0]
#define NUM_OF_DEVICES 7
#define NUM_OF_OPTIONS 4

#define SYS_ID 0
#define DAC_ID 1
#define ADC_ID 2
#define AWG_ID 3
#define OSC_ID 4
#define SA_ID 5
#define LIA_ID 6

#define CONF 0
#define START 1
#define STOP 2
#define RESET 3

//Expected Values's For Data[1]
#define DEV_CONF 0
#define DEV_START 1
#define DEV_STOP 2
#define DEV_Reset 3

uint8_t Data[32];
uint8_t Target;
uint8_t Option;
bool Ready;



//SA Needs 8 Bytes

float SA_SampleRate = 0;
uint16_t SA_CaptureDepth = 0;
uint8_t SA_Amplification = 0;
uint8_t SA_ActiveChannels = 0;

//AWG Needs 9 Bytes

uint32_t AWG_Frequency = 0;
uint16_t AWG_PeakToPeak = 0;
uint8_t AWG_WaveType = 0;
uint8_t AWG_ActiveChannels = 0;
uint8_t AWG_Amplification = 0;

//SA Needs 8 Bytes

uint16_t OSC_mSecPerDiv = 0;
uint16_t OSC_mVoltPerDiv = 0;
uint16_t OSC_Trigger = 0;
uint8_t OSC_Direction = 0;
uint8_t OSC_Amplification = 0;

//LIA Stub needs 20 Bytes

uint32_t LOI_Stub1 = 0;
uint32_t LOI_Stub2 = 0;
uint32_t LOI_Stub3 = 0;
uint32_t LOI_Stub4 = 0;
uint32_t LOI_Stub5 = 0;


//AWG Func

void AWG_Start(){
  printf("AWG_START!\n");
}

void AWG_Stop(){
  printf("AWG_STOP!\n");
}

void AWG_Reset(){
  printf("AWG_RESET!\n");
}

//SA Func

void SA_Start(){
  printf("SA_START!\n");
}

void SA_Stop(){
  printf("SA_STOP!\n");
}

void SA_Reset(){
  printf("SA_RESET!\n");
}

//OSC Func

void OSC_Start(){
   printf("OSC_START!\n");
}

void OSC_Stop(){
   printf("OSC_STOP!\n");
}

void OSC_Reset(){
   printf("OSC_RESET!\n");
}

//OSC Func

void LIA_Start(){
   printf("LIA_START!\n");
}

void LIA_Stop(){
   printf("LIA_STOP!\n");
}

void LIA_Reset(){
   printf("LIA_RESET!\n");
}

/* Serial Data Spec.
 * [0] Peripheral ID - Can Refer to Specific HW or SW Components
 * [1] Data Type - Config Data 0x00, Start 0x01, Stop 0x02, Reset Config 0x03
 * [2-29] Encoded Data [Data format will be descripted in the relevant Section]
 * [30-31] - Padding, Signifies End Of transaction Must be 0x7FFF. (Also used as a cheap way to verity packet validity)
 */ 

//We need stdio_get_until(); But that func. is not exposed to us. getchar_timeout_us(); Wraps this function with a useles timeout feature.
//This can be fixed by adding the function to a header but that requires modifying the SDK, For compatibility reasons its best to avoid doing that.

//Will Read 1 Byte From Serial Buffer Each Time its called if we have recieved 24 bytes Check if the magic number exists and if it does Set the ready flag.
void  Serial_in_Handler_Async(){

  static uint8_t Bytes_Read;  
  int16_t Temp = getchar_timeout_us(0);

  if (Temp == PICO_ERROR_TIMEOUT) {return;}

  Data[Bytes_Read++] = Temp;
  
  if (Bytes_Read == SERIAL_IN_PACKET_SIZE_BYTES){
    //Check last 2 bytes for Required Value

    Bytes_Read = 0;

    if (Packet_Check()){
     Ready = true;
     return;
    }
    Ready = false;
  }
}

//Will Read 24 Bytes From Serial Buffer Each Time its called. If during any point in reading said buffer an invallid character is read, we exit.
//Else we proceed With the packet Check.
void Serial_in_Handler(){

  for(uint8_t Bytes_recieved = 0; Bytes_recieved < (SERIAL_IN_PACKET_SIZE_BYTES); Bytes_recieved++){
    int16_t Temp = getchar_timeout_us(0);
    if (Temp == PICO_ERROR_TIMEOUT) {return;}
    Data[Bytes_recieved] = (uint8_t)Temp;
}
  if (Packet_Check()){
    Ready = true;
    return;
  }
  Ready = false;
}

//Checks the last 2 bytes of our buffer for the magic number 0x7FFF
bool Packet_Check(){
 
  if (PACKET_VALID_MAGIC_NUM == ((Data[SERIAL_IN_PACKET_SIZE_BYTES-2] << 8) | Data[SERIAL_IN_PACKET_SIZE_BYTES-1])){
    return true;
  }
  printf("Packet Error\n");
  return false;
}

//Returns The Pointer To Our Data array. If the data is not ready a nullptr is returned.
//If the data is ready
char* DataIn_Get(){
  if(!Ready){return NULL;}
  return Data;
}

//Clear Data and set the ready flag to false
void DataIn_Clear(){
  for(uint8_t i = 0; i <= SERIAL_IN_PACKET_SIZE_BYTES-1; i++){
    Data[i] = (uint8_t)0;
  }
  Ready = false;
}


bool DataIn_IsReady(){
  return Ready;
}

bool DataIn_ClearReady(){
  Ready = false;
}

bool Decode_Packet(char* Dat){

  if(Dat[DEV_ID_BYTE] > NUM_OF_DEVICES){
    //TODO Throw Decode Error Device
    return false;
    }
  if(Dat[DEV_OPTION_BYTE] > NUM_OF_OPTIONS){
    //TODO Throw Decode Error Device
    return false;
    }

  switch (Dat[DEV_OPTION_BYTE]){
    //Check Option First
    case CONF:{

      switch (Dat[DEV_ID_BYTE]){

        case SYS_ID:{break;}

        case DAC_ID:{break;}

        case ADC_ID:{break;}

        case AWG_ID:{
          AWG_Frequency = (Dat[2] << 24) | (Dat[3] << 16) | (Dat[4] << 8) | Dat[5];
          AWG_PeakToPeak = (Dat[6] << 8) | Dat[7];
          AWG_WaveType = Dat[8];
          AWG_ActiveChannels = Dat[9];
          AWG_Amplification = Dat[10];
          break;
        }

        case OSC_ID:{
          OSC_mSecPerDiv = (Dat[2] << 8) | Dat[3];
          OSC_mVoltPerDiv = (Dat[4] << 8) | Dat[5];
          OSC_Trigger = (Dat[6] << 8) | Dat[7];
          OSC_Direction = Dat[8];
          OSC_Amplification = Dat[9];
          break;
        }
        
        case SA_ID:{
          SA_SampleRate = (Dat[2] << 24) | (Dat[3] << 16) | (Dat[4] << 8) | Dat[5];
          SA_CaptureDepth = (Dat[6] << 8) | Dat[7];
          SA_Amplification = Dat[8];
          SA_ActiveChannels = Dat[9];
          break;
        }
        
        case LIA_ID:{
          LOI_Stub1 = (Dat[2] << 24) | (Dat[3] << 16) | (Dat[4] << 8) | Dat[5];
          LOI_Stub2 = (Dat[6] << 24) | (Dat[7] << 16) | (Dat[8] << 8) | Dat[9];
          LOI_Stub3 = (Dat[10] << 24) | (Dat[11] << 16) | (Dat[12] << 8) | Dat[13];
          LOI_Stub4 = (Dat[14] << 24) | (Dat[15] << 16) | (Dat[16] << 8) | Dat[17];
          LOI_Stub5 = (Dat[18] << 24) | (Dat[19] << 16) | (Dat[20] << 8) | Dat[21];
          break;
        }
      }
      break;
    }

    case START:{
      switch (Dat[DEV_ID_BYTE]){

        case AWG_ID:{AWG_Start(); break;}

        case OSC_ID:{OSC_Start(); break;}
        
        case SA_ID:{SA_Start(); break;}
        
        case LIA_ID:{LIA_Start(); break;}
      }
      break;
    }

    case STOP:{
       switch (Dat[DEV_ID_BYTE]){

        case AWG_ID:{AWG_Stop(); break;}

        case OSC_ID:{OSC_Stop(); break;}
        
        case SA_ID:{SA_Stop(); break;}
        
        case LIA_ID:{LIA_Stop(); break;}
      }
      break;
    }

    case RESET:{

      switch (Dat[DEV_ID_BYTE]){

        case AWG_ID:{AWG_Reset(); break;}

        case OSC_ID:{OSC_Reset(); break;}
        
        case SA_ID:{SA_Reset(); break;}
        
        case LIA_ID:{LIA_Reset(); break;} 
      }
      break;
    }
  }
 return true;
}

void Debug_OSC(){
  printf("-- OSC Config Data -- \n\r mSec/Div: %d \n\r mVolt/Div: %d \n\r Trigger: %d \n\r Direction: %d \n\r Amplification: %d \n\r",OSC_mSecPerDiv,OSC_mVoltPerDiv,OSC_Trigger,OSC_Direction,OSC_Amplification);
  Ready = false;
  DataIn_Clear();
}

void Debug_AWG(){
  
}

void Debug_LIA(){
  
}

void Debug_SA(){
  
}