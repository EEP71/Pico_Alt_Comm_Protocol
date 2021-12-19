#include "settings.h"


void setting_selector(uint16_t input_value){
     switch(input_value){
        case set_adc_capture_depth:
          printf( "Pico toolbox confirms that the ADC capture depth is set to: ");
          printf("%d", convert_to_int());
          break;
        case set_adc_sample_rate:
          printf( "Pico toolbox confirms that the ADC sample rate is set to: ");
          printf("%d", convert_to_int());
          break;
        case set_adc_amplification:
          printf( "Pico toolbox confirms that the ADC amplification is set to: ");
          printf("%d", convert_to_int());
          break;
        case set_channel_number:
          printf( "Pico toolbox confirms that the Channel number is set to: ");
          printf("%d", convert_to_int());
          break;
        case set_awg_wave_type:
          printf( "Pico toolbox confirms that the AWG wave type is set to: ");
          printf("%d ", convert_to_int());
          break;
        case set_dac_freq:
          printf( "Pico toolbox confirms that the DAC freq is set to: ");
          printf("%d ", convert_to_int());
          break;
        case set_dac_channel_number:
          printf( "Pico toolbox confirms that the DAC channel number is set to: ");
          printf("%d ", convert_to_int());
          break;
        case set_peak_to_peak:
          printf( "Pico toolbox confirms that the Peak to Peak is set to: ");
          printf("%d ", convert_to_int());
          break;
        case set_awg_offset:
          printf( "Pico toolbox confirms that the AWG offset is set to: ");
          printf("%d ", convert_to_int());
          break;
        case set_mSeconds_per_dev:
          printf( "Pico toolbox confirms that the mSeconds per dev is set to: ");
          printf("%d ", convert_to_int());
          break;
        case set_trigger:
          printf( "Pico toolbox confirms that the Trigger is set to: ");
          printf("%d ", convert_to_int());
          break;
        case set_direction:
          printf( "Pico toolbox confirms that the Direction is set to: ");
          printf("%d ", convert_to_int());
          break;
        case set_mVolt_per_DIV:
          printf( "Pico toolbox confirms that the mVolt per DIV is set to: ");
          printf("%d ", convert_to_int());
          break;
        case get_adc_capture_depth:
          printf("GET FUNCTIONS ARE ON THE TODO LIST");
          break;
        case get_adc_sample_rate:
          printf("GET FUNCTIONS ARE ON THE TODO LIST");
          break;
      }

}

int convert_to_int(){
    char buf[100];
    int converted_to_int = 0;
    for (int i = 0; i <= 100; i++){
      buf[i] = getchar_timeout_us(1000000);
      if (buf[i] == '\n'){
          buf[i] = '\0';
          converted_to_int = atoi(buf);
          break;
      }
    }
    return converted_to_int;
}

