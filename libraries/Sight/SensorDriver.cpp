#include "SensorDriver.h"

SensorDriver::SensorDriver(int pin)
{
	irPin = pin;
}

uint16_t SensorDriver::distance()
{
	irVal = analogRead(irPin);
	return 187754 * pow(irVal, -1.51);
}