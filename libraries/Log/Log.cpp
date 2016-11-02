#include "Log.h"

void Log::println(const char* msg){
  if (buflast < BUFSIZE - 2){
    int len = snprintf(buffer + buflast, BUFSIZE - buflast - 1, msg);
    buflast += len;
    if (buflast > BUFSIZE - 1)
      buflast = BUFSIZE - 1; // partial write
  }
}

void Log::println(String msg){
    println(msg.c_str());
}

void Log::sendLog(){
  if (buflast > 0){
    for (byte i = 0; i <= buflast/32; i++){
      Wire.write(buffer + (i * 32));
    }
    //for (byte i = 0; i <= buflast; ++i){
    //  Wire.write(buffer[i]);
    //}
    //Wire.write(buffer); 
    buflast = 0;
  }
  else {
    Wire.write(0);
  }
}