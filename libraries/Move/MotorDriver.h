#include <Arduino.h>

class MotorDriver
{
public:
	int pwmPin;
	int dirPin;
	int pwmVal;
	int dirVal;

	int defaultDir;

	MotorDriver(int PWM, int DIR, int defaultDir);
	void power(int power);
	void direction(char direction);
};