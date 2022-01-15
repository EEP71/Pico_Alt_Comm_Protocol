import serial
import time
import sys
import threading



Datatmp = bytes([0x00]*28)
Magic_Bytes = bytes([0x7F,0xFF])
Peripheral_ID = bytes([0x00])
Peripheral_Data = bytes([0x00])

class PicoCom:

    DEV_ID_BYTE = 0
    DEV_OPTION_BYTE = 1

    DEV_CONF  = 0
    DEV_START = 1
    DEV_STOP  = 2
    DEV_RESET = 3

    NUM_OF_DEVICES = 7
    NUM_OF_OPTIONS = 4

    AWG_ID = 3
    OSC_ID = 4
    SA_ID  = 5
    LIA_ID = 6
  
    RESPONSE_OK = 127
    RESPONSE_CONFIG_OK = 128
    RESPONSE_START_OK = 129
    RESPONSE_STOP_OK = 130
    RESPONSE_RESET_OK  = 131

    RESPONSE_STOP_FAIL = 122
    RESPONSE_START_FAIL = 123
    RESPONSE_CONFIG_FAIL = 124
    RESPONSE_OPTION_FAIL = 125
    RESPONSE_FAIL = 126
    
    SA_SampleRateCh1 = 32 ##32
    SA_SampleRateCh2 = 64 ##32
    SA_CaptureDepthCh1 = 1 ##16
    SA_CaptureDepthCh2 = 2 ##16
    SA_AmplificationCh1 = 3 ##8
    SA_AmplificationCh2 = 4 ##8
    SA_ActiveChannels = 5 ##8

    AWG_FrequencyCh1 = 1 ##32
    AWG_FrequencyCh2 = 2 ##32
    AWG_PeakToPeakCh1 = 3 ##16
    AWG_PeakToPeakCh2 = 4 ##16
    AWG_WaveTypeCh1 = 5 ##8
    AWG_WaveTypeCh2 = 6 ##8
    AWG_AmplificationCh1 = 7 ##8
    AWG_AmplificationCh2 = 8 ##8
    AWG_ActiveChannels = 9 ##8

    OSC_mSecPerDivCh1 = 1 ##16
    OSC_mSecPerDivCh2 = 2 ##16
    OSC_mVoltPerDivCh1 = 3 ##16
    OSC_mVoltPerDivCh2 = 4 ##16
    OSC_TriggerCh1 = 5 ##16
    OSC_TriggerCh2 = 6 ##16
    OSC_DirectionCh1 = 7 ##8
    OSC_DirectionCh2 = 8 ##8
    OSC_AmplificationCh1 = 9 ##8
    OSC_AmplificationCh2 = 10 ##8
    OSC_ActiveChannels = 11 ##8

    LOI_Stub1 = 115 ##32
    LOI_Stub2 = 214 ##32
    LOI_Stub3 = 313 ##32
    LOI_Stub4 = 412 ##32
    LOI_Stub5 = 511 ##32
    
    OSC_Ch1 = 0
    OSC_Ch2 = 0
    
    SA_Ch1 = 0
    SA_Ch2 = 0
    
    LIA_Ch1 = 0
    LIA_Ch2 = 0
    
    AWG_Ch1 = 0
    AWG_Ch2 = 0
    

    def send_packet(self,ID,Type,Data_Config,Data_Length):
        Data = bytes()
        ## Convert to bytes just to be sure
        ID_b = ID.to_bytes(1, 'big')
        Type_b = Type.to_bytes(1, 'big')
        ## Concatinate Data out array
        Data += ID_b
        Data += Type_b
        
        Data += Data_Config
        Data += bytes(28-Data_Length)
        Data += Magic_Bytes
        
        print("Data Sent: " + Data.hex())
        ##Send Data Array And read status code back
        self.Pico_Serial.write(bytes(Data))
        tmp = self.Pico_Serial.read(2).hex()
        print("Data Recieved: " + tmp)
        

    def __init__(self):
        self.Pico_Serial = serial.Serial("COM7", timeout=0)
        print("Pi Pico is on: " + self.Pico_Serial.name)
        
    def Start_Dev(self,ID):
        print("Start: " + str(ID))
        Data_Conf = bytes()
        ##print("Raw Config Data: " + Data_Conf.hex() + " / Length: " + str(len(Data_Conf)) + " Bytes")
        self.send_packet(ID,self.DEV_START,Data_Conf,len(Data_Conf))
   
    def Stop_Dev(self,ID):
        print("Stop: " + str(ID))
        Data_Conf = bytes()
       ## print("Raw Config Data: " + Data_Conf.hex() + " / Length: " + str(len(Data_Conf)) + " Bytes")
        self.send_packet(ID,self.DEV_STOP,Data_Conf,len(Data_Conf))
   
    def Reset_Dev(self,ID):
        print("Reset: " + str(ID))
        Data_Conf = bytes()
        ##print("Raw Config Data: " + Data_Conf.hex() + " / Length: " + str(len(Data_Conf)) + " Bytes")
        self.send_packet(ID,self.DEV_RESET,Data_Conf,len(Data_Conf))
    
    def Config_AWG(self):
    
        Data_Conf = bytes()
        
        Data_Conf += self.AWG_FrequencyCh1.to_bytes(4, 'big')
        Data_Conf += self.AWG_FrequencyCh2.to_bytes(4, 'big')
        Data_Conf += self.AWG_PeakToPeakCh1.to_bytes(2, 'big')
        Data_Conf += self.AWG_PeakToPeakCh2.to_bytes(2, 'big')
        Data_Conf += self.AWG_WaveTypeCh1.to_bytes(1, 'big')
        Data_Conf += self.AWG_WaveTypeCh2.to_bytes(1, 'big')
        Data_Conf += self.AWG_AmplificationCh1.to_bytes(1, 'big')
        Data_Conf += self.AWG_AmplificationCh2.to_bytes(1, 'big')
        Data_Conf += self.AWG_ActiveChannels.to_bytes(1, 'big')
        
        print("Raw Config Data: " + Data_Conf.hex() + " / Length: " + str(len(Data_Conf)) + " Bytes")
        self.send_packet(self.AWG_ID,self.DEV_CONF,Data_Conf,len(Data_Conf))
   
        
    def Config_LOA(self):
        Data_Conf = bytes()
        
        Data_Conf += self.LOI_Stub1.to_bytes(4, 'big')
        Data_Conf += self.LOI_Stub2.to_bytes(4, 'big')
        Data_Conf += self.LOI_Stub3.to_bytes(4, 'big')
        Data_Conf += self.LOI_Stub4.to_bytes(4, 'big')
        Data_Conf += self.LOI_Stub5.to_bytes(4, 'big')
        
        print("Raw Config Data: " + Data_Conf.hex() + " / Length: " + str(len(Data_Conf)) + " Bytes")
        self.send_packet(self.LIA_ID,self.DEV_CONF,Data_Conf,len(Data_Conf))
        
    def Config_OSC(self):
        Data_Conf = bytes()
        
        Data_Conf += self.OSC_mSecPerDivCh1.to_bytes(2, 'big')
        Data_Conf += self.OSC_mSecPerDivCh2.to_bytes(2, 'big')
        Data_Conf += self.OSC_mVoltPerDivCh1.to_bytes(2, 'big')
        Data_Conf += self.OSC_mVoltPerDivCh2.to_bytes(2, 'big')
        Data_Conf += self.OSC_TriggerCh1.to_bytes(2, 'big')
        Data_Conf += self.OSC_TriggerCh2.to_bytes(2, 'big')
        Data_Conf += self.OSC_DirectionCh1.to_bytes(1, 'big')
        Data_Conf += self.OSC_DirectionCh2.to_bytes(1, 'big')
        Data_Conf += self.OSC_AmplificationCh1.to_bytes(1, 'big')
        Data_Conf += self.OSC_AmplificationCh2.to_bytes(1, 'big')
        Data_Conf += self.OSC_ActiveChannels.to_bytes(1, 'big')
        
        print("Raw Config Data: " + Data_Conf.hex() + " / Length: " + str(len(Data_Conf)) + " Bytes")
        self.send_packet(self.OSC_ID,self.DEV_CONF,Data_Conf,len(Data_Conf))
        
    def Config_SA(self):
        Data_Conf = bytes()
        
        Data_Conf += self.SA_SampleRateCh1.to_bytes(4, 'big')
        Data_Conf += self.SA_SampleRateCh2.to_bytes(4, 'big')
        Data_Conf += self.SA_CaptureDepthCh1.to_bytes(2, 'big')
        Data_Conf += self.SA_CaptureDepthCh2.to_bytes(2, 'big')
        Data_Conf += self.SA_AmplificationCh1.to_bytes(1, 'big')
        Data_Conf += self.SA_AmplificationCh2.to_bytes(1, 'big')
        Data_Conf += self.SA_ActiveChannels.to_bytes(1, 'big')
        
        print("Raw Config Data: " + Data_Conf.hex() + " / Length: " + str(len(Data_Conf)) + " Bytes")
        self.send_packet(self.SA_ID,self.DEV_CONF,Data_Conf,len(Data_Conf))

    def main(self):
    
        self.Start_Dev(self.SA_ID)
        while(1):
            self.DataHandler()
            self.DataHandler()
            print("Data SA Ch1: " + str(self.SA_Ch1) + " / Data SA Ch2: " + str(self.SA_Ch2))
            ##self.DataHandler()
            ##print("Data SA Ch2: " + str(self.SA_Ch2))
    
       ## self.test()
        
    def test(self):
        self.Config_OSC()
        self.Config_AWG()
        self.Config_LOA()
        self.Config_SA()
        
        self.Start_Dev(self.AWG_ID)
        self.Start_Dev(self.OSC_ID)
        self.Start_Dev(self.SA_ID)
        self.Start_Dev(self.LIA_ID)
        
        self.Stop_Dev(self.AWG_ID)
        self.Stop_Dev(self.OSC_ID)
        self.Stop_Dev(self.SA_ID)
        self.Stop_Dev(self.LIA_ID)
        
        self.Reset_Dev(self.AWG_ID)
        self.Reset_Dev(self.OSC_ID)
        self.Reset_Dev(self.SA_ID)
        self.Reset_Dev(self.LIA_ID)
    
    
    ##TODO This should be put on another thread 
    def DataHandler(self):
        Temp = self.Pico_Serial.read(1)
        if(Temp == b''):
            return
        Tmp = int(Temp.hex(),16)    
        ##print(Tmp)
        if(0b11000000 & Tmp == 0b00000000):
            return ## Return Data is statuscode

        ##AWG AWG AWG AWG AWG AWG AWG AWG AWG AWG AWG 
        if(0b00000111 & Tmp == 0b011):
            ##Read32
            if(0b11000000 & Tmp == 0b11000000):
                #Ch1
                if(0b00001000 & Tmp == 0b00000000):
                    self.AWG_Ch1 = self.read32()
                #Ch2    
                if(0b00001000 & Tmp == 0b00001000):
                    self.AWG_Ch2 = self.read32()
        
        ##OSC OSC OSC OSC OSC OSC OSC OSC OSC OSC OSC 
        if(0b00000111 & Tmp == 0b100):
            ##Read32
            if(0b11000000 & Tmp == 0b11000000):
                #Ch1
                if(0b00001000 & Tmp == 0b00000000):
                    self.OSC_Ch1 = self.read32()
                #Ch2    
                if(0b00001000 & Tmp == 0b00001000):
                    self.OSC_Ch2 = self.read32()
        
        ##SA SA SA SA SA SA SA SA SA SA SA SA SA SA SA 
        if(0b00000111 & Tmp == 0b101):
            ##Read32
            
            if(0b11000000 & Tmp == 0b11000000):
                #Ch1
                
                if(0b00001000 & Tmp == 0b00000000):
                    self.SA_Ch1 = self.read32()
                #Ch2    
                if(0b00001000 & Tmp == 0b00001000):
                    self.SA_Ch2 = self.read32()
        
        
        
        ##LIA LIA LIA LIA LIA LIA LIA LIA LIA LIA LIA LIA 
        if(0b00000111 & Tmp == 0b111):
            ##Read32
            if(0b11000000 & Tmp == 0b11000000):
                #Ch1
                if(0b00001000 & Tmp == 0b00000000):
                    
                    self.LIA_Ch1 = self.read32()
                #Ch2    
                if(0b00001000 & Tmp == 0b00001000):
                    self.LIA_Ch2 = self.read32()
            
    
    def read32(self):
        return int(self.Pico_Serial.read(4).hex(),16)
