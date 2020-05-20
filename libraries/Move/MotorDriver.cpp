#include "MotorDriver.h"

MotorDriver::MotorDriver(int PWM, int DIR, int initDir)
{
	pwmPin = PWM;
	dirPin = DIR;
	defaultDir = initDir;
}

void MotorDriver::power(int power)
{
	pwmVal = power;

	analogWrite(pwmPin, pwmVal);
}

void MotorDriver::direction(char direction)
{
	dirVal = defaultDir;

	if(direction == 'f')
		dirVal = defaultDir;
	if(direction == 'b')
		dirVal == !defaultDir;

	digitalWrite(dirPin, dirVal);
}

