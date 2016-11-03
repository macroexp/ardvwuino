#ifdef ARDUINO
#include <Arduino.h>
#endif
#include <stdio.h>
#include "IWire.h"
#include "Log.h"

Log::Log(IWire* _output){
  buflast = 0;
  output = _output;
}

void Log::println(const char* msg){
  if (buflast < BUFSIZE - 2){
    int len = snprintf(buffer + buflast, BUFSIZE - buflast - 1, "%s", msg);
    buflast += len;
    if (buflast > BUFSIZE - 1)
      buflast = BUFSIZE - 1; // partial write
  }
}

#ifdef ARDUINO
void Log::println(String msg){
    println(msg.c_str());
}
#endif

void Log::sendLog(){
  if (buflast > 0){
    for (char i = 0; i <= buflast/32; i++){
      output->write(buffer + (i * 32));
    }
    buflast = 0;
  }
  else {
    output->write(0);
  }
}