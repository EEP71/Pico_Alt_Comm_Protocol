#ifndef COMMUNICATION_H
#define COMMUNICATION_H

void Serial_in_Handler_Async();
void Serial_in_Handler();

void Serial_out_Handler_Async();
void Serial_out_Handler();

char* Get_DataIn();
void Clear_DataIn();
bool Ready_DataIn();

#endif