#include <Arduino.h>

class SensorDriver
{
public:
	int irPin;
	int irVal;

	SensorDriver();
	SensorDriver(int PWM);
	uint16_t distance();
};