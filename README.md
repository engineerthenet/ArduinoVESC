# ArduinoVESC
This library enables UART communication between a VESC and an Arduino. It uses hardware serial and is designed for use with an Arduino Mega. It has been tested with the latest VESC firmware version.

## Implementation
There are examples for each use case scenario, including software and hardware serial examples. You will need to initiate the ArduinoVESC class and set the serial port. Then you can call the class for each command.

```
#include <ArduinoVESC.h>

ArduinoVESC VESC;

void setup() {
  Serial.begin(115200);

  VESC.setSerialPort(Serial);
}

void loop() {
  if ( VESC.getData() ) {
    Serial.println(VESC.data.tempFET);
	Serial.println(VESC.data.tempMotor);
	Serial.println(VESC.data.avgMotorCurrent);
	Serial.println(VESC.data.avgInputCurrent);
	Serial.println(VESC.data.avgId);
	Serial.println(VESC.data.avgIq);
    Serial.println(VESC.data.dutyCycleNow);
	Serial.println(VESC.data.rpm);
	Serial.println(VESC.data.inpVoltage);
	Serial.println(VESC.data.ampHours);
	Serial.println(VESC.data.apmHoursCharged);
	Serial.println(VESC.data.tachometer);
	Serial.println(VESC.data.tachometerAbs);
  }
}
```

## Commands
getData()				Gets the values from the VESC

## Todo
Read the VESC firmware code and create commands for each function
Write the code to make this work

## License
This library is licensed under The GNU General Public License v3.0.