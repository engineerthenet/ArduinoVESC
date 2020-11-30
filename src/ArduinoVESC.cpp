/*
  ArduinoVESC.h - Enables UART communication between a VESC and an Arduino.
  Created by engineerthenet, 30 November, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ArduinoVESC.h"
#include "HardwareSerial.h"
#include "SoftwareSerial.h"

ArduinoVESC::ArduinoVESC(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}