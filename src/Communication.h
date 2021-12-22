#ifndef COMMUNICATION_H
#define COMMUNICATION_H

void Serial_in_Handler_Async();
void Serial_in_Handler();

char* DataIn_Get();
bool  DataIn_IsReady();
void  DataIn_Clear();
void  DataIn_ClearReady();

bool Packet_Check();
uint8_t Packet_Decode();

void Serial_Out_32(uint8_t Device,uint8_t Channel, uint32_t Data);
void Serial_Out_16(uint8_t Device, uint8_t Channel, uint16_t Data);
void Serial_Out_8(uint8_t Device, uint8_t Channel, uint8_t Data);
void Serial_Response(uint8_t Device, uint8_t Code);

#endif