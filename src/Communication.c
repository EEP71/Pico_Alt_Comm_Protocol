#include <pico/stdlib.h>
#include <stdio.h>
#include "Communication.h"

#define SERIAL_IN_PACKET_SIZE_BYTES (uint8_t)8
#define PACKET_VALID_MAGIC_NUM (uint16_t)0x7FFF

uint8_t Data[64];
bool Ready;

bool Packet_Check();

/* Serial Data Spec.
 * [0] Peripheral ID - Can Refer to Specific HW or SW Components
 * [1] Data Type - Config Data 0x00, Start 0x01, Stop 0x02, Reset Config 0x03
 * [2-61] Encoded Data [Data format will be descripted in the relevant Section]
 * [62-63] - Padding, Signifies End Of transaction Must be 0x7FFF. (Also used as a cheap way to verity packet validity)
 */ 

//We need stdio_get_until() But that func. is not exposed to us. getchar_timeout_us(); Wraps this function with a useles timeout feature.
//This can be fixed by adding the function to a header but that requires modifying the SDK, For compatibility reasons its best to avoid doing that.


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

bool Packet_Check(){
 
  if (PACKET_VALID_MAGIC_NUM == ((Data[SERIAL_IN_PACKET_SIZE_BYTES-2] << 8) | Data[SERIAL_IN_PACKET_SIZE_BYTES-1])){return true;}
  printf("Packet Error\n");
  return false;
}

char* Get_DataIn(){
  if(!Ready){return NULL;}

  Ready = false;
  Clear_DataIn();
  return Data;
}

void Clear_DataIn(){
  for(uint8_t i = 0; i >= SERIAL_IN_PACKET_SIZE_BYTES; i++){
    Data[i] = 0x00;
  }
}

bool Ready_DataIn(){
  return Ready;
}

void Packet_Constructor(){

  
}