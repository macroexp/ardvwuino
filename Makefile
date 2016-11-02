BOARD_TAG    = uno
ARDUINO_PORT = /dev/ttyACM*

ARDUINO_LIBS = SPI MCP_CAN Wire Log
ARDUINO_SKETCHBOOK = .
include /usr/share/arduino/Arduino.mk
