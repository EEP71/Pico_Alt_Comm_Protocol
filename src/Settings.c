#include "settings.h"





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

