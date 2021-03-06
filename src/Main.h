#ifndef MAIN_H
#define MAIN_H

//!! Main.h must only be included with Main.c !!

const char Logo[] = { 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 
                      0x5F, 0x20, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 
                      0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x0A, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x5C, 
                      0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x20, 0x5C, 0x20, 0x2F, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x7C, 0x20, 
                      0x20, 0x5F, 0x5F, 0x20, 0x5C, 0x20, 0x0A, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 
                      0x20, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x7C, 
                      0x20, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x5F, 0x5F, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x0A, 0x20, 
                      0x7C, 0x20, 0x20, 0x5F, 0x20, 0x20, 0x2F, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 
                      0x2F, 0x20, 0x7C, 0x2F, 0x20, 0x5F, 0x5F, 0x2F, 0x20, 0x5F, 0x20, 0x5C, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x5C, 
                      0x5F, 0x5F, 0x5F, 0x20, 0x5C, 0x7C, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x0A, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x5C, 0x20, 0x5C, 0x7C, 
                      0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x7C, 0x20, 
                      0x28, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x5F, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x7C, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x7C, 0x5F, 0x7C, 0x5F, 0x5F, 0x5C, 0x5F, 0x5C, 0x5F, 0x7C, 0x20, 0x20, 0x20, 0x7C, 0x5F, 0x7C, 
                      0x20, 0x7C, 0x5F, 0x7C, 0x5F, 0x20, 0x20, 0x7C, 0x5F, 0x7C, 0x5C, 0x5F, 0x5F, 0x5F, 0x5C, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x20, 0x7C, 0x5F, 
                      0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x7C, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x7C, 0x5F, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x7C, 
                      0x5F, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x20,
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x5F, 0x5F, 
                      0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 
                      0x20, 0x20, 0x5F, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x7C, 0x2F, 0x20, 0x5F, 0x20, 0x5C, 0x20, 0x2F, 0x20, 0x5F, 0x20, 0x5C, 
                      0x7C, 0x20, 0x7C, 0x20, 0x27, 0x5F, 0x20, 0x5C, 0x20, 0x2F, 0x20, 0x5F, 0x20, 0x5C, 0x20, 0x5C, 0x2F, 0x20, 0x2F, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 
                      0x20, 0x7C, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x7C, 0x20, 0x7C, 0x20, 0x7C, 0x5F, 0x29, 0x20, 
                      0x7C, 0x20, 0x28, 0x5F, 0x29, 0x20, 0x3E, 0x20, 0x20, 0x3C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x5F, 0x7C, 0x5C, 0x5F, 0x5F, 0x5F, 
                      0x2F, 0x20, 0x5C, 0x5F, 0x5F, 0x5F, 0x2F, 0x7C, 0x5F, 0x7C, 0x5F, 0x2E, 0x5F, 0x5F, 0x2F, 0x20, 0x5C, 0x5F, 0x5F, 0x5F, 0x2F, 0x5F, 0x2F, 
                      0x5C, 0x5F, 0x5C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
                      0x20, 0x20, 0x20};


//----Global Variable Declaration

//SA
float    SA_SampleRateCh1 = 0;
float    SA_SampleRateCh2 = 0;
uint16_t SA_CaptureDepthCh1 = 0;
uint16_t SA_CaptureDepthCh2 = 0;
uint8_t  SA_AmplificationCh1 = 0;
uint8_t  SA_AmplificationCh2 = 0;
uint8_t  SA_ActiveChannels = 0;

//AWG
uint32_t AWG_FrequencyCh1 = 0;
uint32_t AWG_FrequencyCh2 = 0;
uint16_t AWG_PeakToPeakCh1 = 0;
uint16_t AWG_PeakToPeakCh2 = 0;
uint8_t  AWG_WaveTypeCh1 = 0;
uint8_t  AWG_WaveTypeCh2 = 0;
uint8_t  AWG_AmplificationCh1 = 0;
uint8_t  AWG_AmplificationCh2 = 0;
uint8_t  AWG_ActiveChannels = 0;

//OSC
uint16_t OSC_mSecPerDivCh1 = 0;
uint16_t OSC_mSecPerDivCh2 = 0;
uint16_t OSC_mVoltPerDivCh1 = 0;
uint16_t OSC_mVoltPerDivCh2 = 0;
uint16_t OSC_TriggerCh1 = 0;
uint16_t OSC_TriggerCh2 = 0;
uint8_t  OSC_DirectionCh1 = 0;
uint8_t  OSC_DirectionCh2 = 0;
uint8_t  OSC_AmplificationCh1 = 0;
uint8_t  OSC_AmplificationCh2 = 0;
uint8_t  OSC_ActiveChannels = 0;

//LIA
uint32_t LOI_Stub1 = 0;
uint32_t LOI_Stub2 = 0;
uint32_t LOI_Stub3 = 0;
uint32_t LOI_Stub4 = 0;
uint32_t LOI_Stub5 = 0;

//Global Variable Declaration----


void Init();
void Print_Logo();
void Handle_Data_In();

#endif