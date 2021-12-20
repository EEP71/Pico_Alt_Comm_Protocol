#ifndef COMMUNICATION_H
#define COMMUNICATION_H

void Serial_in_Handler_Async();
void Serial_in_Handler();

void Serial_out_Handler_Async();
void Serial_out_Handler();

char* DataIn_Get();
void DataIn_Clear();

void Debug_OSC();
bool Packet_Check();

bool Decode_Packet(char* Dat);

bool DataIn_IsReady();

bool DataIn_ClearReady();


#endif