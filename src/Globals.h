#ifndef GLOBALS_H
#define GLOBALS_H

//----Communication Protocol

#define DEV_ID_BYTE 0
#define DEV_OPTION_BYTE 1

//Option Byte
#define DEV_CONF  0
#define DEV_START 1
#define DEV_STOP  2
#define DEV_RESET 3

//Expected Values's For Data_in[0]
#define NUM_OF_DEVICES 7
#define NUM_OF_OPTIONS 4

//Device ID's
#define SYS_ID 0
#define DAC_ID 1
#define ADC_ID 2
#define AWG_ID 3
#define OSC_ID 4
#define SA_ID  5
#define LIA_ID 6

//Responce Codes
#define RESPONSE_OK 127
#define RESPONSE_CONFIG_OK 127
#define RESPONSE_START_OK 127
#define RESPONSE_STOP_OK 127
#define RESPONSE_RESET_OK  127

#define RESPONSE_STOP_FAIL 128
#define RESPONSE_START_FAIL 128
#define RESPONSE_CONFIG_FAIL 128
#define RESPONSE_OPTION_FAIL 128
#define RESPONSE_FAIL 128

//#define RESPONSE_FAIL 255
#define RESPONSE_ID 0x00

//Communication Protocol----

//----Device Config Variables

//SA
extern float    SA_SampleRateCh1;
extern float    SA_SampleRateCh2;
extern uint16_t SA_CaptureDepthCh1;
extern uint16_t SA_CaptureDepthCh2;
extern uint8_t  SA_AmplificationCh1;
extern uint8_t  SA_AmplificationCh2;
extern uint8_t  SA_ActiveChannels;

//AWG
extern uint32_t AWG_FrequencyCh1;
extern uint32_t AWG_FrequencyCh2;
extern uint16_t AWG_PeakToPeakCh1;
extern uint16_t AWG_PeakToPeakCh2;
extern uint8_t  AWG_WaveTypeCh1;
extern uint8_t  AWG_WaveTypeCh2;
extern uint8_t  AWG_AmplificationCh1;
extern uint8_t  AWG_AmplificationCh2;
extern uint8_t  AWG_ActiveChannels;

//OSC
extern uint16_t OSC_mSecPerDivCh1;
extern uint16_t OSC_mSecPerDivCh2;
extern uint16_t OSC_mVoltPerDivCh1;
extern uint16_t OSC_mVoltPerDivCh2;
extern uint16_t OSC_TriggerCh1;
extern uint16_t OSC_TriggerCh2;
extern uint8_t  OSC_DirectionCh1;
extern uint8_t  OSC_DirectionCh2;
extern uint8_t  OSC_AmplificationCh1;
extern uint8_t  OSC_AmplificationCh2;
extern uint8_t  OSC_ActiveChannels;

//LIA
extern uint32_t LOI_Stub1;
extern uint32_t LOI_Stub2;
extern uint32_t LOI_Stub3;
extern uint32_t LOI_Stub4;
extern uint32_t LOI_Stub5;

//Device Config Variables----


//??What to do with these :thinking:
#define HIGHEST_CAPTURE_DEPTH 3000
#define DEFAULT_CAPTURE_DEPTH 1000
#define DEFAULT_CLOCK_DEVIDE  960
extern int capture_depth;
extern int clock_divide;

extern uint16_t capture_buf[HIGHEST_CAPTURE_DEPTH];
#endif