// CAN Send Example
// hybridized from a lot of stuff

#include <Wire.h>
#include <mcp_can.h>
#include <SPI.h>
#define BUFSIZE 32*12
#define SLAVE_ADDRESS 0x2A
///#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN Canbus(6);     // Set CS to pin 4
char UserInput;
char number;
int data;
char buffer[BUFSIZE];
unsigned int buflast = 0;
unsigned char *buffirst;
long unsigned int rxId;
unsigned int len = 0;
unsigned char rxBuf[8];

void println(String msg){
  int written = 0;
  if (buflast < BUFSIZE - 1){
    written = snprintf(buffer + buflast, BUFSIZE - buflast, msg.c_str());
    buflast = (written < 0) ? BUFSIZE : buflast + written;
  }
}

void receiveData(int byteCount){
  while(Wire.available()) {
    number = Wire.read();
    //Serial.print(“data received: “);
    //Serial.print(number);
  }
}

void sendData(){
  for (byte i = 0; i <= buflast/32; i++){
    Wire.write(*(buffirst + (i * 32)));
  }
  //for (byte i = 0; i <= buflast; ++i){
  //  Wire.write(buffer[i]);
  //}
  //Wire.write(buffer); 
  buflast = 0;
}

void setup()
{
  Serial.begin(115200);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if (Canbus.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) println("MCP2515 Initialized Successfully!");
  else println("Error Initializing MCP2515...");

  Canbus.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
  delay(250);
  buffirst = buffer;
  //println("Please choose a menu option.");
  //println("1.Speed");
  //println("2.RPM");
  //println("3.Throttle");
  //println("4.Coolant Temperature");
  //println("5.O2 Voltage");
  //println("6.MAF Sensor");
}


//byte data[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

void loop() {
  String s = "Hello ";
  s += len++;
  s += " World\n";
  println(s);
  delay(250); 
  //while(true){
    //println("Hello world\n");
    //delay(250);
  //}
/*
  while (Serial.available()) {
    UserInput = Serial.read();

    if (UserInput == '1') {
      Canbus.ecu_req(VEHICLE_SPEED, buffer);
      Serial.print("Vehicle Speed: ");
      Serial.println(buffer);
      delay(500);
    }
    else if (UserInput == '2') {
      Canbus.ecu_req(ENGINE_RPM, buffer);
      Serial.print("Engine RPM: ");
      Serial.println(buffer);
      delay(500);

    }
    else if (UserInput == '3') {
      Canbus.ecu_req(THROTTLE, buffer);
      Serial.print("Throttle: ");
      Serial.println(buffer);
      delay(500);

    }
    else if (UserInput == '4') {
      Canbus.ecu_req(ENGINE_COOLANT_TEMP, buffer);
      Serial.print("Engine Coolant Temp: ");
      Serial.println(buffer);
      delay(500);

    }
    else if (UserInput == '5') {
      Canbus.ecu_req(O2_VOLTAGE, buffer);
      Serial.print("O2 Voltage: ");
      Serial.println(buffer);
      delay(500);

    }
    else if (UserInput == '6') {
      Canbus.ecu_req(MAF_SENSOR, buffer);
      Serial.print("MAF Sensor: ");
      Serial.println(buffer);
      delay(500);

    }
    // else
      // {
      //  Serial.println(UserInput);
      //  Serial.println("Not a valid input.");
      //  Serial.println("Please enter a valid option.");
      // }
  }
  if (!digitalRead(CAN0_INT))                        // If CAN0_INT pin is low, read receive buffer
  {
    Canbus.readMsgBuf(&rxId, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)

    if ((rxId & 0x80000000) == 0x80000000)    // Determine if ID is standard (11 bits) or extended (29 bits)
      sprintf(buffer, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
    else
      sprintf(buffer, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);

    Serial.print(buffer);

    if ((rxId & 0x40000000) == 0x40000000) {  // Determine if message is a remote request frame.
      sprintf(buffer, " REMOTE REQUEST FRAME");
      Serial.print(buffer);
    } else {
      for (byte i = 0; i < len; i++) {
        sprintf(buffer, " 0x%.2X", rxBuf[i]);
        Serial.print(buffer);
      }
    }

    Serial.println();
  }
  */
}
  /*
    void poop()
    {
    // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
    byte sndStat = CAN0.sendMsgBuf(0x100, 0, 8, data);
    if(sndStat == CAN_OK){
      Serial.println("Message Sent Successfully!");
    } else {
      Serial.println("Error Sending Message...");
    }
    delay(100);   // send data per 100ms
    }
  */
  /*********************************************************************************************************
    END FILE
  *********************************************************************************************************/
