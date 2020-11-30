/*
  Name:    setNunchuckValues.ino
  Created: 30-11-2020
  Author:  engineerthenet
  Description:  Use the serial monitor to set the speed/brake and enable cruise control with the nunchuck values. 
                This example is made using a Arduino Micro (Atmega32u4) that has a HardwareSerial port (Serial1) seperated from the Serial port. 
                A Arduino Nano or Uno that only has one Serial port will not be able to get the commands over the Serial monitor.  
*/

#include <ArduinoVESC.h>

/** Initiate ArduinoVESC class */
ArduinoVESC UART;

void setup() {

  /** Setup Serial port to enter commands */
  Serial.begin(9600);

  /** Setup UART port (Serial1 on Atmega32u4) */
  Serial1.begin(19200);

  while (!Serial1) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&Serial1);
}

String command;
int throttle = 127;

void loop() {

  if (Serial.available()) {

    command = Serial.readStringUntil('\n');

    if (command.equals("cruise")) {

      /** The lowerButton is used to set cruise control */
      UART.nunchuck.lowerButton = true;

    }
    else if (command.equals("nocruise")) {

      /** The lowerButton is used to set cruise control */
      UART.nunchuck.lowerButton = false;

    }else {

      throttle = command.toInt();

      if ( throttle >= 0 && throttle <= 255) {

        /** The valueY is used to control the speed, where 127 is the middle = no current */
        UART.nunchuck.valueY = throttle;
        Serial.println(throttle);
        
      } else {
        
        throttle = 127;
        Serial.println("Unvalid throttle value");
        
      }
    }
  }

  /** Call the function setNunchuckValues to send the current nunchuck values to the VESC */
  UART.setNunchuckValues();

}