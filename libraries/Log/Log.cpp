#ifdef ARDUINO
#include <Arduino.h>
#endif
#include <stdio.h>
#include <string.h>
#include "IWire.h"
#include "Log.h"

#ifndef ARDUINO
#define min(a,b) ((a)<(b)?(a):(b))
#endif

Log::Log(IWire* _output){
  head = tail = 0;
  output = _output;
}

void Log::println(const char* msg){
  unsigned int messageLength = strlen(msg);
  if (messageLength > BUFSIZE){ // whole buffer
    snprintf(buffer, BUFSIZE - 1, "%s", msg);
    head = 0;
    tail = BUFSIZE;
  }
  else if (messageLength >= BUFSIZE - tail){ // split and wrap
    unsigned int room = BUFSIZE - tail - 1;
    snprintf(buffer + tail, room, "%s", msg); // print as much on the end of the buffer as we can

    const char* start = msg + room - 1;
    tail = snprintf(buffer, tail, "%s", start);
  }
  else {
    tail += snprintf(buffer + tail, BUFSIZE - tail - 1, "%s", msg);
  }
  //if (tail < head) head = tail + 1;
}

#ifdef ARDUINO
void Log::println(String msg){
    println(msg.c_str());
}
#endif

void Log::sendLog(){
  if (head != tail ){
    if (tail > head || head <= (BUFSIZE - 33)) // no wrapping
    {
      byte amt = min(tail - head, 32);
      output->write(buffer + head, amt);
      head += amt;
    }
    else { // wrap
      byte amt = BUFSIZE - 1 - head;
      output->write(buffer + head, amt);
      amt = min(tail, 32-amt);
      output->write(buffer, amt);
      head = amt;
    }
  }
  else {
    output->write(0);
  }
}

//void Log::diags(){
//  printf("Head: %d, tail: %d, buffer:\n%s\nend\n", head, tail, buffer);
//}

//byte Log::min(byte a, byte b){
//  return (a < b) ? a : b;
//}