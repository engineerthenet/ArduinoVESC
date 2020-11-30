/*
  ArduinoVESC.h - Enables UART communication between a VESC and an Arduino.
  Created by engineerthenet, 30 November, 2020.
  Released into the public domain.
*/
#ifndef ArduinoVESC_h
#define ArduinoVESC_h

#include "Arduino.h"

class ArduinoVESC
{
  /** Struct to store the telemetry data returned by the VESC */
  struct dataPackage {
    float tempFET;
	float tempMotor;
	float avgMotorCurrent;
	float avgInputCurrent;
	float avgId;
	float avgIq;
	float dutyCycleNow;
	long rpm;
	float inpVoltage;
	float ampHours;
	float ampHoursCharged;
	float wattHours;
	float wattHoursCharged;
	long tachometer;
	long tachometerAbs;
  }
  
  /** Struct to hold the nunchuck values to send to the VESC */
  struct nunchuckPackage {
	int	valueX;
	int	valueY;
	bool upperButton;
	bool lowerButton;
  };
  
  public:
	ArduinoVESC(void);

  private:
	int _pin;
};

#endif