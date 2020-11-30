/*
  Name:    setCurrent.ino
  Created: 30-11-2020
  Author:  engineerthenet
  Description: This is a very simple example of how to set the current for the motor
*/

#include <ArduinoVESC.h>

/** Initiate ArduinoVESC class */
ArduinoVESC UART;

float current = 1.0; /** The current in amps */

void setup() {
  Serial.begin(9600);
  /** Setup UART port (Serial1 on Atmega32u4) */
  Serial1.begin(19200);
  
  while (!Serial1) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&Serial1);
}

void loop() {
  
  /** Call the function setCurrent() to set the motor current */
  UART.setCurrent(current);

  // UART.setBrakeCurrent(current);
  
}