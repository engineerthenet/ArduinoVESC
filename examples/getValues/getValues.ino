/*
  Name:    getVescValues.ino
  Created: 30-11-2020
  Author:  engineerthenet
  Description:  This example is made using a Arduino Micro (Atmega32u4) that has a HardwareSerial port (Serial1) seperated from the Serial port. 
                A Arduino Nano or Uno that only has one Serial port will not be able to display the data returned.
*/

#include <ArduinoVESC.h>

/** Initiate ArduinoVESC class */
ArduinoVESC VESC;

void setup() {

  /** Setup Serial port to display data */
  Serial.begin(115200);

  /** Setup VESC port (Serial1 on Atmega32u4) */
  Serial1.begin(115200);
  
  while (!Serial) {;}

  /** Define which ports to use as VESC */
  VESC.setSerialPort(&Serial1);
}

void loop() {
  
  /** Call the function getVescValues() to acquire data from VESC */
  if ( VESC.getVescValues() ) {
  
  Serial.print("FET Temperature: "); Serial.println(VESC.data.tempFET);
  Serial.print("Motor Temperature: "); Serial.println(VESC.data.tempMotor);
  Serial.print("Average Motor Current: "); Serial.println(VESC.data.avgMotorCurrent);
  Serial.print("Average Input Current: "); Serial.println(VESC.data.avgInputCurrent);
  Serial.print("Average id: "); Serial.println(VESC.data.avgIq);
  Serial.print("Average iq: "); Serial.println(VESC.data.avgIq);
  Serial.print("dutyCycleNow: "); Serial.println(VESC.data.dutyCycleNow);
  Serial.print("Electrical RPM: "); Serial.println(VESC.data.rpm);
  Serial.print("Input Voltage: "); Serial.println(VESC.data.inpVoltage);
  Serial.print("Amp Hours Used: "); Serial.println(VESC.data.ampHours);
  Serial.print("Amp Hours Charged: "); Serial.println(VESC.data.ampHoursCharged);
  Serial.print("Watt Hours Used: "); Serial.println(VESC.data.wattHours);
  Serial.print("Watt Hours Charged: "); Serial.println(VESC.data.wattHoursCharged);
  Serial.print("Tachometer: "); Serial.println(VESC.data.tachometer);
  Serial.print("Absolute Tachometer: "); Serial.println(VESC.data.tachometerAbs);
  Serial.print("Motor Fault Code: "); Serial.println(VESC.data.faultCode);
  Serial.print("PID Position: "); Serial.println(VESC.data.pidPosNow);
  Serial.print("Controller ID: "); Serial.println(VESC.data.controllerId);
  Serial.print("FET1 Temperature: "); Serial.println(VESC.data.fet1);
  Serial.print("FET2 Temperature: "); Serial.println(VESC.data.fet2);
  Serial.print("FET3 Temperature: "); Serial.println(VESC.data.fet3);
  Serial.print("Average Vd: "); Serial.println(VESC.data.avgVd);
  Serial.print("Average Vq: "); Serial.println(VESC.data.avgVq);

  }
  else
  {
    Serial.println("Failed to get data!");
  }

  delay(50);
}